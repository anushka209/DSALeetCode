class Solution {
public:
    void place_queen(int col,int n,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal)
    {
       if(col==n)
       {
          ans.push_back(board);
          return;
       }
       for(int row=0;row<n;row++)       //iterate in every row
       {
         if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0)
         {
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;
            place_queen(col+1,n,board,ans,leftRow,lowerDiagonal,upperDiagonal);
            board[row][col]='.';          //backtrack
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
         }
       }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      vector<string>board(n);
      string s(n,'.');
      for(int i=0;i<n;i++)
      {
        board[i]=s;
      }
      vector<int>leftRow(n,0),lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
      place_queen(0,n,board,ans,leftRow,lowerDiagonal,upperDiagonal);
      return ans;
    }
};