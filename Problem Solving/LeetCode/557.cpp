class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec = tokenize(s);

        string result = "";
        for(int i = 0; i < vec.size(); i++) {
        	reverse(vec[i].begin(), vec[i].end());

        	if(i != vec.size() - 1) {
        		result += vec[i] + " ";
        	} else {
        		result += vec[i];
        	}
        }

        return result;
    }

    vector<string> tokenize(string& s) {
    	vector<string> result;
    	string token;
    	stringstream ss;

    	ss << s;

    	while(ss >> token) {
    		result.push_back(token);
    	}

    	return result;

    }

};