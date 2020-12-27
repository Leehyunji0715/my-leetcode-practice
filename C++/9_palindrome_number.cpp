class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.length();
        
        if(x < 0)
            return false;
        
        if(len % 2 == 0){
            for(int i=0; i<len/2; i++ )
                if(s[i] != s[len-1-i])
                    return false; 
        }
        else {
            for(int i=0; i<len/2; i++ )
                if(s[i] != s[len-1-i])
                    return false; 
        }

        return true;
    }
};
