#ifndef __LK_QUEUE_H__
#define __LK_QUEUE_H__

#include "Node.h"				// �����

// ��������

template<class ElemType>
class LinkQueue
{
protected:
//  ������ʵ�ֵ����ݳ�Ա:
	Node<ElemType> *front,*rear;					// ��ͷ��βָָ

public:
	LinkQueue();									// �޲����Ĺ��캯��
	virtual ~LinkQueue();							// ��������
	int GetLength() const;								// ����г���
	bool IsEmpty() const;								// �ж϶����Ƿ�Ϊ��
	void Clear();									// ���������
	void Traverse(void (*Visit)(const ElemType &)) const ;	// ��������
	Status DelQueue(int k,ElemType &e);				     // ���Ӳ���
	Status GetHead(ElemType &e) const;			     // ȡ��ͷ����
	Status EnQueue(int k,const ElemType e);			     // ��Ӳ���
	LinkQueue(const LinkQueue<ElemType> &q);		// ���ƹ��캯��
	LinkQueue<ElemType> &operator =(const LinkQueue<ElemType> &q);// ��ֵ�������
};

// ���������ʵ�ֲ���

template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
// �������������һ���ն���
{
	rear = front = NULL;	// ����������ͷ���
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
	for (Node<ElemType> *p = front; p != NULL; p = p->next)
		count++;		// ͳ���������еĽ����
	return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
   return rear == front;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear()
// �����������ն���
{
	Node<ElemType> *p = front;
    while (p != NULL)	{	// ����ɾ�������е�Ԫ�ؽ��
        front->next = p->next;
		delete p;
		p = front->next;
	}
	rear = front;
}

template <class ElemType>
void LinkQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζԶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
	for (Node<ElemType> *p = front; p != NULL; p = p->next)
	// �Զ���ÿ��Ԫ�ص��ú���(*visit)����
		(*Visit)(p->data);
}


template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(int k,ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!IsEmpty())
    {	// ���зǿ�
        if(front==rear)
        {
            delete front;
            front=rear=NULL;
        }
        else
        {
            if (k==0)
            {
                Node<ElemType> *p = front	;// ָ�����ͷ��
                e = p->data;						// ��e���ض�ͷԪ��
                front = p->next;
            }
            if(k==1)
            {
                Node<ElemType> *p = rear;
                e=p->data;
                delete rear;
                for (Node<ElemType> *p = front; p != NULL; p = p->next)
                {
                    rear=p;
                }
            }
        }
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
		e = front->data;		// ��e���ض�ͷԪ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(int k,const ElemType e)
// ������������ϵͳ�ռ䲻��������OVER_FLOW,
//	�������Ԫ��eΪ�µĶ�β������SUCCESS
{
	Node<ElemType> *p;
    p = new Node<ElemType>(e);	        // ����һ���½��
    if (front==NULL)
    {
        front=rear=p;
    }
    else
    {
        if(k==1)
        {
            rear->next = p;	                // ���½����ڶ�β
            rear = rear->next;				// rearָ���¶�β
            return SUCCESS;
        }
        if(k==0)
        {
            Node<ElemType> *q;
            q=front;
            front=p;
            front->next=q;
        }
    }

}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &q)
// ����������ɶ���q�����¶���--���ƹ��캯��
{
	rear = front = new Node<ElemType>;	// ���ɶ���ͷ���
	for (Node<ElemType> *p = q.front; p != NULL; p = p->next)
	// ȡq����ÿ��Ԫ�ص�ֵ,�����ڵ�ǰ������������в���
		EnQueue(p->data);
}

template<class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator =(const LinkQueue<ElemType> &q)
// ���������������q��ֵ����ǰ����--��ֵ�������
{
	if (&q != this)	{
		Clear();       //���ԭ�ж���
		for (Node<ElemType> *p = q.front; p != NULL; p = p->next)
		// ȡq����ÿ��Ԫ�ص�ֵ,�����ڵ�ǰ������������в���
			EnQueue(p->data);
	}
	return *this;
}

#endif
