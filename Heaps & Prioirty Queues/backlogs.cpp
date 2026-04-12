class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        priority_queue<pair<int,int>> buy; // max heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> sell; // min heap

        for(auto &o : orders) {
            int price = o[0];
            int amount = o[1];
            int type = o[2];

            if(type == 0) { // BUY
                while(amount > 0 && !sell.empty() && sell.top().first <= price) {
                    auto [sp, sa] = sell.top();
                    sell.pop();

                    int match = min(amount, sa);
                    amount -= match;
                    sa -= match;

                    if(sa > 0) sell.push({sp, sa});
                }
                if(amount > 0) buy.push({price, amount});
            }
            else { // SELL
                while(amount > 0 && !buy.empty() && buy.top().first >= price) {
                    auto [bp, ba] = buy.top();
                    buy.pop();

                    int match = min(amount, ba);
                    amount -= match;
                    ba -= match;

                    if(ba > 0) buy.push({bp, ba});
                }
                if(amount > 0) sell.push({price, amount});
            }
        }

        long long ans = 0;
        int MOD = 1e9 + 7;

        while(!buy.empty()) {
            ans = (ans + buy.top().second) % MOD;
            buy.pop();
        }

        while(!sell.empty()) {
            ans = (ans + sell.top().second) % MOD;
            sell.pop();
        }

        return ans;
    }
};
