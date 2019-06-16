def answer(s):
    ans = []
    for c in s:
        if 'a' <= c <= 'z':
            deciphered = ord('z') - (ord(c) - ord('a'))
            ans.append(chr(deciphered))
        else:
            ans.append(c)

    return ''.join(ans)


if __name__ == '__main__':
    print(answer("wrw blf hvv ozhg mrtsg'h vkrhlwv?"))
    print(answer("Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!"))
