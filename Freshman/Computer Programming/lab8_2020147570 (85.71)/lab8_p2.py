# function removeValuesInPlace
def removeValuesInPlace(L, threshold):
    '''
    input: L, threshold
    if value in list L is big than threshold,
    append it to list L_delete
    after every checking is finished,
    remove value in list L_delete from list L
    return: mutated L
    '''
    L_delete = []
    for l in L:
        if l > threshold:
            L_delete.append(l)
    for ld in L_delete:
        if ld in L:
            L.remove(ld)
    return L
