#pragma once
/****************************************
*461.�������� 
��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��

������������ x �� y����������֮��ĺ������롣

ע�⣺
0 �� x, y < 231.

ʾ��:

����: x = 1, y = 4

���: 2

����:
1   (0 0 0 1)
4   (0 1 0 0)
	   ��   ��

����ļ�ͷָ���˶�Ӧ������λ��ͬ��λ�á�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/hamming-distance
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6
class Solution {
public:
	int hammingDistance(int x, int y) {
		int tmp = x ^ y;
		int ret{ 0 };
		while (tmp != 0)
		{
			if (tmp & 1 == 1)
				++ret;
			tmp =tmp >> 1;
		}
		return ret;
	}
};

