class Solution {
public:
    int count(vector<vector<int>>&mat, int n,int target)
    {
        int curr_row = n-1, curr_col = 0, count = 0;
        while(curr_row>=0 && curr_col<n){
            if(mat[curr_row][curr_col]<=target)
            {
                count +=curr_row+1;
                curr_col++;
            }
            else curr_row--;
        }
        return count;
    }
    
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        /*priority_queue<int>pq;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();*/
        int n = mat.size(),low = mat[0][0], high = mat[n-1][n-1];
        while(low<high)
        {
            int mid = low + (high - low)/2;
            int res = count(mat,n,mid);
            if(res>=k)high = mid;
            else low = mid+1;            
        }
        return high;
    }
};