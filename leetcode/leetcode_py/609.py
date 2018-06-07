class Solution:
    def findDuplicate(self, paths):
        """
        HashTable

        :type paths: List[str]
        :rtype: List[List[str]]
        """
        content2path = {}

        for item in paths:
            fields = item.split(sep=' ')
            dir_path = fields[0]
            for file in fields[1:]:
                subfields = file.split(sep='.')
                fname = subfields[0]
                content = subfields[1][4:-1]
                if content in content2path:
                    content2path[content].append(dir_path + '/' + fname + '.txt')
                else:
                    content2path[content] = [dir_path + '/' + fname + '.txt']

        groups = []
        for value in content2path.values():
            if len(value) < 2:
                continue
            group = []
            for path in value:
                group.append(path)
            groups.append(group)

        return groups


sol = Solution()
print(sol.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]))
print(sol.findDuplicate(["root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"]))