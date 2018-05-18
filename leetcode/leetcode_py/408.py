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


if __name__ == '__main__':
    sol = Solution()
    print(sol.validWordAbbreviation('internationalization', 'i12iz4n'))
    print(sol.validWordAbbreviation('apple', 'a2e'))