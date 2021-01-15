#pragma once
/****************************************
*22.括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
	   "((()))",
	   "(()())",
	   "(())()",
	   "()(())",
	   "()()()"
	 ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-8
class Solution_0 {
public:
	vector<string> generateParenthesis(int n) {
		if (!n)
			return vector<string>{};

		vector<string> ret{};
		generate_it(2 * n, 0, ret, "");

		return ret;
	}
	bool generate_it(int n, int dif, vector<string>& ret, const string& tmp)
	{
		if (n == 0 || dif < 0)
			return false;

		if (dif == 1 && n == 1)
			ret.push_back(tmp + ")");
		else
		{
			generate_it(n - 1, dif - 1, ret, tmp + ")");
			generate_it(n - 1, dif + 1, ret, tmp + "(");
		}

		return true;
	}
};

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (!n)
			return vector<string>{};
		vector<string> ret{};

		vector<string> tmp{};
		for (int i = 0; i < 2 * n; ++i)
		{
					


		}




		return ret;
	}
};



