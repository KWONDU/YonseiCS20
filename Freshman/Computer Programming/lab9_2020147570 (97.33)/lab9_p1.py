# import stack module
import stack

# get user's input
nest = input('Enter parentheses and/or braces: ')

# get new stack and init variables
s = stack.getStack()
i = 0
chk = True
# for item in user's input
while chk:
    item = nest[i]
    # if item is ( or {, push it to stack
    if item == '(' or item == '{':
        stack.push(s, item)
    # if item is ) or }, check if input nested properly
    elif item == ')':
        if stack.pop(s) != '(':
            chk = False
    else:
        if stack.pop(s) != '{':
            chk = False

    # if checking finishes
    if stack.isEmpty(s):
        break
    # go to next item
    i = i + 1

# print according to the conditions
if chk == True:
    print('Nested properly.')
else:
    print('Not properly nested.')
