# input user's number of hours and number of participants
hour = float(input('Please enter the number of hours of video conferencing: '))
part = int(input('Please enter the number of participants: '))

# init fee
fee = 0
# calculate fee
if 0<= hour and hour < 20:
    fee = 870 * hour
elif 20 <= hour and hour < 35:
    fee = 700 * hour
elif 35 <= hour and hour < 100:
    fee = 400 * hour
else:
    fee = 250 * hour
# case which charge is below 3000 KRW
if fee < 3000:
    fee = 3000
# case which the number of participants is more than 4
if part > 4:
    fee = fee * 1.2

# print fee according to the format
fee = format(fee, ',.2f')
print('Your conferencing fee:', fee, 'KRW')
