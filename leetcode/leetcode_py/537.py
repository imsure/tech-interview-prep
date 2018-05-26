class Solution:
    def _extract_ops(self, c):
        ops = c.split('+')
        op1 = ops[0]
        op2 = ops[1][:-1]  # ignore i

        return int(op1), int(op2)

    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a_op1, a_op2 = self._extract_ops(a)
        b_op1, b_op2 = self._extract_ops(b)

        # (a_op1 + a_op2) * (b_op1 + b_op2)
        op1 = a_op1 * b_op1 + a_op2 * b_op2 * -1
        op2 = a_op1 * b_op2 + a_op2 * b_op1

        return str(op1) + '+' + str(op2) + 'i'


if __name__ == '__main__':
    sol = Solution()
    print(sol.complexNumberMultiply('1+1i', '1+1i'))  # 0+2i
    print(sol.complexNumberMultiply('1+-1i', '1+-1i'))  # 0+-2i
