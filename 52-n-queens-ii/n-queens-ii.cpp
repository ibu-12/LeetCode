class Solution {

public:
    int stt=0;
    bool isSafe(int row,int col,vector<string> &board,int n)
    {
        int drow=row;int dcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        col=dcol;
        row=drow;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
       col=dcol;
        row=drow;
         while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }


    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            stt++;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return stt;
    }
};