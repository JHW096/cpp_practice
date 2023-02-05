#pragma once
#include"pch.h"
/*
	Title : ÃÖ´ñ°ª°ú ÃÖ¼Ú°ª
	Level : 2
	Question : 154538
*/

string solution(string s)
{
	string answer{ ""};

	s[0] = toupper(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		s[i - 1] == ' ' ? s[i] = toupper(s[i]) : s[i] = tolower(s[i]);
	}
	answer = s;
	return answer;
}