#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows, vector<vector<int>> preCalculated = {}) {
		if (numRows == 1)
			return vector<vector<int>>{ {1} };

		vector<vector<int>> answer = generate(numRows - 1);
		answer.push_back(vector<int>(numRows));
		answer[numRows - 1][0] = 1;
		answer[numRows - 1][numRows - 1] = 1;
		
		for (int i = 1; i < numRows - 1; i++)
			answer[numRows - 1][i] = answer[numRows - 2][i - 1] + answer[numRows - 2][i];

		return answer;
	}
};


int main() {
	Solution sl;

	auto start = chrono::high_resolution_clock::now();

	auto someName = sl.generate(100);

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop - start);

	cout << "Microseconds: " << duration.count() << std::endl;
	cout << "Nanoseconds: " << duration2.count() << std::endl;


	/*for (auto& obj : someName) {
		for (auto& elem : obj)
			cout << elem << " ";
		cout << std::endl;
	}*/
}