#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

struct Book {
	string author;
	string title;
	int year;
	int pages;
};

string removeQ(const string& s) {
    string result = s;
    result.erase(remove(result.begin(), result.end(), '"'), result.end());
    return result;
}

bool isnumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

Book parseLine(const string& s) {
	Book book;
	book.author = "";
	book.title = "";
	book.year = 0;
	book.pages = 0;

	istringstream iss(s);
	string token;

    while (iss >> token) {
        if (token.size() == 4 && isnumber(token)) {
            book.year = stoi(token);
        }
        else if (token.size() >= 2 && token.size() <= 3 && isnumber(token)) {
            book.pages = stoi(token);
        }
        
        else if (token.front() == '"') {
            if (token.back() == '"') {
                book.title = removeQ(token);
            }
            else {
                book.title = removeQ(token) + " ";
                string nextToken;
                while (iss >> nextToken) {
                    book.title += nextToken;
                    if (nextToken.back() == '"') {
                        book.title = removeQ(book.title);
                        break;
                    }
                    book.title += " ";
                }
            }
        }
        else if (book.author.empty()) {
            book.author = token;
        }
        else {
            book.author += " " + token;
        }
    }
    return book;
}

void printBook(const Book& book) {
    cout << "Автор: " << book.author << endl;
    cout << "Название: " << book.title << endl;
    cout << "Год: " << book.year << endl;
    cout << "Страниц: " << book.pages << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "size = ";
    cin >> size;
    cin.ignore();

    Book* arr = new Book[size];

    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);
        arr[i] = parseLine(s);
    }

    for (int i = 0; i < size; i++) {
        cout << "Книга " << i + 1 << ":" << endl;
        printBook(arr[i]);
    }

    cout << "Введите имя автора: ";
    string searchAuthor;
    getline(cin, searchAuthor);

    cout << "\nКниги автора \"" << searchAuthor << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].author == searchAuthor) {
            printBook(arr[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Книги не найдены." << endl;
    }

    cout << "Введите год: ";
    int searchYear;
    cin >> searchYear;

    cout << "\nКниги опубликованные после " << searchYear << " года:" << endl;
    found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].year > searchYear) {
            printBook(arr[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Книги не найдены." << endl;
    }

    delete[] arr;
    return 0;
}