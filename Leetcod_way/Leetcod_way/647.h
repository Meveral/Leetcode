#pragma once
/****************************************
*647. 回文子串

给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

输入的字符串长度不会超过 1000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include"dft.h"

class Solution {
public:
	int countSubstrings(string& s) {
		if (s.empty())
			return 0;

		int ret{ 0 };
		for (int i = 0; i != s.size(); ++i)
		{
			ret += style_1(s, i);
			ret += style_2(s, i);
		}
		return ret;
	}

	int style_1(string& s, int i)
	{
		int count{ 0 };
		int j{ 0 };
		int left = i - j;
		int right = i + j;
		while (left >= 0 && right < s.size())
		{
			if (s[left--] == s[right++])
				count++;
			else
				break;
		}
		return count;
	}

	int style_2(string& s, int i)
	{
		int count{ 0 };
		int j{ 1 };
		int left = i;
		int right = i + j;
		while (left >= 0 && right < s.size())
		{
			if (s[left--] == s[right++])
				count++;
			else
				break;
		}
		return count;
	}
};
