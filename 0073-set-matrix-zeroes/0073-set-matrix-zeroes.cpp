class Solution {
public:
    void fun(vector<vector<int>>& matrix,int start,int cStart,int cEnd,vector<int>& row,vector<int>& colm){
        for(int i = start;i<matrix.size();i++){
            for(int j = cStart;j<cEnd;j++){
              if(matrix[i][j] == 0){
                int I = 0;
                while(I<matrix.size()){
                    if((matrix[I][j] == 0)&&(i != I)){
                        row.push_back(I);
                    }
                    matrix[I][j] = 0;
                    I++;
                }
                I = 0;
                while(I < matrix[0].size()){
                     if((matrix[i][I] == 0)&&(j != I)){
                        colm.push_back(I);
                    }
                    matrix[i][I] = 0;
                    I++;
                }

                fun(matrix,i+1,0,j,row,colm);
                fun(matrix,i+1,j+1,matrix[0].size(),row,colm);
                  
                return;
              }
            }
        }
        return;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        // vector<int> row;
        vector<int> colm(matrix[0].size(),0);
        // fun(matrix,0,0,matrix[0].size(),row,colm);
        // for(int i : row){
        //     for(int j = 0;j<matrix[0].size();j++){
        //      matrix[i][j] = 0;
        //     }
        // }

        // for(int j : colm){
        //     for(int i = 0;i<matrix.size();i++){
        //         matrix[i][j] = 0;
        //     }
        // }

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