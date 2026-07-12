class Solution {
public:
    int getLteCol(vector<vector<int>>& matrix, int target){
        int st = 0;
        int en = matrix.size()-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(mid == matrix.size()-1 || matrix[mid][0]<=target && matrix[mid+1][0]> target) return mid;
            else if(matrix[mid][0]<target) st = mid+1;
            else en= mid-1;
        }
        return -1;
    }

    bool searchRow(vector<vector<int>>& matrix, int row, int target){
        int st = 0;
        int en = matrix[0].size()-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(matrix[row][mid]==target) return true;
            else if (matrix[row][mid]>target) en = mid-1;
            else st = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;
       // col search
       int lteCol = getLteCol(matrix,target);
       if(lteCol<0 || lteCol>matrix.size()) return false;
       if( matrix[lteCol][0]==target) result = true;
       else{
         result = searchRow(matrix,lteCol,target);
       }       
        return result;
    }
};
