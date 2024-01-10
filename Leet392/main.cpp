#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sCounter = 0;

        if (!s.length()) return true;

        for (auto ch : t) {
            if (s[sCounter] == ch) {
                ++sCounter;
            }
            if (sCounter >= s.length()) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    cout << Solution().isSubsequence("", "abcd") << endl;
}