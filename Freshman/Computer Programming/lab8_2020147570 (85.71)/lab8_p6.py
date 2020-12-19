import turtle

# function drawSquare
def drawSquare(myturtle, x, y, a):
    '''
    input: myturtle, x, y, a
    first, raise pen and set turtle myturtle's position
    second, put down pen
    then, draw the square - the lower left corner's coordinate: (x, y)
                          - the length of each side of the square: a
    return: -
    '''
    myturtle.penup()
    myturtle.setposition(x, y)
    myturtle.pendown()
    myturtle.setposition(x + a, y)
    myturtle.setposition(x + a, y + a)
    myturtle.setposition(x, y + a)
    myturtle.setposition(x, y)
