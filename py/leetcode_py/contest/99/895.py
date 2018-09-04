import heapq

class FreqStack:

    def __init__(self):
        self.ID = 1
        self.stack = {}
        self.count = {}
        self.heap = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if x in self.stack:
            self.stack[x] += 1
        else:
            self.stack[x] = 1

        c = self.stack[x]
        if c in self.count:
            self.count[c].append(x)
        else:
            self.count[c] = [x]
            heapq.heappush(self.heap, -c)

    def pop(self):
        """
        :rtype: int
        """
        most_freq = heapq.heappop(self.heap)
        most_freq = -most_freq
        # print(most_freq)
        x = self.count[most_freq].pop()
        if self.count[most_freq]:
            heapq.heappush(self.heap, most_freq)

        return x


# Your FreqStack object will be instantiated and called as such:
obj = FreqStack()
obj.push(5)
obj.push(7)
obj.push(5)
obj.push(7)
obj.push(4)
obj.push(5)
# print(obj.stack)
# print(obj.count)
# print(obj.heap)
print(obj.pop())
print(obj.pop())
print(obj.pop())
print(obj.pop())