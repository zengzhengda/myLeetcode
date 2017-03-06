#include "mainTest.h"

//28. Implement strStr()
int strStr(string haystack, string needle)
{
	const size_t len_h=haystack.size();
	const size_t len_n=needle.size();
	if(len_h<len_n)
		return -1;
	if(len_n==0)
		return -1;

	int i=0;
	for(i=0;i<len_h-len_n+1;i++)
	{
		bool isY=true;
		for(int j=i,k=0;j<len_h;j++,k++)
		{
			if(haystack[j]!=needle[k])
			{
				isY=false;
				break;
			}
		}
		if(isY)
			return i;
	}
	return -1;
}

//125. Valid Palindrome
bool isPalindrome(string s)
{
	if(s.empty())
		return true;
	const size_t len_s=s.size();
	transform(s.begin(),s.end(),s.begin(),::tolower;
	int left=0;
	int right=len_s-1;
	while(left<=right)
	{
		if(!isalnum(s[left]))
		{
			left++;
			continue;
		}
		else if(!isalnum(s[right]))
		{
			right--;
			continue;
		}
		else if(s[left]!=s[right])
			return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;
}

//92. Reverse Linked List II
ListNode* Solution::reverseBetween(ListNode* head, int m, int n)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		// 边界条件考虑不周全
		if (head == nullptr)
			return head;
		ListNode* prev = head;
		for (int i = 1; i < m - 1; i++)
		{
			prev = prev->next;
		}
		ListNode* tail = prev->next;
		for (int j = m; j < n; j++)
		{
			// 保持头指针和尾指针不变
			ListNode* cur = tail->next;
			tail->next = (cur->next == nullptr ? nullptr : cur->next);
			cur->next = prev->next;
			prev->next = cur;
		}
		return head;
	}
	case 2:
	{
		if (head == nullptr)
			return head;
		ListNode dummy(-1);
		ListNode* prev = &dummy;
		prev->next = head; // 设置一个哑指针在头部
		for (int i = 0; i < m-1; i++)
		{
			prev = prev->next;
		}
		ListNode* tail = prev->next;
		for (int j = 0; j < n - m; j++)
		{
			ListNode* cur = tail->next;
			tail->next= (cur->next == nullptr ? nullptr : cur->next);
			cur->next = prev->next;
			prev->next = cur;
		}
		return prev->next;
	}
	default:
		break;
	}
	
}

//2. Add Two Numbers
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		ListNode* l_sum = NULL;
		int carry = 0;
		while (l1 && l2)
		{
			int sum = l1->val + l2->val + carry;
			carry = sum / 10;
			sum = sum % 10;
			l_sum = linkListInsertT(l_sum, sum);
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == NULL)
		{
			while (l2)
			{
				int sum = l2->val + carry;
				carry = sum / 10;
				sum = sum % 10;
				l_sum = linkListInsertT(l_sum, sum);
				l2 = l2->next;
			}
		}
		else
		{
			while (l1)
			{
				int sum = l1->val + carry;
				carry = sum / 10;
				sum = sum % 10;
				l_sum = linkListInsertT(l_sum, sum);
				l1 = l1->next;
			}
		}
		if (carry > 0)
		{
			l_sum = linkListInsertT(l_sum, carry);
		}
		return l_sum;
	}
	case 2:
	{
		ListNode* l_sum = NULL;
		int carry = 0;
		while (l1 || l2)
		{
			const int ai = (l1 == nullptr ? 0 : l1->val);
			const int bi = (l2 == nullptr ? 0 : l2->val);
			int sum = ai + bi + carry;
			carry = sum / 10;
			sum = sum % 10;
			l_sum = linkListInsertT(l_sum, sum);
			l1 = (l1==nullptr?nullptr:l1->next);
			l2 = (l2==nullptr?nullptr:l2->next);
		}
		if (carry > 0)
		{
			l_sum = linkListInsertT(l_sum, carry);
		}
		return l_sum;
	}
	default:
		break;
	}
	
}
//206. Reverse Linked List
ListNode* Solution::reverseList(ListNode* head)
{
	if (!head)
		return head;
	ListNode* L_r=NULL;
	/*L_r = (ListNode*)malloc(sizeof(ListNode));
	L_r->next = NULL;*/
	ListNode* L_tmp;
	L_tmp = head;
	while (L_tmp)
	{
		L_r=linkListInsertH(L_r, L_tmp->val);
		L_tmp = L_tmp->next;
	}
	return L_r;
}

//83. Remove Duplicates from Sorted List
ListNode* Solution::deleteDuplicates(ListNode* head)
{
	if (head == NULL)
		return head;
	ListNode* node = head;
	while (node->next != NULL)
	{
		if (node->val == node->next->val)
		{
			node->next = node->next->next;
		}
		else
		{
			node = node->next;
		}
	}
	return head;
}

