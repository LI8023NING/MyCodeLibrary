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
		printf("*[1] 查询当前日期      [2] 查询当前时间 *\n");
		printf("*[3] 查询日期时间      [4] 查询星期     *\n");
		printf("*[5] 查询N天后日期     [6] 查询N天前日期*\n");
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


void SelectNowDate(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
	system("pause");
}

void SelectNowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d时%d分%d秒\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}
void SelectDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
	printf("%d时%d分%d秒\n", dt->m_hour, dt->m_minute, dt->m_second);
	system("pause");
}
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

}

//N天后日期
void SelectNextNday(CDateTime *dt)
{

}

//距离某日的天数
void SelectFutureDay(CDateTime *dt)
{

}