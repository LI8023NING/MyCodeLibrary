#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

void CalSelect(CDateTime *dt)
{
	int select = 1;
	while(select)
	{
		system("cls");
		printf("*****************************************\n");
		printf("*[1] ��ѯ��ǰ����      [2] ��ѯ��ǰʱ�� *\n");
		printf("*[3] ��ѯ����ʱ��      [4] ��ѯ����     *\n");
		printf("*[5] ��ѯN�������     [6] ��ѯN��ǰ����*\n");
		printf("*[7] ��ѯ����ĳ�յ�����[0] �������˵�   *\n");
		printf("*****************************************\n");
		printf("��ѡ��:>");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			SelectNowDate(dt);
			break;
		case 2:
			SelectNowTime(dt);
			break;
		case 3:
			SelectDateTime(dt);
			break;
		case 4:
			SelectWeek(dt);
			break;
		case 5:
			SelectLastNday(dt);
			break;
		case 6:
			SelectNextNday(dt);
			break;
		case 7:
			SelectFutureDay(dt);
			break;
		case 0:
			return;
			break;
		}
	}
}


void SelectNowDate(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

void SelectNowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%dʱ%d��%d��\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}
void SelectDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
	printf("%dʱ%d��%d��\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}
void SelectWeek(CDateTime *dt)
{
	int year = 0;
	int month = 0;
	char weeks = 0;
	int num = 0;
	char weeknum[7][10] = { "��", "һ", "��", "��", "��", "��", "��" };
	int week;

	GetNowDateTime(dt);
	year = dt->m_year;  //�õ���ǰ���
	month = dt->m_month;//��ǰ�·�

	//������
	num = GetDays(year, month);

	weeks = dt->week;

	week = (35 + year + year / 4 - year / 100 + year / 400) % 7 - 1; //���㵱���1��1�����ܼ��Ĺ�ʽ 

	printf("%d��%d��%d��  ��%s\n", dt->m_year, dt->m_month, dt->m_day, weeknum[weeks]);
	system("pause");
}

//N��ǰ����
void SelectLastNday(CDateTime *dt)
{

}

//N�������
void SelectNextNday(CDateTime *dt)
{

}

//����ĳ�յ�����
void SelectFutureDay(CDateTime *dt)
{

}