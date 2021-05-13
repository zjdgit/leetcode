/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
*/

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;

		vector<int> dp1;
		vector<int> dp2;
		for (int i = 0; i < intervals.size(); i++)
		{
			dp1.push_back(intervals[i][0]);
			dp2.push_back(intervals[i][1]);
		}
		std::sort(dp1.begin(), dp1.end());
		std::sort(dp2.begin(), dp2.end());

		int l = dp1[0];
		for (int i = 1; i < dp1.size(); i++)
		{
			if (dp1[i] > dp2[i - 1])
			{
				vector<int> t = { l, dp2[i - 1] };
				l = dp1[i];
				res.push_back(t);
			}
		}
		res.push_back({ l, dp2[dp2.size() - 1] });

		return res;
	}
};