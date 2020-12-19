# function drawFlower
def drawFlower(myturtle, r):
    '''
    :param myturtle: type of myturtle is turtle
    :param r: r is radius of the circles
    :return: return nothing, just draw 24 circles on the screen
                             because user has to draw 24 circles,
                             turn the turtle's direction 15 degrees
    '''
    myturtle.pencolor('red') # set the turtle's pen color to red
    myturtle.hideturtle() # hide the turtle
    for theta in range(0, 360, 360//24):
        myturtle.setheading(theta)
        myturtle.circle(r) # draw circle
