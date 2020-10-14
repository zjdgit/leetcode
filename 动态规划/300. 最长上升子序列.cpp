/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

//动态规划
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int num = nums.size();

		vector<int> dp(num, 1);
	
		for (int i = 1; i < num; i++)
		{ 
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		auto biggest = std::max_element(dp.begin(), dp.end());
		return *biggest;
	}
};

//二分查找
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int num = nums.size();

		vector<int> dp;
		dp.push_back(nums[0]);
		
		for (int i = 1; i < num; i++)
		{
			auto iter = std::lower_bound(dp.begin(), dp.end(), nums[i]);
			if (iter == dp.end())
			{
				dp.push_back(nums[i]);
			}
			else
			{
				*iter = nums[i];
			}
		}
		return dp.size();
	}
};