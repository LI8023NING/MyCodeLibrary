#include"StartDefine.h"
#include"HeadFile.h"
//#include"AllShengMing.h"

void HelpMassage()
{
	FILE *fp;
	int size = 0;
	char *ar ;

	//二进制方式打开文件
	fp = fopen("lining.txt","rb");
	if(NULL == fp)
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
	fread(ar,1,size,fp);

	printf("%s",ar);
	fclose(fp);
	free(ar);

	printf("按任意键继续");
	getchar();
	getchar();
}