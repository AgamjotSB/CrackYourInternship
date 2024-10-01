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
