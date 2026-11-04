задача 1
#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<char> s;

public:
    void push(char c) {
        s.push(c);
    }

    char pop() {
        if (!s.empty()) {
            char c = s.top();
            s.pop();
            return c;
        }
        return '\0';
    }

    bool empty() {
        return s.empty();
    }

    char top() {
        return s.top();
    }
};

Stack loadstack() {
    Stack s;

    for (char c = 'a'; c <= 'z'; c++) {
        s.push(c);
    }

    return s;
}

Stack loadstack(int upper) {
    Stack s;

    if (upper == 1) {
        for (char c = 'A'; c <= 'Z'; c++) {
            s.push(c);
        }
    }
    else {
        for (char c = 'a'; c <= 'z'; c++) {
            s.push(c);
        }
    }

    return s;
}

int main() {
    Stack s1 = loadstack();
    Stack s2 = loadstack(1);
    Stack s3 = loadstack(0);

    cout << "Stack s1: ";
    while (!s1.empty()) {
        cout << s1.pop() << " ";
    }

    cout << "\nStack s2: ";
    while (!s2.empty()) {
        cout << s2.pop() << " ";
    }

    cout << "\nStack s3: ";
    while (!s3.empty()) {
        cout << s3.pop() << " ";
    }

    return 0;
}
