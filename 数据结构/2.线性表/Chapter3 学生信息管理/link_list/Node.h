#ifndef __NODE_H__
#define __NODE_H__

// 结点类

class student
{
public:
// 数据成员:
	int id,classe;				// 数据域
	student *next;		// 指针域

// 构造函数:
	student();						// 无参数的构造函数
	student(int i, int c,student *link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分

student::student()
// 操作结果：构造指针域为空的结点
{
   next = NULL;
}


student::student(int i, int c, student *link)
// 操作结果：构造一个数据域为e和指针域为link的结点
{
   id = i;
   classe=c;
   next = link;
}

#endif
