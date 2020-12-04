                                     #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()

{int num1 = 0;
	int num2 = 0;
    int sum = 0;	
    printf("请输入两个整数");
    scanf("%d%d",&num1,&num2);
	sum = num1 + num2;
printf("sum = %d", sum);

	return 0;
}