#input first number
num1 = float(input('Enter a number: '))

#if first number is not positive, stop the program
if num1 <= 0:
    print('No positive number was entered')
#else first number is positive
else:
    #set check as True
    chk = True
    while chk:
        num2 = float(input('Enter a number: '))
        #if input number is not positive
        if num2 <= 0:
            chk = False
        #else input number is positive
        else:
            #find larger number
            if num1 < num2:
                num1 = num2
    #print the largest number
    print('The largest number entered was', format(num1, '.2f'))
