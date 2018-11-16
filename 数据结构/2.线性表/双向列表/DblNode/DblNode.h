#ifndef DBLNODE_H_INCLUDED
#define DBLNODE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;

template<class ElemType>
class DblLinkList
{
protected:
    DblNode<ElemType> *head;
    int length;
public:
    DblLinkList();
    DblLinkList(ElemType v[],int n);
    virtual ~DblLinkList();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit))(const ElemType &) const;
    int LocateElem(const ElemType &e);
    ElemType GetElem(int i;ElemType &e) const;
    void SetElem(int i;const ElemType &e);
    void DeleteElem(int i; ElemType &e);
    void InsertElem(int i;const ElemType &e);
    void InsertElem(const ElemType &e);
    DblLinkList(const DblLinkList<ElemType> &la);
    DblLinkList<ElemType> &operator=(const DblLinkList<ElemType> &la);
};

template<class ElemType>
DblLinkList<ElemType>::DblLinkList()
{
    head= new DblNode<ElemType>;
    head->prior=head->next=head;
    length=0;
}

template<class ElemType>
DblLinkList<ElemType>::DblLinkList(ElemType v[],int n)
{
    DblNode<ElemType> *p;
    p=head=new DblNode<ElemType>;
    for(int i=0;i<n;i++)
    {
        p->next=new DblNode<ElemType>(v[i],p);

    }

}

#endif // DBLNODE_H_INCLUDED
