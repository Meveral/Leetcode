#pragma once
/****************************************
*264.��ת������
��תһ�ö�������

ʾ����

���룺

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
�����

	 4
   /   \
  7     2
 / \   / \
9   6 3   1
��ע:
����������ܵ� Max Howell �� ԭ���� ������ ��

�ȸ裺����90���Ĺ���ʦʹ������д�����(Homebrew)��������ȴ�޷�������ʱ�ڰװ���д����ת����������⣬��̫����ˡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/invert-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == NULL)
			return root;
		else
		{
			auto tmp = root->left;
			root->left = root->right;
			root->right = tmp;
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};


