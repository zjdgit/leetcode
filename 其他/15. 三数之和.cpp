/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		std::sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (nums[i] > 0)
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int l = i + 1;
			int r = len - 1;
			while (l < r)
			{
				if (nums[l] + nums[r] < -nums[i])
					l++;
				else if (nums[l] + nums[r] > -nums[i])
					r--;
				else
				{
					vector<int> tmp = { nums[i], nums[l], nums[r] };
					ans.push_back(tmp);
					l++;
					r--;
					while (l < r && nums[l] == nums[l - 1])
					{
						l++;
					}
					while (l < r && nums[r] == nums[r + 1])
					{
						r--;
					}
				}
			}
		}
		return ans;
	}
};