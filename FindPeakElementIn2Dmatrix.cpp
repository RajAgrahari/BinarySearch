//https://leetcode.com/problems/find-a-peak-element-ii/
int findmax(vector<vector<int>> &mat , int r)
    {
        int maxe=INT_MIN;
        int idx=0;
        for(int i=0;i<mat[0].size();i++)
        {
            
            if(maxe<mat[r][i])
            {
                maxe=mat[r][i];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size() , n=mat[0].size();
        int l=0 , r=m-1;
        
        while(l<=r)
        {
            int mid=(l+(r-l)/2);
            
            int c=findmax(mat , mid);
            
            int val=mat[mid][c];
            
            if(mid==0)
            {
                if(mat[mid+1][c] < val)
                {
                    return {mid , c};
                }
            }
            else if(mid==m-1)
            {
                if(mat[mid-1][c]<val)
                {
                    return {mid , c};
                }
            }
            else if(val>mat[mid+1][c] && val>mat[mid-1][c])
            {
                return {mid , c};
            }
            if( val<mat[mid+1][c]) 
            l=mid+1;
            else
            r=mid-1;  
        }
        return {-1 , -1};
        
    }
