#include <iostream>
using namespace std;

class RINT
{
private:
    int value;

public:
    RINT(int v = 0)
    {
        value = v;
    }

    RINT operator+() const
    {
        return RINT(+value);
    }

    RINT operator+(const RINT& a) const
    {
        return RINT(value + a.value);
    }

    RINT operator-() const
    {
        return RINT(-value);
    }

    RINT operator-(const RINT& a) const
    {
        return RINT(value - a.value);
    }

    RINT operator*(const RINT& a) const
    {
        return RINT(value * a.value);
    }

    RINT operator/(const RINT& a) const
    {
        if (a.value == 0)
        {
            cout << "Error: division by zero!" << endl;
            return RINT(0);
        }

        return RINT(value / a.value);
    }

    void Show() const
    {
        cout << value << endl;
    }
};

int main()
{
    RINT a(10);
    RINT b(5);
    RINT c;

    c = a + b;
    cout << "Addition: ";
    c.Show();

    c = a - b;
    cout << "Subtraction: ";
    c.Show();

    c = -a;
    cout << "Unary minus: ";
    c.Show();

    c = +a;
    cout << "Unary plus: ";
    c.Show();

    c = a * b;
    cout << "Multiplication: ";
    c.Show();

    c = a / b;
    cout << "Division: ";
    c.Show();

    return 0;
}
