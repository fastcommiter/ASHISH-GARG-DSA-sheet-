class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) return 0;

        int cnt = 0;
        int freq[26] = {0};

        // first window
        for(int i = 0; i < 3; i++) freq[s[i]-'a']++;

        if(freq[s[0]-'a'] == 1 && freq[s[1]-'a'] == 1 && freq[s[2]-'a'] == 1)
            cnt++;

        // slide window
        for(int i = 3; i < s.size(); i++){
            freq[s[i]-'a']++;       
            freq[s[i-3]-'a']--;        

            if(freq[s[i]-'a'] == 1 && freq[s[i-1]-'a'] == 1 && freq[s[i-2]-'a'] == 1)
                cnt++;
        }

        return cnt;
    }
};
