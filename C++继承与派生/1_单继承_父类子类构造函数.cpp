#include <iostream>
#include<string>
using namespace std;

class MM
{
public:
    MM(string name,int age) :name(name),age(age)
    {
        cout << "父类带参构造函数" <<endl;
    }  //初始化参数列表
    MM()
    {
        cout <<"父类无参构造函数"<<endl;
    }
    void print()
    {
        cout<<"MM:"<<name << ":" <<age<<endl;
    }

protected:
    string name;
    int age;

 private:
    int num;
};

//继承子类写法 class 子类名字 ：继承方式
//继承方式代表的是父类属性在子类中的最低权限
class Boy :protected MM
{
public:
    //子类的构造函数，必须调用父类的函数
    //1.不想写的适合，习惯于在父类中增加一个无参数构造函数
    Boy()
    {
        cout << "子类无参构造函数" <<endl;
    }

    //采用初始化参数列表的方式调用父类的构造函数
    Boy(string name,int age) :MM(name,age)
    {
        cout<<"子类带参数构造函数"<<endl;
    }
    void printBoy()
    {
        cout << name << age << endl;
        //cout << num << endl;   父类中的私有属性不可访问
    }

// protected:
//     //void print()
//     //string name
//     //int age
// private:

};

int main()
{
    MM mm("MM",25);
    mm.print();
    Boy boy;  //子类构造函数，调用了父类的构造函数
    Boy boy2("张三",2);
    boy2.printBoy();
}