class Solution {
public:
    string reverseVowels(string s) {
        int i, j;
        i = 0;
        j = s.size() - 1;

        while(true) {
        	while(i < s.size() && !isVowel(s[i])) {
        		i++;
        	}

        	while(j >= 0 && !isVowel(s[j])) {
        		j--;
        	}

        	if(i > j) break;

        	swap(s[i], s[j]);

        	i++; j--;
        }

        return s;
    }

    bool isVowel(char c) {
    	c = tolower(c);
    	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};