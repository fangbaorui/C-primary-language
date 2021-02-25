#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convret(int* data, char* time);//转换模块

int weekD_value(int* data);//计算星期差模块

void displayData(int* data, int week);//日期显示模块

int main()
{
    int week;//周

    char time[15];//记录时间

    int data[3] = { 0 };//分别存储年、月、日

    printf("输入格式为：年/月/日或年.月.日\n");
    printf("请输入日期：");
    scanf("%s", time);
    convret(data, time);//将输入的日期字符转换为整型
    week = weekD_value(data);//计算星期模块
    displayData(data, week);//显示模块
    return 0;
}

void convret(int* data, char* time)
{
    int year = 0, month = 0, day = 0;
    int d, i;
    if (time == '\0')
    {
        printf("\n请输入正确的日期！\n");
        exit(0);
    }
    i = 0, d = -1;
    while (time[i])/*变量传入的参数日期，计算出年月日*/
    {
        if ((time[i] == '/' || time[i] == '.') && d == -1)//年转到月
        {
            d = 0;
            i++;
            continue;
        }
        if ((time[i] == '/' || time[i] == '.') && d == 0)//月转到日
        {
            d = 1;
            i++;
            continue;
        }
        if (d == -1)//计算年份
            year = year * 10 + (time[i] - '0');
        if (d == 0)//计算月
            month = month * 10 + (time[i] - '0');
        if (d == 1)//计算天数
            day = day * 10 + (time[i] - '0');
        i++;
    }
    if (month < 1 || month>12)/*如果月份输入错误*/
    {
        printf("请输入正确的日期");
        exit(0);
    }
    data[0] = year;
    data[1] = month;
    data[2] = day;
}

int weekD_value(int* data)
{
    int dy, dm, m2;//三种不同的星期差
    int d;
    int week;
    if (data[0] == 2000)
    {
        dy = 0;/*年引起的星期差为0个*/
        m2 = 1;/*2月份引起的星期差为1个*/
        goto la_100;;//跳转
    }
    if (data[0] > 2000)
        d = (data[0] - 1 - 2000) / 4 - (data[0] - 1 - 2000) / 100 + (data[0] - 1 - 2000) / 400 + 1;
    else
        d = (data[0] - 2000) / 4 - (data[0] - 2000) / 100 + (data[0] - 2000) / 400;
    dy = (data[0] - 2000) + d;/***该年1月一号到2000年一月一号的“星期差”***/
    if ((data[0] % 40 && data[0] % 100 != 0) || (data[0] % 100 == 0 && data[0] % 400 == 0))
        m2 = 1;
    else
        m2 = 0;
la_100:
    /***该月以前所引起的“星期差”***/
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
    week = (dy + dm + data[2] - 1 + 6) % 7;//星期几
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
            strcpy(WEEK, "星期日");
            break;
        case 1:
            strcpy(WEEK, "星期一");
            break;
        case 2:
            strcpy(WEEK, "星期二");
            break;
        case 3:
            strcpy(WEEK, "星期三");
            break;
        case 4:
            strcpy(WEEK, "星期四");
            break;
        case 5:
            strcpy(WEEK, "星期五");
            break;
        case 6:
            strcpy(WEEK, "星期六");
            break;
        }
        printf("\n 今天是：%s  \( %d )\n", WEEK, week);
    }
    else
    {
        ++week;
        week %= 7;
        printf("\n日历如下:");
        printf("\n************************************\n");
        printf("   日   一   二   三   四   五   六\n");
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

