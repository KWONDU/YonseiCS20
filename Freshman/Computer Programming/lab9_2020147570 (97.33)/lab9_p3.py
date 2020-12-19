# Palindrome Checker Program

def re(str):
    '''
    :param str: type of char is string
    :return: return reversed string
    '''
    str_re = ''
    for ch in str:
        str_re = ch + str_re
    return str_re

# welcome
print('This program can determine if a given string is a palindrome\n')
print('(Enter return to exit)')
# init
empty_string = ''
#get string from user
chars = input('Enter string to check: ')
while chars != empty_string:
    if len(chars) == 1:
        print('A one letter word is by definition a palindrome\n')
    else:
        # init
        is_palindrome = True

        # to handle strings of odd length
        compare_length = len(chars) // 2

        # reverse string
        chars_re = re(chars)

        # compare first half of string and another half of string
        k = 0
        while k < compare_length and is_palindrome:
            if chars[k].lower() != chars_re[k].lower():
                is_palindrome = False

            k = k + 1

        # display results
        if is_palindrome:
            print(chars, 'is a palindrome\n')
        else:
            print(chars, 'is NOT a palindrome\n')

    # get next string from user
    chars = input('Enter string to check: ')
