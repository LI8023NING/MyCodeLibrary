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
		printf("*[1] �½�����         [2] �鿴����      *\n");
		printf("*[3] �޸ı���         [0] ������һ��    *\n");
		printf("*****************************************\n");
		printf("��ѡ��:>");
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
	printf("�������ݣ�\n");
	scanf("%s\n", in);
	fwrite(in, 100, 1, fp);  //��һ�Σ�һ�ο�100��
	fclose(fp);
	free(in);
}

void NewBuildNote(CDateTime *dt)
{
	FILE *fp;
	int i = 0;
	char *in = (char*)malloc(sizeof(char)*100);
	fp = fopen("ForgetNode.txt", "rb");
	printf("�������ݣ�\n");
	scanf("%s",in);
	fwrite(in,100,1,fp);  //��һ�Σ�һ�ο�100��
	fclose(fp);
	free(in);
}

void  SelectNote(CDateTime *dt)
{
	FILE *fp;
	int size = 0;
	char *ar;

	//�����Ʒ�ʽ���ļ�
	fp = fopen("ForgetNode.txt", "rb");
	if (NULL == fp)
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
	fread(ar, 1, size, fp);

	printf("%s\n", ar);
	fclose(fp);
	free(ar);

	printf("�����������");
	getchar();
	getchar();
}



