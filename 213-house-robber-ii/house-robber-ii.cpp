class Solution {

private:
    int f(vector<int>& nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int nonpick=0+prev;
            int curri=max(pick,nonpick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        vector<int> t1,t2;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)t1.push_back(nums[i]);
            if(i!=n-1)t2.push_back(nums[i]);
        }
        return max(f(t1),f(t2));
    }
};