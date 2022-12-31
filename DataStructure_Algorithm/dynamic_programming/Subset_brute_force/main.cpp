#include"Subset_brute_force.h"

int main(void)
{
	vector<int> set{ 13, 29, 45, 79 };
	int target = 82;
	bool found = SubsetSum_BruteForce(set, target);

	if (found)
	{
		cout << "Found!" << target << endl;
	}
	else
	{
		cout << "Unfound!" << target << endl;
	}
}