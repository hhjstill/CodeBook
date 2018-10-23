#pragma once
#include "DataType.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************************************
// Method:    ReadFile
// Descrition:读取密码本内容
// Parameter: PSBOOK * *
//************************************
void ReadFile(PSBOOK**);
//************************************
// Method:    SaveFile
// Descrition:保存内容到密码本
// Parameter: PSBOOK *
//************************************
void SaveFile(PSBOOK*);
//************************************
// Method:    Incrypt
// Descrition:加密解密
// Parameter: PSBOOK *
//************************************
void Incrypt(PSBOOK*);
//************************************
// Method:    AddInfo
// Descrition:添加数据
// Parameter: PSBOOK * *
//************************************
void AddInfo(PSBOOK**);
//************************************
// Method:    Dele
// Descrition:删除指定位置的密码
// Parameter: PSBOOK *
//************************************
void Dele(PSBOOK*);
//************************************
// Method:    Correct
// Descrition:修改指定位置的密码
// Parameter: PSBOOK *
//************************************
void Correct(PSBOOK*);
//************************************
// Method:    Find
// Descrition:查找指定位置的密码
// Parameter: PSBOOK *
//************************************
void Find(PSBOOK*);
//************************************
// Method:    ShowInfo
// Descrition:显示所有信息
// Parameter: PSBOOK *
//************************************
void ShowInfo(PSBOOK*);
//************************************
// Method:    KeywordSearch
// Descrition:关键字搜索
// Parameter: PSBOOK *
//************************************
void KeywordSearch(PSBOOK*);
