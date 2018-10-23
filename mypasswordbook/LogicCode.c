#include "LogicCode.h"
extern const char* filename;
extern int g_Count;
extern int g_Maxsize;
void ReadFile(PSBOOK**ppsbook)
{
	FILE* fpFile;
	if (fopen_s(&fpFile, filename, "rb"))
	{
		printf("文件打开失败,你可能需要先创建一个文件!!!\n");
		return;
	}
	fread(&g_Count, sizeof(int), 1, fpFile);
	if (g_Count >= MAXSIZE)        //根据文件大小为结构体分配空间
	{
		*ppsbook = (PSBOOK*)malloc(sizeof(PSBOOK) * (g_Count + 10));
		if (!(*ppsbook))
		{
			printf("内存不足!!!\n");
			return;
		}
		g_Maxsize = g_Count + 10;
	}
	else
	{
		*ppsbook = (PSBOOK*)malloc(sizeof(PSBOOK) * MAXSIZE);
		if (!(*ppsbook))
		{
			printf("内存不足!!!\n");
			return;
		}
		g_Maxsize = MAXSIZE;
	}

	fread(*ppsbook, sizeof(PSBOOK), g_Count, fpFile);
	fclose(fpFile);
	fpFile = NULL;
	Incrypt(*ppsbook);            //解密密码本内容
}
void SaveFile(PSBOOK* psbook)
{
	FILE* fpFile = NULL;
	if (fopen_s(&fpFile, filename, "wb"))
	{
		printf("打开文件失败!!!\n");
		return;
	}
	fwrite(&g_Count, sizeof(int), 1, fpFile);
	Incrypt(psbook);              //加密存放数据
	fwrite(psbook, sizeof(PSBOOK), g_Count, fpFile);
	fclose(fpFile);
	fpFile = NULL;
}
void Incrypt(PSBOOK* psbook)
{
	int nKey = 1;
	int i, j;
	for (i = 0; i < g_Count; i++)
	{
		int webLen = strlen((psbook + i)->webSite);
		int userNameLen = strlen((psbook + i)->userName);
		int pswordLen = strlen((psbook + i)->passWord);
		int infoLen = strlen((psbook + i)->otherInfo);
		for (j = 0; j < webLen; j++)
			(psbook + i)->webSite[j] ^= nKey;
		for (j = 0; j < userNameLen; j++)
			(psbook + i)->userName[j] ^= nKey;
		for (j = 0; j < pswordLen; j++)
			(psbook + i)->passWord[j] ^= nKey;
		for (j = 0; j < infoLen; j++)
			(psbook + i)->otherInfo[j] ^= nKey;
	}
}
void AddInfo(PSBOOK** ppsbook)
{
	printf("你想增加几组数据：\n");
	int nNum = 0;
	scanf_s("%d", &nNum);
	if (nNum + g_Count >= g_Maxsize)
	{
		*ppsbook = (PSBOOK*)realloc(*ppsbook, sizeof(PSBOOK) * (g_Maxsize + nNum));
		if (!(*ppsbook))
		{
			printf("动态增容失败!!!\n");
			return;
		}
		g_Maxsize += nNum;
	}
	while (nNum--)
	{
		puts("请输入网址，用户名，密码和其他信息：");
		scanf_s("%s", (*ppsbook + g_Count)->webSite,
			sizeof((*ppsbook + g_Count)->webSite));
		scanf_s("%s", (*ppsbook + g_Count)->userName,
			sizeof((*ppsbook + g_Count)->userName));
		scanf_s("%s", (*ppsbook + g_Count)->passWord,
			sizeof((*ppsbook + g_Count)->passWord));
		scanf_s("%s", (*ppsbook + g_Count)->otherInfo,
			sizeof((*ppsbook + g_Count)->otherInfo));
		g_Count++;
	}
}
void Dele(PSBOOK* psbook)
{
	if (g_Count == 0)
	{
		puts("已无任何数据!!!");
		return;
	}
	puts("要删除第几组数据：");
	int nDelNum = 0;
	while (!scanf_s("%d", &nDelNum) || nDelNum < 1 || nDelNum > g_Count)    //处理非法输入
	{
		puts("输入有误或者没有这组数据，请重新输入:");
		while (getchar() != '\n')
			;
	}
	if (1 == g_Count)             //处理只有一组数据的情况
	{
		psbook = 0;
	}
	else
	{
		int nIndex;
		for (nIndex = nDelNum - 1; nIndex < g_Count - 1; nIndex++)
		{
			*(psbook + nIndex) = *(psbook + nIndex + 1);
		}
	}
	g_Count--;
}
void Correct(PSBOOK* psbook)
{
	puts("你想修改第几组数据：");
	int nCrtNum = 0;
	while (!scanf_s("%d", &nCrtNum) || nCrtNum < 1 || nCrtNum > g_Count)  //处理非法输入
	{
		puts("输入有误或者没有这组数据，请重新输入:");
		while (getchar() != '\n')
			;
	}
	puts("请输入修改后的网址：");
	scanf_s("%s", (psbook + nCrtNum - 1)->webSite,
		sizeof((psbook + nCrtNum - 1)->webSite));
	puts("请输入修改后的用户名：");
	scanf_s("%s", (psbook + nCrtNum - 1)->userName,
		sizeof((psbook + nCrtNum - 1)->userName));
	puts("请输入修改后的密码：");
	scanf_s("%s", (psbook + nCrtNum - 1)->passWord,
		sizeof((psbook + nCrtNum - 1)->passWord));
	puts("请输入修改后的其他信息：");
	scanf_s("%s", (psbook + nCrtNum - 1)->otherInfo,
		sizeof((psbook + nCrtNum - 1)->otherInfo));
}
void Find(PSBOOK* psbook)
{
	puts("需要查找第几组数据？");
	int nIndex = 0;
	while (!scanf_s("%d", &nIndex) || nIndex < 1 || nIndex > g_Count)    //处理非法输入
	{
		puts("输入有误或者没有这组数据，请重新输入:");
		while (getchar() != '\n')
			;
	}
	printf("网址为：%s\n", psbook->webSite);
	printf("用户名为：%s\n", psbook->userName);
	printf("密码为：%s\n", psbook->passWord);
	printf("其他信息为：%s\n", psbook->otherInfo);
}
void ShowInfo(PSBOOK* psbook)
{
	if (!g_Count)
	{
		printf("没有任何记录。。！\n");
		return;
	}
	int i;
	for (i = 0; i < g_Count; i++)
	{
		printf("--------------------------------------------------"
			"-----------------------------------------------------\n");
		printf("网址：%-16s 用户名：%-16s 密码：%-16s 其他信息：%-16s\n",
			(psbook + i)->webSite,
			(psbook + i)->userName,
			(psbook + i)->passWord,
			(psbook + i)->otherInfo);
	}
	printf("--------------------------------------------------"
		"-----------------------------------------------------\n");
}
void KeywordSearch(PSBOOK*psbook)
{
	printf("请输入你想查找的关键字：\n");
	char keyBuff[32];
	scanf_s("%s", keyBuff, sizeof(keyBuff));
	int nCnt = 0;                                           
	int* nFind = (int*)malloc(sizeof(int) * g_Maxsize);     //开辟空间用于存放已找到的数据索引
	int i;
	for (i = 0; i < g_Count; i++)
	{
		if (strcmp((psbook + i)->webSite, keyBuff) == 0 || strcmp((psbook + i)->userName, keyBuff) == 0
			|| strcmp((psbook + i)->passWord, keyBuff) == 0 || strcmp((psbook + i)->otherInfo, keyBuff) == 0)
		{
			*(nFind + nCnt) = i;
			nCnt++;
		}
	}
	if (0 == nCnt)
	{
		printf("没有该记录!!!\n");
		free(nFind);
		nFind = NULL;
		return;
	}
	printf("搜索记录如下：\n");
	for (i = 0; i < nCnt; i++)
	{
		printf("--------------------------------------------------"
			"-----------------------------------------------------\n");
		printf("%d. 网址：%s\t用户名：%s\t密码：%s\t其他信息：%s\n", 
			i + 1, (psbook + nFind[i])->webSite,
			(psbook + nFind[i])->userName, 
			(psbook + nFind[i])->passWord, 
			(psbook + nFind[i])->otherInfo);
	}
	printf("--------------------------------------------------"
		"-----------------------------------------------------\n");
	free(nFind);
	nFind = NULL;
}