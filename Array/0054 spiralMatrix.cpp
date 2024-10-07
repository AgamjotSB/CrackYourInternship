#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int count = 0,
        total = matrix[0].size() * matrix.size();
    vector<int> answer(total);

    int top    = 0,
        bottom = matrix.size() - 1,
        left   = 0,
        right  = matrix[0].size() - 1;

    while (count < total) {
        for (int i = left; i <= right && count < total; i++) {
            answer[count] = matrix[top][i];
            count++;
        }
        top++;
        for (int i = top; i <= bottom && count < total; i++) {
            answer[count] = matrix[i][right];
            count++;
        }
        right--;
        for (int i = right; i >= left && count < total; i--) {
            answer[count] = matrix[bottom][i];
            count++;
        }
        bottom--;
        for (int i = bottom; i >= top && count < total; i--) {
            answer[count] = matrix[i][left];
            count++;
        }
        left++;
    }

    return answer;
}

int main() {
    vector<vector<int>> v{{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    vector<vector<int>> v2{{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 10, 11, 12}};
    vector<int> ans  = spiralOrder(v);
    vector<int> ans2 = spiralOrder(v2);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : ans2) {
        cout << i << " ";
    }
    cout << endl;
}
