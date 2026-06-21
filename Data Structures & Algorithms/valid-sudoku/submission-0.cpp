class Solution {
public:
    bool isDuplicateRow(vector<vector<char>>&board,int row,int start, int limit){
        unordered_map<char,bool>mp;
        for(int i = start;i<start+limit;i++){
            if(board[row][i]!='.' && mp[board[row][i]]==true) return true;
            if(board[row][i]!='.') mp[board[row][i]] = true;
        }
        return false;
    }
    bool isDuplicateCol(vector<vector<char>>&board,int col,int start, int limit){
        unordered_map<char,bool>mp;
        for(int i = start;i<start+limit;i++){
            if(board[i][col]!='.' && mp[board[i][col]]==true) return true;
            if(board[i][col]!='.') mp[board[i][col]] = true;
        }
        return false;
    }
    bool checkDup(vector<vector<char>>&board,int r, int c,int size){
        unordered_map<char,bool>mp;
        for(int i = r;i<r+size;i++){
            for(int j = c;j<c+size;j++){
                if(board[i][j] != '.' && mp[board[i][j]]==true) return true;
                if(board[i][j]!='.') mp[board[i][j]] = true;
            }
        }
        return false;
    }
    bool isValidSquare(vector<vector<char>>&board,int r,int c,int limit){
        for(int i = r;i<r+limit;i++){
           bool isDupRow = isDuplicateRow(board,i,c,limit);
           if(isDupRow) return false;
        }
        for(int i = c;i<c+limit;i++){
            bool isDupCol = isDuplicateCol(board,i,r,limit);
            if(isDupCol) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // check full square valid
        bool validSq = isValidSquare(board,0,0,9);
        if(!validSq) return false;
        // check 3x3 boxes
        for(int i = 0;i<9;i+=3){
            for(int j= 0;j<9;j+=3){
                bool validMin = isValidSquare(board,i,j,3);
                if(!validMin) return false;
                bool dupBoard = checkDup(board,i,j,3);
                if(dupBoard) return false;
            }
        }
        return true;
    }
};
