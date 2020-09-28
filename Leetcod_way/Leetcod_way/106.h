#pragma once
/****************************************
*106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

	3
   / \
  9  20
	/  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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

/*
后序遍历最后的点为root节点,中序遍历root节点左侧为左子树，右侧为右子树.
	1.找到postorder尾元素root,
	
*/
 
class Solution {
public:
	using location = size_t;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty())
			return nullptr;

		map<int, location> find_tree{};//value->location
		for (int i = 0; i != inorder.size(); ++i)
		{
			find_tree[inorder[i]] = i;
		}
			auto root_value= postorder.back();
			auto it = find_tree[root_value];
			TreeNode* root_node = new TreeNode(root_value);
			root_node->left = do_left(0,it, inorder);	//[begin,end)
			root_node->right= do_right(it+1,inorder.size(), inorder);

			return root_node;
		}
	
		TreeNode* do_left(location begin,location end, vector<int>& inorder)
		{
			if (begin == end)
				return new TreeNode(inorder[begin]);
			TreeNode* tmp_node = new TreeNode(inorder[end]);
			tmp_node->left = do_left()

		}
		TreeNode* do_right(location begin,location end, vector<int>& inorder);

		
		
	
};



