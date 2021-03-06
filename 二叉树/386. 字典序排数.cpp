﻿/*
给定一个整数 n, 返回从 1 到 n 的字典顺序。

例如，

给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。

请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。

*/

class Solution {
public:
	void dfs(vector<int>& res, int i, int n)
	{
		if (i > n)
		{
			return;
		}
		res.push_back(i);
		for (int j = 0; j <= 9; j++) {
			dfs(res, i * 10 + j, n);
		}
	}

	vector<int> lexicalOrder(int n) {
		vector<int> res;
		for (int i = 1; i <= 9; i++)
		{
			dfs(res, i, n);
		}
		return res;
	}
};