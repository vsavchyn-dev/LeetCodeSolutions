#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool isVlaid(string s) {
	string openingChars{ "({[" };
	string closingChars{ ")}]" };
	stack<char> s1;

	for (auto ch : s) {
		if (openingChars.find(ch) != string::npos) {
			s1.push(ch);
		}
		else {
			if (!s1.empty() && closingChars[openingChars.find(s1.top())] == ch) {
				s1.pop();
			}
			else {
				return false;
			}
		}
	}

	return s1.empty();
}