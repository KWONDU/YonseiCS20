# Temperature conversion program Fahrenheit->Celsius

# program greeting:
print('This program will convert degrees Fahrenheit to degrees Celsius')

# get temperature in Fahrenheit:
fahren = float(input('Enter degrees Fahrenheit: '))

# convert Fahrenheit to Celsius:
celsius = (fahren - 32) * 5 / 9

# print result:
print(fahren, 'degrees Fahrenheit equals',
      format(celsius, '.1f'), 'degrees Celsius')
