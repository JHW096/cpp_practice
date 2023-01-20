#pragma once
#include "pch.h"

/*
	Title : 문자열 밀기
	Level : 0
	Question :
	매개변수 A를 한 칸 씩 오른쪽으로 옮겼을 때 B와 같아지는 횟수를 return하는 함수 작성
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
	더 좋은 다른 사람 풀이
	문자열 B를 연달아 붙힌 문자열에서 A가 있는지 찾는다.
*/
int Ohter_Solution(string A, string B)
{
	B += B;
	return B.find(A);
}