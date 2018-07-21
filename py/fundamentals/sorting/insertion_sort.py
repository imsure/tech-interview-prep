def insertion_sort(array):
    """
    In place insertion sort.

    :param array:
    :return:
    """
    n = len(array)

    for i in range(1, n):
        v = array[i]
        k = i
        j = i - 1
        while j >= 0 and array[j] > v:
            array[j], array[k] = v, array[j]
            k = j
            j -= 1


def insertion_sort_2(array):
    """
    In place insertion sort. Eliminate unnecessary variable v and k.

    :param array:
    :return:
    """
    n = len(array)

    for i in range(1, n):
        j = i
        while j > 0 and array[j] < array[j-1]:
            array[j], array[j-1] = array[j-1], array[j]
            j -= 1


array = [5, 4, 3, 2, 1]
insertion_sort(array)
print(array)

array = [5, 4, 6, 7, 1]
insertion_sort(array)
print(array)
