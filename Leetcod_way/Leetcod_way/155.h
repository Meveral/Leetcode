#pragma once
/****************************************
*155.最小栈 
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

pop、top 和 getMin 操作总是在 非空栈 上调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() :pri_stack(vector<int>{}), size(0), min_val(INF) {

	}

	void push(int x) {
		if (size < pri_stack.size())
			pri_stack[size] = x;
		else
			pri_stack.push_back(x);
		++size;
		if (x < min_val)
			min_val = x;

	}

	void pop() {
		--size;
		if (size == 0)
			min_val = INF;
		else
			min_val = *std::min_element(pri_stack.begin(), pri_stack.begin() + size);
	}

	int top() {
		return pri_stack[size - 1];
	}

	int getMin() {
		return min_val;
	}
private:
	vector<int> pri_stack;
	int min_val;
	int size;
	static const int INF = 0x7fffffff;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
