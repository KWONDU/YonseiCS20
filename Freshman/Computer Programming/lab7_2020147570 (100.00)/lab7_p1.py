#function zeroCheck
def zeroCheck(num1, num2, num3):
    '''
    input: num1, num2, num3 - three integers
    return: True - at least one integer is 0
            False - every integer is not 0
    '''
    if num1 == 0 or num2 == 0 or num3 == 0:
        return True
    else:
        return False
