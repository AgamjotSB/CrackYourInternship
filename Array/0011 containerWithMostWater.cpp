#include <algorithm>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left   = 0;
    int right  = height.size() - 1;
    int answer = -1;

    while (left < right) {
        answer = max(answer, (right - left) * min(height[left], height[right]));
        if (height[left] < height[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    return answer;
}
