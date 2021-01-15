#pragma once
/****************************************
*39.组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-12
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<int> tmp{};
		do_it(candidates,0, tmp, target);

		return ret;

	}
	void do_it(vector<int>&candidates,int i, vector<int>&tmp, int target)
	{
		if (i < candidates.size() && target>0)
		{
			do_it(candidates, i + 1, tmp, target);
			tmp.push_back(candidates[i]);
			do_it(candidates, i, tmp, target-candidates[i]);
			tmp.pop_back();//这个厉害
		}
		else if (i < candidates.size() && target == 0)
		{
			ret.push_back(tmp);
		}
		
	}
	vector<vector<int>> ret{};
};
