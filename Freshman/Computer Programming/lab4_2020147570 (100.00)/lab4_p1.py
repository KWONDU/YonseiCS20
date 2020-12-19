#input
income = int(input('Enter the taxable income in USD: '))

#calculate amount of tax
if income <= 750:
    tax = income / 100 * 1
elif 751 <= income <= 2250:
    tax = 7.50 + (income - 750) / 100 * 2
elif 2251 <= income <= 3750:
    tax = 37.50 + (income - 2250) / 100 * 3
elif 3751 <= income <= 5250:
    tax = 82.50 + (income - 3750) / 100 * 4
elif 5251 <= income <= 7000:
    tax = 142.50 + (income - 5250) / 100 * 5
else:
    tax = 230.00 + (income - 7000) / 100 * 6

#print amount of tax
print('Tax due:', format(tax, '.2f'), 'USD')
