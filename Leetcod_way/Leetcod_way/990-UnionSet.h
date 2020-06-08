#pragma once

#include<vector>
#include<string>
#include<numeric>

using std::vector;
using std::string;

class UnionFind {

public:

	UnionFind() {
		parent.resize(26);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int index)
	{
		if (index == parent[index])
			return parent[index];
		parent[index]= find(parent[index]);
		return parent[index];
	}

	
	void merge(const int index1, const int index2)
	{
		parent[find(index2)] = find(index1);
	}

private:

	std::vector<int> parent;

};
class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		UnionFind collection;
		for (const string& equ : equations)
		{
			if (equ[1] == '=')
			{
				int index1 = equ[0] - 'a';
				int index2 = equ[3] - 'a';
				collection.merge(index1, index2);
			}
		}
		for (const string& equ : equations)
		{
			if (equ[1] == '!')
			{
				int index1 = equ[0] - 'a';
				int index2 = equ[3] - 'a';
				if (collection.find(index1) == collection.find(index2))
					return false;
			}
		}
		return true;
	}
};
