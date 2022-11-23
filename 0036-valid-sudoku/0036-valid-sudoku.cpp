class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) 
   {
        
        map<int,map<int,int>> row;
        map<int,map<int,int>> col;
        map<pair<int,int>,map<int,int>> box;
        
        for(int i=0;i<=8;i++)
        {
            for(int j=0;j<=8;j++)
            {
                
                if(board[i][j]=='.')
                {
                    continue;
                }
                if(row[i][board[i][j]] || col[j][board[i][j]] || box[{i/3,j/3}][board[i][j]])
                {
                    return false;
                }
                row[i][board[i][j]]++;
                col[j][board[i][j]]++;
                box[{i/3,j/3}][board[i][j]]++;
            }
        }
        
        return true;
    }
};