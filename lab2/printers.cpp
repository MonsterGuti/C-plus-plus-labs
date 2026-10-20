#include <iostream>
using namespace std;

class pr2;

class pr1 {
    int printing;

public:
    pr1() {
        printing = 0;
    }

    void set_print(int status) {
        printing = status;
    }

    friend bool inuse(pr1 p1, pr2 p2);
};

class pr2 {
    int printing;

public:
    pr2() {
        printing = 0;
    }

    void set_print(int status) {
        printing = status;
    }

    friend bool inuse(pr1 p1, pr2 p2);
};

bool inuse(pr1 p1, pr2 p2) {
    if (p1.printing == 1 || p2.printing == 1)
        return true;
    else
        return false;
}

int main() {
    pr1 obj1;
    pr2 obj2;

    cout << boolalpha;

    cout << "Printer in use: " << inuse(obj1, obj2) << "\n";

    obj1.set_print(1);

    cout << "Printer in use: " << inuse(obj1, obj2) << "\n";

    obj1.set_print(0);
    obj2.set_print(1);

    cout << "Printer in use: " << inuse(obj1, obj2) << "\n";

    obj2.set_print(0);

    cout << "Printer in use: " << inuse(obj1, obj2) << "\n";

    return 0;
}
