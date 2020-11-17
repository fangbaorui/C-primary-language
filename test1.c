//����ָ�����ͨѶ¼
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define DEFAULT_SZ 3
#define INC 2

//��ϵ�˸����ԵĴ�С
#define MAX_NAME 20   //�Ա�
#define MAX_TELE 12   //�绰
#define MAX_ADDR 100  //��ַ
#define MAX_QQ 12     //QQ
#define MAX_SEX 5     //�Ա�

//����ÿ���˵�����Ϊ�ṹ������
typedef struct PeoInfo
{//��������+��������

	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

//Ĭ�Ͽ��Դ��3���˵���Ϣ
typedef struct Contact
{
	PeoInfo *data;  //����
	int sz;  //��Ч����
	int capacity;  //ͨ��¼��ǰ����
}Contact;

//��ʼ��ͨѶ¼
void init_contact(Contact* pc);

//���һ���˵���Ϣ
void add_contact(Contact* pc);

//��ʾͨѶ¼�е���Ϣ
void show_contact(Contact* pc);

//ɾ��ָ������ϵ��
void del_contact(Contact* pc);

//����ָ������ϵ��
void search_contact(Contact* pc);

//�޸�ָ������ϵ��
void modify_contact(Contact* pc);

//����ͨѶ¼������
void sort_contact(Contact* pc);

//����ͨѶ¼
void destroy_contact(Contact* pc);




void init_contact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}

}

void destroy_contact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void add_contact(Contact* pc)
{
	assert(pc);
	if (pc->sz == pc->capacity)
	{
		//��������
		PeoInfo*ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC;
			printf("���ݳɹ�");
		}
		else
		{
			perror("add_contact::realloc");
			return;
		}
	}

	printf("���������֣�>");
	scanf("%s", pc->data[pc->sz].name);
	printf("������绰��>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������QQ��>");
	scanf("%s", pc->data[pc->sz].qq);
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺>");
	scanf("%s", pc->data[pc->sz].age);

	pc->sz++;
	printf("��ӳɹ�\n");

}

void show_contact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "QQ", "�Ա�");
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
			return 1;  // �ҵ��ˣ������±�
		}
	}
	return -1;
}
void del_contact(Contact* pc)
{
	assert(pc);
	if (pc == 0)
	{
		printf("��Ǹ��ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("������Ҫɾ���˵�����:>");
		scanf("%s", name);
		int pos = find_peo_by_name(pc, name);
		if (pos = -1)
		{
			printf("���ź���ɾ�����˲�����\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void search_contact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos = -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "QQ", "�Ա�");
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
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos = -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("�������µ�������>");
		scanf("%s", pc->data[pos].name);
		printf("�������µĵ绰��>");
		scanf("%s", pc->data[pos].tele);
		printf("�������µĵ�ַ��>");
		scanf("%s", pc->data[pos].addr);
		printf("�������µ�QQ��>");
		scanf("%s", pc->data[pos].qq);
		printf("�������µ��Ա�>");
		scanf("%s", pc->data[pos].sex);
		printf("�������µ����䣻>");
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
		int flag = 1;  //һ�ֶ�ð��������Ż���ʽ�������Ѿ�����
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
	//����ͨѶ¼
	Contact con = { 0 };
  //��ʼ��ͨѶ¼
  init_contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}