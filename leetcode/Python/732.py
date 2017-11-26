from collections import OrderedDict

class MyCalendarThree:

    def __init__(self):
        self.maxBooking = 0
        self.booking = {}

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: int
        """
        self.booking[start] = self.booking.get(start, 0) + 1
        self.booking[end] = self.booking.get(end, 0) - 1
        ordered = OrderedDict(sorted(self.booking.items(), key=lambda t: t[0]))
        booked = 0
        for k in ordered:
            booked += ordered[k]
            self.maxBooking = max(self.maxBooking, booked)

        return self.maxBooking


# Your MyCalendarThree object will be instantiated and called as such:
obj = MyCalendarThree()
print (obj.book(10, 20))
print (obj.book(50, 60))
print (obj.book(10, 40))
print (obj.book(5, 15))
print (obj.book(5, 10))
print (obj.book(25, 55))