// 134. Gas Station
int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int method = 3;
	switch (method)
	{
	case 1:
	{
		// 超时
		if (gas.size() != cost.size())
			return -1;
		int sum_c = accumulate(cost.begin(), cost.end(),0);
		int sum_g = accumulate(gas.begin(), gas.end(), 0);
		if (sum_c > sum_g)
			return -1;
		for (int i = 0; i < gas.size(); i++)
		{
			sum_c = 0;
			sum_g = 0;
			bool isY = true;
			for (int j = i; j < i + gas.size(); j++)
			{
				int index = j%gas.size();
				sum_c += cost[index];
				sum_g += gas[index];
				if (sum_c > sum_g)
				{
					isY = false;
					break;
				}
			}
			if (isY == true)
				return i;
		}
		return -1;
	}
	case 2:
	{
		// 最大子序列和问题 不是很懂
		if (gas.size() == 0)
			return -1;
		int index=-1;
		int total = 0;
		int sum = 0;
		int max_sum = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			int diff = gas[i] - cost[i];
			total += diff;
			sum += diff;
			if (sum > max_sum)
				max_sum = sum;
			else if (sum < 0)
			{
				sum = 0;
				index = i;
			}
		}
		return total >= 0 ? index + 1 : -1;
	}
	case 3:
	{
		if (gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) return -1;
		int total = 0, sum = 0, start = 0;
		for (int i = 0; i < gas.size(); ++i) {
			total += (gas[i] - cost[i]);
			if (sum < 0) { //发现油箱空了，从下一个站点尝试
				sum = (gas[i] - cost[i]);
				start = i;
			}
			else
				sum += (gas[i] - cost[i]);
		}
		return total < 0 ? -1 : start+1; //用total判断start 是否是满足要求的解
	}
	default:
		break;
	}
	
}
// 73. Set Matrix Zeroes
void Solution::setZeroes(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0)
		return;

	const size_t len_row = matrix.size();
	const size_t len_col = matrix[0].size();
	vector<bool> rowVec(len_row,false);
	vector<bool> colVec(len_col, false);

	for (int i = 0; i < len_row; i++)
		for (int j = 0; j < len_col; j++)
		{
			if (matrix[i][j] == 0)
			{
				rowVec[i] = true;
				colVec[j] = true;
			}
		}
	for (int i = 0; i < len_row; i++)
	{
		if (rowVec[i])
		{
			fill(matrix[i].begin(), matrix[i].end(), 0);
		}
	}
	for (int j = 0; j < len_col; j++)
	{
		if (colVec[j])
		{
			for (int i = 0; i < len_row; i++)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

// 89. Gray Code
vector<int> Solution::grayCode(int n)
{
	vector<int> result;
	const size_t size = pow(2, n);
	for (size_t i = 0; i < size; i++)
	{
		result.push_back(binary_to_gray(i));
	}
	return result;
}
//70. Climbing Stairs
int Solution::climbStairs(int n)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		// 由于使用阶乘，受值域的限制，当n很大时，超出值域，不适用
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		int ways = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			int len = n - i;
			int tmp = factorial(len) / (factorial(i)*factorial(len - i));
			ways += tmp;
		}
		return ways;
	}
	case 2:
	{
		// 斐波那契数列
		if (n <= 0)
			return 0;
		else if (n == 1)
			return 1;
		int prev = 0;
		int cur = 1;
		for (int i = 1; i <= n; i++) // i从1开始 ： 1 2 3 5 8...
		{
			int tmp = cur;
			cur += prev;
			prev = tmp;
		}
		return cur;
	}
	default:
		break;
	}
	
}
//48. Rotate Image
void Solution::rotate(vector<vector<int>>& matrix)
{
	if (matrix.empty())
		return;
	const int n = matrix.size();
	// 副对角线翻转
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i; j++) // 注意边界
		{
			std::swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		}
	}
	// 上下翻转
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j< n; j++)
		{
			std::swap(matrix[i][j], matrix[n - i - 1][j]);
		}
	}
	return;
}

