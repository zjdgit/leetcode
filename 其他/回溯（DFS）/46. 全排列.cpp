/*
����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> track;
		backtrack(res, nums, track);
		return res;
	}
	void backtrack(vector<vector<int>>& res, vector<int> nums, vector<int>& track)
	{
		if (track.size() == nums.size())
		{
			res.push_back(track);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (std::find(track.begin(), track.end(), nums[i]) != track.end())
			{
				continue;
			}
			track.push_back(nums[i]);
			backtrack(res, nums, track);
			track.pop_back();
		}
	}
};