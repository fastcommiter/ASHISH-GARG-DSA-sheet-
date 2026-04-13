class Solution {
  public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<>>minh;
    
    
    double getanswer()
    {
        if(minh.size() == maxh.size()) return (double)(minh.top() + maxh.top())/2;
        if(maxh.size() > minh.size()) return (double)maxh.top();
        else return (double)minh.top();
    }
    vector<double> getMedian(vector<int> &arr) {
        
        int n = arr.size();
        vector<double>ans;
        for(int i=0;i<n;i++)
        {
            double element = arr[i];
            if(maxh.empty() || element <= maxh.top())
            {
                maxh.push(element);
            }
            else{
                minh.push(element);
            }
            if(maxh.size() > minh.size()+1)
            {
                minh.push(maxh.top());
                maxh.pop();
            }
            else if(minh.size() > maxh.size()+1)
            {
                maxh.push(minh.top());
                minh.pop();
            }
            double result = getanswer();
            ans.push_back(result);
        }
        return ans;
    }
};
