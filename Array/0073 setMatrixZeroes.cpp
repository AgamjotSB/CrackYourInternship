#include <vector>
using namespace std;

void changeRows(vector<vector<int>>& matrix, int key) {
    for (int i = 0; i < matrix[key].size(); i++) {
        matrix[key][i] = 0;
    }
}

void changeColumns(vector<vector<int>>& matrix, int key) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][key] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<char> row(matrix.size(), 0);
    vector<char> col(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < row.size(); i++) {
        if (row[i] == 1) {
            changeRows(matrix, i);
        }
    }

    for (int i = 0; i < col.size(); i++) {
        if (col[i] == 1) {
            changeColumns(matrix, i);
        }
    }
}
