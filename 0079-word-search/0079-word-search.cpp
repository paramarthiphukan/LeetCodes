class Solution 
{
 private:
    	int rows;
    	int cols;
        bool isFound(vector<vector<char> > &board, const char* curChar, int curRow, int curCol)
        {
    		if(curRow<0 || curCol<0 || curRow>=rows || curCol>=cols || board[curRow][curCol]=='\0' || *curChar!=board[curRow][curCol])
    			return false;
            if(*(curChar+1)=='\0')
                return true;
    		char t=board[curRow][curCol];
    		board[curRow][curCol]='\0';
            
    		if(isFound(board, curChar+1, curRow-1, curCol) || isFound(board, curChar+1, curRow+1, curCol) || isFound(board, curChar+1, curRow, curCol-1) || isFound(board, curChar+1, curRow, curCol+1))
    			return true; 
            
    		board[curRow][curCol] = t;
            return false;
        }
    public:
    	 bool exist(vector<vector<char>> &board, string word) 
         {
    		 rows = board.size();
    		 cols = board[0].size();
            for(int curRow = 0; curRow < rows; ++curRow)
            {
                for(int curCol = 0; curCol < cols; ++curCol)
                {
    				if(isFound(board, word.c_str(), curRow, curCol))
    					return true;
                }
            }
            return false;
        }
    
};