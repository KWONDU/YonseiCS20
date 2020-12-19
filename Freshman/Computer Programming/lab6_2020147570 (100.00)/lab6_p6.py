#init check of limit
limit_chk = True

while limit_chk:
    #input the limit L
    num = int(input('Enter the limit L: '))

    #if L is 0, stop the program
    if num == 0:
        limit_chk = False
    #else calculate sum
    else:
        sum = 0
        for i in range(num):
            sum = sum + 1 / (i + 1)
        print('Sum of the initial', num, 'term(s):', format(sum, '.6f'))
