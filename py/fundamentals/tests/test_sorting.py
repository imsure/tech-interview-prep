import pytest
from random import randint

from ..sorting.merge_sort import merge_sort
from ..sorting.quick_sort import quick_sort
from ..sorting.quick_sort import quick_sort_inplace
from ..sorting.counting_sort import counting_sort_non_neg, counting_sort
from ..sorting.insertion_sort import insertion_sort, insertion_sort_2
from ..sorting.radix_sort import radix_sort


# def test_sort(inputs_sorting):
#     for item in inputs_sorting:
#         input_array = item[0]
#         expected_array = item[1]
#
#         ret = merge_sort(input_array)
#         assert ret == expected_array
#
#         ret = quick_sort(input_array)
#         assert ret == expected_array
#
#         quick_sort_inplace(input_array)
#         print(input_array)
#         print(expected_array)
#         assert input_array == expected_array


array_empty = ([], [])
array_single = ([5], [5])
array_double = ([9, 4], [4, 9])
array_triple = ([1, -5, 3], [-5, 1, 3])
array_quadruple = ([8, 5, -4, 6], [-4, 5, 6, 8])
array_sorted = ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5])
array_reverse_sorted = ([5, 4, 3, 2, 1], [1, 2, 3, 4, 5])
rand_small = [randint(-1000, 1000) for _ in range(1000)]
array_rand_small = (rand_small, sorted(rand_small))
rand = [randint(-10000, 10000) for _ in range(50000)]
array_rand = (rand, sorted(rand))


@pytest.mark.parametrize('array, expected', [
    (array_empty[0], array_empty[1]),
    (array_single[0], array_single[1]),
    (array_double[0], array_double[1]),
    (array_triple[0], array_triple[1]),
    (array_quadruple[0], array_quadruple[1]),
    (array_sorted[0], array_sorted[1]),
    (array_rand[0], array_rand[1]),
])
def test_merge_sort(array, expected):
    ret = merge_sort(array)
    assert ret == expected


@pytest.mark.parametrize('array, expected', [
    (array_empty[0], array_empty[1]),
    (array_single[0], array_single[1]),
    (array_double[0], array_double[1]),
    (array_triple[0], array_triple[1]),
    (array_quadruple[0], array_quadruple[1]),
    (array_sorted[0], array_sorted[1]),
    (array_rand[0], array_rand[1]),
])
def test_quick_sort(array, expected):
    ret = quick_sort(array)
    assert ret == expected


@pytest.mark.parametrize('array, expected', [
    (array_empty[0], array_empty[1]),
    (array_single[0], array_single[1]),
    (array_double[0], array_double[1]),
    (array_triple[0], array_triple[1]),
    (array_quadruple[0], array_quadruple[1]),
    (array_sorted[0], array_sorted[1]),
    (array_rand[0], array_rand[1]),
])
def test_quick_sort_inplace(array, expected):
    array_copy = list(array)
    quick_sort_inplace(array_copy)
    assert array_copy == expected


@pytest.mark.parametrize('array, expected', [
    (array_empty[0], array_empty[1]),
    (array_single[0], array_single[1]),
    (array_double[0], array_double[1]),
    (array_triple[0], array_triple[1]),
    (array_quadruple[0], array_quadruple[1]),
    (array_sorted[0], array_sorted[1]),
    (array_rand_small[0], array_rand_small[1]),
])
def test_insertion_sort(array, expected):
    array_copy = list(array)
    insertion_sort(array_copy)
    assert array_copy == expected


@pytest.mark.parametrize('array, expected', [
    (array_empty[0], array_empty[1]),
    (array_single[0], array_single[1]),
    (array_double[0], array_double[1]),
    (array_triple[0], array_triple[1]),
    (array_quadruple[0], array_quadruple[1]),
    (array_sorted[0], array_sorted[1]),
    (array_rand_small[0], array_rand_small[1]),
])
def test_insertion_sort_2(array, expected):
    array_copy = list(array)
    insertion_sort_2(array_copy)
    assert array_copy == expected


rand_nonneg = [randint(0, 10000) for _ in range(10000)]


@pytest.mark.parametrize('array, expected', [
    ([], []),
    ([2, 2, 2], [2, 2, 2]),
    ([i for i in range(10)], [i for i in range(10)]),
    ([i for i in range(9, -1, -1)], [i for i in range(10)]),
    (rand_nonneg, sorted(rand_nonneg)),
])
def test_counting_sort(array, expected):
    ret = counting_sort_non_neg(array)
    assert ret == expected


@pytest.mark.parametrize('array, expected', [
    (array_empty[0], array_empty[1]),
    (array_single[0], array_single[1]),
    (array_double[0], array_double[1]),
    (array_triple[0], array_triple[1]),
    (array_quadruple[0], array_quadruple[1]),
    (array_sorted[0], array_sorted[1]),
    (array_rand[0], array_rand[1]),
])
def test_counting_sort(array, expected):
    ret = counting_sort(array)
    # print(ret)
    assert ret == expected


@pytest.mark.parametrize('array, expected', [
    ([], []),
    ([2, 2, 2], [2, 2, 2]),
    ([i for i in range(10)], [i for i in range(10)]),
    ([i for i in range(9, -1, -1)], [i for i in range(10)]),
    (rand_nonneg, sorted(rand_nonneg)),
])
def test_radix_sort(array, expected):
    ret = radix_sort(array)
    assert ret == expected
