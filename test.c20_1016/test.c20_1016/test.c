////ð������->ֻ������ָ�����ͣ���ָ��int���ͣ��Ͳ�����float���ͣ�
//#include<stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);//����ǰ��ӡһ��
//	}
//	for (i = 0; i < sz - 1; i++) //����Ԫ�ظ�����1������
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i;j++)//ÿ���������
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
//		printf("%d ", arr[i]);//������ӡһ��
//	}
//}
//int main()
//{
//	int arr1[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	bubble_sort(arr1, sz);
//	return 0;
//}



////��������->�����Ŷ������͵�
////void qsort(void* baseԪ����ʼ��ַ, size_t numԪ�ظ���, size_t widthԪ���ֽڴ�С, 
////int(__cdecl* compare)(const void* elem1, const void* elem2)����ָ��ȽϷ�ʽ);
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
//int int_cmp(const void* elem1, const void* elem2)//���ͱȽ�
//{
//	return *(int*)elem1 - *(int*)elem2;//void�����޷�ֱ�ӽ����ã���ǿ������ת��
//}
//void  print(int arr[], int sz)//��װһ����ӡ����
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_Stu_by_age(const void* e1, const void* e2)//�ṹ���Աage���бȽ�
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_Stu_by_name(const void* e1, const void* e2)//�ṹ���Աname���бȽ�
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//
////void qsort(void* baseԪ����ʼ��ַ, size_t numԪ�ظ���, size_t widthԪ���ֽڴ�С, 
////int(__cdecl* compare)(const void* elem1, const void* elem2)����ָ��ȽϷ�ʽ);
////ģ��ʵ��qsort
//void Swap(char* buf1, char* buf2, int width)//��������
//{
//	int i = 0;
//	for (i = 0; i < width; i++) //ÿ���ֽڶ����н���
//	{
//		char tmp = *(buf1 + i);
//		*(buf1 + i) = *(buf2 + i);
//		*(buf2 + i) = tmp;
//	}
//}
////ģ��ʵ��qsort
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* elem1, const void* elem2))//�����޷�����
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++) //����Ԫ�ظ�����1������
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//ÿ���������
//		{ 
//			//��Ϊ��֪��Ҫ����������ʲô���ͣ�ÿ�αȽ��꣬����width���ֽڱȽ���һ��
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//void*ָ�벻��ֱ�ӼӼ������Ĳ���
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test1()//��������
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	//qsort(arr, sz, sizeof(arr[0]), int_cmp);
//	bubble_sort(arr, sz, sizeof(arr[0]), int_cmp);
//	print(arr, sz);
//}
//
//void test2()   //�ṹ�����鰴������������
//{
//	struct Stu arr1[]= { {"zhangsan",20},{"lisi",80},{"wangwu",5} };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//qsort(arr1, sz, sizeof(arr1[0]), cmp_Stu_by_age);
//	bubble_sort(arr1, sz,sizeof(arr1[0]), cmp_Stu_by_age);
//
//}
//
//void test3()   //�ṹ�����鰴������������
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
