# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        nread = 0
        eof = False
        while nread < n and not eof:
            tmp_buf = [''] * 4
            m = read4(tmp_buf)
            # n - nread: number of remaining chars to read
            # m maybe greater than the remaining number of chars to read, so
            # need to pick the min of the two.
            for i in range(0, min(m, n - nread)):
                buf[i + nread] = tmp_buf[i]
            nread += m
            if m < 4:
                eof = True

        return nread if nread < n else n