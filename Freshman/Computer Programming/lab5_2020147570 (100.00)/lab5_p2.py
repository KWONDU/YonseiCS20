#input sentence
str = input('Enter a sentence: ')

#count the number of vowels in a sentence
num_aA = str.count('a') + str.count('A')
num_eE = str.count('e') + str.count('E')
num_iI = str.count('i') + str.count('I')
num_oO = str.count('o') + str.count('O')
num_uU = str.count('u') + str.count('U')
#sum the number of each vowels
num = num_aA + num_eE + num_iI + num_oO + num_uU

#if sentence contains only one vowel
if num == 1:
    print('Your sentence contains', num, 'vowel.')
#else
else:
    print('Your sentence contains', num, 'vowels.')
