
#include <iostream>
using namespace std;

class Vec4
{
private:
    float v[4];

public:
    Vec4(float a = 0, float b = 0, float c = 0, float d = 0)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
    }

    float& operator[](int index)
    {
        return v[index];
    }

    const float& operator[](int index) const
    {
        return v[index];
    }

    Vec4 operator+(const Vec4& a) const
    {
        return Vec4(
            v[0] + a.v[0],
            v[1] + a.v[1],
            v[2] + a.v[2],
            v[3] + a.v[3]
        );
    }

    Vec4 operator-(const Vec4& a) const
    {
        return Vec4(
            v[0] - a.v[0],
            v[1] - a.v[1],
            v[2] - a.v[2],
            v[3] - a.v[3]
        );
    }

    Vec4 operator*(const Vec4& a) const
    {
        return Vec4(
            v[0] * a.v[0],
            v[1] * a.v[1],
            v[2] * a.v[2],
            v[3] * a.v[3]
        );
    }

    Vec4 operator/(const Vec4& a) const
    {
        return Vec4(
            v[0] / a.v[0],
            v[1] / a.v[1],
            v[2] / a.v[2],
            v[3] / a.v[3]
        );
    }

    Vec4 operator+(float x) const
    {
        return Vec4(v[0] + x, v[1] + x,
                    v[2] + x, v[3] + x);
    }

    Vec4 operator-(float x) const
    {
        return Vec4(v[0] - x, v[1] - x,
                    v[2] - x, v[3] - x);
    }

    Vec4 operator*(float x) const
    {
        return Vec4(v[0] * x, v[1] * x,
                    v[2] * x, v[3] * x);
    }

    Vec4 operator/(float x) const
    {
        if (x == 0)
        {
            cout << "Error: division by zero!" << endl;
            return Vec4();
        }

        return Vec4(v[0] / x, v[1] / x,
                    v[2] / x, v[3] / x);
    }

    void Show() const
    {
        cout << "(";
        for (int i = 0; i < 4; i++)
        {
            cout << v[i];
            if (i < 3)
                cout << ", ";
        }
        cout << ")" << endl;
    }
};

int main()
{
    Vec4 a(2, 4, 6, 8);
    Vec4 b(1, 2, 3, 4);
    Vec4 c;

    c = a + b;
    cout << "Addition: ";
    c.Show();

    c = a - b;
    cout << "Subtraction: ";
    c.Show();

    c = a * b;
    cout << "Multiplication: ";
    c.Show();

    c = a / b;
    cout << "Division: ";
    c.Show();

    c = a + 2.0f;
    cout << "Vector + float: ";
    c.Show();

    c = a - 2.0f;
    cout << "Vector - float: ";
    c.Show();

    c = a * 2.0f;
    cout << "Vector * float: ";
    c.Show();

    c = a / 2.0f;
    cout << "Vector / float: ";
    c.Show();

    cout << "Element at index 0: " << a[0] << endl;

    a[0] = 10;
    cout << "Changed vector: ";
    a.Show();

    return 0;
}
