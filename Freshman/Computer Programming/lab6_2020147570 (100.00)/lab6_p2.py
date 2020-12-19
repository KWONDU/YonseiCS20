#input fraction as 'frac'
frac = input('Enter a fraction: ')

#init to find numerator and denominator
frac_notblank = ''
slach_pos = 0
s_pos = 0

#input string character by character
for num in frac:
    #fraction which don't have blank
    if num != ' ':
        frac_notblank = frac_notblank + num
        #find slach's position
        if num == '/':
            slach_pos = s_pos
        s_pos = s_pos + 1

#find numerator and denominator using slach
numerator = int(frac_notblank[:slach_pos])
denominator = int(frac_notblank[slach_pos + 1:])

#init to find GCD
gcd = 0
gcd_chk = False
n = numerator
d = denominator

#the way to find GCD
while not gcd_chk:
    if n == d:
        #find GCD
        gcd = n
        gcd_chk = True
    elif n > d:
        while n > d:
            n = n - d
    else:
        while n < d:
            d = d - n

#find lowest terms of numerator and denominator
numerator = int(numerator / gcd)
denominator = int(denominator / gcd)

#print lowest terms according to conditions
print('In lowest terms: ', end='')
if denominator == 1:
    print(numerator)
else:
    print(numerator, '/', denominator, sep='')
