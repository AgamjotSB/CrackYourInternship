#include <iostream>
#include <vector>
using namespace std;

int countNums(const vector<int>& nums, int val) {
    int count = 0;
    for (int i : nums) {
        if (i <= val) {
            count++;
        }
    }
    return count;
}

// search space method, range is [1,n-1]
// where n is size of array

int findDuplicate(vector<int>& nums) {
    int left  = 1;
    int right = nums.size() - 1;
    int count;

    while (left < right) {
        int mid = left + (right - left) / 2;
        count   = countNums(nums, mid);
        if (count > mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> v{1, 2, 3, 4, 4, 5, 6, 7};
    cout << findDuplicate(v) << endl;
}
