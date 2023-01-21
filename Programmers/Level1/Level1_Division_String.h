#pragma once
#include "pch.h"
/*
	Title : 문자열 나누기
	Level : 1
	Question : 140108
*/


int solution(string s)
{
	int answer{ };
	char x = s[0];
	int i{ }, x_count{ }, other_count{ };
	string str = s;
	while (str[i] != NULL)
	{
		x == str[i] ? x_count++ : other_count++;
		i++;
		if (x_count == other_count)
		{
			answer++;
			str = str.substr(i, str.size());
			i = 0;
			x = str[0];
			x_count = 0; 
			other_count = 0;
		}
	}

	if (str[0] != NULL)
	{
		answer++;
	}

	return answer;
}