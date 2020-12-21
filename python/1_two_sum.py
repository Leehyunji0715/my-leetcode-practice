class Solution(object):
    min_len = 2
    max_len = 1000
    pb_min = -1000000000
    pb_max = 1000000000

    
    def twoSum(self, nums, target):
        arr_length = len(nums)
        if(arr_length < self.min_len or arr_length > self.max_len):
            return []
        
        for k in range(0, arr_length):
            if( nums[k] < self.pb_min or nums[k] > self.pb_max):
                return []
        
        for i in range(0, arr_length-1):
            for j in range(i+1, arr_length):
                if( (nums[i] + nums[j]) == target):
                    return [i, j]
                
        return []
        