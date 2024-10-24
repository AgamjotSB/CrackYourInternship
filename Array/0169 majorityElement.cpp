#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0],
        count     = 0;
    for (int i : nums) {
        if (i == candidate) {
            count++;
        }
        else {
            if (count == 1) {
                candidate = i;
            }
            else {
                count--;
            }
        }
    }
    return candidate;
}

int main() {
    vector<int> v{3, 2, 3};
    cout << majorityElement(v);
}
