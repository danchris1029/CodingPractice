// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

public:
    void setZeroes(vector<vector<int>>& matrix) {
       set<pair<int, int>> addedZeros;
        
        for(int y = 0; y < matrix.size(); y++){
            for(int x = 0; x < matrix[0].size(); x++){

                if(matrix[y][x] == 0){
                    pair<int, int> pos = make_pair(y, x);

                    if(addedZeros.find(pos) == addedZeros.end()){
                        int k = 0;
                        while(k < matrix[0].size()){
                            if(matrix[y][k] != 0){
                               matrix[y][k] = 0;
                               addedZeros.insert(make_pair(y, k));
                            }
                            k++;
                        }

                        k = 0;
                        while(k < matrix.size()){
                            if(matrix[k][x] != 0){
                               matrix[k][x] = 0;
                               addedZeros.insert(make_pair(k, x));
                            }
                            k++;
                        }
                    }
                }
            }
        }
    }
};
