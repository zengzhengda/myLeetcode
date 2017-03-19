#include "mainTest.h"

void main()
{
	//1. ��������Ϊһ�����߶������
	//2. ��������Ϊ�������
	//3. �ַ�������
	//4. ��������Ϊ��������
	//5. ��������Ϊ����
	//6. ��������Ϊ������
	//7. ��������Ϊ�ַ���������
	//8. ��������Ϊ������
	int testCondition = 8;
	switch (testCondition)
	{
	case 1:
	{
		//��������Ϊһ�����߶������
		long long a =15;
		int b = 3;
		Solution sol;
		long long x = sol.climbStairs(a);
		break;
	}
	case 2:
	{
		// ��������Ϊ�������
		int nums_arr1[] = { -2,1,-3,4,-1,2,1,-5,4 };
		int target = 10;
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		Solution sol;
		int res = sol.maxSubArray(nums1);
		break;
	}
	case 3:
	{
		// �ַ�������
		string str1 = "babad";
		string str2 = "11";
		Solution sol;
		string x = sol.longestPalindrome(str1);
		break;
	}
	case 4:
	{
		// ��������Ϊ��������
		int nums_arr1[] = { 1,2,4,5,3,6,7 };
		int nums_arr2[] = { 4,2,5,1,6,3,7 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));
		Solution sol;
		TreeNode* root = sol.buildTree(nums1, nums2);
		break;
	}
	case 5:
	{
		// ��������Ϊ����
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
		//6. ��������Ϊ������ ָ���Ӧ��ʵ����̫�鷳��
		int nums_arr1[] = { 0,2,3,4};
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));

		int nums_arr2[] = { 1 };
		vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));

		int m = 1;
		int n = 2;
		Solution sol;
		ListNode* l1 = sol.LinkListCreatT(nums1);
		ListNode* l2 = sol.LinkListCreatT(nums2);

		ListNode* l_sum = sol.mergeTwoLists(l1,l2);
		break;
	}
	case 7:
	{
		//7. ��������Ϊ�ַ���������
		vector<string> strs;
		string str1 = "a";
		string str2 = "b";
		strs.push_back(str1);
		strs.push_back(str2);
		Solution sol;
		string str = sol.longestCommonPrefix(strs);
	}
	case 8:
	{
		//8. ��������Ϊ������
		int nums_arr1[] = { 5,2,13 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		Solution sol;
		TreeNode* t=sol.creatTreeLevel(nums1); //  ���ɶ�����
		TreeNode* res = sol.convertBST(t);
	}
	
	default:
		break;
	}
}
