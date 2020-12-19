# Bouncing Balls Simulation Program

import turtle
import random
import time
# set turtle's colormode
turtle.colormode(255)

def atLeftEdge(ball, screen_width):
    if ball.xcor() < -screen_width / 2:
        return True
    else:
        return False


def atRightEdge(ball, screen_width):
    if ball.xcor() > screen_width / 2:
        return True
    else:
        return False


def atTopEdge(ball, screen_height):
    if ball.ycor() > screen_height / 2:
        return True
    else:
        return False


def atBottomEdge(ball, screen_height):
    if ball.ycor() < -screen_height / 2:
        return True
    else:
        return False


def bounceBall(ball, new_direction):
    if new_direction == 'left' or new_direction == 'right':
        new_heading = 180 - ball.heading()
    elif new_direction == 'down' or new_direction == 'up':
        new_heading = 360 - ball.heading()

    return new_heading


def createBalls(num_balls):
    balls = []
    for k in range(0, num_balls):
        new_ball = turtle.Turtle()
        new_ball.shape('circle')
        new_ball.fillcolor('black')
        new_ball.speed(0)
        #new_ball.penup() - leave a trail on each ball's path
        new_ball.setheading(random.randint(1, 359))
        balls.append(new_ball)

    return balls

# change ball's color if it hits an edge of the screen
def changeBallColor(ball):
    color_chk = False
    while not color_chk:
        r = random.randint(0, 255)
        g = random.randint(0, 255)
        b = random.randint(0, 255)
        if (r, g, b) != ball.fillcolor():
            color_chk = True
    return (r, g, b)
# ---- main
# program greeting
print('This program simulates bouncing balls in a turtle screen')
print('for a specified number of seconds.')

# init screen size
screen_width = 800
screen_height = 600
turtle.setup(screen_width, screen_height)

# create turtle window
window = turtle.Screen()
# set window's title as Problem 5
window.title('Problem 5')

# prompt user for execution time and number of balls
num_seconds = int(input('Enter number of seconds to run: '))
num_balls = int(input('Enter number of balls in simulation: '))

# create balls
balls = createBalls(num_balls)

# set start time
start_time = time.time()

# begin simulation
terminate = False

while not terminate:
    for k in range(0, len(balls)):
        balls[k].forward(15)

        if atLeftEdge(balls[k], screen_width):
            # function changeBallColor if ball hits left edge
            balls[k].fillcolor(changeBallColor(balls[k]))
            balls[k].setheading(bounceBall(balls[k], 'right'))
        elif atRightEdge(balls[k], screen_width):
            # function changeBallColor if ball hits right edge
            balls[k].fillcolor(changeBallColor(balls[k]))
            balls[k].setheading(bounceBall(balls[k], 'left'))

        if atTopEdge(balls[k], screen_height):
            # function changeBallColor if ball hits top edge
            balls[k].fillcolor(changeBallColor(balls[k]))
            balls[k].setheading(bounceBall(balls[k], 'down'))
        elif atBottomEdge(balls[k], screen_height):
            # function changeBallColor if ball hits bottom edge
            balls[k].fillcolor(changeBallColor(balls[k]))
            balls[k].setheading(bounceBall(balls[k], 'up'))

        if time.time() - start_time > num_seconds:
            terminate = True

# exit on close window
turtle.exitonclick()
