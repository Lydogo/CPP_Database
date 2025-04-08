#include<iostream>
using namespace std;

/*
    普通对象来说：通常 构造顺序和析构顺序是相反的
    对象死亡的适合会调用析构函数

*/

class A 
{
    public:
    A()
    {
        cout << "A";
    }
    ~A()
    {
        cout<<"a";
    }
};

class B :public A
{
    public:
    B()
    {
        cout << "B";
    }
    ~B()
    {
        cout<<"b" ;
    }
};

int main()
{
    {
        A aobject;  //调用A的构造函数
        B bobject;  //先调用A的构造函数，再调用B的构造函数
    }   //析构顺序：BAA
    cout <<endl;
    { //随用随调
        B* p = new B;  //AB
        B bobject;     //AB 
        delete p;  //baba 前一个ba：p指向的对象 后一个ba bobject
        //对象的释放顺序会改变，什么适合delete对象什么适合死亡
    }
    return 0;
}