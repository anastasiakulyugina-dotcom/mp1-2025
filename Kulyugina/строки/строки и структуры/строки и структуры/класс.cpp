#include <iostream>
#include <string>

using namespace std;

class Song {
	string author;
	string title;
	int year;
	double siz;

public:
	Song(string s1 = "", string s2 = "", int y = 2000, double d = 0.0);

	void Print() {
		cout << author << " " << title << " " << year << " " << siz << endl;
	};

	bool Compare(const Song& p2) {
		if (siz < p2.siz) return true;
		else return false;
	};

	Song::Song(string s1, string s2, int y, double d) : title(s1), author(s2), year(y), siz(d) {
		cout << "construstor for " << s1 << "\n";
	}
};

int main() {
	Song p1("Beatles", "Yesterday", 1965, 2.06);
	Song p2;

	p1.Print();
	bool a = p1.Compare(p2);
	cout << a;



	return 0;
}
