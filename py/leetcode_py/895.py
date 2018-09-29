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
    """
    Priority Queue + HashMap + Stack
    """

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
            entry[-1] = -1  # mark the dated entry as invalid
            new_entry = [entry[0] - 1, count, x]
        else:
            new_entry = [-1, count, x]

        self.stacks[x].append(count)  # update stack
        self.entry_map[x] = new_entry
        heapq.heappush(self.pq, new_entry)  # insert new entry

    def pop(self):
        """
        O(1)

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
            return elem


class FreqStack3:
    """
    Improved version:
    Priority Queue + HashMap
    """

    def __init__(self):
        self.counter = itertools.count(0)
        self.pq = []
        self.count_map = collections.defaultdict(int)

    def push(self, x):
        """
        O(1)

        :type x: int
        :rtype: void
        """
        seq_num = -next(self.counter)
        self.count_map[x] += 1
        heapq.heappush(self.pq, [-self.count_map[x], -seq_num, x])

    def pop(self):
        """
        O(1)

        :rtype: int
        """
        entry = heapq.heappop(self.pq)
        self.count_map[entry[2]] -= 1
        return entry[2]


# Your FreqStack object will be instantiated and called as such:
obj = FreqStack3()
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
