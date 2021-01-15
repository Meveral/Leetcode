#pragma once
/****************************************
*135.分发糖果
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
	 第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;

/****************************************
测试：首尾遍历两次
	1.初始化，ret均置为1
	2.for i in range(1,size),哨兵为val[i-1],若比哨兵大，则糖果=哨兵+1，反之为1；
	3.for i in range(size-1,0),哨兵为val[i+1],若比哨兵大，且糖果没有哨兵多，则糖果=哨兵+1，

复杂度:O(N)-O(N)，只需知道哨兵大小，空间复杂度应该可优化为O(1);
***************************************/
class Solution {
public:
	int candy(vector<int>& ratings)
	{
		if (ratings.empty())
			return 0;

		int sz = ratings.size();
		vector<int> ret(sz, 1);
		int sum{};

		for (int i = 1; i < sz; ++i)
		{
			if (ratings[i] > ratings[i - 1])
				ret[i] = ret[i - 1] + 1;
			else
				ret[i] = 1;
		}
		for (int i = sz - 2; i >= 0; --i)
		{
			if (ratings[i] > ratings[i + 1])
			{
				if(ret[i]<=ret[i+1])
				ret[i] = ret[i+1]+1;
			}
			sum += ret[i];
		}
		sum += ret[sz - 1];


		return sum;
	}
};




