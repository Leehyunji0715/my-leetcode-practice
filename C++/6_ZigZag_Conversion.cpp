class Solution {
public:
    string convert(string s, int numRows) {
        // ex. PAYPALISHIRING
        // string[0]: P A H N
        // string[1]: A P L S I I G
        // string[2]: Y I R
        
        vector<string> vs(numRows, "");
        string result = "";
        int n = s.length();
        int at = 0;
        
        while (at < n) 
        {
            /*  at < n: prevent memory area intrusion(?) */
            for (int j = 0; j < numRows  && at < n ; j++) 
                vs[j].push_back(s[at++]);
            
            for (int j = numRows-2; j > 0 && at < n; j--)
                vs[j].push_back(s[at++]);
        }
        
        for (string str: vs){
            str.erase(remove(str.begin(), str.end(), '\x00'), str.end());
            result += str; 
        }
        return result;
    }
};
