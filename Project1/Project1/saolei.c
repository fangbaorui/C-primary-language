#pragma once
#include"test.h"

void game()
{

    int ret = 0;
    init_mine();//��ʼ��������̺����������
    set_mine();//����������̲���
    print_mine();//��ӡ��������̣��ɲ���ӡ��
    printf("\n");
    print_player();//��ӡ�������

    safe_mine();//�����һ�α�ը��

    if (count_show_mine() == COUNT)//һ����Ӯ�����
    {
        print_mine();
        printf("���Ӯ��\n\n");
        return;
    }print_player(); ��ӡ�������

        while (1)//ѭ��ɨ��
        {
            int ret = sweep_mine();//ɨ��,�ȵ��׷���1��û�вȵ��׷���0
            if (count_show_mine() == COUNT)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
            {
                print_mine();//��ӡ���������
                printf("���Ӯ��\n\n");

                break;
            }
            if (ret)//�ж��Ƿ�ȵ���
            {
                printf("����ը��\n");
                print_mine();//��ӡ���������鿴�׵ķֲ�
                break;
            }print_player();//��ӡ�������
        }
}


int main()
{
    srand((unsigned int)time(NULL));//���������������
    int input = 0;
    muen();//�˵�
    do
    {
        scanf_s("%d", &input);
        switch (input)
        {
        case 1:game();
            break;
        case 0:exit(1);//�˳���Ϸ
            break;
        default:
            printf("���������������\n");
            break;
        }
        muen();
        printf("contiue?\n");
    } while (1);//ѭ������Ϸ
    system("pause");
    return 0;
}

