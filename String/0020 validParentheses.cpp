#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> braces;
    for (char ch : s) {
        switch (ch) {
            case '(': braces.push('('); break;
            case '[': braces.push('['); break;
            case '{': braces.push('{'); break;

            case ')':
                if (braces.size() != 0 && braces.top() == '(') {
                    braces.pop();
                }
                else {
                    return false;
                }
                break;
            case ']':
                if (braces.size() != 0 && braces.top() == '[') {
                    braces.pop();
                }
                else {
                    return false;
                }
                break;
            case '}':
                if (braces.size() != 0 && braces.top() == '{') {
                    braces.pop();
                }
                else {
                    return false;
                }
                break;
        }
    }

    if (braces.size() == 0) {
        return true;
    }
    return false;
}
