class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        //sbko merge krna hai to kya appraoch rehti hai is
        //you need a min heap 
        //just place every rows 1 element and 
        //ab process it through min heap 
        vector<int>ans;
        int n = mat.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({mat[i][0],i,0});
            //consist element as ( element -----> row -------> column)
        }
        //bss ab process krte raho 
        while(!pq.empty())
        {
            auto [ele,r,c] = pq.top();
            pq.pop();
            
            ans.push_back(ele);
            //ab agr age element pade hai tbi dekho 
            int n = mat[r].size();
            //us row k size lelo 
            //agr uske age elements hai to push krdo 
            if(c+1 < n)
            {
                pq.push({mat[r][c+1],r,c+1});
            }
        }
        return ans;
    }
};
