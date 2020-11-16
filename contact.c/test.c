//通讯录1，利用结构体创建，非指针
#define _CRT_SECURE_NO_WARNINGS 1
//类型声明+函数声明
#include<stdio.h>
#include<string.h>

//1000位联系人
#define MAX 1000

//联系人个属性的大小
#define MAX_NAME 20   //性别
#define MAX_TELE 12   //电话
#define MAX_ADDR 100  //地址
#define MAX_QQ 12     //QQ
#define MAX_SEX 5     //性别

//定义每个人的类型为结构体类型
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

//通讯录
typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;  //有效个数
}Contact;

//添加一个人的信息
void add_contact(Contact* pc);

//显示通讯录中的信息
void show_contact(Contact* pc);

//删除指定的联系人
void del_contact(Contact* pc);

//查找指定的联系人
void search_contact(Contact* pc);

//修改指定的联系人
void modify_contact(Contact* pc);

//排序通讯录的数据
void sort_contact(Contact* pc);


#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void destroy_contact(Contact* pc)
{

}

void add_contact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };


	printf("请输入名字：>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入QQ：>");
	scanf("%s", pc->data[pc->sz].qq);
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：>");
	scanf("%s", pc->data[pc->sz].age);

	pc->sz++;
	printf("添加成功\n");

}

void show_contact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s %12s %20s %5s %12s %5s\n", "姓名", "电话", "地址", "年龄", "QQ", "性别");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s %12s %20s %5s %12s %5s\n", pc->data[i].name,
			pc->data[i].tele,
			pc->data[i].addr,
			pc->data[i].age,
			pc->data[i].qq,
			pc->data[i].sex);
	}
}

static int find_peo_by_name(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return 1;  // 找到了，返回下标
		}
	}
	return -1;
}
void del_contact(Contact* pc)
{
	assert(pc);
	if (pc == 0)
	{
		printf("抱歉，通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入要删除人的姓名:>");
		scanf("%s", name);
		int pos = find_peo_by_name(pc, name);
		if (pos = -1)
		{
			printf("很遗憾，删除的人不存在\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("删除成功\n");
		}
	}
}

void search_contact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字；>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos = -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "姓名", "电话", "地址", "年龄", "QQ", "性别");
		printf("%10s %12s %20s %5s %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}
void modify_contact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字；>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos = -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入新的姓名；>");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的电话；>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址；>");
		scanf("%s", pc->data[pos].addr);
		printf("请输入新的QQ；>");
		scanf("%s", pc->data[pos].qq);
		printf("请输入新的性别；>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的年龄；>");
		scanf("%s", pc->data[pos].age);
	}
}

void sort_contact(Contact* pc)
{
	assert(pc);
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz; i++)
	{
		int flag = 1;  //一种对冒泡排序的优化方式，假设已经有序
		for (j = 0; j < pc->sz - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name)>0)

			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}

}



enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

void menu()
{
	printf("***********************************\n");
	printf("******1.add       2.del    ********\n");
	printf("******3.search    4.modify ********\n");
	printf("******5.sort      6.show   ********\n");
	printf("******      0.exit         ********\n");
	printf("***********************************\n");
}


void test()
{
	//创建通讯录
	Contact con = { 0 };
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		   case ADD:
				add_contact(&con);
				break;
		   case DEL:
				del_contact(&con);
				break;
		   case SORT:
				sort_contact(&con);
				break;
		   case SHOW:
				show_contact(&con);
				break;
		   case SEARCH:
				search_contact(&con);
				break;
		   case MODIFY:
				modify_contact(&con);
		   case EXIT:
				printf("退出通讯录\n");
					break;
			default:
				printf("输入错误\n");
					break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}