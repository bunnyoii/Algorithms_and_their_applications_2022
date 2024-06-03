#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

class Solution2 {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        int dp1 = 0, dp2 = 0;

        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // 确保共同元素的最大得分是最大化的
                int max_prev = max(dp1, dp2) + nums1[i];
                dp1 = max(dp1, max_prev);
                dp2 = max(dp2, max_prev);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                dp1 += nums1[i];
                i++;
            }
            else {
                dp2+=nums2[j];
                j++;
            }
        }

        // 处理剩余元素
        while (i < nums1.size()) {
            dp1+=nums1[i];
            i++;
        }
        while (j < nums2.size()) {
            dp2+=nums2[j];
            j++;
        }

        return max(dp1, dp2) % MOD;
    }
};

int main() {
    Solution2 s2;
    std::vector<int> nums1,nums2;
    int n;
    std::cout << "请输入nums1数组（输入-1停止输入）：";
    while (std::cin >> n) {
        if (n == -1)
            break;
        else
            nums1.push_back(n);
    }
    std::cout << "请输入nums2数组（输入-1停止输入）：";
    while (std::cin >> n) {
        if (n == -1)
            break;
        else
            nums2.push_back(n);
    }

    cout << "最大得分是: " << s2.maxSum(nums1,nums2) << endl;
    return 0;
}
