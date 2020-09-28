#pragma once
/****************************************
*529.扫雷游戏
让我们一起来玩扫雷游戏！

给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minesweeper
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include"dft.h"

class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int	x = click[0];
		int	y = click[1];
		char c = board[x][y];
		if (c == 'M')
		{
			board[x][y] = 'X';
			return board;
		}
		if (c == 'E')
		{
			queue<pair<int, int>> q{};
			q.emplace(make_pair(x, y));
			do_E(board, q);
			for (auto& it : board)
			{
				for (auto& itt : it)
					if (itt == 'O')
						itt = 'B';
			}
		}
		return board;
	}
private:
	void do_E(vector<vector<char>>& board, queue<pair<int, int>>& q)
	{
		int x_shift[8] = { 0,0,1,1,1,-1,-1,-1 };
		int y_shift[8] = { 1,-1,-1,0,1,-1,0,1 };
		int x_size = board.size();
		int y_size = board.begin()->size();
		while (!q.empty())
		{
			int M_count = 0;
			auto it = q.front();
			int x = it.first;
			int y = it.second;
			vector<pair<int, int>> points_to_enqueue{};
			board[x][y] = 'O';
			q.pop();

			for (int i = 0; i != 8; ++i)
			{
				int x_next = x + x_shift[i];
				int y_next = y + y_shift[i];
				if (x_next >= 0 && x_next < x_size&&y_next >= 0 && y_next < y_size)
				{
					if (board[x_next][y_next] == 'E')
						points_to_enqueue.push_back(make_pair(x_next, y_next));
					else if (board[x_next][y_next] == 'M')
						++M_count;
				}
			}
			if (M_count != 0)
				board[x][y] = M_count + '0';
			else
			{
				for (auto &it : points_to_enqueue)
				{
					board[it.first][it.second] = 'O';
					q.emplace(std::move(it));
				}
			}
		}
	}
};
