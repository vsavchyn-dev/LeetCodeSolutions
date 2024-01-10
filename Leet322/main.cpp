#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solving(vector<int>& coins, int amount, vector<int>& memoized) {
        if (amount == 0)
            return 0;
        if (memoized[amount] != -1)
            return memoized[amount];
        int answ = INT_MAX;
        for (int i : coins)
            if (amount >= i)
                answ = min(answ, solving(coins, amount - 1, memoized));
        memoized[amount] = answ;

        return answ;
    };

    int coinChange(vector<int>& coins, int amount) {
        vector<int> memoz(amount, -1);
        int answ = solving(coins, amount, memoz);
        return answ >= INT_MAX ? -1 : answ;
    };
};


int main() {

}