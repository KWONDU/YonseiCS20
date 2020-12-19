'''
Name: Donguk Kwon
Student ID: 2020147570
Lab Problem: lab12_p4.py
'''


class Fraction(object):
    """
    Class to represent a number as a fraction

    Examples: 1/2, 2/5
    """

    def __init__(self, n, d):
        """ Method to construct a Fraction object """
        # Check that n and d are of type int:
        if type(n) != int or type(d) != int:
            raise ValueError('requires type int')
        # Check that denominator is non-zero:
        if d == 0:
            raise ZeroDivisionError('requires non-zero denominator')
        # If we get here, n and d are ok => initialize Fraction:
        self.num = n
        self.denom = d
        self.reduce()

    def __str__(self):
        """ Returns a string representation of the fraction object (self) """
        return str(self.num) + '/' + str(self.denom)

    def __mul__(self, other):
        """ Returns new Fraction representing self * other """
        new_num = self.num * other.num
        new_denom = self.denom * other.denom
        return Fraction(new_num, new_denom)

    def __add__(self, other):
        """ Returns new Fraction representing self + other """
        new_num = self.num * other.denom + other.num * self.denom
        new_denom = self.denom * other.denom
        return Fraction(new_num, new_denom)

    def __float__(self):
        """ Returns a float-value of the Fraction object """
        return self.num / self.denom  # result of / is of type float

    def reduce(self):
        '''
        divide both num and denom by their GCD,
        remove the signs if both num and denom are negative
        :return: None
        '''
        minus_chk = False

        # remove the signs if both num and denom are negative
        if self.num < 0 and self.denom < 0:
            self.num = 0 - self.num
            self.denom = 0 - self.denom
        # if either num and denom is negative
        elif self.num < 0 and self.denom > 0:
            self.num = 0 - self.num
            minus_chk = True
        elif self.num > 0 and self.denom < 0:
            self.denom = 0 - self.denom
            minus_chk = True
        n = self.num
        d = self.denom

        # calculate num and denom's GCD
        gcd = 1
        chk = True
        while chk:
            if n > d:
                n = n - d
            elif n == d:
                gcd = n
                chk = False
            else:
                d = d - n

            if n == 1 or d == 1:
                chk = False

        # divide both num and denom by their GCD
        self.num = self.num // gcd
        self.denom = self.denom // gcd

        if minus_chk:
            self.num = 0 - self.num

    def adjust(self, factor):
        '''
        :param factor: can be type of number
        multiply num and denom by factor
        :return: None
        '''
        self.num = self.num * factor
        self.denom = self.denom * factor
