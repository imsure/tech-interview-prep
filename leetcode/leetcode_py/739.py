class Solution:
    def dailyTemperatures(self, temperatures):
        """
        Store the (0, t_0) pair for the first temperature on a stack.
        Then for each of the subsequent temperature t_i at index i,
        compare t_i with the value t_j on top of the stack, if t_i > t_j,
        pop t_j out of the stack and output for t_j is i - j, then continue to compare t_j
        with remaining elements on the stack until t_j is less than the value on top of stack or stack becomes empty;
        otherwise if t_i <= t_j, just push (j, t_j). Continue to
        the next temperature.

        After exhausting the input, the elements remained on stack all have output of 0.

        :type temperatures: List[int]
        :rtype: List[int]
        """
        n = len(temperatures)
        output = [0] * n
        stack = [(0, temperatures[0])]

        for i in range(1, n):
            while stack:
                j, value = stack[len(stack) - 1]
                if temperatures[i] > value:
                    output[j] = i - j
                    stack.pop()
                else:
                    break

            stack.append((i, temperatures[i]))

        return output


sol = Solution()
print(sol.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))