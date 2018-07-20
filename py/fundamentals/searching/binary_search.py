def binary_search(array, target):
    lo, hi = 0, len(array) - 1

    while lo <= hi:
        mid = (lo + hi) // 2
        if array[mid] < target:
            lo = mid + 1
        elif array[mid] > target:
            hi = mid - 1
        else:
            return mid

    return -1


def binary_search_leftmost(array, target):
    lo, hi = 0, len(array) - 1

    while lo <= hi:
        mid = (lo + hi) // 2
        if array[mid] < target:
            lo = mid + 1
        elif array[mid] > target:
            hi = mid - 1
        else:
            if mid - 1 >= lo and array[mid-1] == target:
                hi = mid - 1
            else:
                return mid

    return -1


def binary_search_rightmost(array, target):
    lo, hi = 0, len(array) - 1

    while lo <= hi:
        mid = (lo + hi) // 2
        if array[mid] < target:
            lo = mid + 1
        elif array[mid] > target:
            hi = mid - 1
        else:
            if mid + 1 <= hi and array[mid+1] == target:
                lo = mid + 1
            else:
                return mid

    return -1
