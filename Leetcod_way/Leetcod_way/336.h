/****************************************
*336.回文对
给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。

输入: ["abcd","dcba","lls","s","sssll"]
输出: [[0,1],[1,0],[3,2],[2,4]]
解释: 可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#pragma once
#include<vector>
#include<string>
#include<map>

using namespace std;

bool IsPalindrome(string s)
{
	if (s.empty())
		return 0;
	auto left = s.begin();
	auto right = s.end() - 1;
	while (left < right)
	{
		if (*left++ != *right--)
			return 0;
	}
	return 1;
}

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> result{};
		vector<int> nullwords;//record null words;
		map<char, vector<int>> first_letter{};
		map<char, vector<int>> last_letter{};

		for (int i = 0; i != words.size(); ++i)
		{
			//			first_letter[words[i].front()].push_back(i);
			if (!words[i].empty())
				last_letter[words[i].back()].push_back(i);
			else
				last_letter['\0'].push_back(i);
		}

		for (int i = 0; i != words.size(); ++i)
		{
			if (words[i].empty())
			{
				for (int j = 0; j != words.size(); ++j)
				{
					if (j != i)
					{
						if (IsPalindrome(words[i] + words[j]))
						{
							result.push_back({ i, j });
							result.push_back({ j, i });
						}
					}
				}
			}
			else
			{
				for (auto it : last_letter[words[i].front()])
				{
					if (i != it)
					{
						if (IsPalindrome(words[i] + words[it]))
						{
							result.push_back({ i,it });
						}
					}
				}
			}
		}

		return result;
	}
};
