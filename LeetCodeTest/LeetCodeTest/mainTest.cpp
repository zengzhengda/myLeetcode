#include "mainTest.h"

/*
void main()
{
	int k=3;
	int n=7;
	vector<int> nums(n);
	int m=1;
	for(auto it=nums.begin();it!=nums.end();++it)
	{
		*it=m++;
	}
	Solution Sol;
	Sol.rotate(nums,k);
}
*/

//void main()
//{
//	int a=5;
//	Solution sol;
//	vector<vector<int>> p_triangle=sol.generate(a);
//}

void main()
{
	int nums_arr1[]={1,2,4,5};
	vector<int> nums1(nums_arr1,nums_arr1+sizeof(nums_arr1)/sizeof(nums_arr1[0]));
	Solution sol;
	sol.plusOne(nums1);
}