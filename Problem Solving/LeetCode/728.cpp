class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
    	vector<int> res;
        for(int i = left; i <= right; i++) {
            string sval = to_string(i);
            solve(sval, i, res);
        }

        return res;
    }

    void solve(string sval, int val, vector<int>& res) {
    	for(auto c : sval) {
    		if(c == '0')
    			return;

    		if(val % (c - '0') != 0)
    			return;
    	}

    	res.push_back(val);
    }
};