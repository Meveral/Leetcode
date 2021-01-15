#pragma once
/****************************************
*235. 二叉搜索树的最近公共祖先
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

 

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

***************************************/
#include"dft.h"

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//		vector<int> post_order{};
		if (root == NULL)
			return NULL;
		vector<TreeNode*> p_fathers{};
		vector<TreeNode*> q_fathers{};
		find_it(root, p, p_fathers);
		find_it(root, q, q_fathers);

		TreeNode* tmp{ NULL };
		for (auto& it : p_fathers)
		{
			for (auto& itt : q_fathers)
			{
				if (it == itt)
					tmp = itt;
			}
		}
		return tmp;
	}

	TreeNode* find_it(TreeNode* root, TreeNode* p, vector<TreeNode*>& pfathers)
	{
		if (root == NULL)
			return NULL;

		if (root == p)
		{
			pfathers.push_back(root);
			return root;
		}
		else
		{
			if (find_it(root->left, p, pfathers) != NULL || find_it(root->right, p, pfathers) != NULL)
			{
				pfathers.push_back(root);
				return root;
			}
			else return NULL;
		}
	}
};
