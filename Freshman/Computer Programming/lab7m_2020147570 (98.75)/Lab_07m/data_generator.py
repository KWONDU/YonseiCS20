import sys

selection = 0 # use this flag variable to select a tuple of departure times
              # For this to work, you must extend function getDepartTimes()
              # below.

def getDepartTimes():
    """
    Return departure times of the Songdo shuttle.

		This is the data generator for this lab problem. You can add more test
    cases by adding 'elif' branches to the if statement (as indicated in the below
    comment).
    """
    if selection == 0:
        times = ((36, 48, 56),             # 5:00 -  5:59 (am)
                 (2, 15, 31, 43),          # 6:00 -  6:59
                 (2, 17, 34, 46),          # 7:00 -  7:59
                 (2, 16, 32, 42),          # 8:00 -  8:59
                 (2, 10, 20, 30, 40, 50),  # 9:00 -  9:59
                 (3, 11, 21, 32, 42, 53),  #10:00 - 10:59
                 (2, 10, 20, 30, 40, 50),  #11:00 - 11:59
                 (2, 16, 32, 42),          #12:00 - 12:59 (pm)
                 (2, 10, 20, 30, 40, 50),  #13:00 - 13:59
                 (2, 12, 22, 32, 42, 52),  #14:00 - 14:59
                 (4, 15, 30, 45),          #15:00 - 15:59
                 (3, 13, 32, 47),          #16:00 - 16:59
                 (2, 19, 35, 45),          #17:00 - 17:59
                 (2, 15, 30, 45),          #18:00 - 18:59
                 (2, 30)                   #19:00 - 19:59
                )
    # Enter your own testing data here:
    # elif selection == 1:

        #times = (
        # ...
        #)

    else:
        print('ERROR: unknown data generator selection!')
        sys.exit(1)
    return times
