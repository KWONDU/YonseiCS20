def copyFiles(f1, f2, f3):
    '''
    :param f1: first file name, string
    :param f2: second file name, string
    :param f3: third file name, string
    :return: open f1 and f2 for reading, f3 for writing
             if any one of the files cannot be opened, return -1
             else, read every line of f1 and f2 using method readline,
             and copy them to f3 using method write
             return 0
    '''
    try: # open f1, f2, f3
        file1 = open(f1, 'r') # open f1 for reading
        file2 = open(f2, 'r') # open f2 for reading
        file3 = open(f3, 'w') # open f3 for writing
    except OSError: # if any one of the files cannot be opened
        return -1 # return -1

    line1 = file1.readline() # read f1's contents as line, copy it to f3
    while line1 != '':
        file3.write(line1)
        line1 = file1.readline()
    line2 = file2.readline() # read f2's contents as line, copy it to f3
    while line2 != '':
        file3.write(line2)
        line2 = file2.readline()
    file1.close()
    file2.close()
    file3.close()
    return 0 # return 0
