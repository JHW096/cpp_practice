#pragma once
#include "pch.h"
/*
	Title : �߶� �迭�� �����ϱ�
	Level : 0
	Question :
	�־��� ���ڿ��� �־��� ���ڷ� �߶� �迭�� �����ϱ�
*/

vector<string> solution(string my_str, int n)
{
	vector<string> answer;

	string str{ "" };
	for (int i = 0; i < my_str.size(); i++)
	{
		str += my_str[i];
		if (str.size() == n)
		{
			answer.push_back(str);
			str = "";
		}
	}
	
	if (str[0] != NULL)
	{
		answer.push_back(str);
	}

	return answer;
}

/*
	ó������ substr�� ���������� ���� ���ڿ����� �˾Ƽ� ó���������� ������.
*/
vector<string> OtherSolution(string my_str, int n)
{
	vector<string> answer;
	for (int i = 0; i < my_str.size(); i+=n)
	{
		answer.push_back(my_str.substr(i, n));
	}

}