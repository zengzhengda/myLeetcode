#include "mainTest.h"
#include<unordered_map>

bool Solution::isPalindrome(int x) 
 {
	if (x<0) 
	{ 
		return false; 
	}

    int len=1;
    for (len=1; (x/len) >= 10; len*=10 );

    while (x != 0 ) {
        int left = x / len;
        int right = x % 10;

        if(left!=right){
            return false;
        }

        x = (x%len) / 10;
        len /= 100;
    }
    return true;
}

bool Solution::isHappy(int n)
{
	int n_src=n;//±£´æÔ­À´µÄn
	int loopnum=0;
	while(n != 1)
	{
		loopnum++;

		vector<int> digitsVec;
		while(n/10 !=0)
		{
			digitsVec.push_back(n%10);
			n=n/10;
		}
		digitsVec.push_back(n);
		n=0;
		for(int i=0;i<digitsVec.size();i++)
		{
			n=n + digitsVec[i]*digitsVec[i];
		}
		if(n == n_src || loopnum >100)
			return false;
	}
	return true;
}

bool Solution::isUgly(int num)
{
  	if(num <= 0)
		return false;
	else if(num==1)
		return true;
	while(num%2 == 0) num=num/2;
	while(num%3 == 0) num=num/3;
	while(num%5 == 0) num=num/5;
	if(num == 1)
		return true;
	else
		return false;
}

/*//wrong code 
bool Solution::isSameTree_wrong(TreeNode* p,TreeNode* q)
{
   	if(p->val != q->val)
		return false;
	else if((p->left == NULL && q->left != NULL) || (p->left != NULL && q->left == NULL)||
		(p->right == NULL && q->right != NULL) || (p->right != NULL && q->right == NULL))
		return false;
	else
	{
		bool left=isSameTree_wrong(p->left,q->left);
		bool right=isSameTree_wrong(p->right,q->right);
		if(left && right)
			return true;
		else 
			return false;
	}
}*/

bool Solution::isSameTree(TreeNode* p,TreeNode* q)
{
   	if(p ==NULL && q != NULL)
   		return false;
   	else if(p !=NULL && q ==NULL)
   		return false;
   	else if(p == NULL && q == NULL)
   		return true;
   	else if((p != NULL && q != NULL)&& (p->val !=q->val))
   		return false;
   	else 
   	{
   		return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
   	}
}

bool Solution::isAnagram(string s,string t)
{
	return false;
}

int Solution::superPow(int a,vector<int>& b)
{
	int e=0;
	for(int i=b.size()-1;i>=0;i--)
	{
		e=e+b[i]*pow(10,b.size()-i-1);
	}
	int p=(int)pow(a,e)%1337;
	return p;
}
bool Solution:: isPowerOfFour(int n)
{
	double x=log10(n)/log10(4);
	return x-int(x) == 0;
}
bool Solution::isPowerOfThree(int n)
{
	double x=log10(n)/log10(3);
	return x-int(x) == 0;// 判断double x 为整数
}
bool Solution::isPowerOfTwo(int n)
{
	if(n<=0)
		return false;
	if(n == 1)
		return true;
	else
	{
		int remainder=n%2;
		if(remainder == 0)
		{
			n=n/2;
			return isPowerOfTwo(n);
		}
		else
			return false;
	}
}

int Solution::majorityElement(vector<int>& nums)
{
	unordered_map<int,int> freqs;
    for(int i=0;i<nums.size();i++)
    {
    	freqs[nums[i]]++;
    }
    int majorE=0;
    for(auto it:freqs)
    {
    	if(it.second>nums.size()/2)
    	{
			majorE= it.first;
    		break;
    	}
    }
    return majorE;
}

int Solution::titleToNumber(string s)
{
	if(s.empty())
		return 0;
	reverse(s.begin(),s.end());
	int n=0;
	for(int i=0;i<s.size();i++)
	{
		int a=(s[i]-'A'+1)*pow(26,i);
		n=n+a;
	}
	return n;
}

int Solution::computeArea(int A,int B,int C,int D,int E,int F,int G,int H)
{
	int area1=(C-A)*(D-B);
	int area2=(G-E)*(H-F);
	int over_area=overlap(A,B,C,D,E,F,G,H);
	int area=area1+area2-over_area;
	return area;	
}
int Solution::overlap(int A,int B,int C,int D,int E,int F,int G,int H)
{
	int h1=max(A,E);
	int h2=min(C,G);
	int h=h2>h1?h2-h1:0;
	int w1=max(B,F);
	int w2=min(D,H);
	int w=w2>w1?w2-w1:0;
	return w*h;
}

char Solution::findTheDifference(string s,string t)
{
	bool isDif=false;
    if(s=="")
        return t[0];
    char a;
	for(int i=0;i<t.size();i++)
	{
		isDif=true;
		for(int j=0;j<s.size()&& s.size()>0;j++)
		{
			if(s[j]==t[i])
			{
				isDif=false;
				s.erase(j,1);
				break;
			}
		}
		if(isDif==true)
		{
		    a= t[i];
		    break;
		}
	}
	return a;
}

