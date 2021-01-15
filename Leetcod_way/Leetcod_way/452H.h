#pragma once
#include<algorithm>
/****************************************
*452. 用最少数量的箭引爆气球
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

 
示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
示例 3：

输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
示例 4：

输入：points = [[1,2]]
输出：1
示例 5：

输入：points = [[2,3],[2,3]]
输出：1
 

提示：

0 <= points.length <= 104
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/

#include"MeveralUse_HeadersUsual.h"
using namespace std;

inline bool compare_func(vector<int> &v1, vector<int>& v2)
{
	return v1.at(0) <= v2.at(0);
}
//算法正确， 但效率不甚理想，不过跟leetcode官方解法思路一致：排序（NlogN）+贪心（N），不过还应该找到更快的算法。
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points)
	{
		if (points.empty())
			return 0;

		int ret{ 1 };
		vector<pair<int, int>> arrows{};
		sort(points.begin(), points.end(), compare_func);
		arrows.push_back(make_pair(points.begin()->at(0), points.begin()->at(1)));

		for (auto it = points.begin() + 1; it != points.end(); ++it)
		{
			pair<int, int> point = { it->front(),it->back() };
			do_(arrows, ret, point);
		}

		return ret;
	}
private:
	//内部实现算法，(测试);
	void do_(vector<pair<int, int>>& arr, int& ret, pair<int, int>& point)
	{
		auto& last_arrow = arr.back();
		auto a = last_arrow.first;
		auto b = last_arrow.second;
		auto c = point.first;
		auto d = point.second;
		//we know a<=c; 

		if (c <= b && d <= b) //first,p1 inclue p2;
		{
			last_arrow.first = c;
			last_arrow.second = d;
		}
		else if (c<b&&d>b) //then,p1 crossing p2;
		{
			last_arrow.first = c;
		}
		else if (c == b && d > b)//相切
		{
			last_arrow.first = c;
			last_arrow.second = c;
		}
		else //else all
		{
			++ret;
			arr.push_back(make_pair(c, d));
		}
	}
};




