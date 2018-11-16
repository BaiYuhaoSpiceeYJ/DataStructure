#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

class people
{
    char sex;
    char name;
    int age;
public:
    people(char s,char n,int a):sex(s),name(n),age(a){};
    void setSex(char s){sex=s;}
    void setName(char n){name=n;}
    void setAge(int a){age=a;}
    char getSex(){return sex;}
    char getName(){return name;}
    int getAge(){return age;}

};

class teacher : public people
{
    char workid;
    char title;
    int salary;
public:
    teacher(char s,char n,int a,char w,char t,int sa):people(s,n,a),workid(w),title(t),salary(sa){};
    void setWorkid(char w){workid=w;}
    void setTitle(char t){title=t;}
    void setSalary(int sa){salary=sa;}
    char getWorkid(){return workid;}
    char getTitle(){return title;}
    int getSalary(){return salary;}
};

class student : public people
{
    char id;
    char classe;
    char major;
    int note;
public:
    student(char s,char n,int a,char id,char c,char m,int nt):people(s,n,a),id(id),classe(c),major(m),note(nt){};
    void setId(char i){id=i;}
    void setClasse(char c){classe=c;}
    void setMajor(char m){major=m;}
    void setNote(int nt){note=nt;}
    char getId(){return id;}
    char getClasse(){return classe;}
    char getMajor(){return major;}
    int getNote(){return note;}

};

int main()
{
    return 0;
}
