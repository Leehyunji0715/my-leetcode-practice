#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)  return s.size();

        int left=0, right=0, longest = 0;
        int cur_len = 0;
        map<char, int> m;
        
        for(int right = 0; right < s.size(); right++)
        {
            char cur_char = s.at(right);

            if( m.find(cur_char) == m.end() || m[cur_char] < left)
            {
                m[cur_char] = right ;
                cur_len++;
            } 
            else if( m[cur_char] >= left) 
            {
                left = m[cur_char] + 1;
                m[cur_char] = right;
                cur_len = right-left+1;
            }
                longest = max(longest, cur_len);
        }
        return longest;
    }
};


int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << "  => should be 3 \n\n";
    cout << sol.lengthOfLongestSubstring("abcbdaac") << "  => should be 4 \n\n";
    cout << sol.lengthOfLongestSubstring("pwwkew") << "  => should be 3 \n\n";
}