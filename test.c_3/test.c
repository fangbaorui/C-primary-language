////�õ�������x=������a����ƽ�����ĵ�����ʽΪxn+1=��xn+a/xn��/2
////Ҫ��ǰ�����������X�Ĳ�ľ���ֵС��10^-5
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	float a, x0, x1;
//	scanf("%f", &a);
//	x0 = a / 2;  //�ȸ�x0������ֵ
//	x1 = (x0 + a / x0) / 2;   //x1������ֵ
//	do   //ѭ��ֱ����������������ʵ�x
//	{
//		x0 = x1;
//		x1 = (x0 + a / x0) / 2;
//	} while (fabs(x0 - x1) < 10e-5);
//	printf("x1=%f", x1);
//	return 0;
//}


////������Ԫ��a[0]-a[9]��ֵ0-9��Ȼ�����������Ԫ�ص�ֵ
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (i=9; i >= 0; i--)
//		printf("%d ", arr[i]);
//	return 0;
//}


////����������fibonacci��������
//#include<stdio.h>
//int main()
//{
//	int arr[20] = { 1,1 };
//	int i = 0;
//	for (i = 2; i < 20; i++)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	for (i = 0; i < 20; i++)
//	{
//		printf("%12d", arr[i]);
//	}
//	return 0;
//}



////ð������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10-1; i++)
//	{
//		for (j = 0; j < 10 - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



////��һ���������н���,������һ��������
//#include<stdio.h>
//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int b[4][3] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i <3; i++)
//	{
//		for (j = 0; j <4; j++)
//		{
//			printf("%5d", a[i][j]);
//			b[j][i] = a[i][j];
//		}
//		printf("\n");
//	}
//	for (i = 0; i <4; i++)
//	{
//		for (j = 0; j <3; j++)
//		{
//			printf("%5d",b[ i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//��һ����λ������3���飬ÿ����4�ˣ�
//Ҫ���ҳ�ȫ����Ա�е���߹����Լ���ְ�����ڵİ���ź͸�ְ���ڸð����е����
#include<stdio.h>
int main()
{
	int i, j;
	int row = 0;
	int col = 0;
	int arr[3][4] = { 3123,2145,3211,4321,5439,3832,6743,4621,2105,3130,5327,3298 };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[i][j] > arr[row][col])
			{ 
				row = i;
				col = j;
			}
		}
	}
	printf("row=%d  col=%d\n", row+1, col+1);
	return 0;
}