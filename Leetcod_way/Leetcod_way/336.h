/****************************************
*336.���Ķ�
����һ��Ψһ�ĵ��ʣ� �ҳ����в�ͬ ��������(i, j)��ʹ���б��е��������ʣ� words[i] + words[j] ����ƴ�ӳɻ��Ĵ���

����: ["abcd","dcba","lls","s","sssll"]
���: [[0,1],[1,0],[3,2],[2,4]]
����: ��ƴ�ӳɵĻ��Ĵ�Ϊ ["dcbaabcd","abcddcba","slls","llssssll"]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
