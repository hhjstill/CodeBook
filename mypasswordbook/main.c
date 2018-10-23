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
	printf("请输入相应数字：\n");
	//接收用户输入操作
	do
	{
		while (!scanf_s("%d", &nChoice) || nChoice < 0 || nChoice > 9)//..处理非法操作
		{															  //..
			printf("输入有误，请重新输入：\n");						  //..
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
			printf("你已退出系统，再见!!!\n");
			return;
		default:
			printf("未知错误，你已退出!!!\n");
			return;
		}
		printf("你还想执行什么功能,请输入编号：");
	} while (1);
	return 0;
}
