#include <iostream>
#include <vector>

class Solution {
public:
	std::string searchMatrix(std::vector<std::vector<int>> matrix, int target) {
		int row = matrix.size();		// 行数
		int col = matrix[0].size();		// 列数
		int i = row - 1, j = 0;			// 左下角的元素
		while (i >= 0 && j <= col - 1) {
			if (target > matrix[i][j]) {
				j++;
				if (j > col - 1) return "false";
			}
			else if (target < matrix[i][j]) {
				i--;
				if (i < 0) return "false";
			}
			else return "true";
		}
		return "false";
	}
};

int main() {
	Solution solution;
    std::vector<std::vector<int>> vec;
    int numRows, numCols, temp, target;

    std::cout << "请输入行数: ";
    std::cin >> numRows;
	std::cout << "请输入列数: ";
	std::cin >> numCols;
    for (int i = 0; i < numRows; ++i) {
        std::vector<int> row;
        std::cout << "请输入第 " << i + 1 << " 行的元素，用空格分隔: ";
        for (int j = 0; j < numCols; ++j) {
            std::cin >> temp;
            row.push_back(temp);
        }
        vec.push_back(row);
    }

    // 请求输入一个目标值
    std::cout << "请输入一个目标值: ";
    std::cin >> target;

    // 打印输入的二维vector
    std::cout << "输入的矩阵为：" << std::endl;
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // 打印目标值
    std::cout << "输入的目标值为: " << target << std::endl;

	std::cout <<"结果为 : " << solution.searchMatrix(vec, target) << std::endl;
	return 0;
}