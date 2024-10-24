#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.length() == 0 || s.length() == 1) {
        return s.length();
    }

    int maxlength = 1;

    for (int left = 0; left < s.length(); left++) {

        int right = left;
        unordered_map<char, int> chartoindex;

        while (right < s.length()) {
            if (chartoindex.find(s[right]) != chartoindex.end()) {
                break;
            }
            else {
                chartoindex[s[right]] = right;
                right++;
            }
        }

        maxlength = max(right - left, maxlength);
        left      = chartoindex[s[left]];
    }

    return maxlength;
}

int lengthOfLongestSubstring2(string s) {
    if (s.length() == 0 || s.length() == 1) {
        return s.length();
    }

    bool characters[256] = {};

    int maxlength = 0,
        l         = 0,
        r         = 0;
    while (r < s.length()) {
        while (characters[s[r]]) {
            characters[s[l++]] = false;
        }
        characters[s[r]] = true;
        maxlength        = max(r - l + 1, maxlength);
        r++;
    }
    return maxlength;
}

int main() {
    cout << lengthOfLongestSubstring2("abcabcbb") << endl;
    cout << lengthOfLongestSubstring2("aab") << endl;
}
