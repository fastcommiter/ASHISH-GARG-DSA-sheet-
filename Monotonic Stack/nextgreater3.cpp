class Solution {
public:
    long long getreal(vector<int>&arr)
    {
        long long x=0;
        for(int i=0;i<arr.size();i++)
        {
            x=x*10 + arr[i];
        }
        return x;
    }
    int nextGreaterElement(int n) {
        //add the n into a array then 
        //fir usko reverse krdo 
        //get a function jo array s real value generate krde 
        //once done with that
        //try to find the permutation 
        //fir us paermutation ko real mai cpnvert krdo and than 
        // agr wo converted jo value hai wo n s badi hai to return krdo 
        //but agr wo badi hai or int_max s badi hai to return krdo -1 
        vector<int>arr;
        int x = n;
        while(x)
        {
            int r = x%10;
            arr.push_back(r);
            x=x/10;
        }
        reverse(arr.begin(),arr.end());
        //yh humne nikal diya hai num ko vector mai convert krdiya hai 
        int m = arr.size();
        int num = 1<<m;
        long long ans = -1;
        for(int i =0;i<=m;i++)
        {
            next_permutation(arr.begin(),arr.end());
            long long a = getreal(arr);
            if(a > n)
            {
                if(a > INT_MAX) return -1;
                ans = a;
                break;
            }
        }
        return ans;
    }
};
