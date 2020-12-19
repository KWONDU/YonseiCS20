# init list of values
list = []
# open 'data.txt' for reading
file = open('data.txt', 'r')

# read file's contents one by one and append it to list
integer = file.readline()
while integer != '':
    list.append(int(integer[:-1])) # except \n
    integer = file.readline()
# list with substituted values at the edge
list = [list[0]] + list + [list[-1]]

# init the averaged list
avg = []
# calculate the average values and append it to avg
for i in range(len(list)-2):
    avg.append((list[i] + list[i+1] + list[i+2]) / 3)
# print the averaged list
print(avg)
# close the file
file.close()
