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

// ��������Ϊһ������
//void main()
//{
//	int a= -1;
//	Solution sol;
//	int b=sol.reverseInteger(a);
//}

//// ��������Ϊ����
//void main()
//{
//	int nums_arr1[]={ 3,1};
//	int target = 1;
//	vector<int> nums1(nums_arr1,nums_arr1+sizeof(nums_arr1)/sizeof(nums_arr1[0]));
//	Solution sol;
//	bool sum=sol.search2(nums1,target);
//}

// �ַ�������
//void main()
//{
//	string str1 = "1";
//	string str2 = "9";
//	Solution sol;
//	string str3 = sol.multiply(str1, str2);
//}

// ��������Ϊ��������
void main()
{
	int nums_arr1[]={ 1,2};
	int nums_arr2[] = { 3,4 };
	vector<int> nums1(nums_arr1,nums_arr1+sizeof(nums_arr1)/sizeof(nums_arr1[0]));
	vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));
	Solution sol;
	double x=sol.findMedianSortedArrays(nums1,nums2);
}