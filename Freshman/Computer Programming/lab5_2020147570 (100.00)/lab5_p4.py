#input height of a triangle
height = int(input('Enter an integer: '))

#set pos as height
pos = height
while pos > 0:
    #print front blank
    print(' ' * (height - pos), end = '')
    #print '*' 2*pos - 1 times
    print('*' * (2 * pos - 1), end = '')
    #go down a line
    print()
    pos = pos - 1
