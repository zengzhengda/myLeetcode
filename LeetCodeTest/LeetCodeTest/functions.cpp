// ����˽�к�����һ��Ϊͨ�ú���

#include "mainTest.h"

vector<int> heapSort(vector<int> nums)
{
	vector<int> result;
	return result;
}
// ���������㷨
vector<int> Solution::sortMethods(vector<int> nums)
{
	int method=6;
	switch(method)
	{
	case 1: // ��������
	{
		const int n=nums.size();
		for(int i=1;i<n;i++)
		{
			int key=nums[i];
			int j = i-1;
			for( j=i-1;j>=0;j--)
			{
				if(key >= nums[j])
					break;
				nums[j+1]=nums[j];
			}
			nums[j+1]=key;
		}
		return nums;
	}
	case 2: // ð������
	{
		const int n=nums.size();
		for(int i=0;i<n-1;i++)
		{
			for(int j=n-1;j>i;j--)
			{
				if(nums[j-1]> nums[j])
				{
					int tmp=nums[j];
					nums[j-1]=nums[j];
					nums[j-1]=tmp;
				}
			}
		}
		return nums;
	}
	case 3: // ѡ������
	{
		const int n=nums.size();
		for(int i=0;i<n-1;i++)
		{
			int index_min=i;
			for( int j=i+1; j<n; j++)
			{
				if(nums[index_min] < nums[j])
				{
					index_min=j;
				}
			}

			int tmp=nums[i];
			nums[i]=nums[index_min];
			nums[index_min]=tmp;
		}
		return nums;
	}
	case 4: // ��������
	{
		quickSort(nums,0,nums.size()-1);
		return nums;
	}
	case 5: // �鲢����
	{
		mergeSort(nums,0,nums.size()-1);
		return nums;
	}
	case 6: // ��������
	{
		// ���0��max֮�������
		auto largest=max_element(nums.begin(),nums.end());
		int maxVal=*largest;
		int *C = new int[maxVal+1] (); // ��ʼ��Ϊ0
		vector<int> B(nums.size());

		int value,pos;

		for(int i=0;i<nums.size();i++)
		{
			C[A[i]]++;
		}
		for(int i=1;i<C.size();i++)
		{
			C[i]=C[i]+C[i-1];
		}
		for(int i=0;i< nums.size();i++)
		{
			value=nums[i];
			pos=C[value];
			B[pos-1] = value;
			C[value]--;
		}
		return B;

	}
	case 7: // ������
	{
		vector<int> result=heapSort(nums);
	}
	default:break;
	}
}
// �鲢����
void Solution::mergeSort(vector<int>& nums, int ind_l, int ind_r)
{
	if(ind_l<ind_r)
	{
		int q=(ind_l+ind_r)/2;
		mergeSort(nums,ind_l,q);
		mergeSort(nums,q+1,ind_r);
		mergeMaxMin(nums,ind_l,ind_r,q);
	}
}
// ������������������
void Solution::mergeMaxMin(vector<int>& nums, int ind_l, int ind_r, int mid)
{
	vector<int> nums_l,nums_r;
	nums_l.assign(nums.begin()+ind_l,nums.begin()+mid+1);
	nums_r.assign(nums.begin()+mid+1,nums.begin()+ind_r+1);
	nums_l.push_back(INT_MAX);
	nums_r.push_back(INT_MAX);

	int i=0;
	int j=0;
	for(int k=ind_l;k<ind_r+1;k++)
	{
		if(nums_l[i]<nums_r[j])
		{
			nums[k]=nums_l[i];
			i++;
		}
		else
		{
			nums[k]=nums_r[j];
			j++;
		}
	}
}
// �ִ�С��
int Solution::partition(std::vector<int>& nums, int ind_l, int ind_r)
{
	int x=nums[ind_r]; // �������һ����
	int i=ind_l-1;
	for(int j=ind_l; j<ind_r; j++)
	{
		if(nums[j] <= x)
		{
			i=i+1;
			std::swap(nums[i],nums[j]);
		}	
	}
	std::swap(nums[i+1],nums[ind_r]);
	return i+1;
}
// ����
void Solution::quickSort(vector<int> &nums, int ind_l,int ind_r)
{
	if(ind_l<ind_r)
	{
		int q=partition(nums,ind_l,ind_r);
		
		quickSort(nums,ind_l,q-1);
		quickSort(nums,q+1,ind_r);
	}
}
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
// ��������������ֵ
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
// �������������Сֵ
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
// �����������ֵ���β���ɶ��������
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

// �ж��������Ƿ�Գ�
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
//��α������ɶ�����
TreeNode* Solution::creatTreeLevel(vector<int> nums)
{
	TreeNode* t=nullptr;
	if(nums.size()==0)
		return t;
	int len_level=1; // ���������Ĳ�����
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
// �����������
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
//�Ƚ��������Ƿ���ͬ
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
// ͳ�ƽ�����
int Solution::count_tree(TreeNode* t)
{
	if (!t)
		return 0;
	return count_tree(t->left) + count_tree(t->right) + 1;
}
// ����������
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
// ǰ��������ɶ�����
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
// ��α���
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
// ��ջ
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
//��ջ
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

// ����
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
// ����
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

// ǰ�����
void Solution::preorder(TreeNode* t)
{
	int method=2;
	switch(method)
	{
	case 1:
	{
		// �ݹ�ķ���
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
		// �ǵݹ鷽��
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
				while(t)  //ֻҪ��㲻Ϊ�վ�Ӧ����ջ���棬�������ҽ���޹�
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
		// �ݹ鷽��
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
// �������ַ�����ǰ׺
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
// ͷ��������
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
// β��������
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
///������Ľ�����ͷ�巨����������  
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

//������Ľ�����β�巨����������
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
// ��Ȼ������ת�ɸ�����
unsigned int Solution::binary_to_gray(unsigned int n)
{
	return n ^ (n >> 1);
}
// ��n!
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