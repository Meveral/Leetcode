#pragma once
/****************************************
*283.�ƶ��� 
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/move-zeroes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6
//G ,˫ָ��
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size(), left = 0, right = 0;
		while (right < n) {
			if (nums[right]) {
				swap(nums[left], nums[right]);
				left++;
			}
			right++;
		}
	}
};



