class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):

        both = sorted(nums1 + nums2)
        tam = len(both)

        return (both[int(tam/2 - 1)] + both[int(tam/2)])/2.0 if tam % 2 == 0 else both[int(tam/2)]
        
