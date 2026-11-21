class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    // colm array as hash table to store which colms need to be made 0 while traversing 
        vector<int> colm(matrix[0].size(),0);

    // travers to matrix and make those rows 0 where 0 cames and also store their coloums to make them 0 after traversal ends 

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0 ; j < matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    for(int k = 0;k<matrix[0].size();k++){
                        if((matrix[i][k]==0)&&(colm[k] == 0)){
                            colm[k]++;
                        }
                        matrix[i][k] = 0;
                    }
                    break;
                }
            }
        }

        for(int j = 0 ; j < colm.size();j++){
           if(colm[j] == 1){
               for(int i = 0;i<matrix.size();i++){
                    matrix[i][j] = 0;
                }
           }
        } 
    }
    
};