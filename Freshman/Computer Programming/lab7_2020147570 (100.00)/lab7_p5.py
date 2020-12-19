#input ISBN
isbn = input('Enter an ISBN: ')

#split ISBN across the occurences of the dash character
digits = isbn.split('-')

#print ISBN that is breaked down
print(digits[0], '.' * (20 - len(digits[0])), 'GS1 prefix', sep='')
print(digits[1], '.' * (20 - len(digits[1])), 'Group identifier', sep='')
print(digits[2], '.' * (20 - len(digits[2])), 'Publisher code', sep='')
print(digits[3], '.' * (20 - len(digits[3])), 'Item number', sep='')
print(digits[4], '.' * (20 - len(digits[4])), 'Check digit', sep='')
