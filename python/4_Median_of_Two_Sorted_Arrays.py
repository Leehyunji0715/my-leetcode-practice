class Solution:    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        totalSum = 0
        m = len(nums1)
        n = len(nums2)
        
        # Core part: Merge two arrays and sort#
        merged = nums1+nums2
        merged.sort()
        
        length = len(merged) 
        
        if(length > 0):
            med = int(length/2)
            if(length % 2 == 0):
                return (merged[med-1]+merged[med])/2
            else:
                return merged[med]
    
        return 0.0