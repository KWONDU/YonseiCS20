# Pollution/Cancer Correlation Program

import math


def openFiles():
    '''
        Prompts the user for the file names to open, opens the files,
        and returns the file objects for each in a tuple of the form
        (pollution_datafile, cancer_datafile).

        Raises an OSError exception if the files are not successfully
        opened after four attempts of entering file names.
    '''

    # init
    pollution_datafile_opened = False
    cancer_datafile_opened = False
    num_attempts = 4

    # prompt for file names and attempt to open files
    while ((not pollution_datafile_opened) or \
           (not cancer_datafile_opened)) \
            and (num_attempts > 0):
        try:
            if not pollution_datafile_opened:
                file_name = input('Enter air pollution data file name: ')
                pollution_datafile = open(file_name, 'r', encoding='UTF8')
                pollution_datafile_opened = True

            if not cancer_datafile_opened:
                file_name = input('Enter lung cancer data file name: ')
                cancer_datafile = open(file_name, 'r')
                cancer_datafile_opened = True

        except OSError:
            print('File not found:', file_name + '.', 'Please reenter\n')
            num_attempts = num_attempts - 1

    # if one or more files not opened, raise OSError exception
    if not pollution_datafile_opened or not cancer_datafile_opened:
        raise OSError('Too many attempts of reading input files')

    # return file objects if successfully opened
    else:
        return (pollution_datafile, cancer_datafile)


def readFiles(pollution_datafile, cancer_datafile):
    '''
        Reads the data from the provided file objects pollution_datafile
        and cancer_datafile. Returns a list of the data read from each
        in a tuple of the form (pollution_datafile, cancer_datafile).
    '''

    # init
    pollution_data = []
    cancer_data = []
    empty_str = ''

    # read past file headers
    pollution_datafile.readline()
    cancer_datafile.readline()

    # read data files
    eof = False

    while not eof:
        # read line of data from each file
        p_line = pollution_datafile.readline()
        c_line = cancer_datafile.readline()

        # check if at end-of-file of both files
        if p_line == empty_str and c_line == empty_str:
            eof = True

        # # check if end of pollution data file only
        # elif p_line == empty_str:
        #     raise OSError('Unexpected end-of-file for pollution data file')

        # # check if at end of cancer data file only
        # elif c_line == empty_str:
        #     raise OSError('Unexpected end-of-file for cancer data file')

        # append line of data to each list
        else:
            pollution_data.append(p_line.strip().split(','))
            cancer_data.append(c_line.strip().split(','))

    # return list of data from each file
    return (pollution_data, cancer_data)

def orderLists(pollution_data, cancer_data):
    '''
        1. If a data item occurs only in one data set,
        drop that data item from the correlation computation
        2. Correlate the corresponding data items using sort()
    '''
    new_pollution_data = [] # init list 'new_pollution_data'
    new_cancer_data = [] # init list 'new_cancer_data'
    p_not_empty = True
    c_not_empty = True

    while True:
        try:
            pollution_data.remove(['']) # eliminate list 'pollution_data''s empty list subject
        except:
            break
    while True:
        try:
            cancer_data.remove(['']) # eliminate list 'cancer_data''s empty list subject
        except:
            break

    pollution_data.sort() # sort list 'pollution_data' which make easy to run this function
    for p in pollution_data:
        p[0] = p[0].upper() # case like NEW YORK and New York

    cancer_data.sort() # sort list 'cancer_data' to make easy to run this function
    for c in cancer_data:
        c[0] = c[0].upper() # case like NEW YORK and New York

    while p_not_empty and c_not_empty:
        if pollution_data[0][0] == cancer_data[0][0]: # if sorting lists goes well
            new_pollution_data.append(pollution_data.pop(0))
            new_cancer_data.append(cancer_data.pop(0))

        else: # if sorting lists doesn't goes well
            p_chk = False
            for i in range(len(cancer_data)):
                if pollution_data[0][0] == cancer_data[i][0]: # if matching goes well
                    new_pollution_data.append(pollution_data.pop(0))
                    new_cancer_data.append(cancer_data.pop(i))
                    p_chk = True
                    break
            if not p_chk and pollution_data != []: # if matching doesn't goes well
                pollution_data.pop(0) # 1

            c_chk = False
            for j in range(len(pollution_data)):
                if cancer_data[0][0] == pollution_data[j][0]: # if matching goes well
                    new_pollution_data.append(pollution_data.pop(j))
                    new_cancer_data.append(cancer_data.pop(0))
                    c_chk = True
                    break
            if not c_chk and cancer_data != []: # if matching doesn't goes well
                cancer_data.pop(0) # 1

        if pollution_data == []: # if list 'pollution_data' is empty
            p_not_empty = False
        if cancer_data == []: # if list 'cancer_data' is empty
            c_not_empty = False

    new_pollution_data.sort() # 2
    new_cancer_data.sort() # 2

    # return ordered lists
    return(new_pollution_data, new_cancer_data)



def calculateCorrelation(pollution_data, cancer_data):
    '''
        Calculates and returns the correlation value for the data
        provided in lists pollution_data and cancer_data
    '''

    # init
    sum_pollution_vals = sum_cancer_vals = 0
    sum_pollution_sqrd = sum_cancer_sqrd = 0
    sum_products = 0

    # calculate intermediate correlation values
    num_values = len(pollution_data)

    for k in range(0, num_values):
        sum_pollution_vals = sum_pollution_vals + float(pollution_data[k][1])
        sum_cancer_vals = sum_cancer_vals + float(cancer_data[k][1])

        sum_pollution_sqrd = sum_pollution_sqrd + \
                           float(pollution_data[k][1]) ** 2
        sum_cancer_sqrd = sum_cancer_sqrd + \
                          float(cancer_data[k][1]) ** 2

        sum_products = sum_products + float(pollution_data[k][1]) * \
                       float(cancer_data[k][1])

    # calculate and display correlation value
    numer = (num_values * sum_products) - \
            (sum_pollution_vals * sum_cancer_vals)

    denom = math.sqrt(abs( \
        ((num_values * sum_pollution_sqrd) - (sum_pollution_vals ** 2)) * \
        ((num_values * sum_cancer_sqrd) - (sum_cancer_vals ** 2)) \
        ))

    return numer / denom


# ---- main

# program greeting
print('This program will determine the correlation (-1 to 1) between')
print('data on air pollution and incidences of lung cancer\n')

try:
    # open data files
    pollution_datafile, cancer_datafile = openFiles()

    # read data
    pollution_data, cancer_data = readFiles(pollution_datafile, cancer_datafile)

    # if a data item occurs only in one data set,
    # drop that data item from the correlation computation
    # and correlate the corresponding data items
    new_pollution_data, new_cancer_data = orderLists(pollution_data, cancer_data)

    # calculate correlation value
    correlation = calculateCorrelation(new_pollution_data, new_cancer_data)

    # display correlation value
    print('r_value = ', correlation)

except OSError as e:
    print(e)
    print('Program terminated ...')

pollution_datafile.close() # close pollution_datafile
cancer_datafile.close() # close cancer_datafile
