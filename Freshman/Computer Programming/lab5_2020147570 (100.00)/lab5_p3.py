#init list
int_list = []

#set check as True
chk = True
while chk:
    #input number
    num = int(input('Enter an integer: '))
    #if number is 0
    if num == 0:
        chk = False
    #else
    else:
        #if number is greater than 100, change it to 'over'
        if num > 100:
            num = 'over'
        #append number to list
        int_list.append(num)

#print list
print(int_list)
