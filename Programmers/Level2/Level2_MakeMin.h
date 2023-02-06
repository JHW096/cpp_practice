#pragma once
#include"pch.h"
/*
	Title : 최솟값 만들기
	Level : 2
	Question : 12941
*/

int solution(vector<int> A, vector<int> B)
{
	int answer{ };

	sort(A.begin(), A.end(), less<int>());
	sort(B.begin(), B.end(), greater<int>());

	answer = inner_product(A.begin(), A.end(), B.begin(), 0);

	return answer;
}
