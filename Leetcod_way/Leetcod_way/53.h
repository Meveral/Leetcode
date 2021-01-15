#pragma once
/****************************************
*53.最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-7
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int ret{ -0x7fffffff };
		int may_max{ 0 };
		for (auto&it : nums)
		{
			may_max += it;
			ret = max(ret, may_max);
			if (it < 0) may_max = max(may_max, 0);
		}
		return ret;
	};

	int maxSubArray_dc(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums.front();

		int a = do_side(nums, 0, nums.size() / 2);
		int b = do_side(nums, nums.size() / 2, nums.size());
		int c = do_middle(nums, 0, nums.size());
		return max(a, max(b, c));
	}
	int do_side(vector<int>& nums, int begin, int end)
	{
		if (begin + 1 == end)
			return nums[begin];
		int a = do_side(nums, begin, (begin + end) / 2);
		int b = do_side(nums, (begin + end) / 2, end);
		int c = do_middle(nums, begin, end);
		return max(a, max(b, c));
	}
	int do_middle(vector<int>& nums, int begin, int end)
	{
		if (begin + 2 == end)
			return nums[begin] + nums[begin + 1];
		// begin ... mid_left || mid_right ... end -1
		int mid_left = (begin + end) / 2 - 1;
		int ret_left{ 0 };
		int max_left{ -0x7fffffff };
		for (int i = mid_left; i >= begin; --i)
		{
			ret_left += nums[i];
			max_left = max(max_left, ret_left);
		}

		int mid_right = mid_left + 1;
		int ret_right{ 0 };
		int max_right{ -0x7fffffff };
		for (int i = mid_right; i < end; ++i)
		{
			ret_right += nums[i];
			max_right = max(max_right, ret_right);
		}
		return max_left + max_right;

	}

};



