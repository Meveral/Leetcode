#pragma once
/****************************************
*43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		if (num1 == "1")
			return num2;
		if (num2 == "1")
			return num1;
		string ret{};
		int weight = 0;
		for(auto it =num1.rbegin();it!=num1.rend();++it)
		{
			string tmp{};
			string_mul_char(num2, *it, tmp);
			for (int i = 0; i != weight; ++i)
				tmp += '0';
			string_add_string(ret, tmp);
			++weight;
		}
		return ret;
	}

	void string_mul_char(string& s, char& c, string &ret)
	{
		char char_0 = '0';
		int c_value = c - char_0;
		int overflow = 0;
		for (auto it = s.rbegin(); it != s.rend(); ++it)
		{
			int multi_ed = (int)(*it - '0') * c_value;
			int res = multi_ed + overflow;
			if (res < 10)
			{
				char c0 = res + (int)('0');
				ret = c0 + ret;
				overflow = 0;
			}
			else
			{
				char c0 = (res % 10) + (int)('0');
				ret = c0 + ret;
				overflow = res / 10;
			}
		}
		if (overflow != 0)
		{
			char c0 = overflow + '0';
			ret = c0 + ret;
		}
	}
	string& string_add_string(string& ret, string&s2)
	{
		int dif = s2.size() - ret.size();
		int overflow = 0;
		if (dif > 0)
		{
			//将s1补到s2大小
			for (int i = 0; i < dif; ++i)
				ret = '0' + ret;
		}

		for (int i = ret.size() - 1; i >= 0; --i)
		{
			int tmp = ret[i] - '0' + s2[i] - '0' + overflow;
			if (tmp < 10)
			{
				ret[i] = tmp + '0';
				overflow = 0;
			}
			else
			{
				ret[i] = (tmp % 10) + '0';
				overflow = tmp / 10 ;
			}
		}
		if (overflow != 0)
			ret = '1' + ret;
		return ret;
	}
};
