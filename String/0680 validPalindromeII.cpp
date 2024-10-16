#include <string>
using namespace std;

bool checkSkipped(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    int left  = 0,
        right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return (checkSkipped(s, left + 1, right) || checkSkipped(s, left, right - 1));
        }
        left++;
        right--;
    }
    return true;
}
