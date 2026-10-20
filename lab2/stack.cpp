#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<char> s;

public:
    Stack loadstack();
    Stack loadstack(int upper);

    void show();
};

Stack Stack::loadstack() {
    for (char c = 'a'; c <= 'z'; c++) {
        s.push(c);
    }
    return *this;
}

Stack Stack::loadstack(int upper) {
    char start, end;

    if (upper == 1) {
        start = 'A';
        end = 'Z';
    } else {
        start = 'a';
        end = 'z';
    }

    for (char c = start; c <= end; c++) {
        s.push(c);
    }

    return *this;
}

void Stack::show() {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Stack s1, s2, s3;

    s1 = s1.loadstack();
    s2 = s2.loadstack(1);
    s3 = s3.loadstack(0);

    cout << "Small letters:\n";
    s1.show();

    cout << "Capital letters:\n";
    s2.show();

    cout << "Small letters:\n";
    s3.show();

    return 0;
}
