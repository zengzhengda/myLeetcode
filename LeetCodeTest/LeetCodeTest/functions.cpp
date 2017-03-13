// 定义私有函数，一般为通用函数

#include "mainTest.h"

void Solution::pathSum(TreeNode* root, int gap, vector<int> &cur,vector<vector<int>> &result)
{
	if(root==nullptr)
		return;
	cur.push_back(root->val);
	if(root->left==nullptr && root->right==nullptr)
		if(gap==root->val)
			result.push_back(cur);
	pathSum(root->left,gap - root->val, cur,result);
	pathSum(root->right,gap- root->val,cur,result);
	cur.pop_back();
}
bool Solution::rootGreaterLeft(TreeNode* root,int val)
{
	if(!root)
		return true;
	while(root->right)
	{
		root=root->right;
	}
	if(val>root->val)
		return true;
	else
		return false;
}
bool Solution::rootLessRight(TreeNode* root, int val)
{
	if (!root)
		return true;
	while (root->left)
	{
		root = root->left;
	}
	if (root->val > val)
		return true;
	else
		return false;
}
// 二叉查找树的最大值
int Solution::getMaxOfBST(TreeNode* root)
{
	int maxVal = INT_MIN;
	if(!root)
		return maxVal;
	while(root->right)
	{
		root=root->right;
	}
	maxVal=root->val;
	return maxVal;
}
// 二叉查找树的最小值
int Solution::getMinOfBST(TreeNode* root) 
{
	int minVal=INT_MAX;
	if(!root)
		return minVal;
	while(root->left)
	{
		root=root->left;
	}
	minVal=root->val;
	return minVal;
}
// 根据连续数字的首尾生成二叉查找树
vector<TreeNode*> Solution::generateTrees(int start,int end)
{
	vector<TreeNode*> result;
	if(start>end)
	{
		result.push_back(NULL);
		return result;
	}
	for(int i=start;i<=end;i++)
	{
		vector<TreeNode*> left=generateTrees(start,i-1);
		vector<TreeNode*> right=generateTrees(i+1,end);
		for(int m=0;m<left.size();m++)
			for(int n=0;n<right.size();n++)
			{
				TreeNode* root =new TreeNode(i);
				root->left=left[m];
				root->right=right[n];
				result.push_back(root);
			}
	}
	return result;

}

// 判定两棵树是否对称
bool Solution::isSymmetric(TreeNode* p, TreeNode* q)
{
	if(p==nullptr && q==nullptr)
		return true;
	if(p==nullptr || q==nullptr)
		return false;
	bool tmp1=(p->val==q->val);
	bool tmp2=isSymmetric(p->left,q->right);
	bool tmp3=isSymmetric(p->right,q->left);
	return tmp1&&tmp2&&tmp3;
}
//层次遍历生成二叉树
TreeNode* Solution::creatTreeLevel(vector<int> nums)
{
	TreeNode* t=nullptr;
	if(nums.size()==0)
		return t;
	int len_level=1; // 满二叉树的层结点数
	const int len_nums=nums.size();
	int cnt=1;
	seqqueue q;
	q.front = q.rear = 0;
	t=(TreeNode*)malloc(sizeof(TreeNode));
	t->val=nums[0];
	t->left=t->right=nullptr;
	enter_queue(&q,t);
	while(cnt<len_nums)
	{
		for(int i=0;i<len_level && cnt<len_nums;i++)
		{
			TreeNode* tmp2;
			tmp2=delete_queue(&q);
			if(!tmp2)
			{
				i += 2;
				cnt+=2;
				enter_queue(&q,nullptr);
				enter_queue(&q,nullptr);
				continue;
			}

			if(cnt<len_nums)
			{
				TreeNode* lchild=nullptr;
				if(nums[cnt]!=INT_MIN)
				{
					lchild = (TreeNode*)malloc(sizeof(TreeNode));
					lchild->val=nums[cnt++];
					lchild->left = lchild->right = nullptr;
					tmp2->left=lchild;
				}
				else if(nums[cnt]=INT_MIN)
				{
					tmp2->left=nullptr;
					cnt++;
				}
				enter_queue(&q,lchild);
			}
			if(cnt<len_nums)
			{
				TreeNode* rchild=nullptr;
				if(nums[cnt]!=INT_MIN)
				{
					rchild=(TreeNode*)malloc(sizeof(TreeNode));
					rchild->val=nums[cnt++];
					rchild->left = rchild->right = nullptr;
					tmp2->right=rchild;
				}
				else if(nums[cnt]=INT_MIN)
				{
					tmp2->right=nullptr;
					cnt++;
				}
				enter_queue(&q,rchild);
			}	
		}
		len_level *= 2;
	}
	return t;
}
// 二叉树的深度
int Solution::deep_tree(TreeNode* t)
{
	int h, l, r;
	if (!t)
	{
		return 0;
	}
	l = deep_tree(t->left);
	r = deep_tree(t->right);
	h = (l > r) ? l : r+1;
	return h;
}
//比较两个树是否相同
bool Solution::is_equal_tree(TreeNode* t1, TreeNode* t2)
{
	if (!t1 && !t2)
		return true;
	if (t1 && t2 && t1->val == t2->val)
	{
		if (is_equal_tree(t1->left, t2->left))
			if (is_equal_tree(t1->right, t2->right))
				return true;
	}
	return false;
}
// 统计结点个数
int Solution::count_tree(TreeNode* t)
{
	if (!t)
		return 0;
	return count_tree(t->left) + count_tree(t->right) + 1;
}
// 二叉树查找
TreeNode* Solution::search_tree(TreeNode* t, int x)
{
	if (!t)
		return NULL;
	if (t->val == x)
		return t;
	else
	{
		if (!search_tree(t->left, x))
			return search_tree(t->right, x);
		return t;
	}
}
// 前序遍历生成二叉树
void Solution::creatTree(TreeNode* t)
{
	int num;
	if ((num = getchar()) == '#')
		t = NULL;
	else
	{
		t = (TreeNode*)malloc(sizeof(TreeNode));
		t->val = num;
		creatTree(t->left);
		creatTree(t->right);
	}
}
// 层次遍历
void Solution::leveloder(TreeNode* t)
{
	seqqueue q;
	TreeNode* tmp;
	q.front=q.rear=0;
	if(!t)
	{
		printf("the tree is empty\n");
		return;
	}
	enter_queue(&q,t);
	while(q.front != q.rear)
	{
		t=delete_queue(&q);
		printf("%c",t->val);
		if(t->left)
		{
			enter_queue(&q,t->left);
		}
		if(t->right)
		{
			enter_queue(&q,t->right);
		}
	}
}
// 进栈
void push_seq(seqstack* s,TreeNode* t)
{
	if(s->top==SIZE_STACK-1)
	{
		printf("the stack is full\n");
		return;
	}
	else
	{
		s->top++;
		s->data[s->top]=t;
	}
}
//出栈
TreeNode* pop_seq(seqstack* s)
{
	if(s->top==-1)
	{
		return NULL;
	}
	else
	{
		s->top--;
		return s->data[s->top+1];
	}
}

