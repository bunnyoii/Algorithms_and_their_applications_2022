#include <iostream>
#include <vector>

class Solution {
public:
	std::string searchMatrix(std::vector<std::vector<int>> matrix, int target) {
		int row = matrix.size();		// ����
		int col = matrix[0].size();		// ����
		int i = row - 1, j = 0;			// ���½ǵ�Ԫ��
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

    std::cout << "����������: ";
    std::cin >> numRows;
	std::cout << "����������: ";
	std::cin >> numCols;
    for (int i = 0; i < numRows; ++i) {
        std::vector<int> row;
        std::cout << "������� " << i + 1 << " �е�Ԫ�أ��ÿո�ָ�: ";
        for (int j = 0; j < numCols; ++j) {
            std::cin >> temp;
            row.push_back(temp);
        }
        vec.push_back(row);
    }

    // ��������һ��Ŀ��ֵ
    std::cout << "������һ��Ŀ��ֵ: ";
    std::cin >> target;

    // ��ӡ����Ķ�άvector
    std::cout << "����ľ���Ϊ��" << std::endl;
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // ��ӡĿ��ֵ
    std::cout << "�����Ŀ��ֵΪ: " << target << std::endl;

	std::cout <<"���Ϊ : " << solution.searchMatrix(vec, target) << std::endl;
	return 0;
}