#ifndef __NODE_H__
#define __NODE_H__

// �����

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
// ���ݳ�Ա:
	ElemType data;				// ������
	Node<ElemType> *next;		// ָ����

// ���캯��:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType item, Node<ElemType> *link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���
template<class ElemType>
Node<ElemType>::Node()
// �������������ָ����Ϊ�յĽ��
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
// �������������һ��������Ϊitem��ָ����Ϊlink�Ľ��
{
   data = item;
   next = link;
}



#endif
