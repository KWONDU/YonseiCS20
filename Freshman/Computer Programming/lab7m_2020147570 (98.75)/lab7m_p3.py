from data_generator import getDepartTimes
import sys

times = getDepartTimes()

inp = input('Enter preferred departure time (hh:mm): ')
#
# Your code here:
#
# get user input's hour and minute
p = 0
for i in range(len(inp)):
    if inp[i] == ':':
        p = i
hour = int(inp[:p])
minute = int(inp[p+1:])

# if user input is before the 5th hour and after the 19th hour
if hour < 5 or hour > 19:
    print('Outside of operation hours!')
# choose proper bus departure time
else:
    pos = (len(times)-1, len(times[len(times)-1])-1)
    pos_chk = False
    for i in range(len(times)):
        for j in range(len(times[i])):
            if (i+5)*60 + times[i][j] > hour*60 + minute:
                if (i+5)*60 + times[i][j] <= (pos[0]+5)*60 + times[pos[0]][pos[1]]:
                    pos = (i, j)
                    pos_chk = True

    # if there is no more bus in the 19th hour
    if pos == (len(times)-1, len(times[len(times)-1])-1) and pos_chk == False:
        print('Outside of operation hours!')
    # else print the proper time
    else:
        h = str(pos[0]+5)
        m = str(times[pos[0]][pos[1]])
        # if minute's format is 1-digit, change format to 2-digit
        if 0 <= int(m) and int(m) <= 9:
            m = '0' + m
        print('The next bus leaves at ', h, ':', m, sep='')
