#pragma once
/****************************************
*101.对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

	1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

	1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-7
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		vector<int>v1{};
		vector<int>v2{};

		do_1(v1, root);
		do_2(v2, root);
		return v1 == v2;

	}
	void do_1(vector<int>& v1, TreeNode* root)
	{
		if (root != NULL)
		{
			do_1(v1, root->left);
			do_1(v1, root->right);
			v1.push_back(root->val);
		}
		else
			v1.push_back(INF);
	}
	void do_2(vector<int>& v1, TreeNode* root)
	{
		if (root != NULL)
		{
			do_2(v1, root->right);
			do_2(v1, root->left);
			v1.push_back(root->val);
		}
		else
			v1.push_back(INF);
	}
	static const int INF = 0x7fffffff;
};




/****************************************
*	TreeNode A(1);
	TreeNode B(2);
	TreeNode C(2);
	TreeNode D(3);
	TreeNode E(4);
	TreeNode F(4);
	TreeNode G(3);
	A.left = &B;
	A.right = &C;
	B.left = &D;
	B.right= &E;
	C.left = &F;
	C.right= &G;
	Solution sol;
	sol.isSymmetric(&A); 
***************************************/

