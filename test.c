//Ԥ�������
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (i = 0; i < 10; i++)
//	{
//		printf("file:%s  line:%d  data:%s  time:%s  %d\n", \
//			__FILE__, __LINE__, __DATE__, __TIME__,arr[i]);
//		return 0;
//	}
//}


////Ԥ�������д���ļ�
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		perror("open file for writting!");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "file:%s  line:%d  date:%s  time:%s  %d\n", \
//			__FILE__, __LINE__, __DATE__, __TIME__, arr[i]);
//	}
//	fcloce(pf);
//	pf = NULL;
//	return 0;
//}



//#define�����ʶ��


//�ٸ�����
//#define MAX 1000
//#define reg register       //register�Ǹ��ؼ��ִ���һ����̵�����
//#define do_forever for(;;)     //�ø�����ķ������滻һ��ʵ��
//#define CASE break;case        //��дcase����ʱ���Զ��� breakд�ϡ�
//// �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)�����������治�ܼӿո񣬷���ᱻ��Ϊ��ת���ַ�
//#define DEBUG_PRINT printf("file:%s\tline:%d\t \
//                        date:%s\ttime:%s\n", \
//						 __FILE__, __LINE__, \


//#define MAX 1000;
//int a = MAX;   //->int a=1000;;   ����ķֺ��ǿ����


//��define�����ʶ����ʱ��Ҫ��Ҫ�������ϡ�������
//#include<stdio.h>
//#define MAX 1000;
//int main()
//{
//	int a = 5;
//	int b = 0;
//	if (a > 3)
//		b = MAX;
//	else
//		b = 10;
//	printf("%d", b);//�ᱨ��if�������������䣬�ڶ���Ϊ����䣬elseû��ƥ���if
//	return 0;
//}



//#defined�궨��
//#include<stdio.h>
//#define MAX(X,Y)  X>Y?X:Y  //����������
//int Max(int X,int Y)  //��������������
//{
//	return X > Y ? X : Y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = Max(a,b); //20
//	printf("%d\n", max);
//	max = MAX(a, b);
//	printf("%d\n", max);  //20
//	return 0;
//}


//#include<stdio.h>
//#define SQUARE(X) X*X
////#define DOUBLE(X) X+X
//#define DOUBLE(X) (X+X)
//int main()
//{
//	printf("%d\n", SQUARE(5));  //25
//	printf("%d\n", SQUARE(4+1));  //9
//	//printf("%d\n",10*DOUBLE(5));  //55
//	printf("%d\n", 10 * DOUBLE(5)); //100
//	return 0;
//}



////ʹ�� # ����һ���������ɶ�Ӧ���ַ���
//#include<stdio.h>
////#define PRINT(X) printf("the value of X is %d\n", X);
//#define PRINT(X) printf("the value of "#X" is %d\n", X);
//int main()
//{
//	int a = 100;
//	int b = 200;
//	//PRINT(a);  //the value of X is 100
//	//PRINT(b);//the value of X is 200
//	PRINT(a); //the value of a is 100
//	PRINT(b); //the value of b is 200
//	return 0;
//}


////ʹ�� # ����һ���������ɶ�Ӧ���ַ���,�Ѳ������ʹ���ȥ
//#include<stdio.h>
//#define PRINT(FORMAT,X) printf("the value of "#X" is "FORMAT"\n", X);//���԰˱��������ʹ���ȥ
//int main()
//{
//	float a = 99.9;
//	PRINT("%f",a); //the value of a is 99.900002
//	return 0;
//}



////##������
//#include<stdio.h>
//#define CAT(X,Y) X##Y
//int main()
//{
//	int zhangsanage = 20;
//	printf("%d\n", CAT(zhangsan,age));//20
//	return 0;
//}



////�������õĺ����  x+1����������  ++x��������
//#include<stdio.h>
//#define MAX(X,Y)  ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int ret = ((a++) > (b++) ? (a++) : (b++));
//	printf("a=%d  b=%d\n", a, b); //11  13
//	printf("%d\n", ret);//12
//	return 0;
//}




////�������õĺ����  x+1����������  ++x��������
//#include<stdio.h>
//#define MALLOC(num,type)  (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	if (p!=NULL)  //malloc���ٵĿռ�Ҫ�п�
//	return 0;
//	free(p);   // malloc���ٵĿռ�Ҫ��free���ͷ�
//	p = NULL;
//}


//#define nameָ�������Ƴ�һ���궨��
#include<stdio.h>
#define MAX 100
int main()
{
	printf("%d\n",MAX);
#undef MAX
	//printf("%d\n", MAX);�˴��ĺ궨���Ѿ����Ƴ���
	return 0;
}