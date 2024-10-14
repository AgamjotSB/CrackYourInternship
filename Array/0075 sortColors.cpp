#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// O(2n), Single pass possible using Dutch National Flag algo
void sortColors(vector<int>& nums) {
    int red = 0, white = 0, blue = 0;
    for (int i : nums) {
        switch (i) {
            case 0: red++; break;
            case 1: white++; break;
            case 2: blue++; break;
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i < red) {
            nums[i] = 0;
        }
        else if (i - red < white) {
            nums[i] = 1;
        }
        else {
            nums[i] = 2;
        }
    }
}

// 0 -> (low-1) -> 0's EXTREME LEFT
// low -> (mid-1) -> 1's
// mid -> high -> unsorted
// (high+1) -> (n-1) -> 2's EXTREME RIGHT
void dutchNationalFlag(vector<int>& nums) {
    if (nums.size() == 1) {
        return;
    }

    int low  = 0,
        mid  = 0,
        high = nums.size() - 1;
    while (mid <= high) {
        switch (nums[mid]) {
            case 0: {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;
            }
            case 1: {
                mid++;
                break;
            }
            default: {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
}

void printv(vector<int>& nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v{2, 0, 2, 1, 1, 0};
    // vector<int> v{2, 0, 1};
    printv(v);

    dutchNationalFlag(v);
    printv(v);
}
