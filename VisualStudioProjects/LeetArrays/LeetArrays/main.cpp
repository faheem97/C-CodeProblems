#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void ArrayContainsDuplicate();
void SingleInCouples();
void IntersectionOfTwoArrays();
void PlusOneOnInteger();

void NeedleInHaystack(); //strings used 
void TwoSumProblem();


int main()
{
	//	ArrayContainsDuplicate();
	//  SingleInCouples();
	//	IntersectionOfTwoArrays();
	//  PlusOneOnInteger();
	TwoSumProblem();
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

#pragma region SingleInCouples  //uses bitwise XOR 

int SingleNumber(vector<int> nums);

void SingleInCouples()
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

	int s = SingleNumber(arrayOfNums);

	if (s == -1)
	{
		cout << "\n The List contains no single elements! \n";
	}
	else
	{
		cout << "\n The Single Element : " << s << "\n";
	}
}

int SingleNumber(vector<int> nums)
{
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << "Nums[" << i << "] : " << nums[i] << endl;
		res ^= nums[i];
		cout << "Res : " << res << endl;
	}
	return res;
}

#pragma endregion	

#pragma region Intersection Of Two Arrays //uses sort() function must include algorithm header

vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

void IntersectionOfTwoArrays()
{
	vector<int> firstArrayOfNums;
	int firstArraySize;

	cout << "\n Enter the size of the list 1 : ";
	cin >> firstArraySize;
	cout << endl;

	cout << "\n Enter the list of Numbers : ";
	for (int i = 0; i < firstArraySize; i++)
	{
		int n;
		cin >> n;
		firstArrayOfNums.push_back(n);
	}
	cout << endl;

	vector<int> secondArrayOfNums;
	int secondArraySize;

	cout << "\n Enter the size of the list 2 : ";
	cin >> secondArraySize;
	cout << endl;

	cout << "\n Enter the list of Numbers : ";
	for (int i = 0; i < secondArraySize; i++)
	{
		int n;
		cin >> n;
		secondArrayOfNums.push_back(n);
	}
	cout << endl;

	vector<int> mergedArray = intersect(firstArrayOfNums, secondArrayOfNums);
	//or
	//vector<int> mergedArray;
	//set_intersection(firstArrayOfNums.begin(),firstArrayOfNums.end(),secondArrayOfNums.begin(),secondArrayOfNums.end(),mergedArray);

	cout << "\n The Merged list of Numbers : ";
	for (int i = 0; i < mergedArray.size(); i++)
	{
		cout << mergedArray[i] << " ";
	}
	cout << endl;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	vector<int> res;
	int idx1 = 0;
	int idx2 = 0;
	int n1 = nums1.size();
	int n2 = nums2.size();

	while (idx1 < n1  && idx2 < n2)
	{
		int k = nums1[idx1];
		int l = nums2[idx2];

		if (k == l)
		{
			res.push_back(k);
			idx1++, idx2++;
		}
		else if (k > l)
		{
			idx2++;
		}
		else
		{
			idx1++;
		}
	}
	return res;
}

#pragma endregion

#pragma region PlusOneOnInteger

vector<int> plusOne(vector<int>& digits);

void PlusOneOnInteger()
{
	vector<int> arrayOfNums;
	int arraySize;

	cout << "\n Enter the size of the array : ";
	cin >> arraySize;
	cout << endl;

	cout << "\n Enter the list of Numbers Depicting a Positive Integer : ";
	for (int i = 0; i < arraySize; i++)
	{
		int n;
		cin >> n;
		arrayOfNums.push_back(n);
	}
	cout << endl;

	vector<int> nextIntArray = plusOne(arrayOfNums);

	cout << "\n The Next Integer as Array is : ";
	for (int i = 0; i < nextIntArray.size(); i++)
	{
		cout << nextIntArray[i] << " ";
	}
	cout << endl;
}

vector<int> plusOne(vector<int>& digits)
{
	vector<int> nextInt = { 1 };

	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i] += 1;
			return digits;
			break;
		}
		nextInt.push_back(0);
	}

	return nextInt;

}

#pragma endregion	

#pragma region TwoSumProblem 

/*
given an array and a targetInt find two elements that
sum up to the targetInt and return thier indices
*/

vector<int> twoSum(vector<int>& nums, int target);

void TwoSumProblem()
{
	vector<int> arrayOfNums;
	int arraySize;
	int target;

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

	cout << "\n Enter the target integer : ";
	cin >> target;
	cout << endl;

	vector<int> resultantIndeces = twoSum(arrayOfNums, target);
	
	cout << "\n The Resultant Indeces : ";
	for (int i = 0; i < resultantIndeces.size(); i++)
	{
		cout << resultantIndeces[i] << " ";
	}
	cout << endl;

}

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> tempMap;

	//cout << "The Two values are : " << tempMap.count(nums[2]) << " " << 1;

	for (int i = 0; i < nums.size(); i++)
	{
		int complement = target - nums[i];
		cout << "Complement : " << complement << " count : " << tempMap.count(complement);
		
		if (tempMap.count(complement))
			cout << "The Two values are : " << tempMap.count(complement) << " " << nums[i];
		
		//tempMap.insert(nums[i], i);
	}


	/*for(int i =0;i<nums.size();i++)
	{
		tempMap.insert(nums[i],i);
	}

	for(int i = 0;i<nums.size();i++)
	{
		int complement = target - nums[i];
		
		if((tempMap.find(complement)!= tempMap.end()) && tempMap.count(i)!=i)
		{
			return {i,tempMap.find(i)};
		}
	}*/

	return {};
}

#pragma endregion





