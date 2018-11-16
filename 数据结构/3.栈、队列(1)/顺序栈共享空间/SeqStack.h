#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__


// ˳��ջģ����
template<class ElemType>
class SeqStack
{
protected:
// ˳��ջ�����ݳ�Ա:
	int top1,top2;										// ջ��ָ��
	int maxSize;									// ջ���������
	ElemType *elems;								// Ԫ�ش洢�ռ�

public:
//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SeqStack(int size = DEFAULT_SIZE);				// ���캯��
	virtual ~SeqStack();							// ��������
	int GetLength(int k) const;							// ��ջ�ĳ���
	bool IsEmpty(int k) const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear(int k);									// ��ջ���
	void Traverse(int k,void (*Visit)(const ElemType &)) const;	// ����ջ
	Status Push(int k,const ElemType e);				    // ��ջ
	Status Top(int k,ElemType &e) const;				    // ȡ��Ԫ��
	Status Pop(int k,ElemType &e);					    // ��ջ
	SeqStack(const SeqStack<ElemType> &s);		// ���ƹ��캯��
	SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s); // ��ֵ�������
};


// ˳��ջ���ʵ�ֲ���

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// �������������һ���������Ϊsize�Ŀ�ջ
{
	maxSize = size;						// ջ���������
	if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
	top1= -1;
	top2= maxSize;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// �������������ջ
{
	delete []elems;					// �ͷ�ջ�Ĵ洢�ռ�
}

template <class ElemType>
int SeqStack<ElemType>::GetLength(int k) const
// �������������ջ��Ԫ�ظ���
{
    if(k==1){return top1 + 1;}
	if(k==2){return maxSize-top2;}

}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty(int k) const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	if(k==1){return top1== -1;}
	if(k==2){return top2==maxSize;}
}

template<class ElemType>
void SeqStack<ElemType>::Clear(int k)
// ������������ջ
{
	if(k==1){top1 = -1;}
	if(k==2){top2=maxSize;}
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(int k,void (*Visit)(const ElemType &)) const
// �����������ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)����
{
	if(k==1)
        {
            for (int i = top1; i >=0 ; i--)
                (*Visit)(elems[i]);
        }
    if(k==2)
        {
            for(int i = top2;i<maxSize;i++)
                (*Visit)(elems[i]);
        }
}

template<class ElemType>
Status SeqStack<ElemType>::Push(int k,const ElemType e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�SUCCESS,��ջ����������OVER_FLOW
{
	if (top2-top1==1) // ջ����
		return OVER_FLOW;
	else
    {	// �����ɹ�
        if(k==1)
		{
		    elems[++top1] = e;	// ��Ԫ��e׷�ӵ�ջ��
            return SUCCESS;
		}
		if(k==2)
        {
            elems[--top2] = e;
            return SUCCESS;
        }
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Top(int k,ElemType &e) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,��������SUCCESS,����������UNDER_FLOW
{
	if(IsEmpty(k))	 // ջ��
		return UNDER_FLOW;
	else
    { // ջ�ǿ�,�����ɹ�
		if(k==1){e = elems[top1];}	// ��e����ջ��Ԫ��
        if(k==2){e = elems[top2];}
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Pop(int k,ElemType &e)
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����e����ջ��Ԫ��,��������SUCCESS,����
// ��������UNDER_FLOW
{
	if (IsEmpty(k))	 // ջ��
		return UNDER_FLOW;
	else	{ // �����ɹ�
		if(k==1){e = elems[top1--]; }
		if(k==2){e = elems[top2++];}// ��e����ջ��Ԫ��
		return SUCCESS;
	}
}

template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s)
// �����������ջs������ջ--���ƹ��캯��
{
    maxSize = s.maxSize;			    // ջ���������
    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
    elems = new ElemType[maxSize];		// ����洢�ռ�
	top1 = s.top1;
	top2 = s.top2;				    // ����ջ��ָ��
	for (int i = 0; i <= top1; i++)      // ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
		elems[i] = s.elems[i];
    for (int i=maxSize-1;i>=top2;i--)
        elems[i] = s.elems[i];
}

template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
// �����������ջs��ֵ����ǰջ--��ֵ�������
{
	if (&s != this)	{
    maxSize = s.maxSize;			    // ջ���������
    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
    elems = new ElemType[maxSize];		// ����洢�ռ�
    top1 = s.top1;
    top2 = s.top2;					    // ����ջ��ָ��
    for (int i = 0; i <= top1; i++)      // ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
        elems[i] = s.elems[i];
    for (int i=maxSize-1;i>=top2;i--)
        elems[i] = s.elems[i];
	}
	return *this;
}

#endif
