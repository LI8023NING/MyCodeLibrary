#ifndef _ALLSHENGMING_H
#define _ALLSHENGMING_H

#include"StartDefine.h"

/////////////////////////////////////////////////////
//���˵���������
void CalShow(CDateTime *dt);
void CalSelect(CDateTime *dt);
void UpdateCal(CDateTime *dt);
void NotForgetNote(CDateTime *dt);
void HelpMassage();
///////////////////////////////////////////////////
//��ʾ�˵���������
void ShowNowDate(CDateTime *dt);
void ShowNowTime(CDateTime *dt);
void ShowDateTime(CDateTime *dt);
void ShowDnyDateTime(CDateTime *dt);
void ShowCalTable(CDateTime *dt);
//////////////////////////////////////////////////////
//��ѯ������������
void SelectNowDate(CDateTime *dt);
void SelectNowTime(CDateTime *dt);
void SelectDateTime(CDateTime *dt);
void SelectWeek(CDateTime *dt);
void SelectLastNday(CDateTime *dt);
void SelectNextNday(CDateTime *dt);
void SelectFutureDay(CDateTime *dt);
////////////////////////////////////////////////////////
//����¼��������
void NewBuildNote(CDateTime *dt);
void SelectNote(CDateTime *dt);
void UpdateNote(CDateTime *dt);
////////////////////////////////////////////////////////
//�޸����ں�������
void UpdateCal(CDateTime *dt);
//////////////////////////////////////////////////////////
//����¼
void NotForgetNote(CDateTime *dt);
//////////////////////////////////////////////////////////
//������Ϣ
void HelpMassage(CDateTime *dt);
//////////////////////////////////////////////////////////
//������ʼ��
void InitDateTime(CDateTime *dt);
/////////////////////////////////////////////////////////
//�õ�ϵͳʱ��
void GetNowDateTime(CDateTime *dt);

int GetDays(int year, int month);




#endif