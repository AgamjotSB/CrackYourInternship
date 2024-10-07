#include <iostream>
#include <string>
using namespace std;

void printDuplicates(string str) {
    int arr[26] = {};
    for (char ch : str) {
        arr[ch - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(arr[i] > 1) {
            cout << char(i + 'a');
        }
    }
    cout << endl;
}

int main() {
    printDuplicates("aabbcdeefg");
}
