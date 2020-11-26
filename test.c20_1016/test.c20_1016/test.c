////冒泡排序->只能排序指定类型（如指定int类型，就不能排float类型）
//#include<stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);//排序前打印一遍
//	}
//	for (i = 0; i < sz - 1; i++) //进行元素个数减1趟排序
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i;j++)//每趟排序次数
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j+1];
//				arr[j + 1] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);//排序后打印一遍
//	}
//}
//int main()
//{
//	int arr1[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	bubble_sort(arr1, sz);
//	return 0;
//}



////快速排序->可以排多种类型的
////void qsort(void* base元素起始地址, size_t num元素个数, size_t width元素字节大小, 
////int(__cdecl* compare)(const void* elem1, const void* elem2)函数指针比较方式);
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int int_cmp(const void* elem1, const void* elem2)//整型比较
//{
//	return *(int*)elem1 - *(int*)elem2;//void类型无法直接解引用，先强制类型转换
//}
//void  print(int arr[], int sz)//封装一个打印函数
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_Stu_by_age(const void* e1, const void* e2)//结构体成员age进行比较
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_Stu_by_name(const void* e1, const void* e2)//结构体成员name进行比较
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//
////void qsort(void* base元素起始地址, size_t num元素个数, size_t width元素字节大小, 
////int(__cdecl* compare)(const void* elem1, const void* elem2)函数指针比较方式);
////模拟实现qsort
//void Swap(char* buf1, char* buf2, int width)//交换函数
//{
//	int i = 0;
//	for (i = 0; i < width; i++) //每个字节都进行交换
//	{
//		char tmp = *(buf1 + i);
//		*(buf1 + i) = *(buf2 + i);
//		*(buf2 + i) = tmp;
//	}
//}
////模拟实现qsort
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* elem1, const void* elem2))//类型无法传参
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++) //进行元素个数减1趟排序
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//每趟排序次数
//		{ 
//			//因为不知道要排序数据是什么类型，每次比较完，跳过width个字节比较下一个
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//void*指针不能直接加减整数的操作
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test1()//整型排序
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	//qsort(arr, sz, sizeof(arr[0]), int_cmp);
//	bubble_sort(arr, sz, sizeof(arr[0]), int_cmp);
//	print(arr, sz);
//}
//
//void test2()   //结构体数组按照属性来排序
//{
//	struct Stu arr1[]= { {"zhangsan",20},{"lisi",80},{"wangwu",5} };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//qsort(arr1, sz, sizeof(arr1[0]), cmp_Stu_by_age);
//	bubble_sort(arr1, sz,sizeof(arr1[0]), cmp_Stu_by_age);
//
//}
//
//void test3()   //结构体数组按照属性来排序
//{
//	struct Stu arr1[] = { {"zhangsan",20},{"lisi",80},{"wangwu",5} };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//qsort(arr1, sz, sizeof(arr1[0]), cmp_Stu_by_name);
//	bubble_sort(arr1, sz, sizeof(arr1[0]), cmp_Stu_by_name);
//}
//
//int main()
//{
//	test1();
//	//test2();
//	//test3();
//	return 0;
//}
