#pragma once
/****************************************
*49.字母异位词分组 
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"
using namespace std;

/****************************************
排序+哈希;
排序字符串;
查看字符串是否位新字符串,
	若1，添坑，记录坑位；
	若0，填坑。
***************************************/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		vector<vector<string>> ret{};
		if (strs.empty())
			return ret;

		auto tmp = strs;
		map<string, int> mp{};//str->location;
		int count{0};
		

		//排序
		for (auto &it : tmp)
			sort(it.begin(), it.end());

		//存储结果
		for (int i = 0; i < tmp.size(); ++i)
		{
			string str = tmp[i];
			string str_to_push = strs[i];
			if (mp.find(str) == mp.end())//is a new string
			{
				vector<string> tmp_{str_to_push};
				ret.push_back(tmp_);
				mp[str] = count;
				++count;
			}
			else
			{
				ret[mp[str]].push_back(strs[i]);
			}

		}
		return ret;
	}
};










