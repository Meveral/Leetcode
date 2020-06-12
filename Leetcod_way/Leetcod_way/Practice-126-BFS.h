//just a try.
//This can`t find all min_distance route.(maybe some,but not all)
#include<string>
#include<vector>
#include<set>
#include<deque>

using namespace std;

int INF = 1 << 20;

class wordProperty {
public:
	wordProperty(int i1, int i2, int i3, int i4, string s)
		:color(i1), distance(i2), id(i3), pi(i4), word(s)
	{};

	int color = 0;//012-white gray black
	int distance = INF;
	const int id = 0;
	int pi = INF;
	const string word{};
};

bool relative(const string &s1, const string &s2)
{
	size_t size = s1.size();
	size_t dif_count = 0;
	for (int i = 0; i != size; ++i)
	{
		if (s1[i] != s2[i]) ++dif_count;
	}
	return dif_count > 1 ? 0 : 1;
}



class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	
		set<string> wordlist(wordList.begin(), wordList.end());
		vector<wordProperty> words{};
		vector<vector<string>> paths{};
		int minDis = INF + 10;
		int id = 0;

		if (wordlist.find(endWord) == wordlist.end())
			return {};

		wordProperty s(1, 0, id, INF, beginWord);
		words.push_back(s);
		for (auto it : wordlist)
		{
					words.push_back(wordProperty(0, INF, ++id, INF, it));
		}
		
		deque<wordProperty*> Q{ &*words.begin() };//in deque

		while (!Q.empty())
		{
			auto &u =*Q.begin();
			for (auto &it : words)//all search range
			{
				if (it.color == 0)//accurate search range
				{
					if (relative(it.word, u->word))//relative word which meet requirement
					{
						if (u->distance + 1 > minDis)
						{
							it.color = 2;
							it.distance = u->distance + 1;
							it.pi = u->id;
						}
						else if (u->distance + 1 == minDis)
						{
							if (it.word == endWord)
							{
								minDis = u->distance + 1;
								vector<string> path{};
								path.push_back(it.word);
								int up_id = u->id;
								while (up_id != INF)
								{
									path.push_back(words[up_id].word);
									up_id = words[up_id].pi;
								}
								vector<string> rpath(path.rbegin(), path.rend());
								paths.push_back(rpath);
							}
							else
							{
								it.color = 2;
								it.distance = u->distance + 1;
								it.pi = u->id;
							}
						}
						else
						{
							if (it.word == endWord)
							{
								minDis = u->distance + 1;
								vector<string> path{};
								path.push_back(it.word);
								int up_id = u->id;
								while (up_id != INF)
								{
									path.push_back(words[up_id].word);
									up_id = words[up_id].pi;
								}
								vector<string> rpath(path.rbegin(), path.rend());
								paths.push_back(rpath);
							}
							else
							{
								it.color = 1;
								it.distance = u->distance + 1;
								it.pi = u->id;
								Q.push_back(&it);
							}
						}
					}
				}
			}
			u->color = 2;
			Q.pop_front();//out deque
		}
		return paths;
	}
};