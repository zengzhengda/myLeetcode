#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// definition for a binary tree node for 104
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
// definition for singly-linked list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution
{
public:
	int strStr(string haystack,string needle);
	void rotate(vector<int>& nums,int k);
	void moveZeros(vector<int>& nums); //283
	bool canConstruct(string ransomNote,string magazine);
	int guessNumber(int n); //374
	int getSum(int a,int b);//371
	string reverseString(string s); //344
	int addDigits(int num);
	int firstUniqChar(string s);//387
	int firstUniqChar2(string s);//387
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2);
	int factorial(int n);
	int maxDepth(TreeNode* root);//104 maxinum depth of binary tree
	void delectNode(ListNode* node);//237
	string convertToTitle(int n);//168
	char findTheDifference(string s, string t);//389
	int computeArea(int A,int B,int C,int D,int E,int F,int G,int H);//223 rectangle area

	bool isPalindrome(int x);
	bool isHappy(int n);
	bool isUgly(int num);//263 ugly number
	bool isSameTree(TreeNode* p,TreeNode* q);
	bool isAnagram(string s,string t);// 242 Valid Anagram
	int titleToNumber(string s);
	int majorityElement(vector<int>& nums);//169
	bool isPowerOfTwo(int n);//231
	bool isPowerOfThree(int n);
	bool isPowerOfFour(int n);//342
	int superPow(int a,vector<int>& b);//372 super pow
	int thirdMax(vector<int>& nums);// 414 Third Maximum Number
	bool containsNearbyDuplicate(vector<int>& nums, int k); // 219 超时
	bool containsNearbyDuplicate2(vector<int>& nums, int k); // 219
	bool containsDuplicate(vector<int>& nums); //217
	vector<vector<int>> generate(int numRows); // 118
	vector<int> getRow(int rowIndex);// 119
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);//88
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n);//88  不另外增加空间
	vector<int> plusOne(vector<int>& digits); // 66 
	int removeElement(vector<int>& nums, int val);// 27
	int removeDuplicates(vector<int>& nums);// 26
private:
	int overlap(int A,int B,int C,int D,int E,int F,int G,int H);// 223
	bool int_compare(int a,int b); // 414
};