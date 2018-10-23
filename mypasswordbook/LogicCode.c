#include "LogicCode.h"
extern const char* filename;
extern int g_Count;
extern int g_Maxsize;
void ReadFile(PSBOOK**ppsbook)
{
	FILE* fpFile;
	if (fopen_s(&fpFile, filename, "rb"))
	{
		printf("�ļ���ʧ��,�������Ҫ�ȴ���һ���ļ�!!!\n");
		return;
	}
	fread(&g_Count, sizeof(int), 1, fpFile);
	if (g_Count >= MAXSIZE)        //�����ļ���СΪ�ṹ�����ռ�
	{
		*ppsbook = (PSBOOK*)malloc(sizeof(PSBOOK) * (g_Count + 10));
		if (!(*ppsbook))
		{
			printf("�ڴ治��!!!\n");
			return;
		}
		g_Maxsize = g_Count + 10;
	}
	else
	{
		*ppsbook = (PSBOOK*)malloc(sizeof(PSBOOK) * MAXSIZE);
		if (!(*ppsbook))
		{
			printf("�ڴ治��!!!\n");
			return;
		}
		g_Maxsize = MAXSIZE;
	}

	fread(*ppsbook, sizeof(PSBOOK), g_Count, fpFile);
	fclose(fpFile);
	fpFile = NULL;
	Incrypt(*ppsbook);            //�������뱾����
}
void SaveFile(PSBOOK* psbook)
{
	FILE* fpFile = NULL;
	if (fopen_s(&fpFile, filename, "wb"))
	{
		printf("���ļ�ʧ��!!!\n");
		return;
	}
	fwrite(&g_Count, sizeof(int), 1, fpFile);
	Incrypt(psbook);              //���ܴ������
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
	printf("�������Ӽ������ݣ�\n");
	int nNum = 0;
	scanf_s("%d", &nNum);
	if (nNum + g_Count >= g_Maxsize)
	{
		*ppsbook = (PSBOOK*)realloc(*ppsbook, sizeof(PSBOOK) * (g_Maxsize + nNum));
		if (!(*ppsbook))
		{
			printf("��̬����ʧ��!!!\n");
			return;
		}
		g_Maxsize += nNum;
	}
	while (nNum--)
	{
		puts("��������ַ���û����������������Ϣ��");
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
		puts("�����κ�����!!!");
		return;
	}
	puts("Ҫɾ���ڼ������ݣ�");
	int nDelNum = 0;
	while (!scanf_s("%d", &nDelNum) || nDelNum < 1 || nDelNum > g_Count)    //����Ƿ�����
	{
		puts("�����������û���������ݣ�����������:");
		while (getchar() != '\n')
			;
	}
	if (1 == g_Count)             //����ֻ��һ�����ݵ����
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
	puts("�����޸ĵڼ������ݣ�");
	int nCrtNum = 0;
	while (!scanf_s("%d", &nCrtNum) || nCrtNum < 1 || nCrtNum > g_Count)  //����Ƿ�����
	{
		puts("�����������û���������ݣ�����������:");
		while (getchar() != '\n')
			;
	}
	puts("�������޸ĺ����ַ��");
	scanf_s("%s", (psbook + nCrtNum - 1)->webSite,
		sizeof((psbook + nCrtNum - 1)->webSite));
	puts("�������޸ĺ���û�����");
	scanf_s("%s", (psbook + nCrtNum - 1)->userName,
		sizeof((psbook + nCrtNum - 1)->userName));
	puts("�������޸ĺ�����룺");
	scanf_s("%s", (psbook + nCrtNum - 1)->passWord,
		sizeof((psbook + nCrtNum - 1)->passWord));
	puts("�������޸ĺ��������Ϣ��");
	scanf_s("%s", (psbook + nCrtNum - 1)->otherInfo,
		sizeof((psbook + nCrtNum - 1)->otherInfo));
}
void Find(PSBOOK* psbook)
{
	puts("��Ҫ���ҵڼ������ݣ�");
	int nIndex = 0;
	while (!scanf_s("%d", &nIndex) || nIndex < 1 || nIndex > g_Count)    //����Ƿ�����
	{
		puts("�����������û���������ݣ�����������:");
		while (getchar() != '\n')
			;
	}
	printf("��ַΪ��%s\n", psbook->webSite);
	printf("�û���Ϊ��%s\n", psbook->userName);
	printf("����Ϊ��%s\n", psbook->passWord);
	printf("������ϢΪ��%s\n", psbook->otherInfo);
}
void ShowInfo(PSBOOK* psbook)
{
	if (!g_Count)
	{
		printf("û���κμ�¼������\n");
		return;
	}
	int i;
	for (i = 0; i < g_Count; i++)
	{
		printf("--------------------------------------------------"
			"-----------------------------------------------------\n");
		printf("��ַ��%-16s �û�����%-16s ���룺%-16s ������Ϣ��%-16s\n",
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
	printf("������������ҵĹؼ��֣�\n");
	char keyBuff[32];
	scanf_s("%s", keyBuff, sizeof(keyBuff));
	int nCnt = 0;                                           
	int* nFind = (int*)malloc(sizeof(int) * g_Maxsize);     //���ٿռ����ڴ�����ҵ�����������
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
		printf("û�иü�¼!!!\n");
		free(nFind);
		nFind = NULL;
		return;
	}
	printf("������¼���£�\n");
	for (i = 0; i < nCnt; i++)
	{
		printf("--------------------------------------------------"
			"-----------------------------------------------------\n");
		printf("%d. ��ַ��%s\t�û�����%s\t���룺%s\t������Ϣ��%s\n", 
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