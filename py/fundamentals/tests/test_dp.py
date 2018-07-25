import pytest

from ..dp.fib import fib, fib2


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
