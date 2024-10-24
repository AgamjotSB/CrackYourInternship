#include <iostream>
#include <stack>
#include <string>
using namespace std;

string simplifyPath(string path) {
    stack<string> tokens;
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '/') {
            continue;
        }
        string temp;
        while (i < path.size() && path[i] != '/') {
            temp += path[i++];
        }
        if (temp == ".") {
            continue;
        }
        else if (temp == "..") {
            if (tokens.size() != 0) {
                tokens.pop();
            }
        }
        else {
            tokens.push(temp);
        }
    }
    string answer;
    while (tokens.size() != 0) {
        answer = "/" + tokens.top() + answer;
        tokens.pop();
    }
    return (answer.size() == 0) ? "/" : answer;
}

int main() {
    cout << simplifyPath("/.../a/../b/c/../d/./");
}
