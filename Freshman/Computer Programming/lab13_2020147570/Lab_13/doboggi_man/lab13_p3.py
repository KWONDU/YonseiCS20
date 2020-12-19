
# Import our own constants:
from globals import FOODMAX, STEPMAX, WIDTH, HEIGHT, X_MAX, Y_MAX, MS_TO_QUIT
from globals import FOOD as food, GHOSTS as ghosts

# Import our own doboggi_man class:
from characters import doboggi_man 

import turtle


class auto_doboggi_man(doboggi_man):

    """
    Class auto_doboggi_man, the autonomous doboggi-collector.

    The auto_doboggi_man class is a subclass of the doboggi_man class. It
    inherits all data attributes and methods from the doboggi_man class. It
    overrides the move() method of the doboggi_man class to automatically
    navigate doboggi_man across the screen.

    Attributes:
    ... Please describe your attributes here
    """

    def move(self):
        #
        # Change this code to make your doboggi_man navigate the screen
        # and collect all doboggi.
        self.ttl.forward(0)
        #
        # Uncomment to dump positions in the PyCharm console window:
        #
        # print(ghosts[0], ghosts[1])
        # print(food[0], food[1], food[2])
