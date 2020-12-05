////模拟实现strlen，求字符串长度(方法一）
////识别字符串中的每个字符，如果不是’\0’，计数器count++，直到找到’\0’为止，返回计数器coun的值
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);//断言str不是空指针
//	int count = 0;//计数器
//	while (*str != '\0')
//	{
//		count++;//每识别一个不是'\0'的字符，计数器+1
//		str++;//指向下一个字符的地址
//	}
//	return count;//返回计数器的值
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


////模拟实现strlen，求字符串长度（方法二）
////递归方法实现
////my_strlen(“abcdef”)->
////1 + my_strlen(“bcdef”)->
////1 + 1 + my_strlen(“cdef”)->
////1 + 1 + 1 + my_strlen(“def”)->
////1 + 1 + 1 + 1 + my_strlen(“ef”)->
////1 + 1 + 1 + 1 + 1 + my_strlen(“f”)->
////1 + 1 + 1 + 1 + 1 + 1 + my_strlen(" ")->
////1 + 1 + 1 + 1 + 1 + 1 + 0
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);//不断递归调用，直到*str= '\0’
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


////模拟实现strlen，求字符串长度（方法三）
////指针 - 指针，得到元素个数
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* start = str;//start指向元素地址
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;//str指向'\0'的地址
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


////模拟实现strcpy(方法一）
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


////模拟实现strcpy(方法二）
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


////模拟实现strcpy(方法三）
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



////模拟实现strcat字符串追加
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* start = dest;
//	//1.寻找目的空间的'\0'
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.拷贝数据
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



////模拟实现strcmp字符串比较
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* s1, const char* s2)
//{
//	while (*s1 == *s2)
//	{
//		//如果*s1等于0，进入循环的话*s2也等于0，返回0
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	//如果*s1小于*s2返回一个负数，否则返回一个整数
//	return *s1 - *s2;
//}
//int main()
//{
//	int ret = my_strcmp("abcd", "abcdef");
//	if (ret > 0)
//		printf("大于\n");
//	else if(ret==0)
//		printf("等于\n");
//	else
//		printf("小于\n");
//	return 0;
//}




////字符串左旋
//#include<stdio.h>
//#include<string.h>
//void left_move(char* str, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str);
//	//字符左旋n位
//	for (i = 0; i < n; i++)
//	{
//		//把第一个元素保存在tmp中
//		char tmp = *str;
//		//把后面的元素依次往前挪动一位
//		for (j = 0; j < len - 1; j++) 
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		//把第一个元素赋给最后一个元素
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




////判断一个字符串是不是由另一个字符串左旋转得来的
//#include<stdio.h>
//#include<string.h>
//void left_move(char* str, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str);
//	//字符左旋n位
//	for (i = 0; i < n; i++)
//	{
//		//把第一个元素保存在tmp中
//		char tmp = *str;
//		//把后面的元素依次往前挪动一位
//		for (j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		//把第一个元素赋给最后一个元素
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


////运用strncat，strstr判断一个字符串是不是由另一个字符串左旋转得来的
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



////strncmp指定字符串个数比较
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



////strstr字符串查找，查找到了，返回地址，查找不到返回空指针
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
//		printf("查找不到\n");
//	}
//	return 0;
//}


////strtok的作用,遇到分隔符，将分隔符置成'\0'
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
//	//p = strtok(NULL, arr2);//NULL在'@'的位置
//	//printf("%s\n",p);
//
//	//p = strtok(NULL, arr2);//NULL在'.'的位置
//	//printf("%s\n",p);
//	return 0;
//}