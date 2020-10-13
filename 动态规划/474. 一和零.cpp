/*
在计算机界中，我们总是追求用有限的资源获取最大的收益。

现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。

你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

输入: strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出: 4
解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0"
*/

#include <vector>
#include <Windows.h>

using namespace std;

class Solution {
public:
	class Solution {
	public:
		int findMaxForm(vector<string>& strs, int m, int n) {
			int nums = strs.size();

			vector<vector<vector<int>>> dp(nums + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
			for (int k = 1; k <= nums; k++)
			{
				int nums0 = 0;
				int nums1 = 0;
				for (char &c : strs[k - 1])
				{
					if (c == '0')
						nums0++;
					else
						nums1++;
				}
				for (int i = 0; i <= m; i++)
				{
					for (int j = 0; j <= n; j++)
					{
						if (i >= nums0 && j >= nums1)
						{
							dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - nums0][j - nums1] + 1);
						}
						else
						{
							dp[k][i][j] = dp[k - 1][i][j];
						}
					}
				}
			}
			return dp[nums][m][n];
		}
	};
};
