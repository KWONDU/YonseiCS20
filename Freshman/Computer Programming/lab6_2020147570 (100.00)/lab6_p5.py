#from operator import itemgetter
from operator import itemgetter

#init check of quit and list
quit_chk = False
list = []

#input fruit and weight, and store they into the list
while not quit_chk:
    #input fruit
    fruit = input('Enter a fruit type (q to quit): ')
    #if user wants quit
    if fruit == 'q':
        quit_chk = True
    #else
    else:
        #input weight
        weight = int(input('Enter the weight in kg: '))

        #init check of fruit and position of fruit
        fruit_chk = False
        fruit_pos = 0
        #append fruit and its weight to list
        for i in range(len(list)):
            if fruit == list[i][0]:
                fruit_chk = True
                fruit_pos = i
        if fruit_chk:
            list[fruit_pos][1] = list[fruit_pos][1] + weight
        else:
            list.append([fruit, weight])

#if list is empty
if list == []:
    print('No data received, exiting.')
#else print fruit and its weight
else:
    list.sort(key=itemgetter(0))
    for l in list:
        print(l[0], ', ', l[1], 'kg.', sep='')
