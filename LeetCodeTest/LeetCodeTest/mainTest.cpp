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
	int testCondition = 7;

	switch (testCondition)
	{
	case 1:
	{
		//��������Ϊһ�����߶������
		long long a =99999997;
		int b = 3;
		Solution sol;
		bool x = sol.checkPerfectNumber(a);
		break;
	}
	case 2:
	{
		// ��������Ϊ�������
		int nums_arr1[] = { 1,2,3};
		int target = 4;
		vector<int> s;
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		Solution sol;
		vector<vector<int>> res = sol.permute(nums1);
		break;
	}
	case 3:
	{
		// �ַ�������
		string str1 = "23";
		string str2 = "-86+72i";
		Solution sol;
		vector<string> x = sol.letterCombinations(str1);
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
		vector<string> strs({"hot","dot","dog","lot","log","cog"});
		string str1 = "hit";
		string str2 = "cog";
		// strs.push_back(str1);
		// strs.push_back(str2);
		Solution sol;
		int res = sol.ladderLength(str1,str2,strs);
		break;
	}
	case 8:
	{
		//8. ��������Ϊ������
		int nums_arr1[] = { 1,INT_MIN,2,INT_MIN,INT_MIN,3,4 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		Solution sol;
		TreeNode* t=sol.creatTreeLevel(nums1); //  ���ɶ�����
		vector<int> res = sol.boundaryOfBinaryTree(t);
	}
	
	default:
		break;
	}
}
