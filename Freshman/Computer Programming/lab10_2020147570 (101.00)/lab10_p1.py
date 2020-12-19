def countLetters(line):
    '''
    :param line: string
    :return: count the number of letter characters,
             and write it to 'answer'txt'
             return None
    '''
    cnt = 0 # init the number of letter characters
    for l in line: # count the number of letter characters
        if l.isalpha():
            cnt = cnt + 1
    file = open('answer.txt', 'w') # open 'answer.txt' for writing
    file.write(str(cnt) + '\n') # write the number of letter characters
    file.close()
