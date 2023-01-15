#include "LCS_BruteForce.h"

int main(void)
{
	string A{ "ABCXY" };
	string B{ "ACYX" };
	int lcs = LCS_BruteForce(A, B, 0, 0, {});
	cout << A << "와 " << B << " 의 최장 공통 부분 시퀀스 길이 : " << lcs << endl;
	cout << "Subsequence Print" << endl;
	PrintSubsequence(A, B);
}