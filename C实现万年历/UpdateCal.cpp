#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

void UpdateCal(CDateTime *dt)
{
	char in = '\0';
	int y, m, d;
	printf("���ã�Ŀǰ����Ĭ��ϵͳ���ڣ�ȷ��Ҫ�޸���(Y/N)\n");
	scanf("%d",&in);

	if (in == 'y' || in == 'Y')
	{
		printf("����Ҫ�޸ĵ�����:)\n");
		scanf("%d%d%d", &y, &m, &d);
		dt->m_year = y;
		dt->m_month = m;
		dt->m_day = d;
		printf("�޸ĳɹ�����ǰ����Ϊ��\n");
		printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
		system("pause");
		printf("�����������");
		getchar();
		getchar();
	}
	else
	{
		printf("�����޸ĳɹ�����ǰ����Ϊ��\n");
		GetNowDateTime(dt);
		printf("%d��%d��%d��\n", dt->m_year, dt->m_month, dt->m_day);
		system("pause");
		printf("�����������");
		getchar();
		getchar();
	}
}
