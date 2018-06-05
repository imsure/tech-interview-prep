class Solution:
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        n = len(hand)
        if n % W != 0:
            return False

        hand_dict = {}
        for card in hand:
            hand_dict[card] = hand_dict.get(card, 0) + 1

        sorted_hand = sorted(hand)
        min_card = min(hand)
        start_card = min_card
        start_card_count = 0
        for i in range(n // W):
            # start_card_count += hand_dict[start_card]
            end_card = start_card + W
            for card in range(start_card, end_card):
                if card not in hand_dict or hand_dict[card] == 0:
                    return False

                # print(card)
                hand_dict[card] -= 1
                # start_card_count += 1
                if hand_dict[card] == 0:
                    hand_dict.pop(card, None)

            # print(hand_dict)
            # for c in sorted_hand:
            #     if hand_dict[c] != 0:
            #         start_card = c
            #         break
            # print(hand_dict.keys())
            try:
                start_card = min(hand_dict.keys())
            except ValueError:
                pass
            # if hand_dict[start_card] == 0:
            #     start_card = sorted_hand[start_card_count]

            # print('next start:', start_card)

        return True


sol = Solution()
print(sol.isNStraightHand([1,2,3,6,2,3,4,7,8], 3))
print(sol.isNStraightHand([2,1], 2))