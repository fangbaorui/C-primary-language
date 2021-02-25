#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convret(int* data, char* time);//ת��ģ��

int weekD_value(int* data);//�������ڲ�ģ��

void displayData(int* data, int week);//������ʾģ��

int main()
{
    int week;//��

    char time[15];//��¼ʱ��

    int data[3] = { 0 };//�ֱ�洢�ꡢ�¡���

    printf("�����ʽΪ����/��/�ջ���.��.��\n");
    printf("���������ڣ�");
    scanf("%s", time);
    convret(data, time);//������������ַ�ת��Ϊ����
    week = weekD_value(data);//��������ģ��
    displayData(data, week);//��ʾģ��
    return 0;
}

void convret(int* data, char* time)
{
    int year = 0, month = 0, day = 0;
    int d, i;
    if (time == '\0')
    {
        printf("\n��������ȷ�����ڣ�\n");
        exit(0);
    }
    i = 0, d = -1;
    while (time[i])/*��������Ĳ������ڣ������������*/
    {
        if ((time[i] == '/' || time[i] == '.') && d == -1)//��ת����
        {
            d = 0;
            i++;
            continue;
        }
        if ((time[i] == '/' || time[i] == '.') && d == 0)//��ת����
        {
            d = 1;
            i++;
            continue;
        }
        if (d == -1)//�������
            year = year * 10 + (time[i] - '0');
        if (d == 0)//������
            month = month * 10 + (time[i] - '0');
        if (d == 1)//��������
            day = day * 10 + (time[i] - '0');
        i++;
    }
    if (month < 1 || month>12)/*����·��������*/
    {
        printf("��������ȷ������");
        exit(0);
    }
    data[0] = year;
    data[1] = month;
    data[2] = day;
}

int weekD_value(int* data)
{
    int dy, dm, m2;//���ֲ�ͬ�����ڲ�
    int d;
    int week;
    if (data[0] == 2000)
    {
        dy = 0;/*����������ڲ�Ϊ0��*/
        m2 = 1;/*2�·���������ڲ�Ϊ1��*/
        goto la_100;;//��ת
    }
    if (data[0] > 2000)
        d = (data[0] - 1 - 2000) / 4 - (data[0] - 1 - 2000) / 100 + (data[0] - 1 - 2000) / 400 + 1;
    else
        d = (data[0] - 2000) / 4 - (data[0] - 2000) / 100 + (data[0] - 2000) / 400;
    dy = (data[0] - 2000) + d;/***����1��һ�ŵ�2000��һ��һ�ŵġ����ڲ***/
    if ((data[0] % 40 && data[0] % 100 != 0) || (data[0] % 100 == 0 && data[0] % 400 == 0))
        m2 = 1;
    else
        m2 = 0;
la_100:
    /***������ǰ������ġ����ڲ***/
    switch (data[1])
    {
    case 1:
        dm = 0;
        data[1] = 31;
        break;
    case 2:
        dm = 3;
        data[1] = d == 1 ? 29 : 28;
        break;
    case 3:
        dm = 3 + m2;
        data[1] = 30;
        break;
    case 4:
        dm = 6 + m2;
        data[1] = 30;
        break;
    case 5:
        dm = 1 + m2;
        data[1] = 31;
        break;
    case 6:
        dm = 4 + m2;
        data[1] = 30;
        break;
    case 7:
        dm = 6 + m2;
        data[1] = 31;
        break;
    case 8:
        dm = 2 + m2;
        data[1] = 31;
        break;
    case 9:
        dm = 5 + m2;
        data[1] = 30;
        break;
    case 10:
        dm = 5 + m2;
        data[1] = 31;
        break;
    case 11:
        dm = 3 + m2;
        data[1] = 30;
        break;
    case 12:
        dm = 5 + m2;
        data[1] = 31;
        break;
    }
    if (data[2]<0 || data[2]>data[1])
    {
        printf("\n ERROR! the entered DAY is invalid\n");
        exit(0);
    }
    week = (dy + dm + data[2] - 1 + 6) % 7;//���ڼ�
    if (week < 0)
        week += 7;
    return week;
}
void displayData(int* data, int week)
{
    int i;
    char WEEK[9];
    if (data[2] > 0)
    {
        switch (week)
        {
        case 0:
            strcpy(WEEK, "������");
            break;
        case 1:
            strcpy(WEEK, "����һ");
            break;
        case 2:
            strcpy(WEEK, "���ڶ�");
            break;
        case 3:
            strcpy(WEEK, "������");
            break;
        case 4:
            strcpy(WEEK, "������");
            break;
        case 5:
            strcpy(WEEK, "������");
            break;
        case 6:
            strcpy(WEEK, "������");
            break;
        }
        printf("\n �����ǣ�%s  \( %d )\n", WEEK, week);
    }
    else
    {
        ++week;
        week %= 7;
        printf("\n��������:");
        printf("\n************************************\n");
        printf("   ��   һ   ��   ��   ��   ��   ��\n");
        for (i = 0; i < week; i++)
        {
            printf("     ");
        }
        for (i = 1; i <= data[1]; i++)
        {
            printf("%5d", i);

            week++;
            if (week % 7 == 0 && i != data[1])
                printf("\n");
        }
        printf("\n************************************\n");
    }
}

