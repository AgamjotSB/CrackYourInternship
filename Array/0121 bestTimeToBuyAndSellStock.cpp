#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxp = 0;
    int left = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[left]) {
            left = i;
        }
        else {
            maxp = max(maxp, (prices[i] - prices[left]));
        }
    }
    return maxp;
}

int main() {
    vector<int> v{3, 2, 6, 5, 0, 3};
    vector<int> v2{7, 6, 4, 3, 1};
    cout << maxProfit(v) << endl;
    cout << maxProfit(v2) << endl;
}
