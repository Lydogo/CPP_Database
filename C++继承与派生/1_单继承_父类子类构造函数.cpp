#include <iostream>
#include<string>
using namespace std;

class MM
{
public:
    MM(string name,int age) :name(name),age(age)
    {
        cout << "������ι��캯��" <<endl;
    }  //��ʼ�������б�
    MM()
    {
        cout <<"�����޲ι��캯��"<<endl;
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

//�̳�����д�� class �������� ���̳з�ʽ
//�̳з�ʽ������Ǹ��������������е����Ȩ��
class Boy :protected MM
{
public:
    //����Ĺ��캯����������ø���ĺ���
    //1.����д���ʺϣ�ϰ�����ڸ���������һ���޲������캯��
    Boy()
    {
        cout << "�����޲ι��캯��" <<endl;
    }

    //���ó�ʼ�������б�ķ�ʽ���ø���Ĺ��캯��
    Boy(string name,int age) :MM(name,age)
    {
        cout<<"������������캯��"<<endl;
    }
    void printBoy()
    {
        cout << name << age << endl;
        //cout << num << endl;   �����е�˽�����Բ��ɷ���
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
    Boy boy;  //���๹�캯���������˸���Ĺ��캯��
    Boy boy2("����",2);
    boy2.printBoy();
}