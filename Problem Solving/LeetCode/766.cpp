class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    	int m = matrix.size();
    	int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
            	if(!solve(i, j, m, n,matrix))
            		return false;
            }
        }

        return true;
    }

    bool solve(int i, int j, int m, int n, vector<vector<int>>& matrix) {
    	int val = matrix[i][j];
    	while(i < m && j < n) {

    		if(val != matrix[i][j])
    			return false;

    		i++; j++;

    	}

    	return true;
    }
};



// 1234
// 5123
// 9512