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

// 测试数据为一个整数
//void main()
//{
//	int a= -1;
//	Solution sol;
//	int b=sol.reverseInteger(a);
//}

// 测试数据为数组
void main()
{
	int nums_arr1[]={1,2,3,5,4,2};
	vector<int> nums1(nums_arr1,nums_arr1+sizeof(nums_arr1)/sizeof(nums_arr1[0]));
	Solution sol;
	int sum=sol.numberOfArithmeticSlices(nums1);
}

// 字符串测试
//void main()
//{
//	string str1 = "1";
//	string str2 = "9";
//	Solution sol;
//	string str3 = sol.multiply(str1, str2);
//}