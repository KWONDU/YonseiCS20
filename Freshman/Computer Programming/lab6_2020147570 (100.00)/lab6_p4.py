#init check of quit and list
quit_chk = False
list = []

#input word according to conditions
while not quit_chk:
    #input word
    word = input('Enter a word (q to quit): ')
    #if user wants quit
    if word == 'q':
        quit_chk = True
    #else
    else:
        #init first letter of the word and number of letters that overlap with the first letter
        first_letter = word[0]
        count = 0
        #count number
        for w in word:
            #upper case or lower case
            chk = ord(first_letter) - ord(w)
            if chk == -32 or chk == 0 or chk == 32:
                count = count + 1
        #if number of overlaped letters is more than 2 append word to list
        if count > 1:
            list.append(word)

#print sorted list
print(sorted(list))
