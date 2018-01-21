class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ret;

        int p[100010];
        memset(p, -1, sizeof(p));


    	for(int i = 0; i < B.size(); i++) {
			p[B[i]] = i;
		}

		for(auto i : A) {
			ret.push_back(p[i]);
		}

        return ret;
    }
};