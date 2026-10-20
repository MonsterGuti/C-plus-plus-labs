#include <iostream>

using namespace std;

class rectangle {
private:
    double a, b;

public:
    rectangle();

    double face();
    double face(double *p);

    void show(const char *name);

    ~rectangle() {
        cout << "\nDestructing object rectangle!\n";
    }
};

rectangle::rectangle() {
    do {
        cout << "Enter two sides of the rectangle:\n";
        cin >> a >> b;
    } while (a <= 0 || b <= 0);
}

double rectangle::face() {
    return a * b;
}

double rectangle::face(double *p) {
    *p = 2 * (a + b);
    return a * b;
}

void rectangle::show(const char *name) {
    cout << "Sides of rectangle " << name << ":\n";
    cout << "a = " << a << ", b = " << b << "\n";
}

int main() {
    rectangle r1;

    r1.show("r1");

    cout << "The area of rectangle r1 is S = "
         << r1.face() << "\n";

    rectangle r2;

    r2.show("r2");

    double p, s;
    s = r2.face(&p);

    cout << "The area of rectangle r2 is S = " << s
         << ", and the perimeter is P = " << p << "\n";

    return 0;
}
