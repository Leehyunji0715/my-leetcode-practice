#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        bool DP_match_array [21][21] = {0};
        int r = -1;
        //bool DP_match_array [s.length()+1][p.length()+1];
        
        //empty pattern and string exists
        for(int i = 0; i < s.length(); i++)
            DP_match_array[i][0] = false; 
        
        //empty string and pattern exists
        for(int j = 0; j < p.length(); j++)
            DP_match_array[0][j] = false;
        
        // both string and pattern are empty
        DP_match_array[0][0] = true; 
        
        for (int i=0; i< s.length() ; i++){
            for(int j=0; j< p.length() ; j++){
                if(s[0] == p[j] || (i==0 && p[j] == '.'))
                    DP_match_array[1][j+1] = true;
                if(s[i] == p[j] || p[j] == '.'){
                    r=1; DP_match_array[i+1][j+1] = DP_match_array[i][j];
                }
                else if (p[j] == '*' && p[j-1]){
                    // 0 times of preceding character
                    if(DP_match_array[i+1][j-1]){
                        r=3;
                        DP_match_array[i+1][j+1] = true;
                    }
                    else if(DP_match_array[i+1][j]==true || DP_match_array[i][j+1]==true){
                        r =4;
                        DP_match_array[i+1][j+1] = true;
                    }
                    else{
                        r=5;
                        DP_match_array[i+1][j+1] = false;
                    }
                }
                else if(s[i] != p[j]){
                    r=6;
                    DP_match_array[i+1][j+1] = false;
                }
                else
                    return false; // pattern is wrong
                
                cout << "r: "<< r <<"\n";
                cout <<"(i,j): " << i << ", " << j << "\n";
                cout << "(s[i],p[j],DP[i+1][j+1]):  " << "(" << s[i] <<", " << p[j] <<", " << DP_match_array[i+1][j+1] << ")\n\n";
            
            }
        }
        return DP_match_array[s.length()][p.length()];
    }
};

int main(){
    Solution sol;
    cout << sol.isMatch("mississippi", "mis*is*p*.") <<"\n\n";

    //sol.isMatch("mississippi", "mis*is*p*.")
}