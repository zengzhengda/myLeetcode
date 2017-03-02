// 定义私有函数，一般为通用函数

#include "mainTest.h"

// 头插入链表
ListNode* Solution::linkListInsertH(ListNode* L, int x)
{
	if (!L)
	{
 		L = (ListNode*)malloc(sizeof(ListNode));
		L->val = x;
		L->next = NULL;
		return L;
	}
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->val = x;
	p->next = L;
	L = p;
	return L;
}
// 尾插入链表
ListNode* Solution::linkListInsertT(ListNode* L, int x)
{
	if (!L)
	{
		L = (ListNode*)malloc(sizeof(ListNode));
		L->val = x;
		L->next = NULL;
		return L;
	}
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->val = x;
	p->next = NULL;
	ListNode* L_t = L;
	while (L_t->next)
	{
		L_t = L_t->next;
	}
	L_t->next = p;
	return L;
}
///单链表的建立，头插法建立单链表  
ListNode* Solution::LinkListCreatH(vector<int> nums)
{
	ListNode* L;
	L = (ListNode*)malloc(sizeof(ListNode));
	L -> val = nums[0];
	L->next = NULL;

	for (int i = 1; i < nums.size(); i++)
	{
		ListNode*  p;
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = nums[i];
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//单链表的建立，尾插法建立单链表
ListNode* Solution::LinkListCreatT(vector<int> nums)
{
	ListNode* L;
	L = (ListNode*)malloc(sizeof(ListNode));
	L->val = nums[0];
	L->next = NULL;
	ListNode* r;
	r = L;
	for (int i = 1; i < nums.size(); i++)
	{
		ListNode* p;
		p = (ListNode*)malloc(sizeof(ListNode));
 		p->val = nums[i];
 		r->next = p;
		r = p;
	}
	r->next = NULL;

	return L;
}
// 自然二进制转成格雷码
unsigned int Solution::binary_to_gray(unsigned int n)
{
	return n ^ (n >> 1);
}
// 求n!
long long Solution::factorial(int n)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		
		if (n == 0 || n== 1) return 1;
		else 
			return n*factorial(n - 1);
	}
	case 2:
	{
		if (n == 1 || n == 0)
			return 1;
		long long x = 1;
		for (int i = 1; i <= n; i++)
		{
			x = x*i;
		}
		return x;
	}
	default:
		break;
	}
	
}
// 找出两个有序数组中第k个值
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
// 交换数组中的两个数的位置
void Solution::swap(vector<int>& nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

// 讲整数转化为向量
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

// 根据位置loc（从0开始）提取n的数字
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

// 获得数字的长度 , 递归实现
int Solution::getNumLen(int n)
{
	if (n < 10)
		return 1;
	int tmp = n / 10;
	int len = getNumLen(tmp);
	len++;
	return len;
}