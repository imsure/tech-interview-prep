class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        keys = set()
        for index, room in enumerate(rooms):
            for key in room:
                if key != 0 and key != index:
                    keys.add(key)

        if len(keys) == len(rooms) - 1:
            return True

        return False

    def _open_room(self, index, rooms, opened, visited):
        if index in visited:
            return

        visited.add(index)
        for key in rooms[index]:
            opened.add(key)
            self._open_room(key, rooms, opened, visited)

    def canVisitAllRooms2(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        opened = {0}
        visited = set()
        self._open_room(0, rooms, opened, visited)
        if len(opened) == len(rooms):
            return True

        return False


if __name__ == '__main__':
    sol = Solution()
    print(sol.canVisitAllRooms2([[1],[2],[3],[]]))  # true
    print(sol.canVisitAllRooms2([[1,3],[3,0,1],[2],[0]]))  # false
    print(sol.canVisitAllRooms2([[4],[3],[],[2,5,7],[1],[],[8,9],[],[],[6]]))  # false