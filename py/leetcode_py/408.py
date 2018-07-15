class Solution:
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        if len(abbr) > len(word):
            return False

        max_digit = len(word)
        full_word = ''
        i = 0
        j = 0
        while i < len(abbr):
            if abbr[i].isdigit():
                digit = ''
                while i < len(abbr) and abbr[i].isdigit():
                    digit += abbr[i]
                    i += 1
                if digit.startswith('0'):
                    return False
                digit = int(digit)
                if digit > max_digit:
                    return False
                full_word += word[j:j+digit]
                if j+digit > len(word):
                    return False
                j += digit
            else:
                full_word += abbr[i]
                i += 1
                j += 1

        # print(full_word)
        return word == full_word

    def validWordAbbreviation2(self, word, abbr):
        """
        There are two conditions for a 'abbr' to be a valid word abbreviation:
        - the sum of numbers and the count of chars in 'abbr' must equal to len(word)
        - chars in 'abbr' must match with their corresponding chars in 'word'

        :type word: str
        :type abbr: str
        :rtype: bool
        """
        digit_str = ''
        n = 0
        for i in range(0, len(abbr)):
            if abbr[i].isdigit():
                digit_str += abbr[i]
                if digit_str.startswith('0'):
                    return False
            else:
                n += int('0' + digit_str)
                digit_str = ''
                if n >= len(word) or abbr[i] != word[n]:
                    return False
                n += 1

        n += int('0' + digit_str)

        return n == len(word)


if __name__ == '__main__':
    sol = Solution()
    print(sol.validWordAbbreviation('internationalization', 'i12iz4n'))  # True
    print(sol.validWordAbbreviation('apple', 'a2e'))  # False

    print(sol.validWordAbbreviation2('internationalization', 'i12iz4n'))  # True
    print(sol.validWordAbbreviation2('apple', 'a2e'))  # False
    print(sol.validWordAbbreviation2('internationalization', 'i5a11o1'))  # True
    print(sol.validWordAbbreviation2('word', '3e'))  # False
    print(sol.validWordAbbreviation2('hi', '1hi'))  # False
