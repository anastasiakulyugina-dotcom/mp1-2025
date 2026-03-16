#include <iostream>
using namespace std;

class Time {
	int hours;
	int minutes;
	int seconds;

public:
	Time() : hours(0), minutes(0), seconds(0) {}

	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

	void setTime(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}

	int getHours() { return hours; }
	int getMinutes() { return minutes; }
	int getSeconds() { return seconds; }

	int AllSeconds() {
		return hours * 3600 + minutes * 60 + seconds;
	}

	Time different(Time& other) {
		int diff = other.AllSeconds() - this->AllSeconds();
		if (diff < 0) diff = -diff;
		Time res;
		res.hours = diff / 3600;
		diff %= 3600;
		res.minutes = diff / 60;
		res.seconds = diff % 60;

		return res;
	}

	void sdvigforward(int h, int m, int s) {
		hours -= h;
		minutes -= m;
		seconds -= s;
	}

	void sdvigbackward(int h, int m, int s) {
		hours += h;
		minutes += m;
		seconds += s;
	}

	void Vivod() {
		cout << hours << ":" << minutes << ":" << seconds;
	}
};


int main()
{
	Time t1;
	Time t2(10, 30, 45);

	t1.Vivod();
	cout << endl;
	t2.Vivod();
	cout << endl;
	t1.setTime(33, 50, 0);
	t1.Vivod();

	cout << t1.getHours() << " hours "
		<< t1.getMinutes() << " minutes "
		<< t1.getSeconds() << " seconds " << endl;

	Time diff = t2.different(t1);
	diff.Vivod();
	cout << endl;

	t1.Vivod();
	cout << endl;
	t1.sdvigforward(1, 0, 30);
	t1.Vivod();
	cout << endl;

	t2.Vivod();
	cout << endl;
	t2.sdvigbackward(5, 20, 50);
	t2.Vivod();


	return 0;
}