/* 错误的算法
string Solution::convertToTitle(int n)
{
	string titleStr;
	int remainder=n%26;
	while(n/26 != 0)
	{
		remainder=n%26;
		if(remainder==0)
		{
			titleStr.push_back('Z');
		}
		else 
		{
			titleStr.push_back('A'+remainder-1);
		}
		n=n-remainder*26;
	}
	if(remainder !=0 )
	{
		titleStr.push_back('A'+n-1);
	}
	reverse(titleStr.begin(),titleStr.end());
	return titleStr;
}*/
string Solution::convertToTitle(int n)
{
	string titleStr="";
	while(n !=0)
	{
		int remainder=(n-1)%26;
		titleStr.push_back('A'+remainder);
		n=(n-1)/26;
	}
	//反转字符串
	reverse(titleStr.begin(),titleStr.end());
	return titleStr;
}

void Solution::delectNode(ListNode* node)
{
	if(node == NULL || node->next == NULL) return;
	node->val=node->next->val;
	node->next=node->next->next;
}

int Solution::strStr(string haystack,string needle)
{
	int l1=haystack.length();
    int l2 = needle.length();
    for(int i=0;i<=(l1-l2);i++)
    {
        int j;
        for (j=0;j<l2;j++)
        {
            if(haystack[i+j] != needle[j])
            {
                break;
            }
        }
        if(j==l2) return i;
    }
    return -1;
}

void Solution::rotate(vector<int>& nums,int k)
{
	vector<int> nums2;
	if(k>nums.size()) k%=nums.size();
	for (int i=nums.size()-1;i>=0;i--)
	{
		nums2.push_back(nums[i]);
	}
	for(int i=0;i<k;i++)
	{
		nums2.push_back(nums2[i]);
	}
	int j=0;
	for(int i=nums2.size()-1;i>=k;i--)
	{
		nums[j]=nums2[i];
		j++;
	}
}

void Solution::moveZeros(vector<int>& nums)
{
	int len=nums.size();
	vector<int>::iterator it=nums.begin();
	for(int i=0;i<len;i++)
	{
		if(*it==0)
		{
			vector<int>::iterator it2=it;
    		nums.erase(it2);
    		//it=nums.begin()+i;
    		nums.push_back(0);
		}
		else
		{
			it++;
		}
	}
}

bool Solution::canConstruct(string ransomNote,string magazine)
{
	if(ransomNote.size()==0)
		return true;
	unordered_map<char,int> m;
	for(int i=0;i<magazine.size();i++)
	{
		m[magazine[i]]++;
	}
	for(int i=0;i<ransomNote.size();i++)
	{
		if(m.find(ransomNote[i]) ==m.end() || m[ransomNote[i]] == 0)
			return false;
		m[ransomNote[i]]--;
	}
	return true;
}

/*
int Solution::guessNumber(int n)
{
	int left=1,right=n;
	int mid=0;
	while(left<right)
	{
		mid=left+(right-left)/2;
		if(guess(mid)==0)
			return mid;
		else if(guess(mid)== 1)
		{
			left=mid+1;
		}
		else if(guess(mid)==-1)
		{
			right=mid-1;
		}
	}
	return left;
}
*/

int Solution::getSum(int a,int b)
{
	int x=b;
	while(x)
	{
		int carry=a&x;
		a=a^x;
		x=carry<<1;
	}
	return a;
}

string Solution::reverseString(string s)
{
	int len=s.size();
	int a=floor(len/2);
	for(int i=0;i<a;i++)
	{
		char tmp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=tmp;
	}
	return s;
}

int Solution::addDigits(int num)
{
	while(num/10 != 0)
	{
		vector<int> digits;
		while(num/10 != 0)
		{
			digits.push_back(num%10);
			num=num/10;
		}
		digits.push_back(num%10);
		int tmp=0;
		for(auto it=digits.begin();it!=digits.end();it++)
		{
			tmp=tmp+ *it;
		}
		num=tmp;
	}
	return num;
}

int Solution::firstUniqChar(string s)
{
	int i=0;
	bool flag=true;
	for(i=0;i<s.size();i++)
	{
		flag=true;
		int j=0;
		for(j=0;j<s.size();j++)
		{
			if(s[i]==s[j] && i!=j) 
			{
				flag=false;
				break;
			}
		}
		if(flag==true) 
		{
			return i;
		}
	}
	if(flag==false && (i=s.size()-1))
		return -1;
}

int Solution::firstUniqChar2(string s)
{
	int num_char[26]={0};
	for(int i=0;i<s.size();i++)
	{
		num_char[s[i]-'a']++;
	}
	for(int i=0;i<s.size();i++)
	{
		if(num_char[s[i]-'a']==1)
			return i;
	}
	return -1;
}

vector<int> Solution::intersection(vector<int>& nums1,vector<int>& nums2)
{
	vector<int> nums3;
	for(int i=0;i<nums1.size();i++)
	{
		for(int j=0;j<nums2.size();j++)
		{
			if(nums1[i]==nums2[j])
			{
				bool flag=true;
				for(int k=0;k<nums3.size();k++)
				{
					if(nums1[i]==nums3[k])
					{
						flag=false;
						break;
					}
				}
				if(flag==true)
				{
					nums3.push_back(nums1[i]);
					break;
				}
			}
		}
	}
	return nums3;
}

int Solution::factorial(int n){
	if(n==1) return 1;
	else{
		return n*factorial(n-1);
	}
}

//104
int Solution::maxDepth(TreeNode *root)
{
	//设定出口
	if(NULL==root)
	{
		return 0;
	}
	int leftDepth=maxDepth(root->left);
	int rightDepth=maxDepth(root->right);
	return leftDepth>=rightDepth?leftDepth+1:rightDepth+1;
}