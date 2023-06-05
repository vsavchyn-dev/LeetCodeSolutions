#include <vector>

using std::vector;

int minCostClimbingStairs(vector<int>& cost) {
    int steps = 0;
    auto ptr = (cost[0] < cost[1]) ? cost.begin() : cost.begin()++;
    
    if (cost.size() <= 3) {
        return 1;
    }

    while (ptr != cost.end()) {
        (*(ptr + 1) < *(ptr + 2)) ? ptr++ : ptr += 2;
        steps++;
    }
    
    return steps;
}