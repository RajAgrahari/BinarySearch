//https://leetcode.com/problems/search-a-2d-matrix/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx = INT_MAX;
        for(int i=matrix.size()-1; i>=0; i--){
            if(matrix[i][0]==target){
                return true;
            }else if(matrix[i][0]>target){
                    idx = i;
            }else{
                idx = i;
                break;
            }
        }
        int start = 0;
        int end = matrix[0].size()-1; 
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[idx][mid]>target){
                end = mid-1;
            }else if(matrix[idx][mid]<target){
                start = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
