#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class COMMU
{
    string pName;//���������ݳ�ԱΪ˽�е�
    string pSchool;//��λ
    string pNum;//סլ�绰
    string wNum;//�칫�绰
    string Box;//�ʱ�
    string mAdresse;//�ʼ���ַ
    string nTele;//�ֻ�����
public:

    void Print(void)//������ݳ�Ա
    {
        cout << "����:" << pName << "\t";
        cout << "��λ:" << pSchool << "\t";
        cout << "�绰����:" << pNum << "\t";
        cout << "�ʱ�:" << Box << endl;
    }

    void Init(string, string, string, string);

    void SetName(string name)
    {
        pName = name;
    }

    void SetScool(string unit)//����ѧУ����
    {
        pSchool = unit;
    }

    void SetNum(string num)//���õ绰����
    {
        pNum = num;
    }

    void SetBox(string mailnum)//�����ʱ�
    {
        Box = mailnum;
    }

    string GetName(void)//ȡ����
    {
        return pName;
    }

    string GetScool(void )//ȡѧУ
    {
        return pSchool;
    }

    string GetNum(void)//ȡ�绰����
    {
        return pNum;
    }

    string GetBox(void)//ȡ�ʱ�
    {
        return Box;
    }
};

void COMMU::Init(string name, string unit, string num, string b)
{               //��ɳ�ʼ��
    pName = name;
    pSchool = unit;
    pNum = num;
    Box = b;
}

int main()
{
    COMMU c1,c2;
    c1.Init("��Ԫ","�Ϻ���ѧ","021-66138861","200444");
    c2.Init("�ں�","�Ϻ���ѧ","021-66138862","200444");
    c1.Print();
    c2.Print();

    c1.SetName("������");
    cout<<c1.GetName()<<'\n';
    c1.SetScool("������ѧ");
    cout<<c1.GetScool()<<'\n';
    c1.SetNum("021-66138960");
    cout<<c1.GetNum()<<"\n";
    c1.SetBox("200201");
    cout<<c1.GetBox()<<"\n";
    c1.Print();

    c2.SetName("������");
    cout<<c2.GetName()<<'\n';
    c2.SetScool("�Ϻ���ͨ��ѧ");
    cout<<c2.GetScool()<<'\n';
    c2.SetNum("021��55667878");
    cout<<c2.GetNum()<<"\n";
    c2.SetBox("200108");
    cout<<c2.GetBox()<<"\n";
    c2.Print();

    system("pause");
    return 0;
}
