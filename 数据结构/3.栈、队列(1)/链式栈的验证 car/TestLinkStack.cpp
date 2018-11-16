#include "Assistance.h"	// ¸¨ÖúÈí¼ş°ü
#include "LinkStack.h"	// Á´Õ»Àà
#include "Node.h"
int main(void)
{
    LinkStack<Car> sa;
    Car car1("ferrari",2017,11,21,5,12,11);
    Car car2("lamborgini",2017,12,27,22,8,12);
    sa.Push(car1);
    sa.Push(car2);
    sa.getTop()->data.scan();



    system("PAUSE");
	return 0;
}


