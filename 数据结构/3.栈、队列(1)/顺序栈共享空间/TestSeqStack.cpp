#include "Assistance.h"	// ¸¨ÖúÈí¼ş°ü
#include "SeqStack.h"	// Ë³ĞòÕ»Àà

int main(void)
{
    int e;
    SeqStack<int> sa(100);
    sa.Push(1,2);
    sa.Push(1,47);
    sa.Push(1,6);
    sa.Push(1,25);
    sa.Push(1,49);
    sa.Push(2,78);
    sa.Push(2,99);
    sa.Top(2,e);
    sa.Traverse(1,Write<int>);
    cout<<endl;
    sa.Traverse(2,Write<int>);
	system("PAUSE");
	return 0;
}


