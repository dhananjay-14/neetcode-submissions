class Solution {
public:
    string resWord;
    bool solve(vector<vector<char>>&board,int i, int j, int ind, vector<vector<int>>&visited){
        if(ind==resWord.length()-1) return true;
        visited[i][j]=1;

        bool finalRes = false;
        // up 
        if(i>0 &&!visited[i-1][j] && board[i-1][j]==resWord[ind+1]) finalRes = finalRes || solve(board,i-1,j,ind+1,visited);

        // left
        if( j>0 && !visited[i][j-1] &&board[i][j-1]==resWord[ind+1]) finalRes = finalRes || solve(board,i,j-1,ind+1,visited);

        // right
        if(j<board[0].size()-1 && !visited[i][j+1] &&  board[i][j+1]==resWord[ind+1]) finalRes = finalRes || solve(board,i,j+1,ind+1,visited);

        // left
        if(i<board.size()-1 && !visited[i+1][j] &&  board[i+1][j]==resWord[ind+1]) finalRes = finalRes || solve(board,i+1,j,ind+1,visited);

        visited[i][j]=0;
        return finalRes;
    }
    bool exist(vector<vector<char>>& board, string word) {
        resWord = word;
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                bool res = solve(board,i,j,0,visited);
                if(res) return res;
                }
            }
        }
        return false;
    }
};
