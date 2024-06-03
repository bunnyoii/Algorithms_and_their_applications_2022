#include <iostream>
#include <vector>

class Solution {
public:
	bool FirstWinner(std::vector<int>& nums) {
		return total(nums, 0, nums.size() - 1, 1) >= 0;
	}

	int total(std::vector<int>& nums, int start, int end, int turn) {
		if (start == end) {
			return nums[start] * turn;
		}
		int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
		int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
		if (turn == 1) {
			return std::max(scoreStart, scoreEnd);
		}
		else
			return std::min(scoreStart, scoreEnd);
	}
};