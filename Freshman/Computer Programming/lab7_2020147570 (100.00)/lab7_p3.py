#function modCount
def modCount(n, m):
    '''
    input: n, m - two positive integers, m <= n
    return: number of integers that are evenly divisible by m between 1 and n
    '''
    count = n // m
    return count
