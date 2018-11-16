#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

class complex
{
    int re;
    int im;
public:
    complex(int r,int i):re(r),im(i){};
    void setRe(int r){re=r;}
    void setIm(int i){im=i;}
    int getRe(){return re;}
    int getIm(){return im;}
    bool operator>(complex a)
    {
        if((this->re)*(this->re)+(this->im)*(this->im)>(a.re)*(a.re)+(a.im)*(a.im))
            return true;
        else return false;
    }
};

int main()
{
    complex c1(2,3);
    complex c2(-2,-2);
    if (c1>c2)
        cout<<"c1>c2"<<endl;
    return 0;
}
