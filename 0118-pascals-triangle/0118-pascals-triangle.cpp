class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr(numRows);
    
        arr[0].push_back(1);
        for(int i=1;i<numRows;i++){
             arr[i].push_back(1);
            for(int j = 1;j<i;j++){
               arr[i].push_back(arr[i-1][j-1] + arr[i-1][j]);
            }
            arr[i].push_back(1);      
        }

        return arr;
    }
};