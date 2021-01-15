//#include<stdio.h>
////int main()
////{
////	int arr[30][30] = { 0 };
////	int i = 0;
////	int j = 0;
////	int m = 10;
////	int n = 0;
////	printf("请输入杨辉三角的行数");
////		scanf("%d", &m);
////	for (i = 0; i <= m; i++)
////	{
////		arr[i][0] = 1;
////		arr[i][i] = 1;
////		for (j = 1; j <= i; j++)
////		{
////			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
////		}
////	}
////	for (i = 0; i <= m; i++)
////	{
////		for(n=(m-i);n >= 0;n--)
////		{printf("  "); }
////	}
////	for (j = 0; j <= i; j++)
////	{
////		printf("%3d", arr[i][j]);
////	}
////	printf("\n");
////
////}
//void PrintYangHui(int n)
//{
//	int arr[20][20] = { 0 };
//	int col = 1;
//	for (int row = 1; row <= n; row++)      //第一层循环去访问每一行
//	{
//		for (int col = 1; col <= row; col++)
//		{
//			if (col == 1 || col == row)//当前列是第一列或者最后一列，值固定就是1
//			{
//			arr[row][col] = 1; }
//			else
//			{
//				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
//			}
//		}
//			
//
//			print("%d", arr[row][col]);
//		
//	
//	print("\n");
//}
//}
//
//
//
//
//int main()
//{
//	PrintYangHui(10);
//	return 0;
//}



#include<stdio.h>
int main()
{
	int max(int age_1, int age_2);
	int age_1, age_2, age_max;
	scanf("%d,%d", &age_1, &age_2);
	age_max = max(age_1, age_2);
	printf("Max is %f\n", age_max);
	return 0;
}
int max(int x, int y);
{int z;
	if (x > y) z = x;
	else z = y;
	return z;
}