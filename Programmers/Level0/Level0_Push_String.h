#pragma once
#include "pch.h"

/*
	Title : ���ڿ� �б�
	Level : 0
	Question :
	�Ű����� A�� �� ĭ �� ���������� �Ű��� �� B�� �������� Ƚ���� return�ϴ� �Լ� �ۼ�
*/

int solution(string A, string B)
{
	int answer{ };
	if (A == B)
	{
		return 0;
	}

	for (int i = 0; i < A.size() - 1; i++)
	{
		char tmp = A[A.size() - 1];
		A = A.substr(0, A.size() - 1);
		A = tmp + A;

		answer++;

		if (A == B)
		{
			return answer;
		}

	}
	return -1;
}


/*
	�� ���� �ٸ� ��� Ǯ��
	���ڿ� B�� ���޾� ���� ���ڿ����� A�� �ִ��� ã�´�.
*/
int Ohter_Solution(string A, string B)
{
	B += B;
	return B.find(A);
}