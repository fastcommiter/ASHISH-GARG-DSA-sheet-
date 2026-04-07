class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(26);

        if(s.size() < p.size()) return {};
        
        for(int i=0;i<p.size();i++)
        {
            freq[p[i] - 'a']++;
        }
        //yh bana diya meine p k store krdiya hai yh 
        int k = p.size();
        vector<int>freq2(26);

        //is size ki window hai 
        for(int i =0;i<k;i++)
        {
            freq2[s[i] - 'a']++;
        }
        vector<int>ans;
        if(freq == freq2) ans.push_back(0);
        //ab start kro fixed size mai age jana 
        for(int i =k;i<s.size();i++)
        {
            int minus = s[i-k] - 'a';
            int add = s[i] - 'a';

            freq2[add]++;
            freq2[minus]--;

            if(freq==freq2)
            {
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};
