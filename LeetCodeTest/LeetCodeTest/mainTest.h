#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define SIZE_STACK 100
#define MAX_QUEUE 1000


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

//ջ���� 
typedef struct seqstack
{
	TreeNode* data[SIZE_STACK];
	int tag[SIZE_STACK];
	int top;
};
void push_seq(seqstack* s,TreeNode* t);// ��ջ
TreeNode* pop_seq(seqstack* s); //��ջ

// �������
typedef struct seqqueue
{
	TreeNode* data[MAX_QUEUE];
	int front;
	int rear;// β�����һ��Ԫ�ص���һ��λ��
};
void enter_queue(seqqueue* q,TreeNode* t);// ����
TreeNode* delete_queue(seqqueue* q); //����

class Solution
{
//easy
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
	bool containsNearbyDuplicate(vector<int>& nums, int k); // 219 ��ʱ
	bool containsNearbyDuplicate2(vector<int>& nums, int k); // 219
	bool containsDuplicate(vector<int>& nums); //217
	vector<vector<int>> generate(int numRows); // 118
	vector<int> getRow(int rowIndex);// 119
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);//88
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n);//88  ���������ӿռ�
	vector<int> plusOne(vector<int>& digits); // 66 
	int removeElement(vector<int>& nums, int val);// 27
	int removeDuplicates(vector<int>& nums);// 26
	vector<int> twoSum(vector<int>& nums, int target);//1
	int countPrimes(int n);// 204
	int minMoves(vector<int>& nums); // 453 Minimum Moves to Equal Array Elements
	int arrangeCoins(int n);// 441. Arranging Coins
	string addStrings(string num1, string num2);// 415 add strings
	int findNthDigit(int n); // 400 Nth Digit
	int missingNumber(vector<int>& nums); // 268 missing number
	bool isPerfectSquare(int num);// 367 valid perfect square
	int reverseInteger(int x);// 7 reverse integer
	int mySqrt(int x);// 69 sqrt(x)
	int longestConsecutive(vector<int>& nums);// 128. Longest Consecutive Sequence
	int climbStairs(int n); //70. Climbing Stairs
	vector<int> grayCode(int n);// 89. Gray Code
	ListNode* deleteDuplicates(ListNode* head);//83. Remove Duplicates from Sorted List
	ListNode* reverseList(ListNode* head); //206. Reverse Linked List
	bool isPalindrome(string s);//125. Valid Palindrome
	int strStr2(string haystack, string needle);//
	int myAtoi(string str) ; //8. String to Integer (atoi)
	string addBinary(string a, string b); //67. Add Binary
	string countAndSay(int n);//38. Count and Say
	string longestCommonPrefix(vector<string>& strs);//14. Longest Common Prefix
	bool detectCapitalUse(string word);//								   
	int countSegments(string s);//434. Number of Segments in a String
	bool isSymmetric(TreeNode* root);//101. Symmetric Tree
	vector<vector<int>> levelOrderBottom(TreeNode* root);//107. Binary Tree Level Order Traversal II
	vector<vector<int>> zigzagLevelOrder(TreeNode* root);//103. Binary Tree Zigzag Level Order Traversal
	TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder);//106. Construct Binary Tree from Inorder and Postorder Traversal
	int minDepth(TreeNode* root);//111. Minimum Depth of Binary Tree
	bool hasPathSum(TreeNode* root, int sum);//112. Path Sum
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);//21. Merge Two Sorted Lists
public: // medium
	
	 vector<int> findDuplicates(vector<int>& nums);// 442
	 int maxArea(vector<int>& height);// 11
	 int threeSumClosest(vector<int>& nums, int target);// 16
	 vector<vector<int>> threeSum(vector<int>& nums,int target);// 15
	 void nextPermutation(vector<int>& nums);//31
	 int search(vector<int>& nums, int target);// 33
	 int maxProfit(vector<int>& prices);//121
	 int maxProfit2(vector<int>& prices);// 122
	 int maxProfit3(vector<int>& prices);// 123
	 bool isValidSudoku(vector<vector<char>>& board);// 36   δ���
	 string multiply(string num1, string num2);// 43. Multiply Strings
	 int numberOfArithmeticSlices(vector<int>& A);// 413. Arithmetic Slices

	 int removeDuplicates2(vector<int>& nums); // 80. Remove Duplicates from Sorted Array II
	 bool search2(vector<int>& nums, int target);// 81. Search in Rotated Sorted Array II
	 vector<vector<int>> fourSum(vector<int>& nums, int target); // 18. 4Sum

	 string getPermutation(int n, int k);// 60. Permutation Sequence
	 int trap(vector<int>& height);//42. Trapping Rain Water
	 void rotate(vector<vector<int>>& matrix); //48. Rotate Image
	 void setZeroes(vector<vector<int>>& matrix); // 73. Set Matrix Zeroes
	 int canCompleteCircuit(vector<int>& gas, vector<int>& cost);// 134. Gas Station
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);//2. Add Two Numbers
	 ListNode* reverseBetween(ListNode* head, int m, int n);//92. Reverse Linked List II
	 string longestPalindrome(string s);//5. Longest Palindromic Substring
	 vector<vector<int>> levelOrder(TreeNode* root);//102. Binary Tree Level Order Traversal
	 vector<int> preorderTraversal(TreeNode* root);//144. Binary Tree Preorder Traversal
	 vector<int> inorderTraversal(TreeNode* root);//94. Binary Tree Inorder Traversal
	 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);//105. Construct Binary Tree from Preorder and Inorder Traversal
	 int numTrees(int n);//96. Unique Binary Search Trees
	 vector<TreeNode*> generateTrees(int n);//Unique Binary Search Trees II
	 bool isValidBST(TreeNode* root);//98. Validate Binary Search Tree
	 vector<vector<int>> pathSum(TreeNode* root, int sum);//113. Path Sum II
