#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<bool>> subsetSum_Tabulation(vector<int>& set)
{
	//부분 집합의 총 합
	size_t maxSum{ };

	for (size_t i = 0; i < set.size(); i++)
	{
		maxSum += set[i];
	}

	//Data set.size() + 1 * maxSu + 1, Value = all false;
	vector<vector<bool>> DP(set.size() + 1, vector<bool>(maxSum + 1, 0));

	//초기값
	for (size_t i = 0; i < set.size(); i++)
	{
		DP[i][0] = true;
	}

	//모든 Data에 대해서
	for (size_t i = 1; i <= set.size(); i++)
	{
		for (size_t sum = 1; sum <= maxSum; sum++)
		{
			//집합의 원소, 집합의 합 부분이 True가 됨. 첫 True는 해당 sum이 초기값과 or연산하여 True
			if (sum < set[i - 1])
			{
				DP[i][sum] = DP[i - 1][sum];
			}
			else
			{
				DP[i][sum] = DP[i - 1][sum] || DP[i - 1][sum - set[i - 1]];
			}
		}
	}
	return DP;
}

void TEST()
{
	vector<int> set{ 13, 29, 45, 79 };
	
	vector<vector<bool>> DP = subsetSum_Tabulation(set);
	int target{ 58 };

	bool found = DP[set.size()][target];

	if (found)
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "unfound" << endl;
	}
	
}