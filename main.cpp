#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Rational {
private:
    int a, b;
public:
    friend ostream& operator<<(ostream& os, Rational& x);
    Rational(int a, int b){
        this->a = a;
        this->b = b;
    }
    Rational():Rational(0,0){}

    int getA()const{
        return a;
    }
    int getB()const{
        return b;
    }
    Rational operator+(const Rational& x)const{
        return Rational(a*x.getB() + b * x.getA(), b*x.getB());
    }

    Rational operator-(const Rational& x)const{

        return Rational(a * x.getB() - b * x.getA(), b * x.getB()  );;
    }

    Rational operator*(const Rational& x)const{
        return Rational(a * x.getA(), b * x.getB());
    }

    Rational operator/(const Rational& x)const{
        return Rational(a * x.getB(), b * x.getA());
    }
    Rational operator*(int x){
        return Rational(a * x, b);
    }


};
Rational operator*(int x, Rational& r){
    Rational result = r*x;
    return result;
}

ostream& operator<<(ostream& os, Rational& x){
    os<<x.a<<"/"<<x.b;
    return os;
}
int main()
{
    Rational a(1, 2);
    Rational b(2, 3);
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}
