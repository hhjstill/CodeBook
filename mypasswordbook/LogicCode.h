#pragma once
#include "DataType.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************************************
// Method:    ReadFile
// Descrition:��ȡ���뱾����
// Parameter: PSBOOK * *
//************************************
void ReadFile(PSBOOK**);
//************************************
// Method:    SaveFile
// Descrition:�������ݵ����뱾
// Parameter: PSBOOK *
//************************************
void SaveFile(PSBOOK*);
//************************************
// Method:    Incrypt
// Descrition:���ܽ���
// Parameter: PSBOOK *
//************************************
void Incrypt(PSBOOK*);
//************************************
// Method:    AddInfo
// Descrition:�������
// Parameter: PSBOOK * *
//************************************
void AddInfo(PSBOOK**);
//************************************
// Method:    Dele
// Descrition:ɾ��ָ��λ�õ�����
// Parameter: PSBOOK *
//************************************
void Dele(PSBOOK*);
//************************************
// Method:    Correct
// Descrition:�޸�ָ��λ�õ�����
// Parameter: PSBOOK *
//************************************
void Correct(PSBOOK*);
//************************************
// Method:    Find
// Descrition:����ָ��λ�õ�����
// Parameter: PSBOOK *
//************************************
void Find(PSBOOK*);
//************************************
// Method:    ShowInfo
// Descrition:��ʾ������Ϣ
// Parameter: PSBOOK *
//************************************
void ShowInfo(PSBOOK*);
//************************************
// Method:    KeywordSearch
// Descrition:�ؼ�������
// Parameter: PSBOOK *
//************************************
void KeywordSearch(PSBOOK*);
