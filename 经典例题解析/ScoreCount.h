#pragma once

double Cal_Score(int* score, int* judge_type, int n)
{
	int Sumofgeneral = 0;
	int Count1 = 0;
	int Sumofprofessor = 0;
	int Count2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (judge_type[i] == 1)
		{
			Sumofgeneral += score[i];
			Count1++;
		}
		else
		{
			Sumofprofessor += score[i];
			Count2++;
		}
	}

	double Averagegeneral = 0.0;
	double Averageprofessor = 0.0;

	if (Count1)  //普通评委为不零
		Averagegeneral = Sumofgeneral / Count1;
	if (Count2)  //专家评委不为零
		Averageprofessor = Sumofprofessor / Count2;

	return (Averagegeneral*0.4 + Averageprofessor*0.6);
}

void Test()
{
	int mark[] = { 20, 30, 40, 50, 60 };
	//int type[] = { 1, 1, 1, 2, 2 };
	//int type[] = { 1, 1, 1, 1, 1 };
	int type[] = { 2, 2, 2, 2, 2 };
	cout << Cal_Score(mark, type, 5) << endl;
}