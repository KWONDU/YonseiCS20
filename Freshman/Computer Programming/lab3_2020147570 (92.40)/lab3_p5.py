month1 = int(input('Person 1: Enter month born (1-12): '))
day1 = int(input('Person 1: Enter day born (1-31): '))
year1 = int(input('Person 1: Enter year born (4-digit): '))
month2 = int(input('Person 1: Enter month born (1-12): '))
day2 = int(input('Person 1: Enter day born (1-31): '))
year2 = int(input('Person 1: Enter year born (4-digit): '))

numsecs_day = 24 * 60 * 60
numsecs_year = 365 * numsecs_day
avg_numsecs_year = ((4 * numsecs_year) + numsecs_day) // 4
avg_numsecs_month = avg_numsecs_year // 12

numsecs_1900_to_dob1 = (year1 - 1900) * avg_numsecs_year + (month1 - 1) * avg_numsecs_month + (day1 * numsecs_day)
numsecs_1900_to_dob2 = (year2 - 1900) * avg_numsecs_year + (month2 - 1) * avg_numsecs_month + (day2 * numsecs_day)
age_in_secs = abs(numsecs_1900_to_dob1 - numsecs_1900_to_dob2)

print('Age difference in seconds:', age_in_secs)
