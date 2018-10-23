#include <stdio.h>
#include "MenuUi.h"
#include "DataType.h"
#include "InitPsBook.h"
#include "LogicCode.h"
int main()
{
	PSBOOK* psbook = NULL;
	ShowMenu();
	int nChoice = 0;
	printf("��������Ӧ���֣�\n");
	//�����û��������
	do
	{
		while (!scanf_s("%d", &nChoice) || nChoice < 0 || nChoice > 9)//..����Ƿ�����
		{															  //..
			printf("�����������������룺\n");						  //..
			while (getchar() != '\n')								  //..
				;													  //..
		}															  //..
		switch (nChoice)
		{
		case 1:
			InitBook();
			break;
		case 2:
			ReadFile(&psbook);
			break;
		case 3:
			SaveFile(psbook);
			break;
		case 4:
			ShowInfo(psbook);
			break;
		case 5:
			AddInfo(&psbook);
			break;
		case 6:
			Dele(psbook);
			break;
		case 7:
			Correct(psbook);
			break;
		case 8:
			Find(psbook);
			break;
		case 9:
			KeywordSearch(psbook);
			break;
		case 0:
			printf("�����˳�ϵͳ���ټ�!!!\n");
			return;
		default:
			printf("δ֪���������˳�!!!\n");
			return;
		}
		printf("�㻹��ִ��ʲô����,�������ţ�");
	} while (1);
	return 0;
}
