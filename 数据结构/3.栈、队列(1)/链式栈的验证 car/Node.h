#ifndef __NODE_H__
#define __NODE_H__

// 结点类

class Car
{
    string id;
    int year,month,day,hour,minute,second;
public:
    Car(){};
    Car(string i,int y,int mon,int d,int h,int m,int s):id(i),year(y),month(mon),day(d),hour(h),minute(m),second(s){}
    scan(){cout<<id<<" "<<year<<"y"<<month<<"m"<<day<<"d"<<hour<<"h"<<minute<<"m"<<second<<"s"<<endl;}
};

template <class ElemType>
struct Node
{
// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType> *next;		// 指针域

// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType item, Node<ElemType> *link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
   data = item;
   next = link;
}



#endif
