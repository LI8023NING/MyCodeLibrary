#include"HeadFile.h"
#include"AllShengMing.h"

void main()
{	
	CDateTime dt;
	InitDateTime(&dt);
	int select = 1;
	while(select)
	{
		system("cls");
		printf("*****************************************************\n");
		printf("*                       ������                      *\n");
		printf("*                [1]  ��  ��  ��  ʾ ->             *\n");
		printf("*                [2]  ��  ��  ��  ѯ ->             *\n");
		printf("*                [3]  ��  ��  ��  �� ->             *\n");
		printf("*                [4]  ��  ��  ��  �� ¼ ->          *\n");
		printf("*                [5]  ��  Ϣ  ��  ��                *\n");
		printf("*                [0]  ��  ��  ϵ  ͳ                *\n");
		printf("*****************************************************\n");
		printf("��ѡ��:>");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			CalShow(&dt);//��ʾ����
			break;
		case 2:
			CalSelect(&dt);//������ѯ
			break;
		case 3:
			UpdateCal(&dt);//��������
			break;
		case 4:
		    NotForgetNote(&dt);//����¼
			break;
		case 5:
			HelpMassage();//������Ϣ
			break;
		case 0:
			exit(0);//�˳�ϵͳ
			break;
		default:
			break;
		}
	}
}