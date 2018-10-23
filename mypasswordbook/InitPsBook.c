#include "InitPsBook.h"
extern const char* filename;
extern int g_Count;
void InitBook()
{
	FILE* fpFile = NULL;
	errno_t nErr;
	if (nErr = fopen_s(&fpFile, filename, "r")) //打不开则新建
	{
		if (fopen_s(&fpFile, filename, "wb"))
		{
			printf("创建文件失败!!!\n");
			return;
		}
	}
	if (nErr)                                   //新建密码本并初始化数据
	{
		fwrite(&g_Count, sizeof(int), 1, fpFile);
		printf("创建文件成功!!!\n");
	}
	else
		printf("文件打开成功!!!\n");
	fclose(fpFile);
	fpFile = NULL;
}