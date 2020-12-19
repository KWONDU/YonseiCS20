# input i, j
i, j = input('i, j: ').split()
i = int(i) ; j = int(j)

# init maximum cycle length count
ans_cnt = 0
# calculate cycle length
for n in range(i, j+1):
    cnt = 0
    while n != 1:
        if n%2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
        cnt = cnt + 1
    cnt = cnt + 1
    if ans_cnt < cnt:
        ans_cnt = cnt
# print answer
print('Maximum cycle-length:', ans_cnt)
