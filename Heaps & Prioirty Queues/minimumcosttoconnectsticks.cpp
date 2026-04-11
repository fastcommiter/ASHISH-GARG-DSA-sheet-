#include<bits/stdc++.h>

long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.
     //hume minimum cost track krni hai after add 2 sticks 
     //fir humne kya krna hai unko wps add on krdena hai 
     long long cost =0;
     
     priority_queue<int,vector<int>,greater<>>pq;
     for(auto i : arr) pq.push(i);
     while(pq.size() > 1){
          //jb tk empty ni hota kya kro is 
          int a = pq.top();
          pq.pop();
          int b = pq.top();
          pq.pop();
          cost += (a+b);
          int c = a+b;
          pq.push(c);
     }
     return cost;
}
