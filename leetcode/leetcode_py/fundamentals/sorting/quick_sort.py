from random import randint


def quick_sort(array):
    """

    :param input: list[int]
    :return:
    """
    n = len(array)

    if n <= 1:
        return array

    pivot_index = randint(0, n - 1)
    pivot = array[pivot_index]
    left = [x for i, x in enumerate(array) if i != pivot_index and x <= pivot]
    right = [x for i, x in enumerate(array) if i != pivot_index and x > pivot]

    sorted_left = quick_sort(left)
    sorted_right = quick_sort(right)

    return sorted_left + [pivot] + sorted_right


print(quick_sort([]))
print(quick_sort([4]))
print(quick_sort([0, -5]))
print(quick_sort([0, -5, -8]))
print(quick_sort([-3, -2, -1, 0, 1, 2, 3]))
print(quick_sort([5, 4, 3, 2, 1]))
print(quick_sort([5, 8, 3, 9, 1, 0]))
