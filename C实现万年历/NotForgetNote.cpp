#include"StartDefine.h"
#include"HeadFile.h"
#include"AllShengMing.h"

void NotForgetNote(CDateTime *dt)
{
	int select = 1;
	while (select)
	{
		system("cls");
		printf("*****************************************\n");
		printf("*[1] 新建备忘         [2] 查看备忘      *\n");
		printf("*[3] 修改备忘         [0] 返回上一层    *\n");
		printf("*****************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			NewBuildNote(dt);
			break;
		case 2:
			SelectNote(dt);
			break;
		case 3:
			UpdateNote(dt);
			break;
		case 0:
			return;
			break;
		}
	}
}

void UpdateNote(CDateTime *dt)
{
	FILE *fp;
	int i = 0;
	char *in = (char*)malloc(sizeof(char)* 100);
	fp = fopen("ForgetNode.txt", "ab");
	printf("输入内容：\n");
	scanf("%s\n", in);
	fwrite(in, 100, 1, fp);  //拷一次，一次拷100个
	fclose(fp);
	free(in);
}

void NewBuildNote(CDateTime *dt)
{
	FILE *fp;
	int i = 0;
	char *in = (char*)malloc(sizeof(char)*100);
	fp = fopen("ForgetNode.txt", "rb");
	printf("输入内容：\n");
	scanf("%s",in);
	fwrite(in,100,1,fp);  //拷一次，一次拷100个
	fclose(fp);
	free(in);
}

void  SelectNote(CDateTime *dt)
{
	FILE *fp;
	int size = 0;
	char *ar;

	//二进制方式打开文件
	fp = fopen("ForgetNode.txt", "rb");
	if (NULL == fp)
	{
		printf("Error:Open input.c file fail!\n");
		return;
	}

	//求得文件的大小
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	//申请一块能装下整个文件的空间
	ar = (char*)malloc(sizeof(char)*size);

	//读文件
	fread(ar, 1, size, fp);

	printf("%s\n", ar);
	fclose(fp);
	free(ar);

	printf("按任意键继续");
	getchar();
	getchar();
}



