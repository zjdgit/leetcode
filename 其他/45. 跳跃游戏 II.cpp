/*

����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

���������ǿ��Ե�����������һ��λ�á�
*/

class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0;
		int maxPos = 0;
		int end = 0;
		int size = nums.size();

		for (int i = 0; i < size - 1; i++)
		{
			maxPos = max(maxPos, nums[i] + i);

			if (i == end)
			{
				++res;
				end = maxPos;
			}
		}

		return res;
	}
};