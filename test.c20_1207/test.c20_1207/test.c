////模拟实现字符串查找函数strstr，如果找到了，返回字符串所在地址，如果找不到，返回空指针
////用s1表示目标字符串，s2表示查找字符串的内容，用pc标记字符串1，
////从起始位置，若s1==s2，则cp++，s2++，比较下一个值，如果s2=='\0‘之前都一样，则找到了
////如果cp的值先等于'\0'则没找到，如果某个值不想等，s2归位，s1++，继续找
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* pc = str1;
//
//	//如果s2为空，则找到了，返回str1首地址
//	if (*s2 == '\0')
//	{
//		return (char*)str1;
//	}
//
//	while (*pc)
//	{
//		//依次匹配查找的过程
//		s1 = pc;
//		s2 = str2;//每次将s2归位
//		
//		while (*s1 && *s2 && *s1 == *s2)//*sl=='\0',*s2=='\0',*s1!=*s2.三种情况都有退出循环
//		{
//			s1++;
//			s2++;
//		}
//		//循环结束，如果是*s2=='\0'停止的，则找到了
//		if (*s2 == '\0')
//		{
//			return (char*)pc;
//		}
//		//指向下一个字符的地址，从这个字符开始继续查找
//		pc++;
//	}
//	//如果是*pc=='\0'停止循环，则str1查完也没找到
//	return NULL;
//}
//int main()
//{
//	char* str1 = "abcdef";
//	char* str2 = "cde";
//	char* ret = my_strstr(str1, str2);
//	printf("%s\n", ret);
//	return 0;
//}



////strerror,返回错误信息
////当调用库函数发生错误的时候，就会有些错误码
////错误码会放在error这个全局变量中
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<errno.h>
//#include<string.h>
//int main()
//{
//    //读的形式打开一个不存在的文件会出错
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//        perror("open file for reading");//相当于上面那个，更方便
//    }
//    else
//    {
//        printf("打开成功\n");
//    }
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}


