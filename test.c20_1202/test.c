//ѭ�����while
//#include<stdio.h> 
//int main()
//{
//	int line = 0;
//	printf("ѧϰ���\n");
//	while (line <= 20000)
//	{
//		printf("�ô���\n");
//		line++;
//	}
//	if (line >20000)
//	{
//		printf("good offer\n");
//	}
//	return 0;
//
//}


//���庯��
#include<stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	int ret = 0;
	ret = Add(num1, num2);
	printf("ret = %d", ret);
		return 0;
}