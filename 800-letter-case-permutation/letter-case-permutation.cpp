class Solution {
public:

    void solve(int ind,string s,string ans,vector<string> &res){
        if(ind==s.length()){
            res.push_back(ans);
        }
        if(s[ind]>='0'  && s[ind]<='9'){
            ans+=s[ind];
            solve(ind+1,s,ans,res);
        }
        if(s[ind]>='a'  && s[ind]<='z'){
            ans+=toupper(s[ind]);
            solve(ind+1,s,ans,res);
            ans[ans.length()-1]=s[ind];
            solve(ind+1,s,ans,res);
        }
        if(s[ind]>='A'  && s[ind]<='Z'){
            ans+=tolower(s[ind]);
            solve(ind+1,s,ans,res);
            ans[ans.length()-1]=s[ind];
            solve(ind+1,s,ans,res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(0,s,"",res);
        return res;
    }
};