#include "InitPsBook.h"
extern const char* filename;
extern int g_Count;
void InitBook()
{
	FILE* fpFile = NULL;
	errno_t nErr;
	if (nErr = fopen_s(&fpFile, filename, "r")) //�򲻿����½�
	{
		if (fopen_s(&fpFile, filename, "wb"))
		{
			printf("�����ļ�ʧ��!!!\n");
			return;
		}
	}
	if (nErr)                                   //�½����뱾����ʼ������
	{
		fwrite(&g_Count, sizeof(int), 1, fpFile);
		printf("�����ļ��ɹ�!!!\n");
	}
	else
		printf("�ļ��򿪳ɹ�!!!\n");
	fclose(fpFile);
	fpFile = NULL;
}