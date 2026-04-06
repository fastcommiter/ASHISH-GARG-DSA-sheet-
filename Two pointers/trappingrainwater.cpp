class Solution {
public:
    void getleftmax(vector<int>&height,vector<int>&rightmax)
    {
        int n=height.size();
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
    }
    void getrightmax(vector<int>&height,vector<int>&rightmax)
    {
        int n=height.size();
        rightmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            rightmax[i]=max(rightmax[i-1],height[i]);
        }
    }
    int trap(vector<int>& height) {
       int n=height.size();
       vector<int>rightmax(n);
       vector<int>leftmax(n);
        int water=0;
       getrightmax(height,rightmax);
       getleftmax(height,leftmax);
       for(int i=0;i<n;i++)
       {
            int holdings = min(rightmax[i],leftmax[i])-height[i];
            water+=holdings;
       } 
       return water;
    }
};
