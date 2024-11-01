#include <iostream>
using namespace std;

class A
{
    int i;

public:
    A(int ii) : i(ii)
    {
        cout << "A's ctor is called" << endl;
    }
    ~A()
    {
        cout << "A's dtor is called" << endl;
    }
    void f() const
    {
        cout << "A::f() is called" << endl;
    }
};

class B
{
    int i;

public:
    B(int ii) : i(ii)
    {
        cout << "B's ctor is called" << endl;
    }
    ~B()
    {
        cout << "B's dtor is called" << endl;
    }
    void f() const
    {
        cout << "B::f() is called" << endl;
    }
};

class C : public B
{
    A a;

public:
    C(int ii) : B(ii), a(ii)
    {
        cout << "C's ctor is called" << endl;
    }
    ~C()
    {
        cout << "C's dtor is called" << endl;
    }
    void f() const
    {
        B::f();
        a.f();
    }
};

int main()
{
    C c(47);
    c.f();
    return 0;
}