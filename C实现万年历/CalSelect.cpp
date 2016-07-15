#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

//��ѯ�б�
void CalSelect(CDateTime *dt)
{
	int select = 1;
	while(select)
	{
		system("cls");
		printf("*****************************************\n");
		printf("*[1] ��ѯ��ǰ����      [2] ��ѯ��ǰʱ�� *\n");
		printf("*[3] ��ѯ����ʱ��      [4] ��ѯ����     *\n");
		printf("*[5] ��ѯN��ǰ����     [6] ��ѯN�������*\n");
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

//��ѯ��������
void SelectNowDate(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

//��ѯ����ʱ��
void SelectNowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%dʱ%d��%d��\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}

//��ѯʱ�������
void SelectDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
	printf("%dʱ%d��%d��\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}

//��ѯ�ܼ�
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
	int N;
	printf("��Ҫ֪������ǰ����:)\n");
	scanf("%d",&N);

	GetNowDateTime(dt);

	dt->m_day -= N;
	while (dt->m_day <= 0)
	{
		if (dt->m_month == 1)
		{
			dt->m_year--;
			dt->m_month = 12;
		}

		else
		{
			dt->m_month--;
		}

		dt->m_day += GetDays(dt->m_year, dt->m_month);
	}
	printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

//N�������
void SelectNextNday(CDateTime *dt)
{
	int N;
	printf("��Ҫ֪�����������:)\n");
	scanf("%d", &N);

	GetNowDateTime(dt);

	dt->m_day += N;
	while (dt->m_day > GetDays(dt->m_year, dt->m_month))
	{
		dt->m_day -= GetDays(dt->m_year, dt->m_month);
		if (dt->m_month == 12)
		{
			dt->m_year++;
			dt->m_month = 1;
		}
		else
		{
			dt->m_month++;
		}
	}
	printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

//����ĳ�յ�����
void SelectFutureDay(CDateTime *dt)
{
	int flag = 1;
	int y, m, d;
	printf("������Ҫ���������:)\n");
	scanf("%d%d%d",&y,&m,&d);
	CDateTime *max = (CDateTime*)malloc(sizeof(CDateTime));
	max->m_day = d;
	max->m_month = m;
	max->m_year = y;
	CDateTime *min = (CDateTime*)malloc(sizeof(CDateTime));
	GetNowDateTime(min);
	
	if (max->m_year < min->m_year
		|| (max->m_year == min->m_year && max->m_month < min->m_month)
		|| (max->m_year == min->m_year && max->m_month == min->m_month) && max->m_day < min->m_day)
	{
		CDateTime *tmp = nullptr;
		tmp = min;
		min = max;
		max = tmp;

		flag = -1;
	}

	int days = 0;
	while (!(max->m_year == min->m_year && max->m_month == min->m_month && max->m_day == min->m_day))
	{
		min->m_day += 1;
		while (min->m_day > GetDays(min->m_year, min->m_month))
		{
			min->m_day -= GetDays(min->m_year, min->m_month);
			if (min->m_month == 12)
			{
				min->m_year++;
				min->m_month = 1;
			}
			else
			{
				min->m_month++;
			}
		}
		days++;
	}
		
	printf("�����������������: %d\n",flag*days);
	system("pause");
}