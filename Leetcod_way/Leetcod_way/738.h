#pragma once
/****************************************
*738.单调递增的数字 
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_headersUsual.h"
using namespace std;


/****************************************
1.高位->低位
2.高位的取值受限于所有低位的取值,e.g：abcd
	若a>(bcd算法后的最高位e)，则取最终数为(a-1)999;
	反之，取a(bcd算法后的值);
***************************************/
class Solution {
public:
	int monotoneIncreasingDigits(int N)
	{
		string str{ to_string(N) };
		string ret = do_it(str.begin(),str.end());

		return std::stoi(ret);
	}


private:
	//用迭代器写的好怪啊。
	string do_it(string::iterator c,string::iterator end)
	{
		if ((c+1) == end)
			return  string(1,*c);

		string tmp = do_it((c+1), end);
		if ((*c) > tmp.front())
		{
			for (auto it = (c+1); it != end; ++it)
				(*it) = '9';
			(*c) = (*c) - 1;
			return string(c, end);
		}
		else
			return (*c) + tmp;
	}

};

