#pragma once
/****************************************
*417,太平洋大西洋水流问题
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~
	   ~  1   2   2   3  (5) *
	   ~  3   2   3  (4) (4) *
	   ~  2   4  (5)  3   1  *
	   ~ (6) (7)  1   4   5  *
	   ~ (5)  1   1   2   4  *
		  *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2020-12-30    

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
	{
		if (matrix.empty())
			return vector<vector<int>>();

		vector<vector<int>> ret{};
		int m = matrix.size();
		int n = matrix.begin()->size();
		//太平洋
		queue<pair<int, int>> que0{};
		vector<vector<char>> mark0( m,vector<char>(n,'0') );
		for (int i = 0; i < m; ++i)
		{
			que0.push(make_pair(i, 0));
			mark0[i][0] = '1';
		}
		for (int i = 1; i < n; ++i)
		{
			que0.push(make_pair(0, i));
			mark0[0][i] = '1';
		}
		while (!que0.empty())
		{
			int a = que0.front().first;
			int b = que0.front().second;
			que0.pop();
			//(a+1,b)(a-1,b)(a,b+1)(a,b+1)
			do_it(a, b, 1, 0, mark0, matrix, que0);
			do_it(a, b, -1, 0, mark0, matrix, que0);
			do_it(a, b, 0, 1, mark0, matrix, que0);
			do_it(a, b, 0, -1, mark0, matrix, que0);
		}

		//大西洋
		queue<pair<int, int>> que1{};
		vector<vector<char>> mark1( m,vector<char>(n,'0') );
		for (int i = m-1; i >=0 ; --i)
		{
			que1.push(make_pair(i, n-1));
			mark1[i][n-1] = '1';
		}
		for (int i = n-1; i >= 0; --i)
		{
			que1.push(make_pair(m-1, i));
			mark1[m-1][i] = '1';
		}
		while (!que1.empty())
		{
			int a = que1.front().first;
			int b = que1.front().second;
			que1.pop();
			//(a+1,b)(a-1,b)(a,b+1)(a,b+1)
			do_it(a, b, 1, 0, mark1, matrix, que1);
			do_it(a, b, -1, 0, mark1, matrix, que1);
			do_it(a, b, 0, 1, mark1, matrix, que1);
			do_it(a, b, 0, -1, mark1, matrix, que1);
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mark0[i][j] == '1'&&mark1[i][j] == '1')
					ret.push_back(vector<int>{i,j});
			}
		}


		return ret;
	}
	inline	void do_it(const int& a, const int&b, const int& dif_a, const int&dif_b, vector<vector<char>>&mark, vector<vector<int>>&matrix, queue<pair<int, int>>&que)
	{
		int m = matrix.size();
		int n = matrix.begin()->size();
		int a_tmp = a + dif_a;
		int b_tmp = b + dif_b;
		if ((a_tmp >= 0) && (a_tmp < m) && (b_tmp >= 0) && (b_tmp < n))
		{
			if (mark[a_tmp][b_tmp] == false)
			{
				if (matrix[a_tmp][b_tmp] >= matrix[a][b])
				{
					matrix[a_tmp][b_tmp] = true;
					que.push(make_pair(a_tmp, b));
				}
			}
		}
	}
};





