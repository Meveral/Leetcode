#pragma once
/****************************************
*637. 二叉树的层平均值
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

 

示例 1：

输入：
	3
   / \
  9  20
	/  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include"dft.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {

		if (root == NULL)
		{
			return {};
		}

		vector<TreeNode*> nodes{};
		nodes.push_back(root);
		vector<double> ret{};
		double sum{ 0 };
		int count{ 0 };

		while (!nodes.empty())
		{
			vector<TreeNode*> tmp;
			for (auto it : nodes)
			{
				sum += it->val;
				count++;
				if (it->left != nullptr)
					tmp.push_back(it->left);
				if (it->right!= nullptr)
					tmp.push_back(it->right);
			}
			double it = sum / count;
			ret.push_back(std::move(it));
			sum = 0;
			count = 0;
			nodes = std::move(tmp);
		}
		return ret;
	}
};
