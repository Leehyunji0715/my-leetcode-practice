# Make array('arr') that includes current status of evaluation
# Check whether the found value in s is in 'arr' or not

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        arr = []
        idx = -1
        idx2 = -1
        idx_add = 1
        max_len = 0
        cur_len = 0
        s_length = len(s)
        
        if (s_length < 0 or s_length >50000): # check proper condition
            return -1
        
        if (idx == s_length-2): # when s has one character
            max_len = 1
            return max_len
        
        while (idx <= s_length-2): 
            idx = idx + 1
            arr.append(s[idx])
            cur_len = 1
            
            idx2 = idx + 1
            
            while (idx2 <= s_length-1):
                if(s[idx2] not in arr):
                    cur_len = cur_len + 1
                    arr.append(s[idx2])
                    if(max_len < cur_len):
                        max_len = cur_len
                else:
                    print(arr)
                    if(max_len < cur_len):
                        max_len = cur_len
                    arr = []
                    break       
                idx2 = idx2 + 1
                
        return max_len
            