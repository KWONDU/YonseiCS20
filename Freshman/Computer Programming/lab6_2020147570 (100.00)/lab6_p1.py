#input first and last name as 'name'
name = input('Enter a first and last name: ')

#init check of blank, start position of last name
blank_chk = False
start_last = 0
#find blank's position
while not blank_chk:
    #if last name's start position isn't blank
    if name[start_last] != ' ':
        blank_chk = True
    #else increase last name's start position by 1
    else:
        start_last = start_last + 1
#init end position of last name
end_last = start_last
#find blank's position
while blank_chk:
    #if last name's end position is blank
    if name[end_last + 1] == ' ':
        blank_chk = False
    #else increase last name's end position by 1
    else:
        end_last = end_last + 1

#init start position of first name
start_first = end_last + 1
#find blank's position
while not blank_chk:
    #if first name's start position isn't blank
    if name[start_first] != ' ':
        blank_chk = True
    #else increase first name's start position by 1
    else:
        start_first = start_first + 1
#init end position of first name
end_first = start_first
#find blank's position
while blank_chk:
    #if input is finished
    if end_first == len(name) - 1:
        blank_chk = False
    else:
        #if first name's end position is blank
        if name[end_first + 1] == ' ':
            blank_chk = False
        #else increase first name's end position by 1
        else:
            end_first = end_first + 1

#print the last name, a comma, and the initial letter of the first name
print(name[start_first:end_first + 1], ', ', name[start_last], '.', sep='')
