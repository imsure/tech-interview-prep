import pytest
from random import randint


@pytest.fixture(scope='module')
def inputs_sorting():
    ret = []

    empty = []
    ret.append([empty, empty])

    single = [5]
    ret.append([single, single])

    double = [9, 4]
    ret.append([double, sorted(double)])

    triple = [1, 5, 3]
    ret.append([triple, sorted(triple)])

    quadruple = [8, 5, -4, 6]
    ret.append([quadruple, sorted(quadruple)])

    sorted_case = [-3, -2, -1, 0, 1, 2]
    ret.append([sorted_case, sorted_case])

    reverse_sorted_case = [5, 4, 3, 2, 1]
    ret.append([reverse_sorted_case, sorted(reverse_sorted_case)])

    rand_case_1 = [randint(-1000, 1000) for _ in range(1000)]
    ret.append([rand_case_1, sorted(rand_case_1)])

    rand_case_2 = [randint(-10000, 10000) for _ in range(50000)]
    ret.append([rand_case_2, sorted(rand_case_2)])

    return ret
