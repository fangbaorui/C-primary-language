
////�ַ�ָ��
//#include<stdio.h>
//int main()
//{
//	//�ַ�ָ��
//	char ch = 'a';
//	char* pc = &ch;//��ch�ĵ�ַ����pcָ����
//	*pc = 'c';     //ͨ��pc�ĵ�ַ����'c'��ֵ��ch
//	printf("%c\n", *pc);//'c'
//
//	//�����ַ���
//	char* str = "hello wrold";//GCC�������ᱨ��û��const���β����Ͻ�
//	const char* ptr = "hello wrold";  //str��ptr�������Ǵ����ַ������׵�ַ
//	printf("%s\n", str);  //hello wrold
//	printf("%s\n",ptr);   //hello wrold
//
//	char* pstr = "hello world";
//	//*pstr = 'w';  //�����ַ������ܱ��޸�
//	printf("%s\n", pstr);
//
//	char arr[10] = "abcdef";
//	char* p = arr;
//	*p = 'w';  //������Ը�
//	printf("%s\n", p);//wbcdef
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "hello world";//����
//	char arr2[] = "hello world";//����
//	char* arr3 = "hello world"; //ָ��
//	char* arr4 = "hello world"; //ָ��
//	//C/C++��ѳ����ַ����洢��������һ���ڴ����򣬵�����ָ�롣ָ��ͬһ���ַ�����ʱ������ʵ�ʻ�ָ��ͬһ���ڴ档
//	//��������ͬ�ĳ����ַ���ȥ��ʼ����ͬ�������ʱ��ͻῪ�ٳ���ͬ���ڴ�顣
//
//	if (arr1 == arr2)
//	{
//		printf("arr1==arr2");
//	}
//	else
//	{
//		printf("arr1!=arr2");
//	}
//	if (arr3 == arr4)
//	{
//		printf("arr3==arr4");
//	}
//	else
//	{
//		printf("arr3!=arr4");
//	}
//	return 0;
//}



////ָ������
//#include<stdio.h>
//int main()
//{
//	int* arr1[10];//����ָ������:��һ�����飬��10��Ԫ�أ�ÿ��Ԫ�ص�������int*
//	char* arr2[4];//һ���ַ�ָ�����飺��һ�����飬��4��Ԫ�أ�ÿ��Ԫ�ص�������char*
//	char** arr3[5];//�����ַ�ָ�����飺��һ�����飬��5��Ԫ�أ�ÿ��Ԫ�ص�������char**
//	return 0;
//}



////ָ������
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));//*��[]���ȼ���
//	}
//	return 0;
//}



////ָ������
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	int arr2[] = { 2,3,4 };
//	int arr3[] = { 3,4,5 };
//	int* arr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");//1 2 3      2 3 4     3 4 5
//	}
//	return 0;
//}



////ָ������
//#include<stdio.h>
//int main()
//{
//	char* p1 = "zhangsan";
//	char* p2 = "lisi";
//	char* p3 = "wangwu";
//	char* arr[] = { p1,p2,p3 };
//	char* arr1[] = { "zhangsan","lisi","wangwu" };//������Ч��һ��
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s\n", arr[i]);
//		printf("%s\n", arr1[i]);
//	}
//	return 0;
//}



////����ָ��->�ܹ�ָ�������ָ�룬������int(*p)[10],p�Ⱥ�*��ϣ���ʾp��һ��ָ�������
////ָ�����һ����СΪ10�����͵�����
//#include<stdio.h>
//int main()
//{
//	//����ָ��=����ĵ�ַ��&�������õ���������ĵ�ַ
//	char arr[5];
//	char (*pa)[5] = &arr;
//	char* ch[5];
//	char* (*pc)[5] = &ch;
//
//	int arr[3] = { 1,2,3 };
//	int* p = arr;//����������Ԫ�ص�ַ
//	return 0;
//}


////����ָ��
//#include<stdio.h>
//int main()
//{
//	//int* p3;
//	//p3 + 1;//����4���ֽ�
//	//char* p4;
//	//p4 + 1;//����1���ֽ�
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p1 = arr;
//	printf("%p\n", p1);//��ӡ��ַ
//	printf("%p\n", p1+1);// p1 + 1,����һ��Ԫ�ص�4���ֽ�
//	printf("%p\n", arr+1);
//
//	int(*p2)[10] = &arr;//����ָ��
//	printf("%p\n", p2);
//	printf("%p\n", p2+1);//p2+1��������������
//	printf("%p\n", &arr+1);
//
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr);//������ӡ���һ��
//
//	return 0;
//}



////����ָ���ʹ��
//#include<stdio.h>
//void print1(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void print2(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr+i));
//		printf("%d ", arr[i]);//��������ӡ���һ��
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	print1(arr, 10);
//	print2(arr, 10);
//	return 0;
//}



//#include<stdio.h>
////��λ����
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////����ָ��
//void print2(int (*arr)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//			//printf("%d ", (*(p + i))[j]);
//			//printf("%d ", *(*(p + i) + j));//����Ч��һ��
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,0 };
//	print1(arr, 3, 5);
//	print2(arr, 3, 5);
//	return 0;
//}


////һά���鴫��
//#include<stdio.h>
//void test1(int arr1[]) {}//����
//void test1(int arr1[10]) {}//����
//void test1(int* arr1) {}//����
//void test2(int* arr2[10]) {}//����
//void test2(int** arr2) {}//����
//int main()
//{
//	int arr1[10] = { 0 };
//	int* arr2[10] = { 0 };
//	test1(arr1);
//	test2(arr2);
//	return 0;
//}


////��ά���鴫��
//#include<stdio.h>
//void test(int arr[3][5]) {}//����
//void test(int arr[][5]) {}//����
//void test(int arr[][]) {}//������
//void test(int* arr) {}//������
//void test(int* arr[5]) {}//������
//void test(int** arr) {}//������
//void test(int (*arr)[5]) {}//����
//int main()
//{
//	int arr1[3][5] = { 0 };
//	test(arr);
//	return 0;
//}


////һ��ָ�봫��
//#include<stdio.h>
//void test(int* p){}
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int arr[10];
//	test(&a);//����
//	test(p);//����
//	test(arr);//����
//  return 0;
//}


////����ָ�봫��
//#include<stdio.h>
//void test(int** p) {}
//int main()
//{
//	int* p1;
//	int** p2;
//	int* arr[10];
//	test(&p1);//����
//	test(p2);//����
//	test(arr);//����
//	return 0;
//}


