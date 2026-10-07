#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    bool setTime(int h, int m, int s) {
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
            return true;
        } else {
            cout << "Error: Invalid values for hours, minutes, or seconds!\n";
            return false;
        }
    }

    void print24() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }

    void print12() const {
        int h12 = hours % 12;
        if (h12 == 0) {
            h12 = 12;
        }

        string period = (hours >= 12) ? "PM" : "AM";

        cout << setfill('0') << setw(2) << h12 << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << " " << period << endl;
    }
};


int main() {
    Time t1;

    cout << " Setting valid time (13:24:07) " << endl;
    if (t1.setTime(13, 24, 7)) {
        cout << "24-hour format: ";
        t1.print24();

        cout << "12-hour format: ";
        t1.print12();
    }

    cout << "\n Setting morning time (08:05:09) " << endl;
    if (t1.setTime(8, 5, 9)) {
        cout << "24-hour format: ";
        t1.print24();

        cout << "12-hour format: ";
        t1.print12();
    }

    cout << "\n Attempting to set invalid values (25:61:00) " << endl;
    t1.setTime(25, 61, 0);

    return 0;
}