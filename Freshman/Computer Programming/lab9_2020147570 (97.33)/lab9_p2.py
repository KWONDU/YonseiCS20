# import stack module
import stack

# function chk_int
def chk_int(str):
    '''
    :param str: type of str is string
    :return: if str is string of integer, return true
             else, return false
    '''
    chk = True
    for s in str:
        if ord(s) < ord('0') or ord(s) > ord('9'):
            chk = False
    return chk

# while user's input is not an operator or an operand
stop = False
while not stop:
    # get user's input
    rpn = input('Enter an RPN expression: ').split()

    # get new stack and init variables
    s = stack.getStack()
    i = 0 ; ans = ''
    chk = True
    # for item in user's input
    while chk:
        item = rpn[i]
        # if item is integer, push it to stack
        if chk_int(item):
            stack.push(s, int(item))
        # if item is '='
        elif item == '=':
            # conditions under which no error occurs, print answer
            if i == len(rpn)-1 and len(s) == 1:
                n = stack.pop(s)
                # if answer is integer, print it without a fractional point
                if float.is_integer(float(n)):
                    n = int(n)
                # if answer is not integer, print it with two digits after the fractional point
                else:
                    n = format(n, '.2f')
                ans = 'Value of expression: ' + str(n)
                chk = False
            # if error occurs
            else:
                ans = 'Evaluation error'
                chk = False
                stop = True
        # if item is '+' or '-' or '*' or '/'
        elif item == '+' or item == '-' or item == '*' or item == '/':
            # if error occurs
            if len(s) < 2:
                ans = 'Evaluation error'
                chk = False
                stop = True
            # calculate according to the rules
            else:
                n2 = stack.pop(s)
                n1 = stack.pop(s)
                if item == '+':
                    stack.push(s, n1 + n2)
                elif item == '-':
                    stack.push(s, n1 - n2)
                elif item == '*':
                    stack.push(s, n1 * n2)
                elif item == '/':
                    # if error occurs
                    if n2 == 0:
                        ans = 'Evaluation error'
                        chk = False
                        stop = True
                    # else
                    else:
                        stack.push(s, n1 / n2)
        # if user's input is not an operator or an operand
        else:
            chk = False
            stop = True
        # go to next item
        i = i + 1
    # print
    print(ans)
