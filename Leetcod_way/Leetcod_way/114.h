#pragma once
/****************************************
*114.二叉树展开为链表
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

	1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-12
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root)
			do_it(root);

	}
	TreeNode* do_it(TreeNode* root)
	{
		if (!root->left&&root->right)//0L 1R
		{
			auto ret = do_it(root->right);
			return ret;
		}
		else if (root->left && !root->right)//1L 0R
		{
			auto ret = do_it(root->left);
			root->right = root->left;
			root->left = nullptr;
			return ret;

		}
		else if (root->left&&root->right)//1L 1R
		{
			auto tmp = root->right;
			auto ret = do_it(tmp);
			auto last = do_it(root->left);
			root->right = root->left;
			root->left = nullptr;
			last->right = tmp;
			return ret;
		}
		return root;
	}
};

