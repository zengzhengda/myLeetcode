#include "mainTest.h"

void main()
{
	//1. 测试数据为一个或者多个整数
	//2. 测试数据为数组和数
	//3. 字符串测试
	//4. 测试数据为两个数组
	int testCondition = 2;
	switch (testCondition)
	{
	case 1:
	{
		//测试数据为一个或者多个整数
		int a = 3;
		int b = 3;
		Solution sol;
		string x = sol.getPermutation(a,b);
		break;
	}
	case 2:
	{
		// 测试数据为数组和数
		int nums_arr1[] = { 5,5,1,7,1,1,5,2,7,6 };
		int target = 10;
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		Solution sol;
		int x = sol.trap(nums1);
		break;
	}
	case 3:
	{
		// 字符串测试
		string str1 = "1";
		string str2 = "9";
		Solution sol;
		string str3 = sol.multiply(str1, str2);
		break;
	}
	case 4:
	{
		// 测试数据为两个数组
		int nums_arr1[] = { 1,2 };
		int nums_arr2[] = { 3,4 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));
		Solution sol;
		double x = sol.findMedianSortedArrays(nums1, nums2);
		break;
	}
	default:
		break;
	}
}
