////ģ��ʵ���ַ������Һ���strstr������ҵ��ˣ������ַ������ڵ�ַ������Ҳ��������ؿ�ָ��
////��s1��ʾĿ���ַ�����s2��ʾ�����ַ��������ݣ���pc����ַ���1��
////����ʼλ�ã���s1==s2����cp++��s2++���Ƚ���һ��ֵ�����s2=='\0��֮ǰ��һ�������ҵ���
////���cp��ֵ�ȵ���'\0'��û�ҵ������ĳ��ֵ����ȣ�s2��λ��s1++��������
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
//	//���s2Ϊ�գ����ҵ��ˣ�����str1�׵�ַ
//	if (*s2 == '\0')
//	{
//		return (char*)str1;
//	}
//
//	while (*pc)
//	{
//		//����ƥ����ҵĹ���
//		s1 = pc;
//		s2 = str2;//ÿ�ν�s2��λ
//		
//		while (*s1 && *s2 && *s1 == *s2)//*sl=='\0',*s2=='\0',*s1!=*s2.������������˳�ѭ��
//		{
//			s1++;
//			s2++;
//		}
//		//ѭ�������������*s2=='\0'ֹͣ�ģ����ҵ���
//		if (*s2 == '\0')
//		{
//			return (char*)pc;
//		}
//		//ָ����һ���ַ��ĵ�ַ��������ַ���ʼ��������
//		pc++;
//	}
//	//�����*pc=='\0'ֹͣѭ������str1����Ҳû�ҵ�
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



////strerror,���ش�����Ϣ
////�����ÿ⺯�����������ʱ�򣬾ͻ���Щ������
////����������error���ȫ�ֱ�����
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<errno.h>
//#include<string.h>
//int main()
//{
//    //������ʽ��һ�������ڵ��ļ������
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//        perror("open file for reading");//�൱�������Ǹ���������
//    }
//    else
//    {
//        printf("�򿪳ɹ�\n");
//    }
//    //�ر��ļ�
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}


