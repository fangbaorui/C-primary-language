#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<CoreWindow.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 300");
	again:
	printf("请注意，你的电脑将在五分钟内关机，如果输入：不关机，就取消关机\n");
	scanf("%s", input);
	if (strcmp(input, "不关机") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}