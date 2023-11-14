#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX , ans=0;
    for(int i : prices){
        if (i < minPrice) {
            minPrice = i;
        } else {
            ans = max(ans , i - minPrice);
        }
    }

    return ans;
}

int main() {
    vector<int> prices = {7,2,8,3,5,1,6,4};
    cout << maxProfit(prices) << endl;
    
    return 0;
}