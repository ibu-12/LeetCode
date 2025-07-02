class Solution {
public:

    int f(int n, int m, string& s1, string& s2, vector<vector<int>>& memo) {
        if (n == 0 )
            return m;
        if (m == 0 )
            return n;

        if (memo[n][m] != -1)
            return memo[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            memo[n][m] = f(n - 1, m - 1, s1, s2, memo);
        } else {
            memo[n][m] =1 + min({f(n - 1, m, s1, s2, memo), f(n, m - 1, s1, s2, memo),f(n-1,m-1,s1,s2,memo)});
        }

        return memo[n][m];
    }

    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return f(n, m, text1, text2, memo);
    }
};