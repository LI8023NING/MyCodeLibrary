#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

//查询列表
void CalSelect(CDateTime *dt)
{
	int select = 1;
	while(select)
	{
		system("cls");
		printf("*****************************************\n");
		printf("*[1] 查询当前日期      [2] 查询当前时间 *\n");
		printf("*[3] 查询日期时间      [4] 查询星期     *\n");
		printf("*[5] 查询N天前日期     [6] 查询N天后日期*\n");
		printf("*[7] 查询距离某日的天数[0] 返回主菜单   *\n");
		printf("*****************************************\n");
		printf("请选择:>");
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

//查询现在日期
void SelectNowDate(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

//查询现在时间
void SelectNowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d时%d分%d秒\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}

//查询时间和日期
void SelectDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
	printf("%d时%d分%d秒\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}

//查询周几
void SelectWeek(CDateTime *dt)
{
	int year = 0;
	int month = 0;
	char weeks = 0;
	int num = 0;
	char weeknum[7][10] = { "日", "一", "二", "三", "四", "五", "六" };
	int week;

	GetNowDateTime(dt);
	year = dt->m_year;  //得到当前年份
	month = dt->m_month;//当前月份

	//算天数
	num = GetDays(year, month);

	weeks = dt->week;

	week = (35 + year + year / 4 - year / 100 + year / 400) % 7 - 1; //计算当年的1月1日是周几的公式 

	printf("%d年%d月%d日  周%s\n", dt->m_year, dt->m_month, dt->m_day, weeknum[weeks]);
	system("pause");
}

//N天前日期
void SelectLastNday(CDateTime *dt)
{
	int N;
	printf("需要知道几天前日期:)\n");
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
	printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

//N天后日期
void SelectNextNday(CDateTime *dt)
{
	int N;
	printf("需要知道几天后日期:)\n");
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
	printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

//距离某日的天数
void SelectFutureDay(CDateTime *dt)
{
	int flag = 1;
	int y, m, d;
	printf("输入需要计算的日期:)\n");
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
		
	printf("两个日期相隔天数是: %d\n",flag*days);
	system("pause");
}