import pytest

from ..sorting.merge_sort import merge_sort
from ..sorting.quick_sort import quick_sort
from ..sorting.quick_sort import quick_sort_inplace


def test_sort(inputs_sorting):
    for item in inputs_sorting:
        input_array = item[0]
        expected_array = item[1]

        ret = merge_sort(input_array)
        assert ret == expected_array

        ret = quick_sort(input_array)
        assert ret == expected_array

        quick_sort_inplace(input_array)
        print(input_array)
        print(expected_array)
        assert input_array == expected_array
