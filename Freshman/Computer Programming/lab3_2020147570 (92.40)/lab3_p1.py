gigabyte = int(input('Enter USB size (GB): '))
byte = gigabyte * 1000000000

gif_size = 800 * 600 * 1 // 5
jpeg_size = 800 * 600 * 3 // 25
png_size = 800 * 600 * 3 // 8
tiff_size = 800 * 600 * 6

gif = byte // gif_size
jpeg = byte // jpeg_size
png = byte // png_size
tiff = byte // tiff_size

print(format(gif, '>5') + ' images in GIF format can be stored')
print(format(jpeg, '>5') + ' images in JPEG format can be stored')
print(format(png, '>5') + ' images in PNG format can be stored')
print(format(tiff, '>5') + ' images in TIFF format can be stored')
