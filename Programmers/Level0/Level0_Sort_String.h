#pragma once
#include "pch.h"
/*
	Title : ���ڿ� �����ϱ�
	Level : 0
	Question :
	�Ű������� �־��� string�� �ҹ��ڷ� ��ȯ�ϰ� ���ĺ� ������ �����Ͻÿ�.
*/

string solution(string my_string)
{
	string answer{ "" };

	for (auto& ch : my_string)
	{
		ch = tolower(ch);
	}

	sort(my_string.begin(), my_string.end(), less<char>());

	answer = my_string;

	return answer;
}