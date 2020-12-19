#function ordered3
def ordered3(num1, num2, num3):
    '''
    input: num1, num2, num3 - three integers
    return: True - the three integers are in order from smallest to largest
            False - other case...
    '''
    if num1 <= num2 and num2 <= num3:
        return True
    else:
        return False
