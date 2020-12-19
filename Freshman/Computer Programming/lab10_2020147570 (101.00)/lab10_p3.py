def countAllLetters(line):
    '''
    :param line: string
    :return: count the number of times that each letter appears
             return a list containing every letter in the line
             and the number of times that each letter appears
             also, the list of letters is sorted alphabetically
    '''
    cnt = [0] * 26 # init count
    line = line.lower() # change upper-case letters to lower-case letters to count
    for l in line: # count the number of times that each letter appears
        if l.isalpha():
            cnt[ord(l)-97] = cnt[ord(l)-97] + 1
    list = [] # init result list
    for i in range(len(cnt)): # append (letter, how many each letter appears) to result list
        if cnt[i] != 0:
            list.append((chr(i+97), cnt[i]))
    return list # return result list
