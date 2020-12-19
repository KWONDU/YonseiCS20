#inital value
num = 1

#run program, and print numbers one by one
while num <= 100:
    while num % 10 != 0:
        print(format(num, '>3'),end='')
        num = num + 1
    while num % 10 == 0:
        print(format(num, '>3'))
        num = num + 1

