#pragma once
#include<iostream>
#include<vector>

using namespace std;
//normal Fibonacci
int Fibonacci(int n)
{
	if (n < 2)
	{
		return n;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//memoization
const int UNKNOWN = -1;
const int MAX_SIZE = 100;

vector<int> memo(MAX_SIZE, UNKNOWN);
int Fibonacci2(int n)
{
	if (n < 2)
	{
		return n;
	}

	if (memo[n] != UNKNOWN)
	{
		return memo[n];
	}

	int result = Fibonacci2(n - 1) + Fibonacci2(n - 2);
	memo[n] = result;

	return result;
}

//tabulation
int Fibonacci3(int n)
{
	vector<int> DP(n + 1, 0);
	DP[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	return DP[n];

}