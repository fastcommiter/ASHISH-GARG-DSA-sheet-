class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool leftfound = false;
        bool rightfound = false;
        vector<bool>vis(right+1,false);
        for(auto i : ranges)
        {
            int u = i[0];
            int v = i[1];
            //question k mtlb yo hai s 
            //left right k beech mai jitne bhi integers awe hai na wo ssb ane chaia bhai interval mai 

            for(u;u<=v;u++)
            {
                vis[u] = true;
            }
        }   
        for(int i=left;i<=right;i++)
        {
            if(vis[i] == false) return false;
        }
        return true;
    }
};
