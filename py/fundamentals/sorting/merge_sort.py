def _merge(left, right):
    output = []
    p1, p2 = 0, 0

    while p1 < len(left) and p2 < len(right):
        if left[p1] <= right[p2]:
            output.append(left[p1])
            p1 += 1
        else:
            output.append(right[p2])
            p2 += 1

    if p1 < len(left):
        output.extend(left[p1:])

    if p2 < len(right):
        output.extend(right[p2:])

    return output


def merge_sort(array):
    """
    Divide and Conquer, Recursion

    Recursively divide the `input` into halves, sort each half independently, then merge
    the two together as a complete sorted list.

    Base case: each half contains a single element, then it's sorted already.

    :param array: list[int]
    :return:
    """
    n = len(array)

    if n <= 1:
        return array

    mid = n // 2
    sorted_left = merge_sort(array[0:mid])
    sorted_right = merge_sort(array[mid:n])
    output = _merge(sorted_left, sorted_right)

    return output


print(merge_sort([]))
print(merge_sort([4]))
print(merge_sort([0, -5]))
print(merge_sort([0, -5, -8]))
print(merge_sort([-3, -2, -1, 0, 1, 2, 3]))
print(merge_sort([5, 4, 3, 2, 1]))
print(merge_sort([5, 8, 3, 9, 1, 0]))
