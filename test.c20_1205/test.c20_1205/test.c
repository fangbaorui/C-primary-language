////ģ��ʵ��strlen�����ַ�������(����һ��
////ʶ���ַ����е�ÿ���ַ���������ǡ�\0����������count++��ֱ���ҵ���\0��Ϊֹ�����ؼ�����coun��ֵ
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);//����str���ǿ�ָ��
//	int count = 0;//������
//	while (*str != '\0')
//	{
//		count++;//ÿʶ��һ������'\0'���ַ���������+1
//		str++;//ָ����һ���ַ��ĵ�ַ
//	}
//	return count;//���ؼ�������ֵ
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


////ģ��ʵ��strlen�����ַ������ȣ���������
////�ݹ鷽��ʵ��
////my_strlen(��abcdef��)->
////1 + my_strlen(��bcdef��)->
////1 + 1 + my_strlen(��cdef��)->
////1 + 1 + 1 + my_strlen(��def��)->
////1 + 1 + 1 + 1 + my_strlen(��ef��)->
////1 + 1 + 1 + 1 + 1 + my_strlen(��f��)->
////1 + 1 + 1 + 1 + 1 + 1 + my_strlen(" ")->
////1 + 1 + 1 + 1 + 1 + 1 + 0
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);//���ϵݹ���ã�ֱ��*str= '\0��
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


////ģ��ʵ��strlen�����ַ������ȣ���������
////ָ�� - ָ�룬�õ�Ԫ�ظ���
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* start = str;//startָ��Ԫ�ص�ַ
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;//strָ��'\0'�ĵ�ַ
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


////ģ��ʵ��strcpy(����һ��
//#include<stdio.h>
//#include<assert.h>
//void my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src!= NULL);
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}
//int main()
//{
//	char* str1 = "abcdef";
//	char arr[20] = "XXXXXXXXXX";
//	my_strcpy(arr, str1);
//	printf("%s\n", arr);
//	return 0;
//}


////ģ��ʵ��strcpy(��������
//#include<stdio.h>
//#include<assert.h>
//void my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++=*src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char* str1 = "abcdef";
//	char arr[20] = "XXXXXXXXXX";
//	my_strcpy(arr, str1);
//	printf("%s\n", arr);
//	return 0;
//}


////ģ��ʵ��strcpy(��������
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* start = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return start;
//}
//int main()
//{
//	char* str1 = "abcdef";
//	char arr[20] = "XXXXXXXXXX";
//	printf("%s\n", my_strcpy(arr, str1));
//	return 0;
//}



////ģ��ʵ��strcat�ַ���׷��
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* start = dest;
//	//1.Ѱ��Ŀ�Ŀռ��'\0'
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.��������
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return start;
//}
//int main()
//{
//	char arr[20] = "hello ";
//	//my_strcat(arr, "world!");
//	//printf("%s\n", arr);
//	printf("%s\n", my_strcat(arr, "world!"));
//	return 0;
//}



////ģ��ʵ��strcmp�ַ����Ƚ�
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* s1, const char* s2)
//{
//	while (*s1 == *s2)
//	{
//		//���*s1����0������ѭ���Ļ�*s2Ҳ����0������0
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	//���*s1С��*s2����һ�����������򷵻�һ������
//	return *s1 - *s2;
//}
//int main()
//{
//	int ret = my_strcmp("abcd", "abcdef");
//	if (ret > 0)
//		printf("����\n");
//	else if(ret==0)
//		printf("����\n");
//	else
//		printf("С��\n");
//	return 0;
//}




////�ַ�������
//#include<stdio.h>
//#include<string.h>
//void left_move(char* str, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str);
//	//�ַ�����nλ
//	for (i = 0; i < n; i++)
//	{
//		//�ѵ�һ��Ԫ�ر�����tmp��
//		char tmp = *str;
//		//�Ѻ����Ԫ��������ǰŲ��һλ
//		for (j = 0; j < len - 1; j++) 
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		//�ѵ�һ��Ԫ�ظ������һ��Ԫ��
//		*(str + len - 1) = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcedf";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}




////�ж�һ���ַ����ǲ�������һ���ַ�������ת������
//#include<stdio.h>
//#include<string.h>
//void left_move(char* str, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str);
//	//�ַ�����nλ
//	for (i = 0; i < n; i++)
//	{
//		//�ѵ�һ��Ԫ�ر�����tmp��
//		char tmp = *str;
//		//�Ѻ����Ԫ��������ǰŲ��һλ
//		for (j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		//�ѵ�һ��Ԫ�ظ������һ��Ԫ��
//		*(str + len - 1) = tmp;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int i = 0;
//	int len = strlen(arr1);
//	for (i = 0; i < len; i++)
//	{
//		left_move(arr1, 1);
//		if (strcmp(arr1,arr2) == 0)
//		{
//			printf("yes\n");
//			break;
//		}
//	}
//	if(i==len)
//		printf("no\n");
//	return 0;
//}


////����strncat��strstr�ж�һ���ַ����ǲ�������һ���ַ�������ת������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "cdefab";
//	if (strlen(arr1) != strlen(arr2))
//	{
//		printf("no\n");
//		return 0;
//	}
//	strncat(arr1, arr1, 6);
//	char* start = strstr(arr1, arr2);
//	if (start == NULL)
//		printf("no\n");
//	else
//		printf("yes\n");
//	return 0;
//}



////strncmpָ���ַ��������Ƚ�
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abqeee";
//	int ret = strncmp(arr1, arr2, 2);
//	printf("%d\n", ret);
//	return 0;
//}



////strstr�ַ������ң����ҵ��ˣ����ص�ַ�����Ҳ������ؿ�ָ��
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	char* ret = strstr(arr, "cd");
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	else
//	{
//		printf("���Ҳ���\n");
//	}
//	return 0;
//}


////strtok������,�����ָ��������ָ����ó�'\0'
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "zzp@bitedu.tech";
//	char tmp[30] = { 0 };
//	strcpy(tmp, arr1);
//	char arr2[] = "@.";
//	char* p = NULL;
//	for (p = strtok(tmp, arr2); p != NULL; p = strtok(NULL, arr2))
//	{
//		printf("%s\n", p);
//	}
//	//p = strtok(tmp, arr2);
//	//printf("%s\n",p);
//
//	//p = strtok(NULL, arr2);//NULL��'@'��λ��
//	//printf("%s\n",p);
//
//	//p = strtok(NULL, arr2);//NULL��'.'��λ��
//	//printf("%s\n",p);
//	return 0;
//}