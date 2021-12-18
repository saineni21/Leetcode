class Solution {
public:
    
    int temp = 0, largestArea = 0;
    bool atleastOne = false;
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int largestPossibleSquare = getLargestPossibleSquare(matrix);
        
        for(int i = 0; i< matrix.size(); i++){
            for(int j = 0; j< matrix[0].size(); j++){
                
                if(matrix[i][j] == '1'){
                    checkNeighbours(i, j, matrix);
                }
            }
        }

        return largestArea * largestArea;
          
    }
    
    void checkNeighbours(int i, int j, vector<vector<char>>& matrix){

        temp = 1;
        atleastOne = true;

        while(temp + i < matrix.size() && temp + j < matrix[0].size() && atleastOne){
            for (int k = j; k <= temp + j; k++) {
                if (matrix[i + temp][k] == '0') {
                    atleastOne = false;
                    break;
                }
            }
            for (int k = i; k <= temp + i; k++) {
                if (matrix[k][j + temp] == '0') {
                    atleastOne = false;
                    break;
                }
            }
            if (atleastOne){
                temp++;
            }
        }
        if(largestArea < temp){
            largestArea = temp;
        }
    }
    
};