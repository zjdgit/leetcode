﻿/*
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,3,2]
*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 2;

		while (i >= 0 && nums[i] >= nums[i + 1])
		{
			i--;
		}
		int j = nums.size() - 1;
		if (i >= 0)
		{
			while (j >= 0 && nums[j] <= nums[i])
			{
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};