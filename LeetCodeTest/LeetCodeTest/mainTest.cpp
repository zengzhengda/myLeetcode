#include "mainTest.h"

void main()
{
	//1. 测试数据为一个或者多个整数
	//2. 测试数据为数组和数
	//3. 字符串测试
	//4. 测试数据为两个数组
	//5. 测试数据为矩阵
	//6. 测试数据为单链表
	int testCondition = 6;
	switch (testCondition)
	{
	case 1:
	{
		//测试数据为一个或者多个整数
		long long a =15;
		int b = 3;
		Solution sol;
		long long x = sol.climbStairs(a);
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
	case 5:
	{
		// 测试数据为矩阵
		vector<vector<int>> matrix;
		matrix.push_back({0,0,0,5});
		matrix.push_back({ 4,3,1,4 });
		matrix.push_back({ 0,1,1,4 });
		matrix.push_back({ 1,2,1,3 });
		matrix.push_back({ 0,0,1,1 });
		Solution sol;
		sol.setZeroes(matrix);
		break;
	}
	case 6:
	{
		//6. 测试数据为单链表
		int nums_arr1[] = { 1,2,3};
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));

		int nums_arr2[] = { 8,6,3 };
		vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));

		Solution sol;
		ListNode* l1 = sol.LinkListCreatT(nums1);
		ListNode* l2 = sol.LinkListCreatT(nums2);
		ListNode* l_sum = sol.addTwoNumbers(l1, l2);
		break;
	}
	default:
		break;
	}
}
