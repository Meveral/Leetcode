#pragma once
/****************************************
*46.ȫ����
����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-7
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>{};

		vector<vector<int>> ret{ vector<vector<int>> {vector<int>{}} };
		for (auto&it : nums)//�����ѭ�������и���������{1,2,3}
		{
			vector<vector<int>> tmp2{};

			for (auto&itt : ret)//e.g. ret = {{1,2},{2,1}}
			{
				auto tmp = itt;
				tmp.push_back(it);//tmp = {1,2,3}
				int sz = tmp.size();
				for (int i = 0; i < sz; ++i)
				{
					auto tmp_c = tmp;//tmp_c ={1,2,3}
					swap(tmp_c[i], tmp_c[sz - 1]);
					tmp2.push_back(tmp_c);
				}
			}
			ret = tmp2;
		}
		return ret;

	}

};





