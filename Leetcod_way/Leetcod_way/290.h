#pragma once
/****************************************
*290.单词规律 
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"
using namespace std;

/****************************************
//一一映射，用map映射字符和字符串
遍历str的每个单词，查询单词是否映射
	若已经映射，查询映射关系和pattern是否符合
		若符合，continue
		若不符合，返回false
	若未映射，说明可能为新单词，查询字符是否有映射关系，
		若没有，构造映射
		若有，返回false
返回true
FA:
	两者长度不一致，return false;
***************************************/
class Solution {
public:
	bool wordPattern(string pattern, string s) 
	{
		map<string, char> mp{};
		map<char, string> mp2{};
		auto it = pattern.begin();

		stringstream ss(s);
		string word;
		vector<string>  words;
		while (ss >> word)
			words.push_back(word);

		int dif = pattern.size() - words.size();
		if (dif != 0)
			return false;


		for(auto&word:words)
		{
			auto tmp = mp.find(word);
			if (tmp != mp.end())
			{
				if (tmp->second != *it)
					return false;
			}
			else
			{
				auto tmp2 = mp2.find(*it);
				if (tmp2 == mp2.end())
				{
					mp[word] = *it;
					mp2[*it] = word;
				}
				else
					return false;
			}
			++it;
		}
		return true;
	}
};


