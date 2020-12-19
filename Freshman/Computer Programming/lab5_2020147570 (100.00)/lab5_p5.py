#init list
first_names = []

#set check as False
chk = False
while not chk:
    #input first name
    name = input('Enter a name (q to quit): ')
    #if user input is quit
    if name == 'q':
        chk = True
    #else append first name to list
    else:
        first_names.append(name)

#init i and number of 'a', 'A'
i = 0
count_aA = 0
while i < len(first_names):
    #count number of 'a', 'A'
    count_aA = count_aA + first_names[i].count('a')
    count_aA = count_aA + first_names[i].count('A')
    #increase i by 1
    i = i + 1

#print entire number
print('Appearance of letter \'a\':', count_aA)
