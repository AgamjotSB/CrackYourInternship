#include <utility>
#include <vector>
using namespace std;

// TC => O(n), SC => O(1)
void moveZeroes(vector<int>& nums) {
    int zeroindex = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[zeroindex]);
            zeroindex++;
        }
    }
}

// int traverse = 0;
// while (traverse < nums.size()) {
//     if (nums[traverse] == 0) {
//         traverse++;
//     }
//     else {
//         swap(nums[traverse], nums[zeroindex]);
//         zeroindex++;
//         traverse++;
//     }
// }

// TC => O(n), SC => O(n)
void moveZeroes2(vector<int>& nums) {
    vector<int> v(nums.size(), 0);
    int curr = 0;
    for (int i : nums) {
        if (i != 0) {
            v[curr] = i;
            curr++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = v[i];
    }
}
