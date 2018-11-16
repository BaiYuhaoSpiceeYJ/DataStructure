#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Node.h"					// �����

// ��������

class LinkList
{
public:
//  ����������ݳ�Ա
	student *head;				// ͷ���ָ��
	int length;							// ��������

public:
//  ������ĺ�����Ա
	LinkList();							// �޲����Ĺ��캯��
	LinkList(student v[], int n);		// �в����Ĺ��캯��
	virtual ~LinkList();				// ��������
	int GetLength() const;				// ��������
	bool IsEmpty() const;	 			// �жϵ������Ƿ�Ϊ��
	void Clear();						// �����������
	//void Traverse(void (*Visit)(const student &)) const;// ����������
	int LocateElem(const int &e) const;	         // Ԫ�ض�λ
	Status GetElem(int position, int e,int c) const;	 // ��ָ��λ�õ�Ԫ��
	Status SetElem(int position, const int &e);	 // ����ָ��λ�õ�Ԫ��ֵ
	Status DeleteElem(int position, int &e);		 // ɾ��Ԫ��
	Status InsertElem(int position, const int i,const int c);	 // ���ƶ�λ�ò���Ԫ��
	Status InsertElem(const int &i,const int &c);	             // �ڱ�β����Ԫ��
	LinkList(const LinkList &la);            // ���ƹ��캯��
	LinkList &operator =(const LinkList &la); // ���ظ�ֵ����
};


// ���������ʵ�ֲ���

LinkList::LinkList()
// �������������һ��������
{
	head = new student;		// ����ͷ���
	assert(head);                   // ����ͷ���ʧ�ܣ���ֹ��������
	length = 0;						// ��ʼ����������Ϊ0
}


LinkList::LinkList(student v[], int n)
// �����������������v�е�Ԫ�ع��쵥����
{
    student *p;
	p = head = new student;	// ����ͷ���
	assert(head != 0);              // ����ͷ���ʧ�ܣ���ֹ��������
	for (int i = 0; i < n; i++) {
	    p->next = new student(v[i].id,v[i].classe,NULL);
	    assert(p->next);            // ����Ԫ�ؽ��ʧ�ܣ���ֹ��������
	    p = p->next;
    }
	length = n;						// ��ʼ����������Ϊn
}

LinkList::~LinkList()
// ������������ٵ�����
{
	Clear();			// ��յ�����
	delete head;		// �ͷ�ͷ�����ָ�ռ�
}


int LinkList::GetLength() const
// ������������ص�����ĳ���
{
	return length;
}


bool LinkList::IsEmpty() const
// ����������絥����Ϊ�գ��򷵻�true�����򷵻�false
{
	return head->next == NULL;
}


void LinkList::Clear()
// �����������յ�����,ɾ��������������Ԫ�ؽ��
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
// ������������ζԵ������ÿ��Ԫ�ص��ú���(*visit)����
{
    student *p = head->next;
	while (p != NULL) {
		(*Visit)(p->id);	// �Ե�������ÿ��Ԫ�ص��ú���(*visit)����
		p = p->next;
	}*/


int LinkList::LocateElem(const int &e) const
// Ԫ�ض�λ
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
// �������������������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
 	else	{
		student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	            // pָ���i�����
		e = p->id;
		c= p->classe;			// ��e���ص�i��Ԫ�ص�ֵ
		return ENTRY_FOUND;
	}
}


Status LinkList::SetElem(int i, const int &e)
// �����������������ĵ�i��λ�õ�Ԫ�ظ�ֵΪe,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
	else	{
		student *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	           // ȡ��ָ���i������ָ��
		p->id = e;			   // �޸ĵ�i��Ԫ�ص�ֵΪe
		return SUCCESS;
	}
}


Status LinkList::DeleteElem(int i, int &e)
// ���������ɾ��������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 1 || i > length)
		return RANGE_ERROR;   // i��Χ��
 	else	{
		student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	      // pָ���i-1�����
		q = p->next;	      // qָ���i�����
		p->next = q->next;	  // ɾ�����
		e = q->id;		  // ��e���ر�ɾ���Ԫ��ֵ
		length--;			  // ɾ���ɹ���Ԫ�ظ�����1
		delete q;			  // �ͷű�ɾ���
		return SUCCESS;
	}
}


Status LinkList::InsertElem(int i, const int id,const int c)
// ����������ڵ�����ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;
 	else	{
		student *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	                    // pָ���i-1�����
		q = new student(id,c,p->next); // �����½��q
        assert(q);                          // ������ʧ�ܣ���ֹ��������
		p->next = q;				        // ��q���뵽������
		length++;							// ����ɹ��󣬵������ȼ�1
		return SUCCESS;
	}
}


Status LinkList::InsertElem(const int &i,const int &c)
// ����������ڵ�����ı�βλ�ò���Ԫ��e
{
	student *p, *q;
	q = new student(i,c, NULL);    // �����½��q
    assert(q);                          // ������ʧ�ܣ���ֹ��������
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���
    p->next = q;                        // �ڵ�����ı�βλ�ò����½��
	length++;							// ����ɹ��󣬵������ȼ�1
	return SUCCESS;
}


LinkList::LinkList(const LinkList &la)
// ������������ƹ��캯�����ɵ�����la�����µ�����
{
	int laLength = la.GetLength();	// ȡ�����Ƶ�����ĳ���
	int e;
	int c;
	head = new student;		// ����ͷָ��
	assert(head);                   // ����ͷָ��ʧ�ܣ���ֹ��������
	length = 0;						// ��ʼ��Ԫ�ظ���

	for (int i = 1; i <= laLength; i++)	{	// ��������Ԫ��
		la.GetElem(i, e,c);	       // ȡ����i��Ԫ�ص�ֵ����e��
		InsertElem(e,c);		       // ��e���뵽��ǰ������ı�β
	}
}


LinkList &LinkList::operator =(const LinkList &la)
// ������������ظ�ֵ���������������la��ֵ����ǰ������
{
	if (&la != this)	{
		int laLength = la.GetLength();// ȡ����ֵ������ĳ���
		int e;
		int c;
		Clear();							// ��յ�ǰ������
		for (int i = 1; i <= laLength; i++)		{
			la.GetElem(i,e,c);		    // ȡ����i��Ԫ�ص�ֵ����e��
			InsertElem(e,c);		            // ��e���뵽��ǰ������ı�β
		}
	}
	return *this;
}

#endif

