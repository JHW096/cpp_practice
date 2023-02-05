#pragma once
#include"pch.h"
/*
	Title : 숫자 변환하기
	Level : 1
	Question : 154538
*/

int memo[1000001];
int soluiotn(int x, int y, int n)
{
	fill(memo, memo + 1000001, -1);
	memo[x] = 0;
	queue<int> queue;
	queue.push(x);

	while (!queue.empty())
	{
		int current = queue.front();
		queue.pop();
		for (auto e : { current + n, current * 2, current * 3 })
		{
			if (e > y) continue;
			if (memo[e] != -1) continue;
			memo[e] = memo[current] + 1;
			queue.push(e);
		}
	}
	return memo[y];
}

//풀긴 풀었는데 썩 맘에 들진 않음. 저장 용량도 큰 것 같고, 어디선가 break를 걸어주어야 하는데
//어떻게 걸지는 모르겠음. 나머지와 나눗셈으로 백트랙킹 해보고 싶은데, 가상 문제에서 해결되지 않음.