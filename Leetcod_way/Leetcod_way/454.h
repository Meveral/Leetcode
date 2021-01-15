/****************************************
*454.四数相加
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"
using namespace std;

//好像做过四数之和的类似题目。
//总结：形同N数相加的题目，都可变成N/2+N/2，可简化复杂度，注意最后一步可以不再存map里，直接使用数据，另外如果不需要排序信息，可以使用无序map。
class Solution {
public:
	//方法一，四遍遍历。啊超时了，还是想算法吧- -，感觉像是递归，或者多叉树？

	int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		if (A.empty())
			return 0;

		map<value, count> mpA{};
		map<value, count> mpAB{};
		map<value, count> mpABC{};
		map<value, count> mpABCD{};

		for (auto& it : A)
			++mpA[it];
		for (auto& it : B)
		{
			for (auto& a : mpA)
				mpAB[it + a.first] += a.second;
		}
		for (auto&it : C)
		{
			for (auto&a : mpAB)
				mpABC[it + a.first] += a.second;
		}
		for (auto&it : D)
		{
			for (auto&a : mpABC)
				mpABCD[it + a.first] += a.second;
		}

		return mpABCD[0];
	}

	//  方法2:忽然想到另一种遍历方法，将1+1+1+1变成2+2实际实现的效率巨差，不过也在意料之中。
	//	...其实效率还可以，效率低是因为map没用无序map。
	int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		if (A.empty())
			return 0;
		size_t ret{ 0 };
		unordered_map<value, count> mpAB{};
		for (auto& it : A)
		{
			for (auto& b : B)
				++mpAB[it + b];
		}
		for (auto& it : C)
		{
			for (auto& b : D)
			{
				auto fd = mpAB.find(-(it + b));
				if (fd != mpAB.end())
					ret += fd->second;
			}

		}



		return ret;
	}


	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		if (A.empty())
			return 0;

		size_t ret{ 0 };

		map<value, count> BCD_sum{};
		map<value, count> CD_sum{};
		for (auto&it : A)
		{
			//若未找到，说明未遍历过，需遍历。
			if (BCD_sum.find(-it) == BCD_sum.end())
				do_something(BCD_sum,B,C,D);
			// 若找到，则直接加次数。
			ret += BCD_sum[-it];
		}
			






			return ret;
	}

private:
	void do_something(map<int, size_t>& BCD_sum, vector<int>&B, vector<int>&C, vector<int>&D);
	typedef int value;
	typedef size_t count;
};


