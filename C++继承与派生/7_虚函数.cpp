#include<iostream>
using namespace std;

/*虚函数：用virtual修饰的函数（构造函数没有虚函数）
1.虚函数对于类的内存影响
    32位系统下，只会增加4个字节
2.纯虚函数
    2.1抽象类：巨头纯虚函数的类
        抽象类的特性：不能创建对象，但是可以创建对象指针
    2.2 ADT:抽象数据类型 abstract data type
3.虚析构函数
    父类指针被子类对象初始化的析构会有问题
*/

class MM
{

};
class Boy
{
public:
    //虚函数表：一个函数指针用来操作虚函数，无论几个虚函数只会增加4个字节
    virtual void print1()
    {
        cout << "虚函数1" <<endl;
    }
    virtual void print2()
    {
        cout << "虚函数2" <<endl;
    }
    int age;
};

class stack
{
public:
    //纯虚函数，子类如果要创建对象，需要重写
    virtual void push(int element) =0;
    virtual void pop() =0;
    virtual int top() =0;
    virtual bool empty() =0;
};

class arrayStack :public stack
{
public:
    void push(int element)
    {

    };
    void pop()
    {

    };
    int top()
    {
        return 0;
    };
    bool empty()
    {
        return true;
    };
};

class A
{
public:
    virtual ~A()
    {
        cout << "父类析构函数" <<endl;
    }
protected:
};

class B :public A
{
public:
    ~B()
    {
        cout << "子类析构函数" <<endl;
    }
};

int main()
{
    cout<<sizeof(MM)<<endl;  //空的类占用1个字节 内存标记
    cout<<sizeof(Boy)<<endl;  //age占用4个字节,无论几个虚函数都只占用4个字节，共8个

    arrayStack mystack;
    {
        //父类指针被子类对象初始化的析构会有问题
        A* pA = new B;
        delete pA;
    }
    return 0;

}