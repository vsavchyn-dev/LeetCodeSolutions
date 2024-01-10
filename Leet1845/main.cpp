// #include <vector>
#include <queue>
#include <functional>
#include <vector>

class SeatManager {
    //std::vector<int> seats;
    //int minAvIdx = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> availableSeats;
public:
    SeatManager(int n) {
        /*
        seats.resize(n);
        std::fill(seats.begin(), seats.end(), 1);
        memset(&seats[0], 1, sizeof(seats[0]) * seats.size());
        */
        for (int seatNum = 1; seatNum <= n; seatNum++)
            availableSeats.push(seatNum);
    }

    int reserve() {
        /*
        int toReturn = minAvIdx;
        seats[minAvIdx] = 0;

        while (seats[minAvIdx] == 0 && minAvIdx < seats.size()) minAvIdx++;

        return toReturn;
        */
        int minNum = availableSeats.top();
        availableSeats.pop();
        return minNum;
    }

    void unreserve(int seatNumber) {
        /*
        seats[--seatNumber] = 1;

        minAvIdx = std::min(seatNumber, minAvIdx);
        */
        availableSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */