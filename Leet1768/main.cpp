#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string word1, string word2) {
	string merged{};
	int i = 0, j = 0;
	int w1 = word1.length(), w2 = word2.length();

	while (i < w1 || j < w2) {
		if(i < w1)
			merged.push_back(word1[i++]);

		if (j < w2)
			merged.push_back(word2[j++]);
	}

	return merged;
}

int main() {
	auto mergedStr = mergeAlternately("abcd", "pqr");

	cout << mergedStr << endl;
}