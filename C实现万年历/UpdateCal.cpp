#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

void UpdateCal(CDateTime *dt)
{
	char in = '\0';
	int y, m, d;
	printf("您好，目前日期默认系统日期，确定要修改吗？(Y/N)\n");
	scanf("%d",&in);

	if (in == 'y' || in == 'Y')
	{
		printf("输入要修改的日期:)\n");
		scanf("%d%d%d", &y, &m, &d);
		dt->m_year = y;
		dt->m_month = m;
		dt->m_day = d;
		printf("修改成功，当前日期为：\n");
		printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
		system("pause");
		printf("按任意键继续");
		getchar();
		getchar();
	}
	else
	{
		printf("放弃修改成功，当前日期为：\n");
		GetNowDateTime(dt);
		printf("%d年%d月%d日\n", dt->m_year, dt->m_month, dt->m_day);
		system("pause");
		printf("按任意键继续");
		getchar();
		getchar();
	}
}
