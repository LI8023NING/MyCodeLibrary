#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

//日历显示菜单
void CalShow(CDateTime *dt)
{
	
	int select = 1;
	while(select)
	{
		system("cls");
		printf("*****************************************************\n");
		printf("*        [1] 显示当前日期   [2] 显示当前时间        *\n");
		printf("*        [3] 显示日期时间   [4] 动态显示时间        *\n");
		printf("*        [5] 显示本月日历表 [0] 返回主菜单          *\n");
		printf("*****************************************************\n");
		printf("请选择:>");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			ShowNowDate(dt);//日期
			break;
		case 2:
			ShowNowTime(dt);//时间
			break;
		case 3:
			ShowDateTime(dt);//时间日期
			break;
		case 4:
			ShowDnyDateTime(dt);//动态日期时间
			break;
		case 5:
			ShowCalTable(dt);//日历表
			break;
		case 0:
			return;//返回
			break;
		}
	}
}

void ShowNowDate(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n",dt->m_year,dt->m_month,dt->m_day);
	system("pause");
}


void ShowNowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d时%d分%d秒\n",dt->m_hour,dt->m_minute,dt->m_second);
	system("pause");
}


void ShowDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n",dt->m_year,dt->m_month,dt->m_day);
	printf("%d时%d分%d秒\n",dt->m_hour,dt->m_minute,dt->m_second);
	system("pause");

}


void ShowDnyDateTime(CDateTime *dt)
{
	while(!_kbhit())
	{
		GetNowDateTime(dt);
		printf("%d年%d月%d日\n",dt->m_year,dt->m_month,dt->m_day);
		printf("%d时%d分%d秒\n",dt->m_hour,dt->m_minute,dt->m_second);
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
	char weeknum[7][10] = {"日","一","二","三","四","五","六"};
	int week;
	
	GetNowDateTime(dt);
	year = dt->m_year;  //得到当前年份
	month = dt->m_month;//当前月份

	//算天数
	num = GetDays(year, month);

	weeks = dt->week;

	week = (35 + year + year / 4 - year / 100 + year / 400) % 7-1; //计算当年的1月1日是周几的公式 

	printf("%d年%d月%d日   周%s\n",dt->m_year,dt->m_month,dt->m_day,weeknum[weeks]);
	printf("周日   周一    周二    周三    周四    周五    周六\n");
	for (k = 0; k < week; k++)
	{
		printf("                                        "); //每月一号对齐它的星期数
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