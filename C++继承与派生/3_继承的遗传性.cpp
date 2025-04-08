#include<iostream>
using namespace std;

/*
    


*/

class A
{
    public:
    A (int a) :a(a){}
    int a;
};

class B :public A
{
    public:
    B(int a,int b) :b(b),A(a){} // a要用A的构造函数初始化


    // int a;
    int b;
};

class C :public B
{
    public:
    C(int a,int b ,int c) :B(a,b),c(c){} // c类只要用B类的构造函数就行
    // int a;
    // int b;
    int c;
};

class D :public C
{
    public:
    // int a;
    // int b;
    // int c;
    int d;
};  //拓展的越多层，遗传的越多，效率越低