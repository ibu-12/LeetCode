class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=0;i<n;i++){
            s+=to_string(i+1);
        }
        int i=1;
        string st;
        do{
            if(i==k){
                st=s;
                break;
            }
            i++;
        }while(next_permutation(s.begin(),s.end()));
        return st;
    }
};