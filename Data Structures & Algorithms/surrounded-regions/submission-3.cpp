class Solution {
public:
    
    void surround(vector<vector<char>>&board,int i, int j, vector<vector<int>>& visited){
        visited[i][j] = 1;

        int r = board.size();
        int c = board[0].size();

        // up i-1,j
        if(i>0 && !visited[i-1][j] && board[i-1][j]=='O') surround(board,i-1,j,visited);

        // down i+1,j
        if(i+1<=r-1 && !visited[i+1][j] && board[i+1][j]=='O') surround(board,i+1,j,visited);

        // left i,j-1
        if( j>0&&!visited[i][j-1] && board[i][j-1]=='O') surround(board,i,j-1,visited);

        // right i,j+1
        if(j+1<=c-1 && !visited[i][j+1] && board[i][j+1]=='O') surround(board,i,j+1,visited);

    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<int>>visited(r,vector<int>(c,0));
        for(int i = 0;i<c;i++){
            int el1 = board[0][i];
            if(el1=='O' && !visited[0][i]) surround(board,0,i,visited);
            int el2 = board[r-1][i];
            if(el2=='O' && !visited[r-1][i]) surround(board,r-1,i,visited);
        }

        for(int i = 1;i<r-1;i++){
            int el1 = board[i][0];
            int el2 = board[i][c-1];

            if(el1=='O' && !visited[i][0]) surround(board,i,0,visited);
            if(el2=='O' && !visited[i][c-1]) surround(board,i,c-1,visited);
        }

        for(int i = 1;i<r-1;i++){
            for(int j= 1;j<c-1;j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j] = 'X';
            }
        }

        return;
    }
};
