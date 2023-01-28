#pragma once
#include "pch.h"
/*
	Title : 햄버거 만들기
	Level : 1
	Question : 132267
*/


//a = empty bottle, b = return bottle, n = the number of bottles
//ex) 2 1 20 = 19
int solution(int a, int b, int n)
{
	int answer{ };

	while (n / a != 0)
	{
		answer += (n / a) * b;
		n = (n / a) * b + (n % a);
	}
	return answer;
}
