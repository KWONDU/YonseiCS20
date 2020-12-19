#function evalPolynomial
def evalPolynomial(x):
    '''
    input: x - one integer
    return: value of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6
    '''
    return 3 * x**5 + 2 * x**4 - 5 * x**3 - x**2 + 7 * x - 6

#input x as integer
x = int(input('Enter a value for x: '))
#print the calculated value
print('Polynomial for x=', x, ': ', evalPolynomial(x), sep='')