//42. Trapping Rain Water
int Solution::trap(vector<int>& height)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		if (height.size() <= 2)
			return 0;
		int water = 0;
		for (int i = 1; i < height.size() - 1; i++)
		{
			auto left_largest = max_element(height.begin(), height.begin() + i); // 注意end()的位置是末尾的下一位
			auto right_largest = max_element(height.begin() + i + 1, height.end());
			int min_side = min(*left_largest, *right_largest);
			if (min_side > height[i])
				water = water + (min_side - height[i]);
		}
		return water;
	}
	case 2:
	{
		if (height.size() <= 2)
			return 0;
		int water = 0;
		auto iter_largest = max_element(height.begin(), height.end());
		int id_max = distance(height.begin(), iter_largest);
		// 处理最大值左边
		int bar = 0;
		for (int i = 0; i < id_max; i++)
		{
			if (height[i] > bar) bar = height[i];
			else water += (bar - height[i]);
		}
		// 处理最大值右边
		bar = 0;
		for (int i = height.size() - 1; i > id_max; i--)
		{
			if (height[i] > bar) bar = height[i];
			else water += (bar - height[i]);
		}
		return water;
	}
	default:
		break;
	}
	
}
// 60. Permutation Sequence
string Solution::getPermutation(int n, int k)
{
	vector<int> nums;
	long x = 1;
	for (int i = 1; i <= n; i++)
	{
		nums.push_back(i);
		x = x*i;
	}
	if (k > x || k <= 0)
		return string();
	int j = 1;
	while (j<k)
	{
		nextPermutation(nums);
		j++;
	}
	string permuStr = "";
	for (auto val : nums)
	{
		permuStr.push_back('0' + val);
	}
	return permuStr;
}
// 18. 4Sum
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> fourSumVec;
	if (nums.size() < 4) return fourSumVec;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3;i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		const int gap = target - nums[i];
		vector<int> nums_tmp(nums.begin()+i+1,nums.end());
		vector<vector<int>> threeSumVec = threeSum(nums_tmp, gap);
		if (threeSumVec.size() == 0) continue;
		for (int j = 0; j < threeSumVec.size(); j++)
		{
			fourSumVec.push_back({nums[i],threeSumVec[j][0],threeSumVec[j][1] ,threeSumVec[j][2] });
		}
	}
	return fourSumVec;
}
// 128. Longest Consecutive Sequence
int Solution::longestConsecutive(vector<int>& nums)
{
	if (nums.empty()) return 0;
	unordered_map<int, int> used;
	int longest = 0;
	for (auto i : nums)
	{
		used[i] = false;
	}
	for (auto i : nums)
	{
		if (used[i] == true) continue;
		int j = 0;
		int length = 1;
		for (j = i + 1; used.find(j) != used.end(); j++)
		{
			length++;
			used[j] = true;
		}
		for (j = i - 1; used.find(j) != used.end(); j--)
		{
			length++;
			used[j] = true;
		}
		longest = max(longest, length);
	}
	return longest;
}
// 4. Median of Two Sorted Arrays
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		const int len1 = nums1.size();
		const int len2 = nums2.size();
		const int len3 = len1 + len2;
		if (len3 % 2 == 0)
		{
			double x1 = findKthInTwoVec(nums1, nums2, len3 / 2 - 1);
			double x2 = findKthInTwoVec(nums1, nums2, len3 / 2);
			return (x1 + x2) / 2;
		}
		else
			return findKthInTwoVec(nums1, nums2, len3 / 2);
	}
	case 2:
	{
		const int len1 = nums1.size();
		const int len2 = nums2.size();
		const int len3 = len1 + len2;
		if (len3 == 0) return 0;
		else if (len3 != 0 && len1 == 0)
		{
			if (len3 % 2 == 0)
				return ((double)(double)nums2[len3 / 2 - 1] + (double)nums2[len3 / 2]) / 2;
			else
				return (double)nums2[len3 / 2];
		}
		else if (len3 != 0 && len2 == 0)
		{
			if (len3 % 2 == 0)
				return ((double)(double)nums1[len3 / 2 - 1] + (double)nums1[len3 / 2]) / 2;
			else
				return (double)nums1[len3 / 2];
		}

		int index1 = 0;
		int index2 = 0;
		vector<int>nums3;
		for (int i = 0; i < len3; i++)
		{
			if (index1 < len1 && index2 < len2)
			{
				if (nums1[index1] <= nums2[index2])
				{
					nums3.push_back(nums1[index1]);
					index1++;
				}
				else
				{
					nums3.push_back(nums2[index2]);
					index2++;
				}
			}
			else if (index1 >= len1 && index2 < len2)
			{
				nums3.push_back(nums2[index2]);
				index2++;
			}
			else if (index2 >= len2 && index1 < len1)
			{
				nums3.push_back(nums1[index1]);
				index1++;
			}
		}
		double mid = 0;
		if (len3 % 2 == 0) mid = (double)((double)nums3[len3 / 2 - 1] + (double)nums3[len3 / 2]) / 2;
		else mid = (double)nums3[len3 / 2];
		return mid;
	}
	default:
		break;
	}
	
}

// 81. Search in Rotated Sorted Array II
bool Solution::search2(vector<int>& nums, int target)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		int len = nums.size();
		for (int i = 0; i<len; i++)
		{
			if (nums[i] == target)
				return true;
		}
		return false;
	}
	case 2:
	{
		if (nums.empty()) return false;
		const int len1 = nums.size();
		int left = 0, right = len1 - 1;
		while (left <= right)
		{
			const int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[mid] > nums[left])
			{
				if (target >= nums[left] && target < nums[mid])
					right = mid-1;
				else
					left = mid + 1;
			}
			else if (nums[mid] < nums[left])
			{
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
				left++;
		}
		return false;
	}
	default:
		break;
	}
}

