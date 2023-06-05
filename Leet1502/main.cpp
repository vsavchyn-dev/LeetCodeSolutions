#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
	auto sortArr = arr;
	bool flag = true;

	sort(sortArr.begin(), sortArr.end());

	int step = sortArr[1] - sortArr[0];

	for (auto i = 1; i < sortArr.size() - 1 && flag; i++) {
		if (sortArr[i+1] - sortArr[i] != step) {
			flag = false;
		}
	}

	return flag;
}

int main() {
	vector<int> arr1 = {3, 5, 1};
	vector<int> arr2 = {1, 2, 4};

	cout << canMakeArithmeticProgression(arr1) << endl;
	cout << canMakeArithmeticProgression(arr2) << endl;

}