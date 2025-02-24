class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            if(f!=s){
                pq.push(f-s);
            }
            else{
                pq.push(0);
            }
        }
        if(pq.size()==0)return 0;
        return pq.top();
    }
};