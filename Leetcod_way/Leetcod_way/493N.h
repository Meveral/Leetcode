#pragma once
/****************************************
*493.翻转对
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。

示例 1:

输入: [1,3,2,3,1]
输出: 2
示例 2:

输入: [2,4,3,5,1]
输出: 3
注意:

给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"
using namespace std;

//感觉跟比大小一样，只是有个倍数关系。
class Solution {
public:
	//1超时了，好气，不过1的复杂度只是N~2-一些重复的数，说到底还是N~2，超时也意料之中。
	int reversePairs1(vector<int>& nums)
	{
		if (nums.empty())
			return 0;

		int ret{ 0 };
		vector<int> dic(nums.size(), -1);

		for (int i = 0; i < nums.size(); ++i)
		{
			if (dic[i] != -1)
				ret += dic[i];
			else
				ret += do_less(nums[i], nums, i, dic);
		}

		return ret;
	}
	//
	int do_less(int a, vector<int>& nums, int begin, vector<int>& dictionary)
	{
		int ret{ 0 };
		double flag = (double)a / 2;
		for (int i = begin + 1; i < nums.size(); ++i)
		{
			if (nums[i] == a)
			{
				if (nums[i] < flag)
					++ret;
				if (dictionary[i] == -1)
					ret += do_less(nums[i], nums, i, dictionary);
				else
					ret += dictionary[i];
				break;
			}
			else if (nums[i] < flag)
				++ret;
		}
		dictionary[begin] = ret;
		return ret;
	}

	//原来是用分治算法。自己写的有点问题，耗时太长，还是得看答案...
	int reversePairs2(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int ret = do_dc(nums, 0, nums.size() - 1);
		return ret;
	}
private:
	int do_dc(vector<int>& nums, int left, int right)//[]
	{
		int ret{ 0 };
		if (left == right)
			return 0;
		else
		{
			int middle = (left + right) / 2;
			ret += do_dc(nums, left, middle);
			ret += do_dc(nums, middle + 1, right);
			ret += do_cross_dc(nums, left, right);
		}
		return ret;
	}
	int do_cross_dc(vector<int>&nums, int left, int right)
	{
		if (left == right)
			return 0;

		int ret{ 0 };
		int middle = (left + right) / 2;

		//排序
		std::sort(nums.begin() + left, nums.begin() + middle + 1, std::less<int>());
		std::sort(nums.begin() + middle + 1, nums.begin() + right + 1, std::less<int>());

		//比较数组1中的每个数小于数组2的每个数的总和。应该是本算法的核心。
		int tmp_count{ 0 };
		int v1 = left;
		int v1_end = middle + 1;
		int v2 = middle + 1;
		while (v1 != v1_end)
		{
			double flag = (double)nums[v1] / 2;
			if (flag > nums[v2])
			{
				++tmp_count;
				if (v2 == right)
					break;
				else
					++v2;
			}
			else
			{
				ret += tmp_count;
				++v1;
			}
		}
		ret += (v1_end - v1)*tmp_count;



		return ret;
	}
};
//
class Solution2 {
public:
	int find_reversed_pairs(vector<int>& nums, int& left, int& right) {
		int res = 0, mid = left + (right - left) / 2;
		int i = left, j = mid + 1;
		for (; i <= mid; i++) {
			while (j <= right && (long)nums[i] > 2 * (long)nums[j]) {
				res += mid - i + 1;
				j++;
			}
		}
		return res;
	}

	int merge_sort(vector<int>& nums, vector<int> nums_sorted, int left, int right) {
		if (left >= right) return 0;
		int mid = left + (right - left) / 2;

		//divide and conquer.
		int res = merge_sort(nums, nums_sorted, left, mid) +
			merge_sort(nums, nums_sorted, mid + 1, right) +
			find_reversed_pairs(nums, left, right);

		int i = left, j = mid + 1, ind = left;

		while (i <= mid && j <= right) 
		{
			if (nums[i] <= nums[j]) nums_sorted[ind++] = nums[i++];
			else nums_sorted[ind++] = nums[j++];
		}
		while (i <= mid) nums_sorted[ind++] = nums[i++];
		while (j <= right) nums_sorted[ind++] = nums[j++];

		for (int ind = left; ind <= right; ind++)
			nums[ind] = nums_sorted[ind];

		return res;
	}

	int reversePairs(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> nums_sorted(nums.size(), 0);
		return merge_sort(nums, nums_sorted, 0, nums.size() - 1);
	}
};











