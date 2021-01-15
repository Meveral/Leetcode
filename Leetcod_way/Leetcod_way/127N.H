#pragma once
/****************************************
*127.单词接龙
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	 返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"
using namespace std;

//层序遍历，测试(果然超时了，淦！)
class Solution_overtime {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		if (beginWord == endWord)
			return 1;
		queue<string> que{};
		int count{ 1 };
		map<string, bool> mark{};

		que.emplace(beginWord);
		mark[beginWord] = 1;

		while (!que.empty())
		{
			++count;
			auto tmp_que = new queue<string>{};
			while (!que.empty())
			{
				auto it = que.front();
				for (auto w : wordList)
					if (is_right(w, it) && (mark.find(w) == mark.end()))
					{
						tmp_que->emplace(w);
						mark[w] = 1;
						if (w == endWord)
						{
							return count;
						}
					}
				que.pop();
			}
			que = *tmp_que;
		}

		return 0;
	}

private:
	inline void find_one_dif(string word, vector<string>& wordList, queue<string>*que, map<string, bool>&mark)
	{

	}
	inline bool is_right(string& word, string& target_word)
	{
		int count{ 0 };
		for (int i = 0; i != word.size(); ++i)
		{
			if (word[i] != target_word[i])
				++count;
			if (count > 1)
				return false;
		}
		return true;
	}
};

//深度优先,应该可以
//dfs+备忘录
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		for (auto it : wordList)
		{
			if (is_right(it))

		}

		do_dfs();

	}
private:
	void do_dfs(string&beginWord, string&endWord, vector<string>&wordList)
	{
		for (auto it : wordList)
		{
			if (is_right(it, beginWord))
			{


			}

		}

	}

	inline bool is_right(string& word, string& target_word)
	{
		int count{ 0 };
		for (int i = 0; i != word.size(); ++i)
		{
			if (word[i] != target_word[i])
				++count;
			if (count > 1)
				return false;
		}
		return true;
	}
};
