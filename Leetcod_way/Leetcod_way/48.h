#pragma once
/****************************************
*48.旋转图像 
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-11
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n > 1)
		{
			int r = n / 2;
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < r; ++j)
				{
					do_it(matrix, i, j);
				}
			}
			if (n % 2 == 1)
			{
				int i = n / 2;
				for (int j = 0; j < n / 2; ++j)
				{
					do_it(matrix, i, j);
				}
			}

		}
	}
	void do_it(vector<vector<int>>& matrix, int x, int y)
	{
		int n = matrix.size() - 1;
		pair<int, int> head(x, y);
		int head_val = matrix[x][y];

		matrix[x][y] = matrix[n - y][x];
		matrix[n - y][x] = matrix[n - x][n - y];
		matrix[n - x][n - y] = matrix[y][n - x];
		matrix[y][n - x] = head_val;
	}
};
