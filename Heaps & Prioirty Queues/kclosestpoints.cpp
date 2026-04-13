class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //hume k closest points chaia from the origin 0,0
        vector<vector<int>>ans;
        //sbse kam distance from the origin to hum kya krnege is we will mark the points into the pq with the distance and 
        priority_queue<pair<double,pair<int,int>>>pq;
        //isme kya krnenge hum process krenge points ko and calculate krnge humri distance for each of the coordinates 
        //and we will figure out the answer 
        for(auto i : points)
        {
            int x = i[0];
            int y = i[1];

            double dis = sqrt(pow(x,2) + pow(y,2));
            pq.push({dis,{x,y}});
            if(pq.size() > k) pq.pop();
        }
        //ab humare pas sare wo elements hai jo kya hai closest hai 
        while(!pq.empty())
        {
            auto p = pq.top();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;

            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};