public:// hard
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);// 4. Median of Two Sorted Arrays
	vector<int> postorderTraversal(TreeNode* root);//145. Binary Tree Postorder Traversal
public: // �����Ժ���
	// ���������
	ListNode* LinkListCreatH(vector<int> nums); ///������Ľ�����ͷ�巨����������  
	ListNode* LinkListCreatT(vector<int> nums); ///������Ľ�����β�巨���������� 
private:
	int overlap(int A,int B,int C,int D,int E,int F,int G,int H);// 223
	bool int_compare(int a,int b); // 414
	int getNumLen(int n); // ������ֵĳ���
	int getDigitOfNum(int n, int loc); // ����λ��loc����0��ʼ����ȡn������
	vector<int> getDigitVec(int); // ������ת��Ϊ����
	void swap(vector<int>& nums, int i, int j); // ���������е���������λ��
	int findKthInTwoVec(vector<int>& nums1, vector<int>& nums2, int k);// �ҳ��������������е�k��ֵ
	long long factorial(int n); // ��n!
	unsigned int binary_to_gray(unsigned int n);// ��Ȼ������ת�ɸ�����
	ListNode* linkListInsertH(ListNode* L, int x); // ͷ��������
	ListNode* linkListInsertT(ListNode* L, int x); // β��������
	string getNextStrForCountAndSay(string s);
	string getPrifixStrOfTwo(string str1, string str2); // �������ַ�����ǰ׺
	bool isSymmetric(TreeNode* p, TreeNode* q);// �ж��������Ƿ�Գ�
	vector<TreeNode*> generateTrees(int start,int end);// �����������ֵ���β���ɶ��������
public: // ����������
	void preorder(TreeNode* t);// ǰ�����
	void midorder(TreeNode* t); // �������
	void postorder(TreeNode* t); // ������� 
	void leveloder(TreeNode* t); // ��α���
	void creatTree(TreeNode* t); // ǰ��������ɶ�����
	TreeNode* creatTreeLevel(vector<int> nums); //��α������ɶ�����
	TreeNode* search_tree(TreeNode* t, int x);// ����������
	int count_tree(TreeNode* t); // ͳ�ƽ�����
	bool is_equal_tree(TreeNode* t1, TreeNode* t2); //�Ƚ��������Ƿ���ͬ
	int deep_tree(TreeNode* t); // �����������
	int getMaxOfBST(TreeNode* root);// ��������������ֵ
	int getMinOfBST(TreeNode* root); //�������������Сֵ
	bool rootGreaterLeft(TreeNode* root,int val);
	bool rootLessRight(TreeNode* root,int val);
	void pathSum(TreeNode* root, int gap, vector<int> &cur,vector<vector<int>> &result);// 
};