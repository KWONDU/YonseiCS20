'''
Name: Donguk Kwon
Student ID: 2020147570
Lab Problem: lab12_p1.py
'''


def addDailyTemp(mydict, day, temperature):
    '''
    :param mydict: type dictionary
    :param day: can be any type, key
    :param temperature: can be any type, value
    if key 'day' does not exist in dictionary 'mydict',
    add key 'day' and value 'temparture' to dictionary 'mydict'
    :return: dictionary 'mydict'
    '''
    if day not in mydict:  # if key 'day' does not exist in dictionary 'mydict'
        mydict[day] = temperature

    return mydict  # return result
