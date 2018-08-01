import pytest

from ..dp.fib import fib, fib2
from ..dp.lis import lis2, lis3, lis4


@pytest.mark.parametrize('n, expected', [
    (0, 0),
    (1, 1),
    (2, 1),
    (3, 2),
    (4, 3),
    (5, 5),
    (6, 8),
    (7, 13),
    (8, 21),
    (12, 144),
])
def test_fib(n, expected):
    assert fib(n) == expected
    assert fib2(n) == expected


@pytest.mark.parametrize('A, expected', [
    ([], 0),
    ([3], 1),
    ([3, 3], 1),
    ([3, 5], 2),
    ([3, 2], 1),
    ([1, 2, 3], 3),
    ([3, 2, 1], 1),
    ([10, 9, 2, 5, 3, 7, 101, 18], 4),
])
def test_lis2(A, expected):
    assert lis2(A) == expected


@pytest.mark.parametrize('A, expected', [
    ([], 0),
    ([3], 1),
    ([3, 3], 1),
    ([3, 5], 2),
    ([3, 2], 1),
    ([1, 2, 3], 3),
    ([3, 2, 1], 1),
    ([10, 9, 2, 5, 3, 7, 101, 18], 4),
])
def test_lis3(A, expected):
    assert lis3(A) == expected


@pytest.mark.parametrize('A, expected', [
    ([], 0),
    ([3], 1),
    ([3, 3], 1),
    ([3, 5], 2),
    ([3, 2], 1),
    ([1, 2, 3], 3),
    ([3, 2, 1], 1),
    ([10, 9, 2, 5, 3, 7, 101, 18], 4),
])
def test_lis4(A, expected):
    assert lis4(A) == expected
