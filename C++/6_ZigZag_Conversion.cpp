class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.length();
        int interval = numRows + (numRows-2);
        int at = 0;
        char result[length];
        
        for(int i=0; i<numRows; i++){
            for(int j=0; j<length; j++){
                if(j % interval == i){
                    result[j] = s[at];
                    at++;
                }
            }
        }
        cout << interval << "-";
        cout << result << "\n";
        return result;
    }
};
