class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum=sum+arr[i];
        }
        int avg=sum/k;
        if(avg>=threshold)
        {
            cnt++;
        }
        for(int i=k;i<arr.size();i++)
        {
            sum=sum+arr[i];
            sum=sum-arr[i-k];

            avg=sum/k;
            if(avg>=threshold)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
