#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

//������ʾ�˵�
void CalShow(CDateTime *dt)
{
	
	int select = 1;
	while(select)
	{
		system("cls");
		printf("*****************************************************\n");
		printf("*        [1] ��ʾ��ǰ����   [2] ��ʾ��ǰʱ��        *\n");
		printf("*        [3] ��ʾ����ʱ��   [4] ��̬��ʾʱ��        *\n");
		printf("*        [5] ��ʾ���������� [0] �������˵�          *\n");
		printf("*****************************************************\n");
		printf("��ѡ��:>");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			ShowNowDate(dt);//����
			break;
		case 2:
			ShowNowTime(dt);//ʱ��
			break;
		case 3:
			ShowDateTime(dt);//ʱ������
			break;
		case 4:
			ShowDnyDateTime(dt);//��̬����ʱ��
			break;
		case 5:
			ShowCalTable(dt);//������
			break;
		case 0:
			return;//����
			break;
		}
	}
}

void ShowNowDate(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d��%d��%d��\n",dt->m_year,dt->m_month,dt->m_day);
	system("pause");
}


void ShowNowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%dʱ%d��%d��\n",dt->m_hour,dt->m_minute,dt->m_second);
	system("pause");
}


void ShowDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d��%d��%d��\n",dt->m_year,dt->m_month,dt->m_day);
	printf("%dʱ%d��%d��\n",dt->m_hour,dt->m_minute,dt->m_second);
	system("pause");

}


void ShowDnyDateTime(CDateTime *dt)
{
	while(!_kbhit())
	{
		GetNowDateTime(dt);
		printf("%d��%d��%d��\n",dt->m_year,dt->m_month,dt->m_day);
		printf("%dʱ%d��%d��\n",dt->m_hour,dt->m_minute,dt->m_second);
		Sleep(1000);
		system("cls");
	}
}


int GetDays(int year, int month)
{
	int days = 0;
	int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	{
		if (month == 2)
		{
			days = mon[month] + 1;
		}
	}
	days = mon[month];
	return days;
}

void ShowCalTable(CDateTime *dt)
{
	int k, j;
	int year = 0;
	int month = 0;
	char weeks = 0;
	int num = 0;
	char weeknum[7][10] = {"��","һ","��","��","��","��","��"};
	int week;
	
	GetNowDateTime(dt);
	year = dt->m_year;  //�õ���ǰ���
	month = dt->m_month;//��ǰ�·�

	//������
	num = GetDays(year, month);

	weeks = dt->week;

	week = (35 + year + year / 4 - year / 100 + year / 400) % 7-1; //���㵱���1��1�����ܼ��Ĺ�ʽ 

	printf("%d��%d��%d��   ��%s\n",dt->m_year,dt->m_month,dt->m_day,weeknum[weeks]);
	printf("����   ��һ    �ܶ�    ����    ����    ����    ����\n");
	for (k = 0; k < week; k++)
	{
		printf("                                        "); //ÿ��һ�Ŷ�������������
	}

	for (j = 1; j <= num; j++)
	{
		printf("%3d     ",j);
		if (++week >= 7)
		{
			printf("\n\n");
			week = week % 7;
		}
	}

	getchar();
	getchar();
}



void InitDateTime(CDateTime *dt)
{
	dt->m_year = 1;
	dt->m_month = 1;
	dt->m_day = 1;
	dt->m_hour = 0;
	dt->m_minute = 0;
	dt->m_second = 0;
	dt->week = 1;
}
void GetNowDateTime(CDateTime *dt)
{
	time_t te;
	time(&te);
	tm *ptm = localtime(&te);
	dt->m_year = ptm->tm_year+1900;
	dt->m_month = ptm->tm_mon+1;
	dt->m_day = ptm->tm_mday;
	dt->m_hour = ptm->tm_hour;
	dt->m_minute = ptm->tm_min;
	dt->m_second = ptm->tm_sec;
	dt->week = ptm->tm_wday;
}