// 80. Remove Duplicates from Sorted Array II
int Solution::removeDuplicates2(vector<int>& nums)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		if (nums.empty())
			return 0;
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++)
		{
			map[nums[i]]++;
		}
		nums.clear();
		for (auto iter = map.begin(); iter != map.end();iter++)
		{
			if (iter->second == 1)
			{
				nums.push_back(iter->first);
			}
			else if (iter->second >= 2)
			{
				nums.push_back(iter->first);
				nums.push_back(iter->first);
			}
		}
		sort(nums.begin(),nums.end());
		return nums.size();
	}
	case 2:
	{
		if (nums.empty())
			return 0;
		int index = 0;
		int cnt = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[index] != nums[i])
			{
				nums[++index] = nums[i];
				cnt = 1;
			}
			else if (nums[index] == nums[i] && cnt < 2)
			{
				nums[++index] = nums[i];
				cnt++;
			}
		}
		return index + 1;
	}
	case 3:
	{
		const int n = nums.size();
		int index = 0;
		if (n <= 2) return n;
		for (int i = 2; i < n; i++)
		{
			if (i < n - 1 && nums[i - 1] == nums[i] && nums[i] == nums[i + 1])
				continue;
			nums[index++] = nums[i];
		}
		return index;
	}
	default:
		break;
	}
}

