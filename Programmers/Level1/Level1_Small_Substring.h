#pragma once
#include "pch.h"
/*
	Title : ũ�Ⱑ ���� �κ� ���ڿ�
	Level : 1
	Question :
	���������� ���� ��ȣ 147355 Ȯ��
*/

int solution(string t, string p)
{
	int answer{ };
	for (int i = 0; i <= t.size() - p.size(); i++)
	{
		t.substr(i, p.size()) <= p ? answer++ : answer;
	}
	return answer;
}