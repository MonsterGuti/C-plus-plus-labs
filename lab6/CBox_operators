
#include <iostream>
using namespace std;

class CBox
{
public:

    CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0)
        : m_Height(hv)
    {
        m_Length = lv > wv ? lv : wv;
        m_Width = wv < lv ? wv : lv;
    }

    double Volume() const
    {
        return m_Length * m_Width * m_Height;
    }

    int operator>(const CBox& aBox) const
    {
        return Volume() > aBox.Volume();
    }

    int operator>(const double& value) const
    {
        return Volume() > value;
    }

    CBox operator+(const CBox& aBox) const
    {
        return CBox(
            m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
            m_Width > aBox.m_Width ? m_Width : aBox.m_Width,
            m_Height + aBox.m_Height
        );
    }

    int operator<(const CBox& aBox) const
    {
        return Volume() < aBox.Volume();
    }

    int operator==(const CBox& aBox) const
    {
        return Volume() == aBox.Volume();
    }

    CBox operator-(const CBox& aBox) const
    {
        return CBox(
            m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
            m_Width > aBox.m_Width ? m_Width : aBox.m_Width,
            m_Height - aBox.m_Height
        );
    }

    void ShowBox() const
    {
        cout << m_Length << " "
             << m_Width << " "
             << m_Height << endl;
    }

private:
    double m_Length;
    double m_Width;
    double m_Height;
};

int main()
{
    CBox smallBox(4.0, 2.0, 1.0);
    CBox mediumBox(10.0, 4.0, 2.0);
    CBox aBox;
    CBox bBox;

    aBox = smallBox + mediumBox;
    cout << "aBox dimensions are ";
    aBox.ShowBox();

    bBox = aBox + smallBox + mediumBox;
    cout << "bBox dimensions are ";
    bBox.ShowBox();

    aBox = mediumBox - smallBox;
    cout << "Subtraction: ";
    aBox.ShowBox();

    cout << "smallBox < mediumBox: "
         << (smallBox < mediumBox) << endl;

    cout << "smallBox == mediumBox: "
         << (smallBox == mediumBox) << endl;

    cout << "mediumBox > smallBox: "
         << (mediumBox > smallBox) << endl;

    return 0;
}
