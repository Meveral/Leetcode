﻿#pragma once

/****************************************
*169.多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：[3,2,3]
输出：3
示例 2：

输入：[2,2,1,1,1,2,2]
输出：2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count{ 0 };
		int number{ nums.front() };
		for (auto&it : nums)
		{
			if (it == number)
				++count;
			else
				--count;

			if (count == 0)
			{
				count = 1;
				number = it;
			}
		}
		return  number;

	}
};