// 413. Arithmetic Slices
int Solution::numberOfArithmeticSlices(vector<int>& A)
{
	if (A.size() < 3)
		return 0;
	vector<int> dif;
	for (int i = 1; i < A.size(); i++)
	{
		int tmp = A[i] - A[i - 1];
		dif.push_back(tmp);
	}
	bool isA = false; //相邻三个数是否是算数递变的
	int j = 0;
	int sum_ari=0;// 算术片段的数量
	int step = 1;
	for (int i = 0; i < dif.size()-1; i=i+step)
	{
		isA = false;
		int j=i+1;
		while(j<dif.size())
		{
			if (dif[j] == dif[i])
			{
				j++;
				isA = true;
			}
			else
			{
				break;
			}
		}
		if (isA == true)
		{
			step = j - i;
			int x1 = step - 1;
			int x2 = x1*(x1 + 1) / 2;
			sum_ari = sum_ari + x2;
		}
		else
		{
			step = 1;
		}
	}
	return sum_ari;
}
// 43. Multiply Strings
string Solution::multiply(string num1, string num2)
{
	if (num1.empty() || num2.empty())
		return "";
	if (num1 == "0" || num2 == "0")
		return "0";
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	string ret = "";// 存储最终结果
	int carry = 0; // 进位
	int len1 = strlen(num1.c_str());
	int len2 = num2.size();
	for (int i = 0; i < len1; i++)
	{
		int tmp = 0;
		int pos = i;
		for (int j = 0; j < len2; j++)
		{
			tmp = (num1[i] - '0')*(num2[j] - '0') + carry;
			if (pos < ret.length())
			{
				tmp = tmp + (ret[pos] - '0');
				ret[pos] = tmp % 10 + '0';
			}
			else
			{
				ret.append(1, tmp % 10 + '0');
			}
			carry = tmp / 10;
			pos++;
		}
		if (carry > 0)
		{
			ret.append(1, carry + '0');
		}
		carry = 0;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
// 69 sqrt(x)
int Solution::mySqrt(int x)
{
	if (x <= 0) return 0;
	if (x == 1) return 1;
	int left = 0, right = x / 2;
	long mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long val = mid*mid;
		if (val == x) return mid;
		else if (val < x) left = mid + 1;
		else right = mid - 1;
	}
	return left-1;
}

// 7 reverse integer
int Solution::reverseInteger(int x)
{
	bool isPos = true;
	if (x < 0) isPos = false;
	else isPos = true;
	x = abs(x);
	vector<int> digitVec = getDigitVec(x);
	reverse(digitVec.begin(), digitVec.end());
	long x2 = 0;
	for (int i = digitVec.size() - 1; i >= 0;i--)
	{
		x2 = x2 + digitVec[i] * pow(10, digitVec.size() - i - 1);
	}
	if (x2 > 2147483647) x2 = 0; // 超出int的范围
	if (isPos == false)
	{
		x2 = -x2;
	}
	return x2;

}
// 367 valid perfect square
bool Solution::isPerfectSquare(int num)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		bool isP = false;
		long x = 1; // 注意整数的值域
		while (true)
		{
			if (x*x == num)
			{
				isP = true;
				break;
			}
			else if (x*x < num)
			{
				x++;
			}
			else
			{
				isP = false;
				break;
			}
		}
		return isP;
	}
	case 2:
	{
		// 二分查找
		if (num < 1) return false;
		if (num == 1) return 1;
		int left = 1, right = num / 2;
		int mid = 0;
		while (left < right)
		{
			mid = (left + right) / 2;
			int val = mid*mid;
			if (val == num) return true;
			else if (val < num) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
	default:
		break;
	}
	

}
// 268 missing number
int Solution::missingNumber(vector<int>& nums)
{
	int method = 1;
	switch (method)
	{
	case 1:
	{
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i != nums[i])
			{
				return i;
			}
		}
		return nums.size();
	}
	case 2:
	{
		int i = 0;
		while (i < nums.size())
		{
			int x = nums[i];
			if (x >= nums.size())
			{
				i++;
				continue;
			}
			if (i != nums[i])
			{
				swap(nums, x, i);
			}
			else
			{
				i++;
			}
		}
		for (int j = 0; j < nums.size(); j++)
		{
			if (j != nums[j])
				return j;
		}
		return nums.size();
	}
	default:
		break;
	}
	
}
// 400
int Solution::findNthDigit(int n)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		// 有问题，不好改
		int len_num = getNumLen(n);
		int x1 = 0;
		int i = 0;
		int cnt1 = 0;
		for (i = 0; i < len_num; i++)
		{
			if (i != 0)
			{
				x1 = x1 + (9 * pow(10, i - 1));
			}
			if (n < x1)
				break;
		}
		int y1 = x1 - (9 * pow(10, i - 1));
		int x2 = n - y1;
		int j;
		int sum2 = 0;
		for (j = 0; j < (9 * pow(10, i - 1)); j++)
		{
			sum2 = sum2 + i;
			if (sum2 > x2)
				break;
		}
		int x3 = sum2 - i;
		int x4 = x2 - x3; // 单位数的位置
		int y2 = y1 + x3 + 1; // 最接近的小于n的位数
		int digit = getDigitOfNum(y2, x4);
		return digit;
	}
	case 2:
	{
		// 该范围内所有实际数字都占用了digit个单数字
		int digit = 1;
		// 该范围之前的所有实际数字已经占用了totalDigit个单数字
		long totalDigit = 0;
		// 先查出区间范围
		while (true) {
			long top = totalDigit + digit * 9 * (long)pow(10, digit - 1);
			if (n >= totalDigit && n <= top)
				break;
			totalDigit = top;
			digit++;
		}

		// 根据范围算出具体的值
		int start = (int)pow(10, digit - 1);
		int ret = 0;
		totalDigit += 1;
		// 第n个digit在哪个具体的实际数字上
		int value = start + (n - (int)totalDigit) / digit;
		ret = getDigitOfNum(value, (int)((n - totalDigit) % digit));
		return ret;
	}
	default:
		break;
	}
	

}
string Solution::addStrings(string num1, string num2)
{
	// reverse num1 and num2
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int len1 = num1.size();
	int len2 = num2.size(); 
	int len = len1>len2 ? len1 : len2;
	if (len1<len2)
	{
		for (int i = 0; i < len - len1; i++)
		{
			num1.push_back('0');
		}
	}
	else
	{
		for (int i = 0; i < len - len2; i++)
		{
			num2.push_back('0');
		}
	}
	int c = 0;
	for (int i = 0; i < len; i++)
	{
		char tmp = num1[i] + num2[i]+c-'0';
		if (tmp > '9')
		{
			c = 1;
			tmp = tmp - 10; // '9'的后一位是‘：’
		}
		else
		{
			c = 0;
		}
		num1[i] = tmp;
	}
	if (c == 1)
	{
		num1.push_back('1');
	}
	reverse(num1.begin(), num1.end());
	return num1;
}
// 411
int Solution::arrangeCoins(int n)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		int len_row = 1;

		while (n >= len_row)
		{
			n = n - len_row;
			len_row++;
		}
		return len_row - 1;
	}
	case 2:
	{
		if (n == 0)
			return 0;
		long len_row = 1; // 不能是int 
		long sum1 = 0;
		while (1)
		{
			sum1 = len_row*(len_row + 1) / 2;
			long tmp = n - sum1;
			if (tmp < len_row+1 && tmp>=0)
			{
				return len_row;
			}
			len_row++;
		}
	}
	default:
		break;
	}
	
}
int Solution::minMoves(vector<int>& nums)
{
	auto smallest = min_element(begin(nums), end(nums));
	int sum_move = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum_move += (nums[i] - *smallest);
	}
	return sum_move;
}
int Solution::countPrimes(int n)
{
	int method=2;
	switch (method)
	{
	case 1:
		{
			if(n<=2)
				return 0;
			else if(n==3)
				return 1;
			else if(n==4)
				return 2;
			int count=1;
			for(int i=3;i<n;i++)
			{
				bool flag=false;
				for(int j=2;j<=sqrt(i)+1;j++)
				{
					if(i%j==0)
					{
						flag=true;
						break;
					}
				}
				if(flag==false)
					count++;
			}
			return count;
		}
	case 2:
		{
			if(n<=2)
				return 0;
			else if(n==3)
				return 1;
			int count=1;
			vector<int> prime_vec;
			prime_vec.push_back(2);
			for(int i=3;i<n;i++)
			{
				bool flag=false;
				for(int j=0;j<prime_vec.size();j++)
				{
					if(i%prime_vec[j]==0)
					{
						flag=true;
						break;
					}
				}
				if(flag==false)
				{
					prime_vec.push_back(i);
					count++;
				}
			}
			return count;
		}
	default:
		break;
	}
}
bool Solution::isValidSudoku(vector<vector<char>>& board)
{
	// 行检测
	for(int i=0;i<9;i++)
	{
		unordered_map<char,bool> rowValid;
		for(int j=0;j<9;j++)
		{
			if(board[i][j] != '.')
			{
				if(rowValid[board[i][j]]==true)
					return false;
				else
					rowValid[board[i][j]]=true;
			}
			
		}
	}
	// 列检测
	for(int i=0;i<9;i++)
	{
		unordered_map<char,bool> colValid;
		for(int j=0;j<9;j++)
		{
			if(board[j][i] != '.')
			{
				if(colValid[board[j][i]]==true)
					return false;
				else
					colValid[board[j][i]]=true;
			}
		}
	}
	// 子九宫格检测
	for(int i=0;i<9;i++)
	{
		unordered_map<char,bool> subValid;
		for(int j=0;j<9;j++)
		{
			int row=i/3*3+j/3;
			int col=i%3*3+j%3;
			if(board[row][col] != '.')
			{
				if(subValid[board[row][col]]==true)
					return false;
				else
					subValid[board[row][col]]= true;
			}
		}
	}
	return true;
}
int Solution::maxProfit3(vector<int>& prices)
{
	int min=INT_MAX;
 	int max=INT_MIN;
	vector<int> leftP;
	vector<int> rightP;
	if(prices.size()==0)
		return 0;
	for(int i=0;i<prices.size();i++)
	{
		min=prices[i]<min? prices[i]:min;
		max=prices[i]-min> max? prices[i]-min : max;     
		leftP.push_back(max); 
	}
	int max2=INT_MIN;
	int max3=INT_MIN;
	for(int i=prices.size()-1; i>=0;i--)
	{
		max2=prices[i]>max2 ? prices[i] : max2;
		max3=max2- prices[i]> max3 ?max2- prices[i] :  max3;
		rightP.push_back(max3);
	}
	reverse(rightP.begin(),rightP.end());
	int maxP=INT_MIN;
	for(int i=0;i<prices.size();i++)
	{
		int temp=leftP[i]+rightP[i];
		maxP=maxP> temp ? maxP :temp;
	}
	if(maxP<=0)
		return 0;
	else
		return maxP;

}
int Solution::maxProfit2(vector<int>& prices)
{
	int sumMax=0;
	if(prices.size()==0) return 0;
	for(int i=0;i<prices.size()-1;i++)
	{
		if(prices[i]<prices[i+1])
		{	
			sumMax=sumMax+(prices[i+1]-prices[i]);
		}
	}
	return sumMax;
}
int Solution::maxProfit(vector<int>& prices)
{
	int method=3;
	switch (method)
	{
	case 1:
		{
			// 超时
			int max=INT_MIN;
			if(prices.size()==0)
				return 0;
			for(int i=0;i<prices.size()-1;i++)
			{
				for(int j=i+1;j<prices.size();j++)
				{
					int temp=prices[j]-prices[i];
					if(temp>max)
					{
						max=temp;
					}
				}
			}
			if(max>0) return max;
			else return 0;
		}
	case 2:
		{
			// 超时
			int max=INT_MIN;
			if(prices.size()==0)
				return 0;
			for(int i=0;i<prices.size()-1;i++)
			{
				vector<int>:: iterator biggest;
				biggest=max_element(begin(prices)+i+1,end(prices));
				int temp=*biggest-prices[i];
				if(temp>max) max=temp;
			}
			if(max>0) return max;
			else return 0;
		}
	case 3:
		{
			int min=INT_MAX;
			int max=INT_MIN;
			if(prices.size()==0)
				return 0;
			for(int i=0;i<prices.size();i++)
			{
				min=min<prices[i]?min:prices[i];
				max=prices[i]-min>max? prices[i]-min :max;
			}
			return max;
		}
	default:
		break;
	}
}
int Solution::search(vector<int>& nums, int target)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		int target_ind = -1;
		int len = nums.size();
		bool flag = false;
		for (int i = 0; i<len; i++)
		{
			if (nums[i] == target)
			{
				target_ind = i;
				flag = true;
				break;
			}
		}
		if (flag = false)
			return -1;
		else
			return target_ind;
	}
	case 2:
	{
		if (nums.empty()) return -1;
		const int len1 = nums.size();
		int left = 0, right = len1 - 1;
		while (left <= right)
		{
			const int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] >= nums[left])
			{
				if (target >= nums[left] && target < nums[mid])
					right = mid;
				else
					left = mid + 1;
			}
			else
			{
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid;
			}
		}
		return -1;
	}
	default:
		break;
	}
	
}
void Solution::nextPermutation(vector<int>& nums)
{
	if(nums.size()==0)
		return;
	for(int i=nums.size()-2;i>=0;i--)
	{
		int min=INT_MAX;
		int k=-1;
		for(int j=nums.size()-1;j>i;j--)
		{
			if(nums[i]<nums[j] && nums[j]< min)
			{
				k=j;
				min=nums[j];
			}
		}
		if(k != -1)
		{
			int temp=nums[k];
			nums[k]=nums[i];
			nums[i]=temp;
			sort(nums.begin()+i+1,nums.end());
			return;
		}
	}
	// 如果是最大时
	for(int i=0;i<nums.size()/2;i++)
	{
		int temp=nums[i];
		nums[i]=nums[nums.size()-i-1];
		nums[nums.size()-i-1]=temp;
	}
	return;
}
 vector<vector<int>> Solution::threeSum(vector<int>& nums,int target=0)
 {
	 sort(nums.begin(),nums.end());
	 vector<vector<int>> three_vec;
	 if(nums.size()<3)
		return three_vec;
	 for(int i=0;i<nums.size()-2;i++)
	 {
		 if(i>=1 && nums[i]==nums[i-1])
			 continue;
		 int left=i+1,right=nums.size()-1;
		 bool isZero=false;
		 while(left<right)
		 {
			 if(isZero==true && nums[left-1]==nums[left] && nums[right]== nums[right+1])
			 {
				 left++;
				 right--;
				 continue;
			 }
			 isZero=false;

			 vector<int> three;
			 int sum3=nums[i]+nums[left]+nums[right];
			 if(sum3==target)
			 {
				 three.push_back(nums[i]);
				 three.push_back(nums[left]);
				 three.push_back(nums[right]);
				 three_vec.push_back(three);
				 right--;
				 left++;
				 isZero=true;
			 }
			 else if(sum3>target)
			 {
				 right--;
			 }
			 else
			 {
				 left++;
			 }
		 }
	 }
	 return three_vec;
 }
