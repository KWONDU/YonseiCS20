# function resetValuesInPlace
def resetValuesInPlace(L, threshold):
    '''
    input: L, threshold
    if value in list L is big than threshold,
    it is set to zero
    return: mutated L
    '''
    for i in range(len(L)):
        if L[i] > threshold:
            L[i] = 0
    return L
