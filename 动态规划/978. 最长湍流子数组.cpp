/*

�� A �������� A[i], A[i+1], ..., A[j] ������������ʱ�����ǳ���Ϊ���������飺

�� i <= k < j���� k Ϊ����ʱ�� A[k] > A[k+1]���ҵ� k Ϊż��ʱ��A[k] < A[k+1]��
�� �� i <= k < j���� k Ϊż��ʱ��A[k] > A[k+1] ���ҵ� k Ϊ����ʱ�� A[k] < A[k+1]��
Ҳ����˵������ȽϷ������������е�ÿ������Ԫ�ض�֮�䷭ת����������������������顣

���� A ���������������ĳ��ȡ�
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

