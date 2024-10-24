#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseWords(string s) {
    stack<string> words;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        string temp;
        while (i < s.size() && s[i] != ' ') {
            temp += s[i++];
        }
        words.push(temp);
    }
    string answer;
    while (!words.empty()) {
        answer += words.top() + ' ';
        words.pop();
    }
    answer.pop_back();
    return answer;
}

string reverseWords2(string s) {
    string answer;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            continue;
        }
        int wordleft = i;
        while (wordleft >= 0 && s[wordleft] != ' ') {
            wordleft--;
        }
        answer += s.substr(wordleft + 1, i - wordleft) + " ";
        i = wordleft;
    }
    answer.pop_back();
    return answer;
}

int main() {
    cout << reverseWords2("   this    is a sentence   ");
}
