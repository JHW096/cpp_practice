#pragma once
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>

/*
	Longest Common Subsequence : �� ���ڿ� �߿��� ���� �� ���� �κ��� ã�´�. ���ڿ� ������ �ٲ��� �ʴ´�.
*/

using namespace std;

vector<vector<pair<int, int>>> found;

int LCS_BruteForce(string A, string B, int i, int j, vector<pair<int, int>> subsequence)
{
	//�� ���ڿ� ��, �ϳ��� ���ڿ��� ũ��� �Ѿ�ٸ�, 
	if (i >= A.size() || j >= B.size())
	{
		//�κ� �������� Found�� �ְ� �������� ����� ����
		found.push_back(subsequence); 

		return subsequence.size();
	}

	//���ڰ� ���� �κ��� ã�´ٸ�,
	if (A[i] == B[j])
	{
		//�κ� �������� �ְ�
		subsequence.push_back({ i, j });

		//�� ���ڿ��� ���� ���ڸ� Ȯ���Ѵ�.
		return LCS_BruteForce(A, B, i + 1, j + 1, subsequence);
	}
	
	//���ڰ� ���� �κ��� ���ٸ�,
	//A ���ڿ��� ���� �κа� B ���ںκ��� Ȯ���� �κ�, B���ڿ��� ���� �κа� A���ڿ��� Ȯ�� �� �κ� ��
	//���� ū �κ��� return�Ѵ�.
	return max(
		LCS_BruteForce(A, B, i + 1, j, subsequence),
		LCS_BruteForce(A, B, i, j + 1, subsequence)	
		);
}


void PrintSubsequence(string A, string B)
{
	//subsequence�� ũ�Ⱑ ���� ���
	sort(found.begin(), found.end(), [](auto a, auto b)
	{
		if (a.size() != b.size())
		{
			return a.size() < b.size();
		}
		return a < b;
	});

	//BruteForce���� �� �ߺ��� �͵� ����
	found.erase(unique(found.begin(), found.end()), found.end());

	int previousSize{ };

	//SubSequence Size�� ���
	for (auto subsequence : found)
	{
		if (subsequence.size() != previousSize)
		{
			previousSize = subsequence.size();
			cout << "SIZE = " << previousSize << endl;
		}
		string a_seq(A.size(), '_');
		string b_seq(B.size(), '_');

		for (auto pair : subsequence)
		{
			a_seq[pair.first] = A[pair.first];
			b_seq[pair.second] = B[pair.second];
		}
		cout << "\t" << a_seq << " " << b_seq << endl; 
	}

}