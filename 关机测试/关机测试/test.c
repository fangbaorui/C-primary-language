#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<CoreWindow.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 300");
	again:
	printf("��ע�⣬��ĵ��Խ���������ڹػ���������룺���ػ�����ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input, "���ػ�") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}