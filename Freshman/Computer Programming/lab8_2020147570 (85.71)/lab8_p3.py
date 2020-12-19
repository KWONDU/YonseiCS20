# function resetValues
def resetValues(L, threshold):
    '''
    input: L, threshold
    if value in list L is big than threshold,
    append 0 to new list Result
    else,
    append value in list L to new list Result
    return: Result
    '''
    Result = []
    for l in L:
        if l > threshold:
            Result.append(0)
        else:
            Result.append(l)
    return Result

