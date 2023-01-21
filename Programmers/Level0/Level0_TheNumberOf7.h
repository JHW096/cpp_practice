#pragma once
#include "pch.h"
/*
	Title : 7�� ����
	Level : 0
	Question :
	�Ű������� �־��� Vector<int> ���� 7�� ���� ���ϱ�
*/

//�迭�� ���ڸ� String���� �ٲپ� ��ģ��, string�� ���� char�� ���� '7' ������ �˻�.
int solution(vector<int> array)
{
	int answer{ };

	string str{ "" };

	for (auto e : array)
	{
		str += to_string(e);
	}

	for (auto e : str)
	{
		if (e == '7')
		{
			answer++;
		}
	}

	return answer;
}
