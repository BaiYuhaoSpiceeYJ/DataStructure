#ifndef __NODE_H__
#define __NODE_H__

// �����

class student
{
public:
// ���ݳ�Ա:
	int id,classe;				// ������
	student *next;		// ָ����

// ���캯��:
	student();						// �޲����Ĺ��캯��
	student(int i, int c,student *link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���

student::student()
// �������������ָ����Ϊ�յĽ��
{
   next = NULL;
}


student::student(int i, int c, student *link)
// �������������һ��������Ϊe��ָ����Ϊlink�Ľ��
{
   id = i;
   classe=c;
   next = link;
}

#endif
