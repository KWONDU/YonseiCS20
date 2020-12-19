'''
Name: Donguk Kwon
Student ID: 2020147570
Lab Problem: lab12_p2.py
'''


def moderateDays(mydict):
    '''
    :param mydict: type dictionary, key: 'Sun' ~ 'Sat'
    if average daily temperature for each day of the week is between 70 and 79,
    append day of the week to dictionary 'result_lst'
    (70 and 79 is included)
    :return: list 'result_list'
    '''
    result_list = []

    for day_of_the_week in mydict:
        if 70 <= mydict[day_of_the_week] <= 79:
            result_list.append(day_of_the_week)

    return result_list  # return result
