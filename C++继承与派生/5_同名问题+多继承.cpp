#include<iostream>
using namespace std;

/*
同名问题：
1.数据成员同名
2.成员函数同名
*/

/*
多继承：存在两个以及以上的父类

1.权限与单继承相同
2.构造函数写法也与单继承相同

*/

class MM
{
public:
    MM(string mmFName, string mmSName)
        :mmFName(mmFName), mmSName(mmSName) {}
protected:
    string mmFName;
    string mmSName;
};

class Boy
{
public:
    Boy(string boyFName, string boySName)
        :boyFName(boyFName), boySName(boySName) {}
protected:
    string boyFName;
    string boySName;
};

// Multiple inheritance
class Son : public MM, public Boy
{
public:
    Son(string mmFName, string mmSName, string boyFName, string boySName,string sSname) 
        : MM(mmFName, mmSName), Boy(boyFName, boySName), sFName(boyFName+mmFName),sSName(sSname){}
    
        void print()
        {
            cout << "MM:" <<mmFName + mmSName<<endl;
            cout << "Boy:" <<boyFName + boySName<<endl;
            cout << "Son:" <<sFName + sSName<<endl;
        }
protected:
    string sFName;
    string sSName;
};

int main()
{
    Son *pSon = new Son();
    pSon ->print();
    return 0;

}