import heapq
import itertools
import collections


class FreqStack:

    def __init__(self):
        import collections

        self.seq_num = 0
        self.data = collections.defaultdict(list)

    def push(self, x):
        """
        O(1)

        :type x: int
        :rtype: void
        """
        self.data[x].append(self.seq_num)
        self.seq_num += 1

    def pop(self):
        """
        O(N)

        :rtype: int
        """
        ret = -1
        max_freq, max_seq = -1, -1
        for elem in self.data:
            freq = len(self.data[elem])
            last_seq = self.data[elem][freq-1]
            if freq > max_freq:
                ret = elem
                max_freq = freq
                max_seq = last_seq
            elif freq == max_freq and last_seq > max_seq:
                ret = elem
                max_seq = last_seq

        self.data[ret].pop()
        if len(self.data[ret]) == 0:
            self.data.pop(ret)

        return ret


class FreqStack2:

    def __init__(self):
        self.counter = itertools.count(0)
        self.pq = []
        self.entry_map = {}
        self.stacks = collections.defaultdict(list)

    def push(self, x):
        """
        O(1)

        :type x: int
        :rtype: void
        """
        count = -next(self.counter)
        if x in self.entry_map:
            entry = self.entry_map.pop(x)
            entry[-1] = -1  # mark as invalid
            new_entry = [entry[0] - 1, count, x]
        else:
            new_entry = [-1, count, x]

        self.stacks[x].append(count)
        self.entry_map[x] = new_entry
        heapq.heappush(self.pq, new_entry)
        # print(self.pq)
        # print(self.stacks)

    def pop(self):
        """
        O(N)

        :rtype: int
        """
        while self.pq:
            top_entry = heapq.heappop(self.pq)
            if top_entry[-1] == -1:
                continue
            freq, count, elem = -top_entry[0], top_entry[1], top_entry[2]
            self.entry_map.pop(elem)
            self.stacks[elem].pop()
            if self.stacks[elem]:
                new_entry = [-(freq-1), self.stacks[elem][len(self.stacks[elem])-1], elem]
                self.entry_map[elem] = new_entry
                heapq.heappush(self.pq, new_entry)
            # print(self.stacks)
            # print(self.pq)
            return elem


# Your FreqStack object will be instantiated and called as such:
obj = FreqStack2()
obj.push(5)
obj.push(7)
obj.push(5)
obj.push(7)
obj.push(4)
obj.push(5)
print(obj.pop())  # 5
print(obj.pop())  # 7
print(obj.pop())  # 5
print(obj.pop())  # 4
