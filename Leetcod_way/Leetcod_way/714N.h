#pragma once
/****************************************
*714. 买卖股票的最佳时机含手续费
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include"MeveralUse_HeadersUsual.h"
using namespace std;
/****************************************
经典买卖股票，多了一个限制条件
s.t.每次交易需要扣除利息
无非是每次交易时候决策，做不做这笔生意;
算差值，得到每天的势力变化值。

从i=0开始:
do_have_food(i):
若i为尾,判断 power[i] - 利息 < 0;
	若1，则返回0；并记录利润
	若0，返回利润；并记录利润
判断power[i] < 0，
	若1，此时肯定不会开始做生意，记录maxP[i] = do_have_food(i+1),并返回maxP[i];
	若0，可以考虑，抉择是否做生意
		做：power[i]+do_no_food(i+1);
		不：do_have_food(i+1);

do_no_food(i):
若i为尾,,判断 power[i] - 利息 < 0;
	若1，则返回0；并记录利润
	若0，返回利润，并记录利润
抉择生意还做不做，
	做：power[i]+do_no_food(i+1)
	不：do_have_food(i+1) - 利息;
***************************************/
//虽然做出来了， 效率一般，记得去看题解
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee)
	{
		if (prices.empty()||prices.size() == 1)
			return 0;

		vector<int> power{};
		for (int i = 1; i < prices.size(); ++i)
			power.push_back(prices[i] - prices[i - 1]);
		map<int, int> MaxProfit_no_stock{};
		map<int, int> MaxProfit_have_stock{};
		return do_no_stock(0, power, fee, MaxProfit_no_stock, MaxProfit_have_stock);
	}
	int do_no_stock(int i, vector<int>&power, int fee, map<int, int>&MaxProfit_no_stock, map<int, int>&MaxProfit_have_stock)
	{
		if (MaxProfit_no_stock.find(i) != MaxProfit_no_stock.end())
			return MaxProfit_no_stock[i];

		if (i == power.size() - 1)
			MaxProfit_no_stock[i] = (power[i] - fee) > 0 ? (power[i] - fee) : 0;
		else
		{
			if (power[i] < 0)
				MaxProfit_no_stock[i] = do_no_stock(i + 1, power, fee, MaxProfit_no_stock, MaxProfit_have_stock);
			else
				MaxProfit_no_stock[i] = max(	power[i] + do_have_stock(i+1, power, fee, MaxProfit_no_stock, MaxProfit_have_stock), \
											do_no_stock(i + 1, power, fee, MaxProfit_no_stock, MaxProfit_have_stock));
		}
		return MaxProfit_no_stock[i];
	}
	int do_have_stock(int i, vector<int>&power, int fee, map<int, int>&MaxProfit_no_stock, map<int, int>&MaxProfit_have_stock)
	{
		if (MaxProfit_have_stock.find(i) != MaxProfit_have_stock.end())
			return MaxProfit_have_stock[i];

		if (i == power.size() - 1)
			MaxProfit_have_stock[i] = (power[i] - fee) < 0 ? -fee : (power[i] - fee);
		else
			MaxProfit_have_stock[i] = max(power[i] + do_have_stock(i + 1, power, fee, MaxProfit_no_stock, MaxProfit_have_stock),  \
										-fee + do_no_stock(i + 1, power, fee, MaxProfit_no_stock, MaxProfit_have_stock));

		return MaxProfit_have_stock[i];
	}
};


