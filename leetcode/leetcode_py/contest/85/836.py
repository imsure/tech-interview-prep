class Solution:
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        x_lower, y_lower = rec1[0], rec1[1]
        x_upper, y_upper = rec1[2], rec2[3]

        if rec1[0] >= rec2[2] or rec2[0] >= rec1[2]:
            return False

        if rec1[1] >= rec2[3] or rec2[1] >= rec1[3]:
            return False

        # if (x_lower < rec2[0] < x_upper) and (y_lower < rec2[1] < y_upper):
        #     return True
        #
        # if (x_lower < rec2[2] < x_upper) and (y_lower < rec2[3] < y_upper):
        #     return True
        #
        # if (x_lower < rec2[0] < x_upper) and (y_lower < rec2[3] < y_upper):
        #     return True
        #
        # if (x_lower < rec2[2] < x_upper) and (y_lower < rec2[1] < y_upper):
        #     return True

        return True