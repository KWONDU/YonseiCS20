import turtle

# set window size
turtle.setup(800, 450)
# get reference to turtle window
window = turtle.Screen()
# set window title bar
window.title('Problem 4')

# draw a big X on the screen
the_turtle = turtle.getturtle()
the_turtle.hideturtle()
the_turtle.penup()
the_turtle.setposition(-400, 225)
the_turtle.pendown()
the_turtle.setposition(400, -225)
the_turtle.penup()
the_turtle.setposition(400, 225)
the_turtle.pendown()
the_turtle.setposition(-400, -225)

# exit on close window
window.exitonclick()
