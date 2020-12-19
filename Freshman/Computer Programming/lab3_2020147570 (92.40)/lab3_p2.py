ean = int(input('Enter the first 12 digits of and EAN: '))

ean_12 = ean % 10
ean_11 = (ean // 10) % 10
ean_10 = (ean // 10 ** 2) % 10
ean_09 = (ean // 10 ** 3) % 10
ean_08 = (ean // 10 ** 4) % 10
ean_07 = (ean // 10 ** 5) % 10
ean_06 = (ean // 10 ** 6) % 10
ean_05 = (ean // 10 ** 7) % 10
ean_04 = (ean // 10 ** 8) % 10
ean_03 = (ean // 10 ** 9) % 10
ean_02 = (ean // 10 ** 10) % 10
ean_01 = (ean // 10 ** 11) % 10

first_sum = ean_02 + ean_04 + ean_06 + ean_08 + ean_10 + ean_12
second_sum = ean_01 + ean_03 + ean_05 + ean_07 + ean_09 + ean_11
remainder = ((first_sum * 3 + second_sum) - 1) % 10
result = 9 - remainder

print('Check digit:', result)
