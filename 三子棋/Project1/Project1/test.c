#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char CheckWin(char board[ROW][COL], int row, int col);

//����Ӯ��  #  ���������ַ�����
//���Ӯ��  *  
//ƽ��     E  --even
//����     C  --continue


#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{  //Init ��ʼ��Ӣ����д
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
		//��ӡ�ָ���
		printf("|");
		int j = 0;
		for (j = 0; j < col; j++)
			printf(" %c |", board[i][j]);
		printf("\n");
		//��ӡ�ָ���
		for (j = 0; j < col; j++)
			printf(" ---");
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)                  //������һ��whileѭ��������¶�Ϊֹ
	{
		printf("������һ������,��:1 1>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row)
		{
			if (board[x - 1][y - 1] != ' ')//������λ��Ϊ��ʱ,���ܼ���
				printf("���걻ռ��,����������!\n");
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("����Ƿ�,����������!\n");//������һ�����100 100,�⵱ȻҲ����
	}
}
void
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������:>\n");
	while (1)
	{
		int x = rand() % row;//�����õ�������������Ĺ���
		int y = rand() % col;//���Բ����ص�����,�����Կ���
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
	//���е��ж�
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//���е��ж�
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//ƽ��
	if (IsFull(board, row, col) == 1)//�����ֵ���IsFull����
	{
		return 'E';
	}
	return 'C';
}

#include"game.h"

void menu()
{
	printf("********  ������  ********\n");
	printf("1.��ʼ��Ϸ       2.�˳���Ϸ\n");
	printf("**************************\n");
}
void game()
{
	//���ݵĴ洢�Ƕ�ά����
	char board[ROW][COL];
	//��ʼ������-��ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
		PrintBoard(board, ROW, COL);
		//��������
		ComputerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
		PrintBoard(board, ROW, COL);
	}
	if (ret == '*')
		printf("���Ӯ!\n");
	else if (ret == '#')
		printf("����Ӯ!\n");
	else if (ret == 'E')
		printf("ƽ��\n");
}
int main()
{
	int input = 2;
	do {                          //������do...whileѭ��
		menu();                   //�˵���0
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();               //��������Ϸ
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��!\n);
				break;
		}
		system("cls");
	} while (input - 2);             //ֱ���õ���ֵ�ж��Ƿ������Ϸ
	return 0;
}