int Solution::threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(),nums.end());
	int min=100000;
	for(int i=0;i<nums.size()-2;i++)
	{
		int left=i+1,right=nums.size()-1;
		while(left<right)
		{
			int sum3=nums[i]+nums[left]+nums[right];
			int delta=sum3-target;
			if(abs(delta)<abs(min)) min=delta;
			if(delta==0) return target;
			else if(delta>0) right--;
			else   left++;
		}
	}
	return target+min;
}
int Solution::maxArea(vector<int>& height)
{
	int method=2;
	switch (method)
	{
	case 1:
		{
			// 超时
			int area;
			vector<int> area_vec;
			for(int i=0;i<height.size()-1;i++)
			{
				for(int j=i+1;j<height.size();j++)
				{
					int x=height[i]<height[j]?height[i]:height[j];
					area_vec.push_back(x*(j-i));
				}
			}
			vector<int>::iterator biggest=max_element(begin(area_vec),end(area_vec));
			area=*biggest;
			return area;
			break;
		}
	case 2:
		{
			int max_area=0;
			int left=0,right=height.size()-1;
			while(left<right && left<height.size() && right>=0)
			{
				int x=height[left]<height[right]?height[left]:height[right];
				int area_tmp=x*(right-left);
				max_area=max_area>area_tmp?max_area:area_tmp;
				if(height[left]<height[right])
					left++;
				else
					right--;
			}
			return max_area;
		}
	default:
		break;
	}
}
 vector<int> Solution::findDuplicates(vector<int>& nums)
 {
	 vector<int> nums2;
	 unordered_map<int,int> map;
	 for(int i=0;i<nums.size();i++)
	 {
		 if(map.find(nums[i])==map.end())
		 {
			 map[nums[i]]+=1;
		 }
		 else
		 {
			 if(map[nums[i]]==1)
			 {
				 nums2.push_back(nums[i]);
			 }	
		 }
	 }
	 return nums2;
 }
vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	int method = 2;
	switch (method)
	{
	case 1:
	{
		int x = 0;
		int i = 0, j = 0;
		bool flag = false;
		vector<int> index;
		for (i = 0; i<nums.size() - 1; i++)
		{
			x = target - nums[i];
			for (j = i + 1; j<nums.size(); j++)
			{
				if (nums[j] == x)
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
				break;
		}
		if (flag == true)
		{
			index.push_back(i);
			index.push_back(j);
		}
		return index;
	}
	case 2:
	{
		vector<int> indexVec;
		unordered_map<int, int> mapping;
		for (int i = 0; i < nums.size();i++)
		{
			mapping[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			const int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap]>i)
			{
				indexVec.push_back(i);
				indexVec.push_back(mapping[gap]);
				break;
			}
		}
		return indexVec;
	}
	default:
		break;
	}
	
}
int Solution::removeDuplicates(vector<int>& nums)
{
	int method=1;
	switch (method)
	{
	case 1:
		{
			unordered_map<int,int> map;
			for(int i=0;i<nums.size();i++)
			{
				map[nums[i]]++;
			}
			nums.clear();
			for(auto iter=map.begin();iter!=map.end();iter++)
			{
				nums.push_back(iter->first);
			}
			sort(nums.begin(),nums.end());
			return nums.size();
			break;
		}
	default:
		break;
	}
}
int Solution::removeElement(vector<int>& nums, int val)
{
	vector<int>::iterator iter;
	iter=nums.begin();
	while(iter != nums.end())
	{
		if(*iter==val)
		{
			iter=nums.erase(iter);
		}
		else
			++iter;
	}
	return nums.size();
}
vector<int> Solution::plusOne(vector<int>& digits)
{
	int carry=1;
    int i=digits.size()-1;
    for(;i>=0;i--)
    {
    	digits[i]=digits[i]+carry;
    	if(digits[i]==10)
    	{
    		carry=1;
    		digits[i]=0;
    	}
    	else
    	{
    		carry=0;
    		break;
    	}
    }
    if(i==-1 && carry==1)
    {
    	digits.insert(digits.begin(),1);
    }
    return digits;
}
//88
void Solution::merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int pa=m-1,pb=n-1,pc=m+n-1;
	while(pa>=0 && pb>=0)
	{
		if(nums1[pa]>=nums2[pb])
		{
			nums1[pc]=nums1[pa];
			pa--;
			pc--;
		}
		else
		{
			nums1[pc]=nums2[pb];
			pb--;
			pc--;
		}
	}
	while(pa>=0) 
	{
		nums1[pc--]=nums1[pa--];
	}
	while(pb>=0)
	{
		nums1[pc--]=nums2[pb--];
	}
}
// 88
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> nums3;
	int i=0;
	int k=0;
	bool flag=false;
	int j=0;
	for(int i=0;i<nums1.size();i++)
	{
		for(j=k;j<nums2.size();j++)
		{
			if(nums1[i]<=nums2[j])
			{
				nums3.push_back(nums1[i]);
				if(j==nums2.size()-1)
				{
					nums3.push_back(nums2[j]);
				}
				break;
			}
			else
			{
				nums3.push_back(nums2[j]);
				if(k<nums2.size()-1)
				{
					k=j+1;
				}
				else
				{
					flag=true;
					break;
				}
			}
		}
		if(flag==true)
		{
			nums3.push_back(nums1[i]);
		}
	}
	nums1.clear();
	for(int i=0;i<nums3.size();i++)
	{
		nums1.push_back(nums3[i]);
	}
}
//119
vector<int> Solution::getRow(int rowIndex)
{
	vector<int> vec_row;
	vec_row.push_back(1);
	for(int row=0;row<rowIndex;row++)
	{
		vector<int> vec_row2;
		vec_row2.push_back(vec_row[0]);
		for(int i=0;i<vec_row.size()-1;i++)
		{
			vec_row2.push_back(vec_row[i]+vec_row[i+1]);
		}
		vec_row2.push_back(vec_row[vec_row.size()-1]);
		vec_row=vec_row2;
	}
	return vec_row;
}
// 118
vector<vector<int>> Solution::generate(int numRows) 
{
	vector<int> vec_row;
	vector<vector<int>> P_triangle;
	vec_row.push_back(1);
	for(int row=0;row<numRows;row++)
	{
		vector<int> vec_row2;
		vec_row2.push_back(vec_row[0]);
		for(int i=0;i<vec_row.size()-1;i++)
		{
			vec_row2.push_back(vec_row[i]+vec_row[i+1]);
		}
		P_triangle.push_back(vec_row);
		vec_row2.push_back(vec_row[vec_row.size()-1]);
		vec_row=vec_row2;
	}
	return P_triangle;
}
// 217
bool Solution::containsDuplicate(vector<int>& nums) 
{
	unordered_map<int,int> map;
	for(int i=0;i<nums.size();i++)
	{
		if(map.find(nums[i]) != map.end())
		{
			return true;	
		}
		else
		{
			map[nums[i]]=1;
		}
	}
}
//219
bool Solution::containsNearbyDuplicate2(vector<int>& nums, int k)
{
	bool flag=false;
	unordered_map<int,int> map;
	for(int i=0;i<nums.size();i++)
	{
		if(map.find(nums[i]) != map.end() && i-map[nums[i]]<=k)
		{
			flag=true;	
		}
		else
		{
			map[nums[i]]=i;
		}
	}
	return flag;
}
// 219
bool Solution::containsNearbyDuplicate(vector<int>& nums, int k)
{
	bool flag=false;
	if(nums.size()<=1)
		return flag;
	for(int i=0;i<nums.size()-1;i++)
	{
		for(int j=i+1;j<nums.size();j++)
		{
			if(nums[i]==nums[j] && j-i<=k)
			{
				flag=true;
				break;
			}
		}
	}
	return flag;
}
// 414
int Solution::thirdMax(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	reverse(nums.begin(),nums.end());
	int n=1;
	int temp=nums[0];
	for (int i=0;i<nums.size();i++)
	{
		if(nums[i]<temp)
		{
			n++;
			temp=nums[i];
		}
		if(n==3)
		{
			break;
		}
	}
	if(n<3)
	{
		temp=nums[0];
	}
	return temp;
}

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