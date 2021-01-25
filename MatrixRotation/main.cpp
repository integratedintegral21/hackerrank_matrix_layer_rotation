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

void rotateRect(vector<vector<int>> &matrix, int index) {
	int m = matrix.size();    // rows quantity
	int n = matrix[0].size(); // columns quantity

	int first = matrix[index][index];

	//upper side
	for (int j = index; j < n - index - 1; j++) {
		matrix[index][j] = matrix[index][j + 1];
	}

	//right side
	for (int i = index; i < m - index - 1; i++) {
		matrix[i][n - index - 1] = matrix[i + 1][n - index - 1];
	}

	//lower side
	for (int j = n - index - 1; j > index; j--) {
		matrix[m - index - 1][j] = matrix[m - index - 1][j - 1];
	}

	//left side
	for (int i = m - index - 1; i > index; i--) {
		matrix[i][index] = matrix[i - 1][index];
	}

	matrix[index + 1][index] = first;
}

void matrixRotation(vector<vector<int>>& matrix, int r) {
	int min_dim = min(matrix.size(), matrix[0].size());
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < min_dim / 2; j++) {
			rotateRect(matrix, j);
		}
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