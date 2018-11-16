#ifndef __LK_QUEUE_H__
#define __LK_QUEUE_H__

#include "Node.h"				// �����

// ��������

template<class ElemType>
class LinkQueue
{
protected:
//  ������ʵ�ֵ����ݳ�Ա:
	Node<ElemType>  *rear;					// ��ͷ��βָָ

public:
	LinkQueue();									// �޲����Ĺ��캯��
	virtual ~LinkQueue();							// ��������
	int GetLength() const;								// ����г���
	bool IsEmpty() const;								// �ж϶����Ƿ�Ϊ��
	void Clear();									// ���������
	void Traverse(void (*Visit)(const ElemType &)) const ;	// ��������
	Status DelQueue(ElemType &e);				     // ���Ӳ���
	Status GetHead(ElemType &e) const;			     // ȡ��ͷ����
	Status EnQueue(const ElemType e);			     // ��Ӳ���
	LinkQueue(const LinkQueue<ElemType> &q);		// ���ƹ��캯��
	LinkQueue<ElemType> &operator =(const LinkQueue<ElemType> &q);// ��ֵ�������
};

// ���������ʵ�ֲ���

template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
// �������������һ���ն���
{
	rear =  NULL;	// ����������ͷ���
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
// ������������ٶ���
{
	Clear();
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength() const
// ������������ض��г���
{
	int count = 0;		// ��ʼ��������
	for (Node<ElemType> *p = rear->next; p == rear; p = p->next)
		count++;		// ͳ���������еĽ����
	return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
   return rear == NULL;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear()
// �����������ն���
{
	Node<ElemType> *p = rear->next;
    while (p != NULL)	{	// ����ɾ�������е�Ԫ�ؽ��
        rear->next = p->next;
		delete p;
		if(p!=NULL)p = rear->next;
	}
	rear = NULL;
}

template <class ElemType>
void LinkQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζԶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
	for (Node<ElemType> *p = rear->next; p == rear; p = p->next)
	// �Զ���ÿ��Ԫ�ص��ú���(*visit)����
		(*Visit)(p->data);
}


template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	// ���зǿ�
		Node<ElemType> *p = rear->next;	// ָ�����ͷ��
		e = p->data;						// ��e���ض�ͷԪ��
		if (rear == p) delete rear;
		else {rear->next = p->next;				// frontָ����һԪ��

		delete p;}							// �ͷų��ӵ�Ԫ�ؽ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ���������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	            // ���зǿ�
		e = rear->next->data;		// ��e���ض�ͷԪ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e)
// ������������ϵͳ�ռ䲻��������OVER_FLOW,
//	�������Ԫ��eΪ�µĶ�β������SUCCESS
{
	Node<ElemType> *p;
    p = new Node<ElemType>(e);
    Node<ElemType> *front;       // ����һ���½��
    if(rear==NULL){rear=rear->next=p;}
    else
    {
            if (p)
            {
                front= rear->next;
                rear->next = p;	                // ���½����ڶ�β
                rear = rear->next;
                rear->next=	front;	// rearָ���¶�β
                return SUCCESS;
            }
            else                               //ϵͳ�ռ䲻��������OVER_FLOW
                return OVER_FLOW;
    }
}


template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &q)
// ����������ɶ���q�����¶���--���ƹ��캯��
{
	rear = NULL;// ���ɶ���ͷ���
	for (Node<ElemType> *p = q.rear->next; p == rear; p = p->next)
	// ȡq����ÿ��Ԫ�ص�ֵ,�����ڵ�ǰ������������в���
		EnQueue(p->data);
}

template<class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator =(const LinkQueue<ElemType> &q)
// ���������������q��ֵ����ǰ����--��ֵ�������
{
	if (&q != this)	{
		Clear();       //���ԭ�ж���
		for (Node<ElemType> *p = q.rear->next; p ==rear; p = p->next)
		// ȡq����ÿ��Ԫ�ص�ֵ,�����ڵ�ǰ������������в���
			EnQueue(p->data);
	}
	return *this;
}

#endif
