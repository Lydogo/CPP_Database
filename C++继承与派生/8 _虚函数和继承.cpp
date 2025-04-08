#include<iostream>
using namespace std;

class A
{
public:
    void print()
    {
        cout << "A"<<endl;
    }
};

class B :public A
{
public:
    virtual void print()
    {
        cout << "B"<<endl;
    }
};

class C :public B
{
public:
    void print()
    {
        cout << "C"<<endl;
    }
};

//虚函数一旦被继承，永远是虚函数
class D :public C
{
public:
    void print()
    {
        cout << "D"<<endl;
    }
};

int main()
{
    //正常对象，正常指针访问：都是就近原则
    //不正常情况：
    //1.不存在virtual 看指针类型
    A*pA = new B;
    pA->print();

    //2.存在virtual 看对象
    B*pB = new C;
    pB->print();
    pB = new B; //就近原则
    pB->print();

    C c;
    pB = &c;  //多态：virtual+指针引用
    pB ->print();

    C* pC = new D;
    pC->print();
    return 0;
}