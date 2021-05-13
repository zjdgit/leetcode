﻿/*

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。


示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pre = 0, maxAns = nums[0];
		for (const auto &x : nums) {
			pre = max(pre + x, x);
			maxAns = max(maxAns, pre);
		}
		return maxAns;
	}
};