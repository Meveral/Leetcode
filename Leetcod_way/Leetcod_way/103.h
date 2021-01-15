#pragma once
/****************************************
*103.二叉树的锯齿形层序遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/****************************************
经典的层序遍历：两个vector
***************************************/
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		if (root == NULL)
			return {};

		vector < vector<int> > ret{};
		vector<TreeNode*> v1{ root };
		vector<TreeNode*> v2{};
		bool mark = true;

		do
		{
			if(mark == true)
			{
				vector<int>to_ret{};
				for (auto it = v1.rbegin(); it != v1.rend(); ++it)
				{
					auto& node = **it;
					do_it(v2, node.right);
					do_it(v2, node.left);
					to_ret.push_back(node.val);
				}
				vector<int> tmp(to_ret.rbegin(),to_ret.rend());
				ret.push_back(tmp);
				v1.clear();
				mark = false;
				if (v2.empty())
					return ret;
			}
			else
			{
				vector<int>to_ret{};
				for (auto it = v2.rbegin(); it != v2.rend(); ++it)
				{
					auto& node = **it;
					do_it(v1, node.left);
					do_it(v1, node.right);

					to_ret.push_back(node.val);
				}
				vector<int> tmp(to_ret.rbegin(),to_ret.rend());
				ret.push_back(tmp);
				v2.clear();
				mark = true;
				if (v1.empty())
					return ret;
			}
		} while (true);
		return ret;
	}
	inline void do_it(vector<TreeNode*>&v1, TreeNode*node)
	{
		if (node != NULL)
			v1.push_back(node);
	}
};

