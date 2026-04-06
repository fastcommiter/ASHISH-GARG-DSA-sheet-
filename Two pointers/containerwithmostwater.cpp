class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=INT_MIN;
        int l=0;
        int r=height.size()-1;
        while(l<r)
        {
            int h=min(height[l],height[r]);
            int w=r-l;
            int unit=h*w;
            maxwater=max(unit,maxwater);
            if(height[l] < height[r])
            {
                l++;
            }
            else{
                r--;
            }
        }
        return maxwater;
    }
};
