#define _CRT_SECURE_NO_WARNINGS


////����n�Ľ׳�
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d\n", ret);
//	return 0;
//}


////����1!+2!+3!+...+10���Ľ׳�
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



////��д���룬��ʾ����ַ��������ƶ������м���
////welcom to bit
////#############
////w###########t
////we#########it
////wel#######bit
////welc##### bit
////welco###o bit
////welcom#to bit
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "welcom to bit";
//	char arr2[] = "#############";
//	int left = 0;
//	int right = strlen(arr1)-1;
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}



////���ֲ���
////��������б�������
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	scanf("%d", &n);
//	int mid = 0;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��� %d\n",mid);
//				break;
//		}
//	}
//	if (left > right)
//	{
//		printf("û�ҵ�\n");
//	}
//	return 0;
//}



////���ֲ��ҷ�װ�ɺ���
//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ���");
//			return mid;
//		}
//	}
//	printf("û�ҵ�");
//	return -1;
//}


////��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Σ�ֻ���������������룬
////���������ȷ����ʾ��¼�ɹ���������ξ�����������˳�����
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	//����������"123456"
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("���������룺\n");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("������ȷ\n");
//			break;
//		}
//		else
//		{
//			printf("���������������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("������������˳�����\n");
//	}
//	return 0;
//}





//��������Ϸ
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("************************\n");
//	printf("********** 1.play ******\n");
//	printf("********** 2.exit ******\n");
//	printf("************************\n");
//}
//
//void game()
//{
//	//����һ��1��100֮��������,rand()
//	int random = rand() % 100 + 1;
//	int guess = 0;
//	while(1)
//	{
//		printf("������֣�>");
//		scanf("%d", &guess);
//		if (guess > random)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < random)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	//����ʱ�������һ�����ֵ��������������õ���ʼ��
//	srand((unsigned)time(NULL));
//	do
//	{
//		//��ӡ�˵�
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();  //��������Ϸ����
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ���������������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}



////goto����ʹ��
//#include<stdio.h>
//#include<windows.h>
//#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");//����ʱ��60��ػ�
//again:
//	printf("��ע�⣬��ĵ�����1�����ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");//ȡ���ػ�
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");//����ʱ��60��ػ�
	while (1)
	{
		printf("��ע�⣬��ĵ�����1�����ڹػ���������룺��������ȡ���ػ�\n");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)
		{
			system("shutdown -a");//ȡ���ػ�
			break;
		}
	}
	return 0;
}