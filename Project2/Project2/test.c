#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)


void print(int week, int day)
{
    int i = 0;
    int date = 1;
    int flag = week;
    //printf("%d %d\n", week, day);
    printf("日 一 二 三 四 五 六\n");
    for (i = 0; i < (day + week) / 7 + 1; i++)
    {
        int j = 0;
        int k = 0;

        for (j = 0; j < week; j++)
        {
            if (flag != 0)
            {
                printf("   ");
            }

            flag--;
        }
        for (k = 0; k < 7 - week; k++)
        {
            printf("%2d ", date);
            date++;
            if (date > day)
                break;
        }
        week = 0;
        printf("\n");
    }
}
int Calculate(int y, int m)
{
    int sy = 2018;
    int i = 0;
    int sum = 0;//用来保存所输入的日期与基准相差的天数
    int flag1 = 0;//用来判断闰年二月
    int flag2 = 0;//用来判断输入年份与基准大小关系
    int week = 0;//用来保存算出来每月第一天是周几

    if (sy > y)
    {
        sy ^= y;
        y ^= sy;
        sy ^= y;
        flag2 = 1;
    }

    for (i = sy; i < y; i++)
    {
        if (((i % 4 == 0) && (i % 100 == 0)) || (i % 400 == 0))
        {
            sum = sum + 366;
            flag1 = 1;
        }
        else
            sum = sum + 365;
    }//计算出年份与基准年份相差的天数

    for (i = 1; i < m; i++)
    {

        if ((i == 1) || (i == 3) || (i == 5) || (i == 7)
            || (i == 8) || (i == 10) || (i == 12))
        {
            sum = sum + 31;
        }

        else if ((i == 2) && (flag1 == 1))
        {
            sum = sum + 29;
        }

        else if ((i == 2) && (flag1 == 0))
        {
            sum = sum + 28;
        }
        else
            sum = sum + 30;

    }
    if (flag2 == 0)
        week = sum % 7 + 1;//加一是由于基准月份第一天是周一
    else
        week = sum % 7 - 1;//比基准年份小是要减一
    //printf("%d\n", sum);
    return week;

}

int all_day(int y, int m)
{
    int flag = 0;
    int day = 30;

    if (((y % 4 == 0) && (y % 100 == 0)) || (y % 400 == 0))
    {
        flag = 1;
    }

    if ((m == 1) || (m == 3) || (m == 5) || (m == 7)
        || (m == 8) || (m == 10) || (m == 12))
    {
        day = 31;
    }

    else if ((m == 2) && (flag == 1))
    {
        day = 29;
    }

    else if ((m == 2) && (flag == 0))
    {
        day = 28;
    }
    else
        day = 30;

    return day;

}


int main()
{
    int year = 0;
    int month = 0;
    int week = 0;//用来保存输入月份第一天是周几
    int* p = NULL;
    int day = 0;//用来保存每月共有多少天

    scanf("%d%d", &year, &month);
    week = Calculate(year, month);//计算出与基准年月差多少天2018-0101，星期一
    day = all_day(year, month);//用来计算每月共有多少天

    //printf("%d\n", week);
    //printf("%d\n", day);
    print(week, day);
    system("pause");

    return 0;
}
