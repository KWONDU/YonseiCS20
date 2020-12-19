# Password Encryption/Decryption Program

# init
password_out = ''
case_changer = ord('a') - ord('A')
encryption_key = (('a', 'm'), ('b', 'h'), ('c', 't'), ('d', 'f'), ('e', 'g'),
                  ('f', 'k'), ('g', 'b'), ('h', 'p'), ('i', 'j'), ('j', 'w'), ('k', 'e'), ('l', 'r'),
                  ('m', 'q'), ('n', 's'), ('o', 'l'), ('p', 'n'), ('q', 'i'), ('r', 'u'), ('s', 'o'),
                  ('t', 'x'), ('u', 'z'), ('v', 'y'), ('w', 'v'), ('x', 'd'), ('y', 'c'), ('z', 'a'),
                  # init encryption of # and @ and %
                  ('#', '!'), ('@', '('), ('%', ')'))

encrypting = True

# get password
password_in = input('Enter password: ')

# perform encryption / decryption
if encrypting:
    from_index = 0
    to_index = 1
else:
    from_index = 1
    to_index = 0

case_changer = ord('a') - ord('A')

# check if non-alphabetic characters isn't # or @ or %
non_alphabetic_chk = True

# check if password violate the rule
lower_case = False
upper_case = False
non_alphabetic_character = False
digit = False

for ch in password_in:
    letter_found = False

    for t in encryption_key:
        if ('a' <= ch and ch <= 'z') and ch == t[from_index]:
            password_out = password_out + t[to_index]
            letter_found = True
            lower_case = True
        elif ('A' <= ch and ch <= 'Z') and chr(ord(ch) + 32) == t[from_index]:
            password_out = password_out + chr(ord(t[to_index]) - case_changer)
            letter_found = True
            upper_case = True
        # if character is # or @ or %
        elif (ch == '#' or ch == '@' or ch == '%') and ch == t[from_index]:
            password_out = password_out + t[to_index]
            letter_found = True
            non_alphabetic_character = True

    if not letter_found:
        # if character is integer number
        if ('0' <= ch and ch <= '9'):
            password_out = password_out + ch
            digit = True
        # if non-alphabetic characters isn't # or @ or %
        else:
            non_alphabetic_chk = False

# output
if not non_alphabetic_chk or not((lower_case
                                 or upper_case)
                                 and non_alphabetic_character
                                 and digit):
    # output if password violate the rule
    print('Invalid password!')
else:
    if encrypting:
        print('Your encrypted password is:', password_out)
    else:
        print('Your decrypted password is:', password_out)
