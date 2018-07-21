def radix_sort(array):
    """
    Radix sort on array of non-negative integers.

    :param array:
    :return:
    """
    if not array:
        return []

    max_key_len = len(str(max(array)))
    array = [str(n)[::-1] for n in array]

    sorted_array = array
    for i in range(max_key_len):
        buckets = {str(i): [] for i in range(10)}
        for num in sorted_array:
            try:
                digit = num[i]
            except IndexError:
                digit = '0'
            buckets[digit].append(num)

        tmp = []
        for key in range(10):
            tmp += buckets[str(key)]

        sorted_array = tmp

    sorted_array = [int(n[::-1]) for n in sorted_array]
    return sorted_array


print(radix_sort([12, 42, 9, 0, 78, 46, 45, 45]))
print(radix_sort([1, 2, 3, 4, 5]))
print(radix_sort([5, 4, 3, 2, 1]))
print(radix_sort([1000, 299, 39, 4556, 9, 538, 4, 90]))
print(radix_sort([1, 10, 100, 1000, 1111]))