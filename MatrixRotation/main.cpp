#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void print_matrix(vector<vector<int>> mt) {
	int m = mt.size();
	int n = mt[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(8) << mt[i][j];
		}
		cout << endl;
	}
}

void rotateRect(vector<vector<int>> &matrix, int index, int r) {
	int rect_height = matrix.size() - 2 * index;
	int rect_width = matrix[0].size() - 2 * index;
	int perimeter = 2 * (rect_height + rect_width) - 4;

	
}

void matrixRotation(vector<vector<int>>& matrix, int r) {
	int min_dim = min(matrix.size(), matrix[0].size());
	// rotate each layer by r
	for (int j = 0; j < min_dim / 2; j++) {
		rotateRect(matrix, j, r);
	}
	int m = matrix.size();
	int n = matrix[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
	}
}

int main() {
	return 0;	
}