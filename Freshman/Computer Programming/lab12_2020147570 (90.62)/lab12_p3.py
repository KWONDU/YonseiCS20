'''
Name: Donguk Kwon
Student ID: 2020147570
Lab Problem: lab12_p3.py
'''
import random
import sys

file_name = input('Enter a filename: ')  # input file name

if file_name[-3:] == 'txt':  # encryption
    try:
        file_input = open(file_name, 'r')
    except:
        print('Wrong filename')  # error message
        sys.exit(0)

    char_set = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ']

    # create list of keys
    rand_key = list(char_set)
    f_x_chk = True
    f_x_pos = 0
    while f_x_chk:
        if char_set[f_x_pos] == rand_key[f_x_pos]:
            random.shuffle(rand_key)
            f_x_pos = 0
        else:
            f_x_pos = f_x_pos + 1

        if f_x_pos == len(rand_key):
            f_x_chk = False

    file_key = open(file_name[:-3] + 'key', 'w')
    file_enc = open(file_name[:-3] + 'enc', 'w')

    # write the file '###.key'
    for pos in range(len(rand_key)):
        file_key.write(char_set[pos] + ', ' + rand_key[pos] + '\n')
    file_key.close()

    # write the file '###.enc'
    enc_line = ''
    pos_chk = len(char_set)
    for line in file_input:
        for ch in line:
            if ch in char_set:  # can encrypt
                pos_chk = char_set.index(ch)
                enc_line = enc_line + rand_key[pos_chk]
            else:  # can't encrypt
                enc_line = enc_line + ch
        file_enc.write(enc_line)
        enc_line = ''
        pos_chk = len(char_set)
    file_enc.close()

elif file_name[-3:] == 'enc':  # decryption
    try:
        file_input = open(file_name, 'r')
    except:
        print('Wrong filename')  # error message
        sys.exit(0)

    file_key = open(file_name[:-3] + 'key', 'r')
    file_dec = open(file_name[:-3] + 'txt', 'w')

    # make list of words and list of keys
    word_list = []
    key_list = []
    for line in file_key:
        word_list.append(line[0])
        key_list.append(line[3])
    file_key.close()

    # write the file '###.txt'
    enc_line = ''
    pos_chk = len(key_list)
    for line in file_input:
        for ch in line:  # can decrypt
            if ch in key_list:
                pos_chk = key_list.index(ch)
                enc_line = enc_line + word_list[pos_chk]
            else:  # can't decrypt
                enc_line = enc_line + ch
        file_dec.write(enc_line)
        enc_line = ''
        pos_chk = len(key_list)
    file_dec.close()

else:
    print('Wrong file extension')  # error message
    sys.exit(0)
