#pragma once
/****************************************
* 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include"dft.h"

class Solution {
public:

	bool cmp(pair<int, int>& p1, pair<int, int>& p2)
	{
		return p1.second > p2.second;
	}

	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		map<int, int> counts;
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> que(cmp);
		vector<int> ret;

		for (auto it : nums)
			counts[it]++;

		for (auto it : counts)
		{
			if (que.size() < k)
				que.emplace(make_pair(it.first, it.second));
			else if (it.second > que.top().second)
			{
				que.pop();
				que.emplace(make_pair(it.first, it.second));
			}
		}

		while (!que.empty())
		{
			ret.push_back(que.top().first);
			que.pop();
		}

		return ret;
	}
};
