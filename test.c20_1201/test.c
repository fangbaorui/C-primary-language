#include<stdio.h>
int main()
{
	int num = 10;
	int *p = &num;
	*p = 30;
	printf("num = %d\n", num);
	return 0;

}


Void Swap1(int x, int y)
{
	int z = 0;
	z = x;
	x = y;
	y = z;
}
Void Swap2(int*p1, int*p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	Swap1()
		pfintf("%d%d",num1 num2 )
		Swap2()
		pfintf("%d%d", num1 num2)
	
}