// 进队
void enter_queue(seqqueue* q,TreeNode* t)
{
	if(q->rear == MAX_QUEUE)
	{
		printf("the queue is full\n");
	}
	else
	{
		q->data[q->rear]=t;
		q->rear++;
	}
}
// 出队
TreeNode* delete_queue(seqqueue* q)
{
	if(q->front == q->rear)
		return NULL;
	else
	{
		q->front++;
		return q->data[q->front-1];
	}
}

// 前序遍历
void Solution::preorder(TreeNode* t)
{
	int method=2;
	switch(method)
	{
	case 1:
	{
		// 递归的方法
		if(t)
		{
			int val = t->val;
			preorder(t->left);
			preorder(t->right);
		}
		break;
	}
	case 2:
	{
		// 非递归方法
		seqstack s;
		s.top=-1;
		if(!t)
		{
			printf("the tree is empty\n");
		}	
		else
		{
			while(t||s.top !=-1)
			{
				while(t)  //只要结点不为空就应该入栈保存，与其左右结点无关
				{
					printf("%c",t->val);
					push_seq(&s,t);
					t=t->left;
				}
				t=pop_seq(&s);
				t=t->right;
			}
		}
		break;
	}
	default:break;
	}
	
}
void Solution::midorder(TreeNode* t)
{
	int method=2;
	switch (method)
	{
	case 1:
	{
		// 递归方法
		if (t)
		{
			midorder(t->left);
			int val = t->val;
			midorder(t->right);
			break;
		}
	}
	case 2:
	{
		seqstack s;
		s.top = -1;
		if (!t)
		{
			printf("the tree is empty\n");
		}
		else
		{
			while (t || s.top != -1)
			{
				while (t)
				{
					push_seq(&s, t);
					t = t->left;
				}
				t = pop_seq(&s);
				printf("%c", t->val);
				t = t->right;
			}
		}
		break;
	}
	default: break;
	}
}

void Solution::postorder(TreeNode* t)
{
	if(t)
	{
		postorder(t->left);
		postorder(t->right);
		int val=t->val;
	}
}
// 求两个字符串的前缀
string Solution::getPrifixStrOfTwo(string str1, string str2)
{
	if (str1.empty() || str2.empty())
		return string();
	int i = 0;
	for (; i < str1.size() && i < str2.size(); i++)
	{
		if (str1[i] != str2[i])
			break;
	}
	return str1.substr(0, i);
}
string Solution::getNextStrForCountAndSay(string s)
{
	stringstream ss;
	for (auto it = s.begin(); it != s.end();)
	{
		auto j = find_if(it, s.end(), bind1st(not_equal_to<char>(), *it));
		ss << distance(it, j) << *it;
		it = j;
	}
	return ss.str();
}
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