#pragma once
/****************************************
*46.全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-7
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>{};

		vector<vector<int>> ret{ vector<vector<int>> {vector<int>{}} };
		for (auto&it : nums)//最外层循环，排列个数的增加{1,2,3}
		{
			vector<vector<int>> tmp2{};

			for (auto&itt : ret)//e.g. ret = {{1,2},{2,1}}
			{
				auto tmp = itt;
				tmp.push_back(it);//tmp = {1,2,3}
				int sz = tmp.size();
				for (int i = 0; i < sz; ++i)
				{
					auto tmp_c = tmp;//tmp_c ={1,2,3}
					swap(tmp_c[i], tmp_c[sz - 1]);
					tmp2.push_back(tmp_c);
				}
			}
			ret = tmp2;
		}
		return ret;

	}

};





