#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class COMMU
{
    string pName;//姓名，数据成员为私有的
    string pSchool;//单位
    string pNum;//住宅电话
    string wNum;//办公电话
    string Box;//邮编
    string mAdresse;//邮件地址
    string nTele;//手机号码
public:

    void Print(void)//输出数据成员
    {
        cout << "姓名:" << pName << "\t";
        cout << "单位:" << pSchool << "\t";
        cout << "电话号码:" << pNum << "\t";
        cout << "邮编:" << Box << endl;
    }

    void Init(string, string, string, string);

    void SetName(string name)
    {
        pName = name;
    }

    void SetScool(string unit)//设置学校名称
    {
        pSchool = unit;
    }

    void SetNum(string num)//设置电话号码
    {
        pNum = num;
    }

    void SetBox(string mailnum)//设置邮编
    {
        Box = mailnum;
    }

    string GetName(void)//取姓名
    {
        return pName;
    }

    string GetScool(void )//取学校
    {
        return pSchool;
    }

    string GetNum(void)//取电话号码
    {
        return pNum;
    }

    string GetBox(void)//取邮编
    {
        return Box;
    }
};

void COMMU::Init(string name, string unit, string num, string b)
{               //完成初始化
    pName = name;
    pSchool = unit;
    pNum = num;
    Box = b;
}

int main()
{
    COMMU c1,c2;
    c1.Init("王元","上海大学","021-66138861","200444");
    c2.Init("于海","上海大学","021-66138862","200444");
    c1.Print();
    c2.Print();

    c1.SetName("王国安");
    cout<<c1.GetName()<<'\n';
    c1.SetScool("复旦大学");
    cout<<c1.GetScool()<<'\n';
    c1.SetNum("021-66138960");
    cout<<c1.GetNum()<<"\n";
    c1.SetBox("200201");
    cout<<c1.GetBox()<<"\n";
    c1.Print();

    c2.SetName("李明明");
    cout<<c2.GetName()<<'\n';
    c2.SetScool("上海交通大学");
    cout<<c2.GetScool()<<'\n';
    c2.SetNum("021—55667878");
    cout<<c2.GetNum()<<"\n";
    c2.SetBox("200108");
    cout<<c2.GetBox()<<"\n";
    c2.Print();

    system("pause");
    return 0;
}
