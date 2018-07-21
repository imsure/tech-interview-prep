def counting_sort_non_neg(array):
    """
    Counting sort for array of non-negative integers

    :param array:
    :return:
    """
    if not array:
        return array

    max_num = max(array)
    map = [0] * (max_num + 1)

    for num in array:
        map[num] += 1

    output = []
    for index, count in enumerate(map):
        if count > 0:
            output += [index] * count

    return output


def counting_sort(array):
    neg_sub = [num for num in array if num < 0]
    non_neg_sub = [num for num in array if num >= 0]

    neg_sub_reverse_sign = [0 - num for num in neg_sub]
    neg_sub_sorted = counting_sort_non_neg(neg_sub_reverse_sign)
    neg_sub_sorted = [0 - num for num in neg_sub_sorted]

    non_neg_sub_sorted = counting_sort_non_neg(non_neg_sub)

    return neg_sub_sorted[::-1] + non_neg_sub_sorted


print(counting_sort_non_neg([5, 5, 4, 3, 2, 1]))
print(counting_sort([3, 4, 5, -1, -2]))
