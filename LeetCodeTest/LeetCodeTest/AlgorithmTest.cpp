#include "mainTest.h"

//算法导论15.1 钢条切割，动规版，bottom-up
int AlgorithmTest::bottomUpCutRop(vector<int>& p, int n)
{
	vector<int> ri;
	ri.push_back(0);
	if (n <= 0)
		return 0;
	for (int i = 1; i <= n; i++)
	{
		int r_max = 0;
		for (int j = 1; j <= i; j++)
		{
			int r_tmp = p[j - 1] + ri[i - j];
			if (r_max < r_tmp)
			{
				r_max = r_tmp;
			}
		}
		ri.push_back(r_max);
	}
	return ri[n];
}
//钢条切割，动规版的子函数
int AlgorithmTest::memoizedCutRodAux(vector<int>& p,int n,vector<int>& ri)
{
	// 先判断是否为0的情况
	if (n == 0)
	{
		return 0;
	}
	if (ri.size() >= n)
		return ri[n - 1];
	int r_max=0;
	for(int i = 1; i<= n; i++)
	{
		int r_tmp=p[i-1]+ memoizedCutRodAux(p,n - i,ri);
		r_max = r_max>r_tmp? r_max : r_tmp;
	}
	ri.push_back(r_max);
	return r_max;
}

//算法导论15.1 钢条切割，动规版，top-bottom
int AlgorithmTest::memoizedCutRod(vector<int> p, int n) {
	vector<int> ri; // 备份
	int result=memoizedCutRodAux(p,n,ri);
	return result;
}

// 算法导论15.1 钢条切割
int AlgorithmTest::cutRod(vector<int> p, int n)
{
	int method =1;// 1 递归，2 非递归
	switch(method)
	{
	case 1:
	{
		if (n == 0)
			return 0;
		int r_max = 0;
		for (int i = 1; i <= n; i++)
		{
			int r_tmp1 = p[i - 1];
			int r_tmp2 = cutRod(p, n - i);
			int r_tmp = r_tmp1 + r_tmp2;
			r_max = r_max>r_tmp ? r_max : r_tmp;
		}
		return r_max;
	}
	}
	
}