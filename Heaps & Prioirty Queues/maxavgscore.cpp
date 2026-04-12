class Solution {
public:

    double gain(double a ,double b)
    {
        return (a+1)/(b+1) - (a/b);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<pair<double,pair<int,int>>>pq;
       for(auto i : classes)
       {
            double p = i[0];
            double t = i[1];
            pq.push({gain(p,t),{p,t}});
       } 
       //yh humne fill krdiya hai gained value or noaml value k hisb s 
       //ab kya kro extrastudents mai iterate kro or nikalo kint apossible hai 
       while(extraStudents--)
       {
            auto a = pq.top();
            double x = a.second.first;
            double y = a.second.second;

            x+=1;
            y+=1;
            //dono mai 1-1 value add kri humne 
            //ab nikalo values 
            pq.pop();
            pq.push({gain(x,y),{x,y}});
       }
       double sum=0;
       //ab mera final ready hai queue jisme sare final coordinates pade hue hai 
       while(!pq.empty())
       {
            double a = pq.top().second.first;
            double b = pq.top().second.second;

            double res = a/b;
            sum+=res;
            pq.pop();
       }
       return sum/classes.size();
    }
};
