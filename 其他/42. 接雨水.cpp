/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty())
			return 0;

		auto maxEle = std::max_element(height.begin(), height.end());

		int ret = 0;
		int left = 0;
		int right = 0;
		for (auto it = height.begin(); it < maxEle; it++)
		{
			right = *it;
			if (right < left)
			{
				ret = ret + (left - right);
			}
			else
			{
				left = right;
			}
		}
		left = 0;
		for (auto it = height.end() - 1; it > maxEle ; it--)
		{
			right = *it;
			if (right < left)
			{
				ret = ret + (left - right);
			}
			else
			{
				left = right;
			}
		}
		return ret;
	}
};