#pragma once
#include "pch.h"

/*
	Title : ���ӵ� ���� ��
	Level : 0
	Question :
	�� ���� num�� total�� �־��� ��, ���ӵ� �� num���� ���� ���� total�� �Ǵ� �迭 or �����͸� ���������� ����ÿ�.
*/

int solution(int common[], size_t common_len)
{
	//������ �� ��
	int answer = common[common_len - 1]; 
	int gap;

	/*
		0, 1, 2�� �̿��� ���� �߾��� �̿�
		TestCase { 1, 2, 4 } �� ���� int�� ������ ������ �νĵ� �� ��������
		���� �߾��� ���� �̻����� �ʵ��� ���� �߰�
	*/
	if ((common[0] + common[2]) % 2 == 0 && (common[0] + common[2]) / 2 == common[1])
	{
		gap = common[1] - common[0];
		answer += gap;
	}
	else
	{
		gap = common[1] / common[0];
		answer *= gap;
	}
	return answer;
}