#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int UNKNOWN = -1;
const int FOUNDMAX = 1000;

bool SubsetSum_Memoization(vector<int>& set, int sum, int i, vector<vector<int>>& memo)
{
	//백 트랙킹 방법으로 원소들의 값을 하나 씩 빼면서 0이 되면 true
	if (sum == 0)
	{
		return true;
	}

	//반복 횟수가 집합의 수를 넘어가거나, 다음 원소를 뺄 때 그 합계의 수가 더 작다면 false
	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	//cache값이 갱신되지 않았다면,
	if (memo[i][sum] == UNKNOWN)
	{
		//해당 원소를 sum에서 제거 
		bool append = SubsetSum_Memoization(set, sum - set[i], i + 1, memo);
		//해당 값을 유지
		bool ignore = SubsetSum_Memoization(set, sum, i + 1, memo);

		
		memo[i][sum] = append || ignore;
	}
	
	return memo[i][sum];
}
/*
									Fn(58, 0)
	          Fn(45, 1)									 Fn(58, 0)
	Fn(29, 2)			Fn(45, 1)			   Fn(29, 1)           Fn(58, 1)
	False, False       True, False 			True, Fn(29, 2) // Fn(13, 2) Fn(58, 2)

*/

void TEST()
{
	vector<int> set{ 13, 29, 45, 79 };
	int sum = 58;
	vector<vector<int>> memo(set.size(), vector<int>(FOUNDMAX, UNKNOWN));

	bool found = SubsetSum_Memoization(set, sum, 0, memo);

	if (found)
	{
		cout << "Found! : " << sum << endl;
	}
	else
	{
		cout << "unFound" << endl;
	}
	
}