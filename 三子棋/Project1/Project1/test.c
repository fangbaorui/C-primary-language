#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
char CheckWin(char board[ROW][COL], int row, int col);

//电脑赢了  #  利用所用字符代表
//玩家赢了  *  
//平局     E  --even
//继续     C  --continue


#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{  //Init 初始化英文缩写
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	printf(" --- --- ---\n");
	for (i = 0; i < row; i++)
	{
		//打印分割列
		printf("|");
		int j = 0;
		for (j = 0; j < col; j++)
			printf(" %c |", board[i][j]);
		printf("\n");
		//打印分割行
		for (j = 0; j < col; j++)
			printf(" ---");
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请下棋:>\n");
	while (1)                  //这里用一个while循环让玩家下对为止
	{
		printf("请输入一个坐标,例:1 1>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row)
		{
			if (board[x - 1][y - 1] != ' ')//当所下位置为空时,才能键入
				printf("坐标被占用,请重新输入!\n");
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("坐标非法,请重新输入!\n");//可能玩家会输入100 100,这当然也不行
	}
}
void
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = rand() % row;//这里用到了生成随机数的功能
		int y = rand() % col;//可以查查相关的资料,还可以看它
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//三行的判断
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//三列的判断
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//平局
	if (IsFull(board, row, col) == 1)//这里又调用IsFull函数
	{
		return 'E';
	}
	return 'C';
}

#include"game.h"

void menu()
{
	printf("********  三子棋  ********\n");
	printf("1.开始游戏       2.退出游戏\n");
	printf("**************************\n");
}
void game()
{
	//数据的存储是二维数组
	char board[ROW][COL];
	//初始化棋盘-初始化为空格
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
		PrintBoard(board, ROW, COL);
		//电脑下棋
		ComputerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
		PrintBoard(board, ROW, COL);
	}
	if (ret == '*')
		printf("玩家赢!\n");
	else if (ret == '#')
		printf("电脑赢!\n");
	else if (ret == 'E')
		printf("平局\n");
}
int main()
{
	int input = 2;
	do {                          //这里用do...while循环
		menu();                   //菜单栏0
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();               //三子棋游戏
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择!\n);
				break;
		}
		system("cls");
	} while (input - 2);             //直接用到真值判断是否继续游戏
	return 0;
}
