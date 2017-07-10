from PIL import Image
import os.path

image = Image.open("m.png")

size = 353, 353

for i in range(0, 9):
	for j in range(0, 9):
		newimg = image.crop((353*i, 353*j, 353*(i+1), 353*(j+1)))
		numBlackPix = 0
		idx = 0
		for pixel in newimg.getdata():
			if pixel == (0, 0, 0, 255):
				numBlackPix = numBlackPix + 1

		path = "image/test" + str(numBlackPix) + "-"
		while os.path.isfile(path + str(idx) + ".png"):
			idx = idx + 1
		
		newimg.save(path + str(idx) + "-" + str(i) + "-" + str(j) + ".png")