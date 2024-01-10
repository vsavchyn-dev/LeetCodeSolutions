#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
/*
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> arrival(dist.size());

        for (int i = 0; i < dist.size(); i++)
            arrival[i] = (int)ceil((double)dist[i] / speed[i]);

        sort(arrival.begin(), arrival.end());
        
        int answ = 0;
        for (int i = 0; i < arrival.size(); i++) {
            if (arrival[i] <= i) break;
            answ++;
        }
        return answ;
    }
};
*/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); i++)
            dist[i] = (int)ceil((double)dist[i] / speed[i]);

        sort(dist.begin(), dist.end());

        int answ = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] <= i) break;
            answ++;
        }
        return answ;
    }
};

int main() {
    Solution s;
    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 2, 3};
    std::cout << s.eliminateMaximum(dist, speed);
    return 0;
}