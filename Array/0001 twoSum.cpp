#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> valueIndexMap;
    for (int i = 0; i < nums.size(); i++) {
        int pair = target - nums[i];
        if (valueIndexMap.find(pair) != valueIndexMap.end()) {
            return {valueIndexMap[pair], i};
        }
        valueIndexMap[nums[i]] = i;
    }
    return {};
}
