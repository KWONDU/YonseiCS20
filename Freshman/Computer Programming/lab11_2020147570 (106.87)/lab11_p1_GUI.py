import time
import turtle

# init window's width and length
width = 1000
length = 650

def GUI_printWorld(world):
    '''
    :param world: data structure of n generation (type list)
    :return: None, just print cellular automaton GUI to turtle
    '''
    # init between pixel
    pixel = 16

    # set turtle
    window.clear()
    turtle.tracer(0, 0)
    gui = turtle.getturtle()
    gui.hideturtle()
    gui.penup()

    # draw line
    gui.setposition(-SIZE//2 * pixel - pixel//2, SIZE//2 * pixel + pixel)
    gui.pendown()
    gui.forward(SIZE * pixel)
    gui.penup()

    # draw cellular automaton GUI
    for i in range(len(world)):
        gui.setposition(-SIZE//2 * pixel - pixel//2, (SIZE//2 - i) * pixel)
        gui.write('|')
        for j in range(len(world[i])):
            gui.setposition((-SIZE//2 + j) * pixel, (SIZE//2 - i) * pixel)
            if world[i][j] == 1:
                gui.write('x')
        gui.setposition((SIZE - SIZE//2) * pixel - pixel//2, (SIZE//2 - i) * pixel)
        gui.write('|')

    # draw line
    gui.setposition(-SIZE//2 * pixel - pixel//2, (SIZE//2 - SIZE + 1) * pixel - pixel//2)
    gui.pendown()
    gui.forward(SIZE * pixel)
    gui.penup()

    # write row n
    for i in range(len(world)):
        gui.setposition((SIZE//2 + 1) * pixel, (SIZE//2 - i) * pixel)
        gui.write('row ' + str(i))

# type 1: using try and except
def NextGeneration1(world):
    '''
    :param world: data structure of n generation (type list)
    :return: new_world, which is data structure of n + 1 generation (type list)
    '''
    new_world = [[0 for j in range(SIZE)] for i in range(SIZE)]  # init new world

    for i in range(len(world)):
        for j in range(len(world[i])):
            # init lists of position which we have to check
            default = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1),
                       (i, j - 1),                 (i, j + 1),
                       (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]

            cnt = 0 # init count variable
            for check_pos in default:
                try:
                    # AT PYTHON, list[-1] IS WELL DEFINED -> WRONG CODE
                    # if world[check_pos[0]][check_pos[1]] == 1:
                    #     cnt = cnt + 1
                    # THIS CODE IS PROPER CODE
                    if check_pos[0] < 0 or check_pos[1] < 0:
                        raise IndexError
                    elif world[check_pos[0]][check_pos[1]] == 1:
                        cnt = cnt + 1
                except IndexError:
                    cnt = cnt

            if (cnt == 2 or cnt == 3) and world[i][j] == 1: # second condition
                new_world[i][j] = 1
            elif cnt == 3 and world[i][j] == 0: # fourth condition
                new_world[i][j] = 1

    return new_world # data structure of next generation

# type 2: using list
def NextGeneration2(world):
    '''
    :param world: data structure of n generation (type list)
    :return: new_world, which is data structure of n + 1 generation (type list)
    '''
    new_world = [[0 for j in range(SIZE)] for i in range(SIZE)]  # init new world

    for i in range(len(world)):
        for j in range(len(world[i])):
            # init lists of position which we have to check
            default = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1),
                       (i, j - 1),                 (i, j + 1),
                       (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]
            i_0 = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1)]
            i_SIZE = [(i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]
            j_0 = [(i - 1, j - 1), (i, j - 1), (i + 1, j - 1)]
            j_SIZE = [(i - 1, j + 1), (i, j + 1), (i + 1, j + 1)]
            remove = []

            if i == 0:
                for pos_ in i_0:
                    if pos_ not in remove: # prevent duplication
                        remove.append(pos_)
            elif i == SIZE - 1:
                for pos_ in i_SIZE:
                    if pos_ not in remove: # prevent duplication
                        remove.append(pos_)
            if j == 0:
                for pos_ in j_0:
                    if pos_ not in remove: # prevent duplication
                        remove.append(pos_)
            elif j == SIZE - 1:
                for pos_ in j_SIZE:
                    if pos_ not in remove: # prevent duplication
                        remove.append(pos_)

            for remove_pos_ in remove:
                default.remove(remove_pos_) # remove positions which don't exist

            cnt = 0 # init count variable
            for check_pos_ in default:
                if world[check_pos_[0]][check_pos_[1]] == 1:
                    cnt = cnt + 1

            if (cnt == 2 or cnt == 3) and world[i][j] == 1: # second condition
                new_world[i][j] = 1
            elif cnt == 3 and world[i][j] == 0: # fourth condition
                new_world[i][j] = 1

    return new_world # data structure of next generation

#
# Main program
#
not_faulty = False
while not not_faulty:
    try:
        SIZE = int(input('Grid sidelength (default 20): '))
        if SIZE <= 0: # if grid sidelength is not larger than 0
            raise ValueError
        elif SIZE < 20: # if grid sidelength is smaller than 20
            raise ValueError
        not_faulty = True
    except ValueError:
        SIZE = 20
        not_faulty = True
    try:
        max = int(input('Max generation: '))
        if max <= 0: # if max generation is not larger than 0
            raise ValueError('\'' + str(max) + '\' : not larger than 0')
    except ValueError as v:
        not_faulty = False
        print(v)

# Set data structure using world and position
position = [[0, 1],
       [1, 1],
       [2, 1],
       [10, 10], [10, 11], [10, 12],
       [11, 10],
       [12, 10], [12, 11], [12,12]]
world = [[0 for j in range(SIZE)] for i in range(SIZE)]
for pos in position:
    world[pos[0]][pos[1]] = 1

# Set window
turtle.setup(width, length)
window = turtle.Screen()
window.title('cellular automaton GUI')

# Compute:
GUI_printWorld(world)
time.sleep(1)
while max > 0: # 0 ~ Max generation
    world = NextGeneration1(world)
    GUI_printWorld(world)
    max = max - 1
    time.sleep(1)

window.exitonclick()
