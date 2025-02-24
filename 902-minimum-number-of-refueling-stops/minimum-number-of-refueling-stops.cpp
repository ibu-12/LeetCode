class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        int curr=startFuel;
        int result=0;
        int i=0;
        priority_queue<int> pq;
        while(curr<target){
            while(i<n && curr>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
            return -1;

            curr+=pq.top();
            pq.pop();
            result++;
        }
        return result;
    }
};