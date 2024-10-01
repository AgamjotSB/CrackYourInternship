#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int position = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[position] = nums[i];
            position++;
        }
    }
    return position;
}

int main() {
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int s = removeDuplicates(nums);
    for (int i : nums) {
        cout << i;
    }
    cout << endl
         << s << endl;
}
