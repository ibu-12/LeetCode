class Solution {
public:
    
    int findSubtreeSum(TreeNode* root, unordered_map<int,int> &map,int &maxFrequency){
        
       if(root == NULL)
           return 0;
        
        int left = findSubtreeSum(root->left,map,maxFrequency);
        int right = findSubtreeSum(root->right,map,maxFrequency);
        
        int currSubTreeSum = left + right + root->val;
        
        map[currSubTreeSum] += 1 ;
        
        if(map[currSubTreeSum]>maxFrequency)
            maxFrequency = map[currSubTreeSum];
        
        return currSubTreeSum;
        
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int>map;
        
        int maxFrequency = 0 ;
        
        findSubtreeSum(root,map,maxFrequency);
        
        vector<int>result;
        
        for(auto element : map)
            if(element.second == maxFrequency)
                result.push_back(element.first);
        
        return result;
    }
};