#pragma once
/****************************************
*78.子集 
给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。

 
示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-8
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>{vector<int>{}};

		vector<vector<int>> ret{};
		ret.push_back(vector<int>{});

		for (auto&it : nums)
		{
			int tmp_sz = ret.size();
			for (int i = 0; i < tmp_sz; ++i)
			{
				vector<int> tmp__ = ret[i];
				tmp__.push_back(it);
				ret.push_back(tmp__);
			}
		}
		return ret;
	}
};
