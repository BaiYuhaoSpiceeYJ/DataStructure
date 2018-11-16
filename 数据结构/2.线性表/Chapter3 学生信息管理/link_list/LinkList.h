#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Node.h"					// 结点类

// 单链表类

class LinkList
{
public:
//  单链表的数据成员
	student *head;				// 头结点指针
	int length;							// 单链表长度

public:
//  单链表的函数成员
	LinkList();							// 无参数的构造函数
	LinkList(student v[], int n);		// 有参数的构造函数
	virtual ~LinkList();				// 析构函数
	int GetLength() const;				// 求单链表长度
	bool IsEmpty() const;	 			// 判断单链表是否为空
	void Clear();						// 将单链表清空
	//void Traverse(void (*Visit)(const student &)) const;// 遍历单链表
	int LocateElem(const int &e) const;	         // 元素定位
	Status GetElem(int position, int e,int c) const;	 // 求指定位置的元素
	Status SetElem(int position, const int &e);	 // 设置指定位置的元素值
	Status DeleteElem(int position, int &e);		 // 删除元素
	Status InsertElem(int position, const int i,const int c);	 // 在制定位置插入元素
	Status InsertElem(const int &i,const int &c);	             // 在表尾插入元素
	LinkList(const LinkList &la);            // 复制构造函数
	LinkList &operator =(const LinkList &la); // 重载赋值运算
};


// 单链表类的实现部分

LinkList::LinkList()
// 操作结果：构造一个空链表
{
	head = new student;		// 构造头结点
	assert(head);                   // 构造头结点失败，终止程序运行
	length = 0;						// 初始化单链表长度为0
}


LinkList::LinkList(student v[], int n)
// 操作结果：根据数组v中的元素构造单链表
{
    student *p;
	p = head = new student;	// 构造头结点
	assert(head != 0);              // 构造头结点失败，终止程序运行
	for (int i = 0; i < n; i++) {
	    p->next = new student(v[i].id,v[i].classe,NULL);
	    assert(p->next);            // 构造元素结点失败，终止程序运行
	    p = p->next;
    }
	length = n;						// 初始化单链表长度为n
}

LinkList::~LinkList()
// 操作结果：销毁单链表
{
	Clear();			// 清空单链表
	delete head;		// 释放头结点所指空间
}


int LinkList::GetLength() const
// 操作结果：返回单链表的长度
{
	return length;
}


bool LinkList::IsEmpty() const
// 操作结果：如单链表为空，则返回true，否则返回false
{
	return head->next == NULL;
}


void LinkList::Clear()
// 操作结果：清空单链表,删除单链表中所有元素结点
{
    student *p = head->next;
	while (p != NULL) {
		head->next = p->next;
        delete p;
		p = head->next;
	}
	length = 0;
}


/*void LinkList::Traverse(void (*Visit)(const int i)) const
// 操作结果：依次对单链表的每个元素调用函数(*visit)访问
{
    student *p = head->next;
	while (p != NULL) {
		(*Visit)(p->id);	// 对单链表中每个元素调用函数(*visit)访问
		p = p->next;
	}*/


int LinkList::LocateElem(const int &e) const
// 元素定位
{
    student *p = head->next;
    int count = 1;
	while (p != NULL && p->id != e) {
	    count++;
		p = p->next;
	}
    return  (p != NULL) ? count : 0;
}

Status LinkList::GetElem(int i, int e,int c) const
// 操作结果：当单链表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,
//	否则函数返回NOT_PRESENT
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
 	else	{
		student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	            // p指向第i个结点
		e = p->id;
		c= p->classe;			// 用e返回第i个元素的值
		return ENTRY_FOUND;
	}
}


Status LinkList::SetElem(int i, const int &e)
// 操作结果：将单链表的第i个位置的元素赋值为e,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
	else	{
		student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	           // 取出指向第i个结点的指针
		p->id = e;			   // 修改第i个元素的值为e
		return SUCCESS;
	}
}


Status LinkList::DeleteElem(int i, int &e)
// 操作结果：删除单链表的第i个位置的元素, 并用e返回其值,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length)
		return RANGE_ERROR;   // i范围错
 	else	{
		student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	      // p指向第i-1个结点
		q = p->next;	      // q指向第i个结点
		p->next = q->next;	  // 删除结点
		e = q->id;		  // 用e返回被删结点元素值
		length--;			  // 删除成功后元素个数减1
		delete q;			  // 释放被删结点
		return SUCCESS;
	}
}


Status LinkList::InsertElem(int i, const int id,const int c)
// 操作结果：在单链表的第i个位置前插入元素e
//	i的取值范围为1≤i≤length+1
//	i合法时返回SUCCESS, 否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;
 	else	{
		student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	                    // p指向第i-1个结点
		q = new student(id,c,p->next); // 生成新结点q
        assert(q);                          // 申请结点失败，终止程序运行
		p->next = q;				        // 将q插入到链表中
		length++;							// 插入成功后，单链表长度加1
		return SUCCESS;
	}
}


Status LinkList::InsertElem(const int &i,const int &c)
// 操作结果：在单链表的表尾位置插入元素e
{
	student *p, *q;
	q = new student(i,c, NULL);    // 生成新结点q
    assert(q);                          // 申请结点失败，终止程序运行
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点
    p->next = q;                        // 在单链表的表尾位置插入新结点
	length++;							// 插入成功后，单链表长度加1
	return SUCCESS;
}


LinkList::LinkList(const LinkList &la)
// 操作结果：复制构造函数，由单链表la构造新单链表
{
	int laLength = la.GetLength();	// 取被复制单链表的长度
	int e;
	int c;
	head = new student;		// 构造头指针
	assert(head);                   // 构造头指针失败，终止程序运行
	length = 0;						// 初始化元素个数

	for (int i = 1; i <= laLength; i++)	{	// 复制数据元素
		la.GetElem(i, e,c);	       // 取出第i个元素的值放在e中
		InsertElem(e,c);		       // 将e插入到当前单链表的表尾
	}
}


LinkList &LinkList::operator =(const LinkList &la)
// 操作结果：重载赋值运算符，将单链表la赋值给当前单链表
{
	if (&la != this)	{
		int laLength = la.GetLength();// 取被赋值单链表的长度
		int e;
		int c;
		Clear();							// 清空当前单链表
		for (int i = 1; i <= laLength; i++)		{
			la.GetElem(i,e,c);		    // 取出第i个元素的值放在e中
			InsertElem(e,c);		            // 将e插入到当前单链表的表尾
		}
	}
	return *this;
}

#endif

