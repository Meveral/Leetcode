#pragma once
/****************************************
*85.最大矩形 
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = [["0"]]
输出：0
示例 4：

输入：matrix = [["1"]]
输出：1
示例 5：

输入：matrix = [["0","0"]]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;

/****************************************
有一种思路，假设5*5矩阵,(下标从1开始):
	1).倍率为2,1行与2行相乘，得到一个01序列；2与3相乘...一共得到4个序列，遍历，得到连1最长的子序列，记录行号a*b，记录最大值为连1的数目*倍率
	2).假设1）中得到的行号为2*3，
	
 
***************************************/
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) 
	{
		if (matrix.empty())
			return 0;


	}
};

