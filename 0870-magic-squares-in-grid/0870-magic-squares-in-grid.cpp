class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                if(isMagicSquare(grid,i,j))
                    count++;
            }
        }
        return count;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid,int r,int c)
    {
        vector<int>nums;
        //check if 3x3 grid contains all numbers from 1 to 9
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        for(int k=0;k<9;k++)
        {
            if(nums[k]!=k+1)
                return false;
        }
        //Calculate the sum of first row
        int sum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        //check rows
        for (int i = r; i < r + 3; i++) {
            if (grid[i][c] + grid[i][c + 1] + grid[i][c + 2] != sum) {
                return false;
            }
        }

        // Check columns
        for (int j = c; j < c + 3; j++) {
            if (grid[r][j] + grid[r + 1][j] + grid[r + 2][j] != sum) {
                return false;
            }
        }

        // Check diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum) {
            return false;
        }
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum) {
            return false;
        }

        return true;
    }
};