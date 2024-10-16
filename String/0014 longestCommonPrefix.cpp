#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string answer;
    for (int i = 0; i < strs[0].length(); i++) {
        char temp = strs[0][i];
        for (string str : strs) {
            if (i >= str.length() || str[i] != temp) {
                return answer;
            }
        }
        answer.push_back(temp);
    }
    return answer;
}
