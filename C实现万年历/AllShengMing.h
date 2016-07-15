#ifndef _ALLSHENGMING_H
#define _ALLSHENGMING_H

#include"StartDefine.h"

/////////////////////////////////////////////////////
//主菜单声明部分
void CalShow(CDateTime *dt);
void CalSelect(CDateTime *dt);
void UpdateCal(CDateTime *dt);
void NotForgetNote(CDateTime *dt);
void HelpMassage();
///////////////////////////////////////////////////
//显示菜单声明部分
void ShowNowDate(CDateTime *dt);
void ShowNowTime(CDateTime *dt);
void ShowDateTime(CDateTime *dt);
void ShowDnyDateTime(CDateTime *dt);
void ShowCalTable(CDateTime *dt);
//////////////////////////////////////////////////////
//查询函数声明部分
void SelectNowDate(CDateTime *dt);
void SelectNowTime(CDateTime *dt);
void SelectDateTime(CDateTime *dt);
void SelectWeek(CDateTime *dt);
void SelectLastNday(CDateTime *dt);
void SelectNextNday(CDateTime *dt);
void SelectFutureDay(CDateTime *dt);
////////////////////////////////////////////////////////
//备忘录函数声明
void NewBuildNote(CDateTime *dt);
void SelectNote(CDateTime *dt);
void UpdateNote(CDateTime *dt);
////////////////////////////////////////////////////////
//修改日期函数声明
void UpdateCal(CDateTime *dt);
//////////////////////////////////////////////////////////
//备忘录
void NotForgetNote(CDateTime *dt);
//////////////////////////////////////////////////////////
//帮助消息
void HelpMassage(CDateTime *dt);
//////////////////////////////////////////////////////////
//声明初始化
void InitDateTime(CDateTime *dt);
/////////////////////////////////////////////////////////
//得到系统时间
void GetNowDateTime(CDateTime *dt);

int GetDays(int year, int month);




#endif