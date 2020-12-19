#inital value
stop = False
sum = 0

#sum numbers if they are not  greater than 100
while stop == False:
    num = int(input('Your number: '))
    if num == 0:
        stop = True
    elif num <= 100:
        sum = sum + num

#print sum
print('Sum:', sum)
