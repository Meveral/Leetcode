#pragma once
/****************************************
*130. 被围绕的区域
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		queue<pair<int, int>> que{};
		int row = board.size();
		int col = board[0].size();

		//Initialize:find boundary survival points;
		for (int y = 0; y != col; ++y)
		{
			if (board[0][y] == 'O')
				que.emplace(make_pair(0, y));
			if (board[row - 1][y] == 'O')
				que.emplace(make_pair(row - 1, y));
		}
		for (int x = 0; x != row; ++x)
		{
			if (board[x][0] == 'O')
				que.emplace(make_pair(x, 0));
			if (board[x][col - 1] == 'O')
				que.emplace(make_pair(x, col - 1));
		}

		//dfs
		int shift_x[5] = { 1,-1,0,0 };
		int shift_y[5] = { 0,0,1,-1 };
		while (!que.empty())
		{
			pair<int, int> central_point = que.front();
			que.pop();
			int cx = central_point.first;
			int cy = central_point.second;
			if (board[cx][cy] == 'A')
				continue;
			else
				board[cx][cy] = 'A';
			//radio
			for (int i = 0; i != 4; ++i)
			{
				int x = cx + shift_x[i];
				int y = cy + shift_y[i];
				if (x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O')
					que.emplace(make_pair(x, y));
			}
		}

		//make 'A'->'O','O'->'X';
		for (auto &row_elements : board)
		{
			for (auto &it : row_elements)
			{
				if (it == 'A')
					it = 'O';
				else if (it == 'O')
					it = 'X';
			}
		}
	}
};
