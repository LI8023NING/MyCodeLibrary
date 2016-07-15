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
		printf("*                       万年历                      *\n");
		printf("*                [1]  日  历  显  示 ->             *\n");
		printf("*                [2]  日  历  查  询 ->             *\n");
		printf("*                [3]  修  改  日  期 ->             *\n");
		printf("*                [4]  日  期  备  忘 录 ->          *\n");
		printf("*                [5]  信  息  帮  助                *\n");
		printf("*                [0]  退  出  系  统                *\n");
		printf("*****************************************************\n");
		printf("请选择:>");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			CalShow(&dt);//显示日历
			break;
		case 2:
			CalSelect(&dt);//日历查询
			break;
		case 3:
			UpdateCal(&dt);//更新日历
			break;
		case 4:
		    NotForgetNote(&dt);//备忘录
			break;
		case 5:
			HelpMassage();//帮助信息
			break;
		case 0:
			exit(0);//退出系统
			break;
		default:
			break;
		}
	}
}