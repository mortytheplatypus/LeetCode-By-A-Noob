#include <bits/stdc++.h>
using namespace std;

class SeatManager {
    priority_queue<int, vector<int>, greater<int>> unreserved;
    int maxSeat;
public:
    SeatManager(int n) {
        maxSeat = 0;
    }
    
    int reserve() {
        if (!unreserved.size()) {
            return ++maxSeat;
        }

        int n = 1 + unreserved.top();
        unreserved.pop();
        
        return n;
    }
    
    void unreserve(int seatNumber) {
        unreserved.push(seatNumber-1);
    }
};

int main() {
    SeatManager seatManager(3);

    cout << seatManager.reserve() << " ";
    cout << seatManager.reserve() << " ";
    seatManager.unreserve(1);
    seatManager.unreserve(2);
    cout << seatManager.reserve() << " ";
    seatManager.unreserve(1);
    cout << seatManager.reserve() << " ";
    seatManager.unreserve(1);
    
    return 0;
}