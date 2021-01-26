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
	// remove full rotations
	r %= perimeter;

	//flatten the rectangle
	vector <int> flattened;
	int i = index, j = index;
	for (i; i < index + rect_height; i++) {
		flattened.push_back(matrix[i][j]);
	}
	i--; //decrement after for loop (i is now equal to index, which exceeds the size of 'flattened')
	j++; //move to next element, as left corner is already added
	for (j; j < index + rect_width; j++) {
		flattened.push_back(matrix[i][j]);
	}
	j--;
	i--;
	for (i; i >= index; i--) {
		flattened.push_back(matrix[i][j]);
	}
	i++;
	j--;
	for (j; j > index; j--) { //matrix[index][index] has already been added
		flattened.push_back(matrix[i][j]);
	}
	// rotate by shifting 'flattened'
	vector <int> shifted_flattened;
	for (int i = perimeter - r; i < perimeter; i++) { //size of 'flattened' i equal to the perimeter of the rectangle
		shifted_flattened.push_back(flattened[i]);
	}
	for (int i = 0; i < perimeter - r; i++) {
		shifted_flattened.push_back(flattened[i]);
	}
	// modify the original rectangle
	i = index;
	j = index;
	int k = 0; // shifted_flatten iterator
	for (i; i < index + rect_height; i++) {
		matrix[i][j] = shifted_flattened[k];
		k++;
	}
	i--;
	j++;
	for (j; j < index + rect_width; j++) {
		matrix[i][j] = shifted_flattened[k];
		k++;
	}
	j--;
	i--;
	for (i; i >= index; i--) {
		matrix[i][j] = shifted_flattened[k];
		k++;
	}
	i++;
	j--;
	for (j; j > index; j--) {
		matrix[i][j] = shifted_flattened[k];
		k++;
	}
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
		cout << endl;
	}
}

int main() {
	vector<vector<int>> test_0 = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	vector<vector<int>> test_1 = {
		{1, 2, 3, 4},
		{7, 8, 9, 10},
		{13, 14, 15, 16},
		{19, 20, 21, 22},
		{25, 26, 27, 28}
	};
	/*
	print_matrix(test_1);
	rotateRect(test_1, 0, 12);
	print_matrix(test_1);
	*/
	matrixRotation(test_1, 7);
	return 0;	
}