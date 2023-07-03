#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// Iterative Version, too long, somewhat O(n * m)?
class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		vector<int> result(spells.size());
		int i = 0;

		for(int i = 0; i < spells.size() - 1; i++)
			result.push_back(0);

		for (auto spell : spells) {
			for (auto pos : potions)
				if ((long long)(pos * spell) >= success)
					result[i]++;
			i++;
		}

		return result;
	}
};
*/

class Solution {
public:
	int binary_search(vector<int>& potions, long long&& success) {
		int low = 0;
		int high = potions.size() - 1;

		while (low < high) {
			int mid = low + (high - low) / 2;

			if (potions[mid] < success)
				low = mid + 1;
			else
				high = mid;
		}

		return potions[low] >= success ? low : -1;
	}

	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		vector<int> result(spells.size());
		sort(potions.begin(), potions.end());

		for (int i = 0; i < spells.size(); i++) {
			int index = binary_search(potions, (long long)ceil((1.0 * success) / spells[i]));
			result[i] = ((index == -1) ? 0 : potions.size() - index);
		}

		return result;
	}
};