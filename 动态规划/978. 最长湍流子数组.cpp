/*

当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		int nums = A.size();
		if (nums <= 1)
			return nums;

		vector<int> dp(nums, 0);
		dp[0] = 1;
		dp[1] = 2;

		int flag = -1;
		if (A[0] < A[1])
			flag = 0;
		if (A[0] > A[1])
			flag = 1;

		for (int i = 1; i < nums; i++)
		{
			if (flag != 1)
			{
				if (A[i - 1] < A[i])
				{
					dp[i] = 2;
				}
				else if (A[i - 1] > A[i])
				{
					dp[i] = dp[i - 1] + 1;
					flag = 1;
				}
				else
				{
					dp[i] = 1;
					flag = -1;
				}

			}
			else if (flag != 0)
			{
				if (A[i - 1] < A[i])
				{
					dp[i] = dp[i - 1] + 1;
					flag = 0;
				}
				else if (A[i - 1] > A[i])
				{
					dp[i] = 2;
				}
				else
				{
					dp[i] = 1;
					flag = -1;
				}
			}
			else
			{
				dp[i] = 1;
			}
		}
		auto biggest = std::max_element(dp.begin(), dp.end());
		return *biggest;
	}
};

