#pragma once
#include"pch.h"
/*
	Title : ���� ��ȯ�ϱ�
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

//Ǯ�� Ǯ���µ� �� ���� ���� ����. ���� �뷮�� ū �� ����, ��𼱰� break�� �ɾ��־�� �ϴµ�
//��� ������ �𸣰���. �������� ���������� ��Ʈ��ŷ �غ��� ������, ���� �������� �ذ���� ����.