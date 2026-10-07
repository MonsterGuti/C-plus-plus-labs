#include <iostream>

using namespace std;

class Line {
private:
    int Len;

public:
    Line(int length) {
        Len = length;
        for (int i = 0; i < Len; i++) {
            cout << "*";
        }
        cout << endl;
    }
    ~Line() {
        for (int i = 0; i < Len; ++i) {
            cout << "\b \b";
        }
        cout << "\n[Line deleted from screen]" << endl;
    }
};
int main() {
    cout << "Creating Line object..." << endl;

    {
        Line myLine(15);

        cout << "Line is currently drawn above." << endl;
    }

    cout << "Program ended." << endl;

    return 0;
}