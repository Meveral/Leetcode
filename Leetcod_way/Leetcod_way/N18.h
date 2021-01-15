#pragma once
#include"MeveralUse_HeadersUsual.h"
/****************************************
*18.四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		map<int, pair<int, int>> mp;//sum-Index<first,second>
		vector<vector<int>> ret{};

		//遍历nums，找出所有二元组组合
		find_all_binarysum(nums, mp);

		//组合不同的二元组
		vector<vector<int>> tmp{};
		find_target_of_2(target, mp, tmp);

		//输出无重复元素的结果
		for (auto it : tmp)
		{
			set<int> temp{};
			for (auto i : it)
				temp.emplace(i);
			if (temp.size() == 4)
			{
				vector<int> foo(temp.begin(), temp.end());
				ret.push_back(foo);
			}
		}
		return ret;
	}

private:
	void find_all_binarysum(vector<int>& nums, map<int, pair<int, int>>& mp)
	{
		int size = nums.size();
		for (int i = 0; i < size; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				mp.emplace(make_pair(nums[i] + nums[j], make_pair(i, j)));
			}
		}
	}

	void find_target_of_2(int target, map<int, pair<int, int>>& mp, vector<vector<int>> res)
	{
		typedef vector<pair<int, int>> locations;
		map<int, locations> tmp{};//<value-locations>;
		for (auto it = mp.begin(); it != mp.end(); ++it)
		{
			auto fd = mp.find(target - it->first);
			if (fd != mp.end() && fd != it)
			{
			}
		}
	}
};
