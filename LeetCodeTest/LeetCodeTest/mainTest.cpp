#include "mainTest.h"

void main()
{
	//1. ��������Ϊһ�����߶������
	//2. ��������Ϊ�������
	//3. �ַ�������
	//4. ��������Ϊ��������
	int testCondition = 2;
	switch (testCondition)
	{
	case 1:
	{
		//��������Ϊһ�����߶������
		int a = 3;
		int b = 3;
		Solution sol;
		string x = sol.getPermutation(a,b);
		break;
	}
	case 2:
	{
		// ��������Ϊ�������
		int nums_arr1[] = { 5,5,1,7,1,1,5,2,7,6 };
		int target = 10;
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		Solution sol;
		int x = sol.trap(nums1);
		break;
	}
	case 3:
	{
		// �ַ�������
		string str1 = "1";
		string str2 = "9";
		Solution sol;
		string str3 = sol.multiply(str1, str2);
		break;
	}
	case 4:
	{
		// ��������Ϊ��������
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
