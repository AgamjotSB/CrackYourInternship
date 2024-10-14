#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int goalIndex = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= goalIndex) {
            goalIndex = i;
        }
    }
    if (goalIndex == 0) {
        return true;
    }
    return false;
}
