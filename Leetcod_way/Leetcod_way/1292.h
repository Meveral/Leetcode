#pragma once
/****************************************
*1292.元素和小于等于阈值的正方形的最大边长
给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。

请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。
 

示例 1：



输入：mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
输出：2
解释：总和小于 4 的正方形的最大边长为 2，如图所示。
示例 2：

输入：mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
输出：0
示例 3：

输入：mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
输出：3
示例 4：

输入：mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
输出：2
 

提示：

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2020-12-29
class Solution {
public:
	int maxSideLength(vector<vector<int>>& mat, int threshold)
	{
		if (mat.empty() || threshold == 0)
			return 0;
		int ret{ 0 };
		int m = mat.size();
		int n = mat.begin()->size();

		//二维矩阵前缀和
		for (int i = 1; i < m; ++i) mat[i][0] += mat[i - 1][0];
		for (int i = 1; i < n; ++i) mat[0][i] += mat[0][i - 1];
		for (int i = 1; i < m; ++i) for (int j = 1; j < n; ++j) mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mat[i][j] <= threshold)
					ret = max(ret, 1);

				int dif = ret;
				int a = i - dif;
				int b = j - dif;
				while (a >= 0 && b >= 0)
				{
					int a1 = a - 1;
					int b1 = b - 1;
					int s1 = a1 >= 0 ? mat[a1][j] : 0;
					int s2 = b1 >= 0 ? mat[i][b1] : 0;
					int s3 = (a1 >= 0 && b1 >= 0) ? mat[a1][b1] : 0;
					int s_tmp = mat[i][j] - s1 - s2 + s3;
					if (s_tmp <= threshold)//1
					{
						++ret;
						--a;
						--b;
					}
					else
						break;

				}
			}
		}
		return ret;
	}
};




