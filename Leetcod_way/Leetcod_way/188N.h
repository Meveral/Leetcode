#pragma once
/****************************************
*188.买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
	 随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 

提示：

0 <= k <= 109
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;

/****************************************
三维动态规划：是否有股票、日期、交易次数
动态规划:
have_stock[i][j]:第i天时候，手中拥有股票，且恰好进行了j次交易。
	have_stock[i][j]=max(假设股票是i天买的，假设股票不是i天买的)=max(no_stock[i-1][j]-prices[i],have_stock[i-1][j])

no_stock[i][j]:第i天时候，手中没有股票，且恰好进行了j次交易。
	no_stock[i][j]=max(假设股票是i天卖的，假设股票不是i天卖的)=max(have_stock[i-1][j-1]+prices[i],no_stock[i-1][j])
	
注意边界条件.
***************************************/
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) 
	{
		if (k == 0 || prices.empty()||prices.size()==1)
			return 0;

		int sz = prices.size();
		k = min(k, sz / 2);
		vector<vector<int>> have_stock(sz, vector<int>(k + 1, 0));
		vector<vector<int>> no_stock(sz, vector<int>(k + 1, 0));

		for (int i = 0; i < k; ++i)
		{
			have_stock[0][i] = -65536;
			no_stock[0][i] = -65536;
		}
		have_stock[0][0] = -prices[0];
		no_stock[0][0] = 0;
		//求no_stock[i][0-k]的最大值。
		for (int i = 1; i < sz; ++i) {
			have_stock[i][0] = max(have_stock[i - 1][0], no_stock[i - 1][0] - prices[i]);
			for (int j = 1; j <= k; ++j) {
				have_stock[i][j] = max(have_stock[i - 1][j], no_stock[i - 1][j] - prices[i]);
				no_stock[i][j] = max(no_stock[i - 1][j], have_stock[i - 1][j - 1] + prices[i]);
			}
		}
		return *max_element(no_stock[sz-1].begin(),no_stock[sz-1].end());
	}
};
