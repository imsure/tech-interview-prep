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


def partition(array, p, lo, hi):
    """
    Partition the given `array` around the value at index `p` in place and return
    the new index of the value. The effect of this is such that all the values on
    the left side of the index are less than or equal to the value, and all the values
    on the right side of the index are greater than the value.

    :param array:
    :param p:
    :return:
    """
    array[p], array[hi] = array[hi], array[p]

    i, j = lo, hi - 1
    while i <= j:
        while i <= j and array[i] <= array[hi]:
            i += 1
        while i <= j and array[j] > array[hi]:
            j -= 1

        if i < j:
            array[i], array[j] = array[j], array[i]

    array[i], array[hi] = array[hi], array[i]
    return i


def quick_sort_inplace(array, lo, hi):
    """

    :param array:
    :return:
    """
    if lo >= hi:
        return

    pivot_index = randint(lo, hi)
    split_index = partition(array, pivot_index, lo, hi)
    quick_sort_inplace(array, lo, split_index-1)
    quick_sort_inplace(array, split_index+1, hi)


# print(quick_sort([]))
# print(quick_sort([4]))
# print(quick_sort([0, -5]))
# print(quick_sort([0, -5, -8]))
# print(quick_sort([-3, -2, -1, 0, 1, 2, 3]))
# print(quick_sort([5, 4, 3, 2, 1]))
# print(quick_sort([5, 8, 3, 9, 1, 0]))

array = [5, 3, 4, 6, 1]
print(partition(array, 2, 0, len(array) - 1))
print(array)

array = [5, 3, 4, 6, 1]
print(partition(array, 3, 0, len(array) - 1))
print(array)

array = [5, 3, 4, 6, 1]
print(partition(array, 4, 0, len(array) - 1))
print(array)

array = [5, 8, 3, 9, 1, 0]
quick_sort_inplace(array, 0, 5)
print(array)

array = [-3, -2, -1, 0, 1, 2, 3]
quick_sort_inplace(array, 0, 6)
print(array)
