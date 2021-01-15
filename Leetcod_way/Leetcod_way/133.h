#pragma once
/****************************************
* 133. 克隆图

给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
	public int val;
	public List<Node> neighbors;
}
 

测试用例格式：

简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。

邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。

给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

示例见图。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include<vector>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

#include<map>
#include<set>
#include<queue>
/*
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL)
			return;
		set<int> sign{};
		queue<Node*> que;
		map<int, Node*> mps;

		//first:
		que.emplace(node);
		while (!que.empty())
		{
			auto n = que.front();
			que.pop();
			if (sign.find(n->val) != sign.end())
				continue;
			mps.emplace(n->val, new Node(n->val));
			sign.insert(n->val);
			for (auto it: n->neighbors)
			{
				que.push(it);
			}
		}

		sign.clear();
		//second:
		que.emplace(node);
		while (!que.empty())
		{
			auto n = que.front();
			que.pop();
			if (sign.find(n->val) != sign.end())
				continue;

			auto n_value = n->val;
			auto clone_n = mps[n_value];
			for (auto it : n->neighbors)
			{
				clone_n->neighbors.push_back(mps[it->val]);
				que.emplace(it);
			}
			sign.insert(n->val);
		}
		return mps.begin()->second;
	}
};
*/
//dfs：暂定，下此再写
class Solution {
public:
	Node* cloneGraph(Node* node) {
	}

	Node* dfs(Node* node, vector<Node*> &vec)
	{
		vec.push_back(new Node(node->val));
		for (auto it : node->neighbors)
		{
			vec.back->nerghbors.push_back(dfs(it, vec));
		}
	}
};
