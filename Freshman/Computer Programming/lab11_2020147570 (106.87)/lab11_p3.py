"""
File WordCount.py

Program to count the number of occurrences of a word
in a textfile.
"""

def getFile():
    """
    Returns the file name and associated file object for reading the
    file  as tuple of the form (file_name, input_file).
    """
    input_file_opened = False
    while not input_file_opened:
        try:
            file_name = input('Enter input file name (with extension): ')
            input_file = open(file_name, 'r')
            input_file_opened = True
        except OSError:
            print ('Unable to open input file, please reenter')
    return (file_name, input_file)

def countWords(input_file, search_word):
    """
    Returns the number of occurrences
    of search_word in the provided input_file object.
    """
    num_occurrences = 0
    word_delimiters = (' ', ',', ';', ':', '.','\n',
                       '"',"'", '(', ')')
    search_word_len = len(search_word)
    for line in input_file:
        line = line.lower() # convert to lower case characters.
        end_of_line = False
        begin_of_line = True # the begin of line counts as a word_delimiter
        while not end_of_line:
            # print('>' + line.strip() + '<')
            try:
                found_search_word = False
                index = line.index(search_word) #throws ValueError if not found
                if index == 0:
                    # Only valid case for 'index == 0' is at begin of line.
                    # In the middle of a line, line[index-1] must be a delimiter. If not,
                    # the word lacks a LEFT delimiter and we're in the middle of a
                    # word, for example at the second 'foo' in 'foofoo' when counting
                    # 'foo'. Thus, index==0 is not possible in the middle of a line.
                    if begin_of_line and line[search_word_len] in word_delimiters:
                        found_search_word = True
                elif index > 0:
                    # if file ends without word_delimiters like
                    # aDa
                    # Ada
                    # ada (no \n)
                    # in the original program it makes error
                    # at modified program it doesn't make error
                    if line[index - 1] in word_delimiters and \
                            index + search_word_len == len(line):
                        num_occurrences = num_occurrences + 1
                        raise ValueError

                    # All matching cases in middle of line must have 'index > 0',
                    # because line[index - 1] must be a delimiter! (So index=0 is
                    # invalid, because the LEFT delimiter is missing.)
                    if line[index - 1] in word_delimiters and \
                        line[index + search_word_len] in word_delimiters:
                        found_search_word = True
                if found_search_word:
                    # print('Pos:', index)
                    num_occurrences = num_occurrences + 1
                begin_of_line = False # we moved past the begin of line
                line = line[index + search_word_len:]
            except ValueError:
                end_of_line = True
    return num_occurrences

file_name, input_file = getFile()
chk_file = open(file_name, 'r')

word_list = []
word_delimiters = (' ', ',', ';', ':', '.','\n',
                       '"',"'", '(', ')')
for line in chk_file:
    pos1 = 0 # init pos1
    pos2 = 0 # init pos2
    end = False
    while not end:
        try:
            if line[pos2] in word_delimiters:
                search_word = line[pos1:pos2]
                if search_word != '': # exclude cases like ;; or .,
                    search_word = search_word.lower()
                    chk = True
                    for item in word_list:
                        if search_word == item[0]:
                            chk = False # if the program already check search_word's counts
                    if chk:
                        num_occurrences = countWords(input_file, search_word) # count
                        word_list.append([search_word, num_occurrences]) # append to word_list
                        input_file.seek(0) # init input_file's check position
                pos1 = pos2 + 1 # move pos1
            pos2 = pos2 + 1 # increase pos2 by 1
        except IndexError:
            end = True

output_file = open(file_name[:-3] + 'wc', 'w')
word_list.sort() # sort list of the words alphabetically
for item in word_list: # write sorted list of the words and their counts
    output_file.write(item[0] + ': ' + str(item[1]) + '\n')
input_file.close()
output_file.close()
