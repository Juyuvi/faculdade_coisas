class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        ss2 = ""
        c = 0
        for i in s:
            ss2 += i
            while (ss2.count(i) > 1):
                ss2 = ss2[1:]
            

            if len(ss2) > c:
                c += 1

        return c
        
                