#include<iostream>
using namespace std;

class A
{
public:
    A(int a) : a(a) {}
    int a;
};

class B : virtual public A
{
public:
    B(int a) : A(a) {}
};

class C : virtual public A
{
public:
    C(int a) : A(a) {}
};

class D : public B, public C
{
public:
    //虚继承中构造函数的写法必须调用祖父的构造函数
    //并且当前类中的属性继承祖先类属性只和调用的祖父类构造函数传参有关系
    D(int a) : B(a), C(a),A(123)
    {

    }
    void print()
    {
        //  cout << C:a <<endl; 使用类名限定不会出现二义性问题  
        cout << a <<endl;
    }
};

int main()
{
    
    
    return 0;
}