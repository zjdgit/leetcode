/*
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

返回使 A 中的每个值都是唯一的最少操作次数。

示例 1:

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。

*/

class Solution {
public:
	int findPostion(int a, vector<int>& pos)
	{
		int b = pos[a];
		if (b == -1)
		{
			pos[a] = a;
			return a;
		}
		b = findPostion(b + 1, pos);
		pos[a] = b;
		return b;
	}

	int minIncrementForUnique(vector<int>& A) {
		if (A.empty())
			return 0;
		int ans = 0;
		vector<int> pos(80000, -1);
		for (int a : A)
		{
			int b = findPostion(a, pos);
			ans += b - a;
		}
		return ans;

	}
};