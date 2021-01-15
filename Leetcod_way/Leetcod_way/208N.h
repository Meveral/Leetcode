#pragma once
/****************************************
*208.实现Trie(前缀树) 
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
//2021-1-13
//改天看了前缀树再来
#include<MeveralUse_HeadersUsual.h>
using namespace std;
class Trie {
public:
	/** Initialize your data structure here. */
	Trie(const string&s) {
		mps[s.front()].push_back(s);
		sets.emplace(s);

	}
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word) {

		mps[word.front()].push_back(word);
		sets.emplace(word);

	}

	/** Returns if the word is in the trie. */
	bool search(string word) {

		if (sets.find(word) == sets.end())
			return false;
		else
			return true;

	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		int sz = prefix.size();
		bool ret{ true };
		auto it = mps.find(prefix.front());//it = (char,vector<string>)
		if (it == mps.end())
			return false;
		else
		{
			for (auto&word : (it->second))//every string
			{
				bool mark{ true };
				if (word.size() < sz)
					continue;
				else
				{
					for (int i = 0; i < sz; ++i)
					{
						if (word[i] != prefix[i])
						{
							mark = false;
							break;
						}
					}
					if (mark == true)
						return true;
				}
			}
			return false;
		}
	}

	unordered_map<char, vector<string>> mps{};
	unordered_set<string> sets{};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//Trie* trie = new Trie();
//trie->insert("apple");
//trie->search("apple");   // 返回 true
//trie->search("app");     // 返回 false
//trie->startsWith("app"); // 返回 true
//trie->insert("app");
//trie->search("app");     // 返回 true


