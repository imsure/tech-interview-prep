class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        At time_i, if time_i - time_(i-1) >= duration, then Ashe will
        be poisoned by duration seconds, otherwise Ashe will be poisoned
        by time_i - time_(i-1) seconds.

        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        n = len(timeSeries)
        if n == 0:
            return 0

        t_prev = timeSeries[0]
        total_dur = duration

        for t_cur in timeSeries[1:]:
            if t_cur - t_prev >= duration:
                total_dur += duration
            else:
                total_dur += t_cur - t_prev

            t_prev = t_cur

        return total_dur


sol = Solution()
print(sol.findPoisonedDuration([1,4], 2))
print(sol.findPoisonedDuration([1,2], 2))
print(sol.findPoisonedDuration([1,2,3,4,5], 5))
