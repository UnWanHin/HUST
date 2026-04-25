import cv2 as cv
import matplotlib.pyplot as plt

img_path = r'E:\Download\Sushi.jpg'
img = cv.imread(img_path)
height, width, _ = img.shape

if height > width:
    new_height = 600
    new_width = int(width * new_height / height)
else:
    new_width = 600
    new_height = int(height * new_width / width)

img_new = cv.resize(img, (new_width, new_height))

cv.imshow('Resized Image', img_new)
cv.waitKey(0)
cv.destroyAllWindows()

channel_sum = img_new[:, :, 1].sum(axis=1)
plt.plot(channel_sum)
plt.show()