class Solution {
public:

    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds,int k) {
        if (target == 0) {
            if(ds.size()==k)
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds,k);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector < vector < int >> ans;
        vector < int > ds;
        vector<int> arr;
        for(int i=1;i<10;i++){
            arr.push_back(i);
        }
        findCombination(0, n, arr, ans, ds, k);
        return ans;
    }
};