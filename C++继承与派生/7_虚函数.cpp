#include<iostream>
using namespace std;

/*�麯������virtual���εĺ��������캯��û���麯����
1.�麯����������ڴ�Ӱ��
    32λϵͳ�£�ֻ������4���ֽ�
2.���麯��
    2.1�����ࣺ��ͷ���麯������
        ����������ԣ����ܴ������󣬵��ǿ��Դ�������ָ��
    2.2 ADT:������������ abstract data type
3.����������
    ����ָ�뱻��������ʼ����������������
*/

class MM
{

};
class Boy
{
public:
    //�麯����һ������ָ�����������麯�������ۼ����麯��ֻ������4���ֽ�
    virtual void print1()
    {
        cout << "�麯��1" <<endl;
    }
    virtual void print2()
    {
        cout << "�麯��2" <<endl;
    }
    int age;
};

class stack
{
public:
    //���麯�����������Ҫ����������Ҫ��д
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
        cout << "������������" <<endl;
    }
protected:
};

class B :public A
{
public:
    ~B()
    {
        cout << "������������" <<endl;
    }
};

int main()
{
    cout<<sizeof(MM)<<endl;  //�յ���ռ��1���ֽ� �ڴ���
    cout<<sizeof(Boy)<<endl;  //ageռ��4���ֽ�,���ۼ����麯����ֻռ��4���ֽڣ���8��

    arrayStack mystack;
    {
        //����ָ�뱻��������ʼ����������������
        A* pA = new B;
        delete pA;
    }
    return 0;

}