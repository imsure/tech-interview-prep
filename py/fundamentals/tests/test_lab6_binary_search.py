import pytest

from ..uiuc_cs374.lab6_binary_search import first_greater_than


@pytest.mark.parametrize('A, t, expected', [
    ([], 3, -1),
    ([1, 3, 5, 6, 7], 5, 3),
    ([1, 3, 5, 6, 7], 7, -1),
    ([1, 3, 5, 6, 7], 6, 4),
    ([1, 3, 5, 6, 7], 1, 1),
    ([1, 3, 5, 6, 7], 0, 0),
])
def test_first_greater_than(A, t, expected):
    assert first_greater_than(A, t) == expected
