#pragma once
#include "pch.h"
/*
	Title : ¼ýÀÚ Â¦±Ã
	Level : 1
	Question : 131128
*/

string solution(string X, string Y)
{
	string answer{ "" };
	vector<string> vecX(10, "");
	vector<string> vecY(10, "");
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < X.size(); j++)
		{
			if (i == X[j] - 48)
			{
				vecX[i] += X[j];
			}
		}

		for (int k = 0; k < Y.size(); k++)
		{
			if (i == Y[k] - 48)
			{
				vecY[i] += Y[k];
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (vecX[i].size() == 0 || vecY[i].size() == 0)
		{
			continue;
		}
		vecX[i].size() <= vecY[i].size() ? answer += vecX[i] : answer += vecY[i];
	}

	sort(answer.begin(), answer.end(), greater<char>());

	if (answer == "")
	{
		answer += "-1";
	}
	if (answer[0] == '0')
	{
		answer = "0";
	}

	return answer;
}