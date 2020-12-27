#define _CRT_SECURE_NO_WARNINGS
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

//方法一
#include<stdio.h>
#include<stdlib.h>
typedef int SDataType;
//顺序表实现栈
typedef struct stack
{
    SDataType* data;
    size_t size;
    size_t capacity;
}stack;

//初始化栈
void stackInit(stack* st);

//入栈
void stackPush(stack* st, SDataType val);

//出栈
void stackPop(stack* st);

//栈的大小
int stackSize(stack* st);

//判空
int stackEmpty(stack* st);

//检查容量：增容
void checkCapacity(stack* st);

//初始化栈
void stackInit(stack* st)
{
    //空栈
    if (st == NULL)
        return;
    st->data = NULL;
    st->size = st->capacity = 0;
}

//检查容量：增容
void checkCapacity(stack* st)
{
    if (st->size == st->capacity)
    {
        int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
        st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
        st->capacity = newCap;
    }
}

//入栈：尾插
void stackPush(stack* st, SDataType val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->data[st->size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == NULL || st->size == 0)
        return;
    st->size--;
}

//获取栈顶元素
int stackTop(stack* st)
{
    return st->data[st->size - 1];
}

//判空:为空返回1，不为空返回0
int stackEmpty(stack* st)
{
    if (st == NULL || st->size == 0)
        return 1;
    return 0;
}

//栈的大小
int stackSize(stack* st)
{
    if (st == NULL || st->size == 0)
        return 0;
    return st->size;
}
布尔类型 isValid(char* s) {
    //括号映射
    char map[3][2] = { {'(',')'},{'{','}'},{'[',']'} };
    struct stack st;
    stackInit(&st);
    while (*s)
    {
        //标记flag看看是否是左括号
        int flag = 0;
        //左括号：入栈
        for (int i = 0; i < 3; i++)
        {
            if (*s == map[i][0])
            {
                stackPush(&st, *s);
                //判断下一个字符
                ++s;
                flag = 1;
                break;
            }
        }
        //右括号
        if (flag == 0)
        {
            //如果栈为空的话，没有适合的左括号匹配右括号，返回false
            if (stackEmpty(&st))
                return false;
            //取出栈顶元素：左括号
            char topChar = stackTop(&st);
            stackPop(&st);
            //找到当前字符*s对应的左括号
            for (int i = 0; i < 3; i++)
            {
                if (map[i][1] == *s)
                {
                    if (topChar == map[i][0])
                    {
                        ++s;
                        break;
                    }
                    else
                        return false;
                }
            }
        }
    }
    return stackEmpty(&st);
}



//方法二

#include<stdio.h>
#include<stdlib.h>
typedef int SDataType;
//顺序表实现栈
typedef struct stack
{
    SDataType* data;
    size_t size;
    size_t capacity;
}stack;

//初始化栈
void stackInit(stack* st);

//入栈
void stackPush(stack* st, SDataType val);

//出栈
void stackPop(stack* st);

//栈的大小
int stackSize(stack* st);

//判空
int stackEmpty(stack* st);

//检查容量：增容
void checkCapacity(stack* st);

//初始化栈
void stackInit(stack* st)
{
    //空栈
    if (st == NULL)
        return;
    st->data = NULL;
    st->size = st->capacity = 0;
}

//检查容量：增容
void checkCapacity(stack* st)
{
    if (st->size == st->capacity)
    {
        int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
        st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
        st->capacity = newCap;
    }
}

//入栈：尾插
void stackPush(stack* st, SDataType val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->data[st->size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == NULL || st->size == 0)
        return;
    st->size--;
}

//获取栈顶元素
int stackTop(stack* st)
{
    return st->data[st->size - 1];
}

//判空:为空返回1，不为空返回0
int stackEmpty(stack* st)
{
    if (st == NULL || st->size == 0)
        return 1;
    return 0;
}

//栈的大小
int stackSize(stack* st)
{
    if (st == NULL || st->size == 0)
        return 0;
    return st->size;
}
布尔类型 isValid(char* s) {
    //括号映射
    char arr[128] = { 0 };
    arr[')'] = '(';
    arr['}'] = '{';
    arr[']'] = '[';
    struct stack st;
    stackInit(&st);
    while (*s)
    {
        //标记flag看看是否是左括号
        int flag = 0;
        //左括号：入栈
        if (*s == '(' || *s == '[' || *s == '{')
        {
            stackPush(&st, *s);
            ++s;
            flag = 1;
        }
        //右括号
        if (flag == 0)
        {
            //如果栈为空的话，没有适合的左括号匹配右括号，返回false
            if (stackEmpty(&st))
                return false;
            //取出栈顶元素：左括号
            char topChar = stackTop(&st);
            stackPop(&st);
            //找到当前字符*s对应的左括号
            if (arr[*s] == topChar)
                ++s;
            else
                return false;
        }
    }
    return stackEmpty(&st);
}