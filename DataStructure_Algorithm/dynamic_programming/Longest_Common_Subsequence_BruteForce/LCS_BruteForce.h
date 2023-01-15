#pragma once
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>

/*
	Longest Common Subsequence : 두 문자열 중에서 가장 긴 공통 부분을 찾는다. 문자열 순서는 바뀌지 않는다.
*/

using namespace std;

vector<vector<pair<int, int>>> found;

int LCS_BruteForce(string A, string B, int i, int j, vector<pair<int, int>> subsequence)
{
	//두 문자열 중, 하나의 문자열의 크기라도 넘어간다면, 
	if (i >= A.size() || j >= B.size())
	{
		//부분 시퀀스를 Found에 넣고 시퀀스의 사이즈를 리턴
		found.push_back(subsequence); 

		return subsequence.size();
	}

	//문자가 같은 부분을 찾는다면,
	if (A[i] == B[j])
	{
		//부분 시퀀스를 넣고
		subsequence.push_back({ i, j });

		//두 문자열의 다음 문자를 확인한다.
		return LCS_BruteForce(A, B, i + 1, j + 1, subsequence);
	}
	
	//문자가 같은 부분이 없다면,
	//A 문자열의 다음 부분과 B 문자부분을 확이한 부분, B문자열의 다음 부분과 A문자열을 확인 한 부분 중
	//가장 큰 부분을 return한다.
	return max(
		LCS_BruteForce(A, B, i + 1, j, subsequence),
		LCS_BruteForce(A, B, i, j + 1, subsequence)	
		);
}


void PrintSubsequence(string A, string B)
{
	//subsequence의 크기가 작은 대로
	sort(found.begin(), found.end(), [](auto a, auto b)
	{
		if (a.size() != b.size())
		{
			return a.size() < b.size();
		}
		return a < b;
	});

	//BruteForce과정 중 중복된 것들 제거
	found.erase(unique(found.begin(), found.end()), found.end());

	int previousSize{ };

	//SubSequence Size별 출력
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