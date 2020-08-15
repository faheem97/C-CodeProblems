#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void ArrayContainsDuplicate();

int main()
{
	//ArrayContainsDuplicate();

	return 0;
}

#pragma region ArrayContainsDuplicate  //used unordered_set and vector

bool ContainsDuplicate(vector<int> nums);

void ArrayContainsDuplicate()
{
	vector<int> arrayOfNums;
	int arraySize;

	cout << "\n Enter the size of the list : ";
	cin >> arraySize;
	cout << endl;

	cout << "\n Enter the list of Numbers : ";
	for (int i = 0; i < arraySize; i++)
	{
		int n;
		cin >> n;
		arrayOfNums.push_back(n);
	}
	cout << endl;
/*
	cout << "\n The Given list of Numbers : ";
	for (int i = 0; i < arraySize; i++)
	{
		cout << arrayOfNums[i] << " ";
	}
	cout << endl;*/

	if (ContainsDuplicate(arrayOfNums))
	{
		cout << "\n The List contains Duplicate entries! \n";
	}
	else
	{
		cout << "\n The List contains all Unique Numbers \n";
	}
}

bool ContainsDuplicate(vector<int> nums)
{
	unordered_set<int> duplicateCheckList;

	for (int a : nums)
	{
		if (!duplicateCheckList.count(a))
		{
			duplicateCheckList.insert(a);
		}
		else
		{
			return true;
		}
	}

	return false;
}

#pragma endregion		
