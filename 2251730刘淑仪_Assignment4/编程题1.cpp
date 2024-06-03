#include <iostream>
#include <vector>

class Solution1 {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size && n > 0; ++i)
        {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;  // 在当前位置种花
                n--;  // 减少需要种植的花的数量
                i++;
            }
        }
        return n == 0;
    }
};
int main() {
    Solution1 s1;
    std::vector<int> flowerbed;
    int flower, n;
    std::cout << "请输入花坛数组（输入-1停止输入）：";
    while (std::cin >> flower) {
        if (flower == -1)
            break;
        else
            flowerbed.push_back(flower);
    }
    std::cout << "请输入种花数量n：";
    std::cin >> n;
    if (s1.canPlaceFlowers(flowerbed, n))
        std::cout << "True";
    else
        std::cout << "False";   

    return 0;
}
