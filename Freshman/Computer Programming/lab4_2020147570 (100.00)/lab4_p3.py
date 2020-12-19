#input number
num = int(input('Enter a number: '))

#inital value
digit = 0
count = num

#check number's digit
while count != 0:
    count = count // 10
    digit = digit + 1

#print 'digit' if digit is one, or print 'digits'
if digit == 1:
    print('The number', num, 'contains', digit, 'digit')
else:
    print('The number', num, 'contains', digit, 'digits')
