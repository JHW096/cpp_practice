#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<bool>> subsetSum_Tabulation(vector<int>& set)
{
	//�κ� ������ �� ��
	size_t maxSum{ };

	for (size_t i = 0; i < set.size(); i++)
	{
		maxSum += set[i];
	}

	//Data set.size() + 1 * maxSu + 1, Value = all false;
	vector<vector<bool>> DP(set.size() + 1, vector<bool>(maxSum + 1, 0));

	//�ʱⰪ
	for (size_t i = 0; i < set.size(); i++)
	{
		DP[i][0] = true;
	}

	//��� Data�� ���ؼ�
	for (size_t i = 1; i <= set.size(); i++)
	{
		for (size_t sum = 1; sum <= maxSum; sum++)
		{
			//������ ����, ������ �� �κ��� True�� ��. ù True�� �ش� sum�� �ʱⰪ�� or�����Ͽ� True
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