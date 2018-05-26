class Solution:
    def partitionLabels(self, S):
        """
        Linear scan the input string, store the previous partitions
        into a list. If the current char belongs to any of the previous
        partitions, merge them with the current char into one partition.

        :type S: str
        :rtype: List[int]
        """
        import itertools

        parts = []
        sets = []
        for c in S:
            # print(parts)
            seen = False
            merge_start = -1
            for i in range(0, len(sets)):
                if c in sets[i]:
                    seen = True
                    merge_start = i
                    break

            parts.append([c])
            sets.append({c})
            if seen:
                parts_tmp = []
                sets_tmp = []
                for i in range(merge_start):
                    parts_tmp.append(parts[i])
                    sets_tmp.append(sets[i])

                parts_tmp.append(list(itertools.chain(*parts[merge_start:])))
                sets_tmp.append(set(itertools.chain(*sets[merge_start:])))
                parts = parts_tmp
                sets = sets_tmp

        return [len(part) for part in parts]


    def partitionLabels2(self, S):
        """
        Keep a dict/map of each unique letter's last position index (anchor) in the input.
        Then greedily choose the smallest partition for the first letter 'c'

        :type S: str
        :rtype: List[int]
        """
        lasts = {c: index for index, c in enumerate(S)}

        parts = []
        end = anchor = 0
        for i, c in enumerate(S):
            end = max(end, lasts[c])
            if end == i:
                parts.append(end - anchor + 1)
                anchor = end + 1

        return parts


if __name__ == '__main__':
    sol = Solution()
    print(sol.partitionLabels('ababcbacadefegdehijhklij'))  # [9, 7, 8]
    print(sol.partitionLabels2('ababcbacadefegdehijhklij'))  # [9, 7, 8]
    # print(sol.partitionLabels2('ababcbacadefegdehijhklij'))  # [9, 7, 8]
