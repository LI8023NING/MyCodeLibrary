#include"StartDefine.h"
#include"HeadFile.h"
//#include"AllShengMing.h"

void HelpMassage()
{
	FILE *fp;
	int size = 0;
	char *ar ;

	//�����Ʒ�ʽ���ļ�
	fp = fopen("lining.txt","rb");
	if(NULL == fp)
	{
		printf("Error:Open input.c file fail!\n");
		return;
	}

	//����ļ��Ĵ�С
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	//����һ����װ�������ļ��Ŀռ�
	ar = (char*)malloc(sizeof(char)*size);

	//���ļ�
	fread(ar,1,size,fp);

	printf("%s",ar);
	fclose(fp);
	free(ar);

	printf("�����������");
	getchar();
	getchar();
}