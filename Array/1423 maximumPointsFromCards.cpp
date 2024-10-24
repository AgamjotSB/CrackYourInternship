#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += cardPoints[i];
    }
    if (k == cardPoints.size()) {
        return sum;
    }
    int answer = sum;
    for (int i = 0; i < k; i++) {
        sum    = sum - cardPoints[k - i - 1] + cardPoints[cardPoints.size() - 1 - i];
        answer = max(answer, sum);
    }
    return answer;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 1};
    cout << maxScore(v, 3);
}
