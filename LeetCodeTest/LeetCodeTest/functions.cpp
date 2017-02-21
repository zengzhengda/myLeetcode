// ����˽�к�����һ��Ϊͨ�ú���

#include "mainTest.h"

// �ҳ��������������е�k��ֵ
int Solution::findKthInTwoVec(vector<int>& nums1, vector<int>& nums2, int k)
{
	int index1 = 0, index2 = 0;
	for (int i = 0; i < k; i++)
	{
		if (index1 >= nums1.size() && index2 < nums2.size())
			index2++;
		else if (index2 >= nums2.size() && index1 < nums1.size())
			index1++;
		else if (nums1[index1] <= nums2[index2])
			index1++;
		else
			index2++;
	}
	if (index1 >= nums1.size())
		return nums2[index2];
	else if (index2 >= nums2.size())
		return nums1[index1];
	else
	{
		return nums1[index1] <= nums2[index2] ? nums1[index1] : nums2[index2];
	}
}
// ���������е���������λ��
void Solution::swap(vector<int>& nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

// ������ת��Ϊ����
vector<int> Solution::getDigitVec(int n) {
	vector<int> digitVec;
	while (n>9)
	{
		int x = n % 10; 
		digitVec.push_back(x);
		n = n / 10;
	}
	digitVec.push_back(n);
	reverse(digitVec.begin(), digitVec.end());
	return digitVec;
}

// ����λ��loc����0��ʼ����ȡn������
int Solution::getDigitOfNum(int n, int loc)
{
	int digit = 0;
	vector<int> digitVec = getDigitVec(n);
	digit = digitVec[loc];
	return digit;
}

int Solution::overlap(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int h1 = max(A, E);
	int h2 = min(C, G);
	int h = h2>h1 ? h2 - h1 : 0;
	int w1 = max(B, F);
	int w2 = min(D, H);
	int w = w2>w1 ? w2 - w1 : 0;
	return w*h;
}

bool Solution::int_compare(int a, int b)
{
	return a>b;
}

// ������ֵĳ��� , �ݹ�ʵ��
int Solution::getNumLen(int n)
{
	if (n < 10)
		return 1;
	int tmp = n / 10;
	int len = getNumLen(tmp);
	len++;
	return len;
}