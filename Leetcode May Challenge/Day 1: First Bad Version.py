# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):



class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start,end = 1,n
        while start <= end:
            mid = start+(end-start)//2
            if isBadVersion(mid) == True and isBadVersion(mid) != isBadVersion(mid-1):
                result = mid
                break
            elif isBadVersion(mid) == True:
                end = mid-1
            else:
                start = mid+1
        
        return result
        
        
        
