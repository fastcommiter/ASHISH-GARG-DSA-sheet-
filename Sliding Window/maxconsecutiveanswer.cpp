class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0;
        int t =0;
        int f =0;
        int maxlen = 0;
        for(int r=0;r<answerKey.size();r++)
        {
            if(answerKey[r] == 'T') t++;
            else f++;

            while(min(t,f) > k)
            {
                if(answerKey[l]=='T')t--;
                else f--;
                l++;
            }

            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
