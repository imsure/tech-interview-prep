import pytest

from ..backtracking.lis import lis_rec


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
def test_lis(A, expected):
    assert lis_rec(A) == expected
