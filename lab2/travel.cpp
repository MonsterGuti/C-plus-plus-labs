#include <iostream>
using namespace std;

class truck;

class car {
    int passengers;
    int speed;

public:
    car(int p, int s) {
        passengers = p;
        speed = s;
    }

    friend int sp_greater(car c, truck t);
    friend double travel_time(car c, double S);
};

class truck {
    int weight;
    int speed;

public:
    truck(int w, int s) {
        weight = w;
        speed = s;
    }

    friend int sp_greater(car c, truck t);
    friend double travel_time(truck t, double S);
};

int sp_greater(car c, truck t) {
    return c.speed - t.speed;
}

double travel_time(car c, double S) {
    return S / c.speed;
}

double travel_time(truck t, double S) {
    return S / t.speed;
}

int main() {
    car c1(6, 55), c2(2, 120);
    truck t1(10000, 55), t2(20000, 72);

    double S;

    cout << "Enter distance in kilometers: ";
    cin >> S;

    cout << "Time for car c1: "
         << travel_time(c1, S) << " hours\n";

    cout << "Time for truck t2: "
         << travel_time(t2, S) << " hours\n";

    return 0;
}
