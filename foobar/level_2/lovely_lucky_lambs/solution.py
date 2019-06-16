def generous_handout(total_lambs):
    num_lamb_cur_rank = 1
    total_lambs -= num_lamb_cur_rank  # rule #1
    count = 1
    while total_lambs >= 2 * num_lamb_cur_rank:  # rule #2
        num_lamb_cur_rank *= 2  # rule #2: assign twice # of lambs of current rank to the next rank
        total_lambs -=  num_lamb_cur_rank
        count += 1

    # take care of the remaining
    if total_lambs >= num_lamb_cur_rank + num_lamb_cur_rank // 2:
        count += 1

    return count;


def stingy_handout(total_lambs):
    if total_lambs == 1:
        return 1

    num_lamb_cur_rank = 1
    num_lamb_prev_rank = 1
    total_lambs -= num_lamb_cur_rank  # rule # 1
    total_lambs -= num_lamb_prev_rank  # the 2nd most junior henchman requires at least as many as the most junior henchman got
    count = 2
    while total_lambs >= num_lamb_cur_rank + num_lamb_prev_rank:
        num_lamb_next_rank = num_lamb_cur_rank + num_lamb_prev_rank
        total_lambs -= num_lamb_next_rank
        num_lamb_prev_rank = num_lamb_cur_rank
        num_lamb_cur_rank = num_lamb_next_rank
        count += 1

    return count


def answer(total_lambs):
    min_num = generous_handout(total_lambs)
    max_num = stingy_handout(total_lambs)
    return max_num - min_num


if __name__ == '__main__':
    print answer(1)
    print answer(2)
    print answer(10)
    print answer(143)
    print answer(1e8)
