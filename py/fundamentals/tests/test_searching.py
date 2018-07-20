import pytest

from ..searching.binary_search import binary_search
from ..searching.binary_search import binary_search_leftmost
from ..searching.binary_search import binary_search_rightmost


@pytest.mark.parametrize('array, target, expected', [
    ([], 3, -1),
    ([5], 5, 0),
    ([5], 4, -1),
    ([1, 2, 3, 4, 5], 4, 3),
    ([-1, 2, 3, 4], 4, 3),
    ([-1, 2, 3, 4], -1, 0),
    ([-1, 2, 3, 4], 2, 1),
    ([i for i in range(1000)], 500, 500),
    ([i for i in range(1000)], 0, 0),
    ([i for i in range(1000)], 999, 999),
    ([i for i in range(1000)], 1000, -1),
])
def test_binary_search(array, target, expected):
    assert binary_search(array, target) == expected
    assert binary_search_leftmost(array, target) == expected
    assert binary_search_rightmost(array, target) == expected


@pytest.mark.parametrize('array, target, expected', [
    ([], 0, -1),
    ([1, 1, 1, 1, 1, 1], 1, 0),
    ([1, 1, 1, 1, 1, 1], 2, -1),
    ([-3, -2, -1, -1, -1, 1], -1, 2),
    ([1, 2, 3, 4, 4, 4], 4, 3),
    ([1, 2, 3, 4, 4, 5], 4, 3),
    ([i for i in range(1000)] + [1000] * 1000, 1000, 1000),
    ([0] * 1000 + [i for i in range(1000)], 0, 0),
    ([-1] * 1000 + [i for i in range(1000)], 0, 1000),
])
def test_binary_search_leftmost(array, target, expected):
    assert binary_search_leftmost(array, target) == expected


@pytest.mark.parametrize('array, target, expected', [
    ([], 0, -1),
    ([1, 1, 1, 1, 1, 1], 1, 5),
    ([1, 1, 1, 1, 1, 1], 2, -1),
    ([-3, -2, -1, -1, -1, 1], -1, 4),
    ([1, 2, 3, 4, 4, 5], 4, 4),
    ([1, 2, 3, 4, 4, 4], 4, 5),
    ([1, 2, 3, 4, 4, 5], 5, 5),
    ([1, 2, 3, 4, 4, 5], 6, -1),
    ([i for i in range(1000)] + [1000] * 1000, 1000, 1999),
])
def test_binary_search_rightmost(array, target, expected):
    assert binary_search_rightmost(array, target) == expected
