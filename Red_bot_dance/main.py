 
'''
use https://musescore.com
 in order to use grab_screen you need pywin32 you can get it with pip install pywin32 I belive might have to dowlod it

 if you are on mac or cant downlad it you will have to use the PIL libary or something else to get image data

 the cords for grabeing and finding keys is for a width=2560, height=1600 screen useing a Opera broweser with a side bar
 if you want to find your own you can run grab_screen to find the key offsets and take a screen shot and paste it into paint to find the box for the keyboard
'''
from grabscreen import grab_screen
import cv2
import numpy as np
import time
#import pandas as pd
from math import floor, ceil
import pyautogui as pag
from read_prec import read_prec

time.sleep(5)


#Numpy runs in c++ but I did not see that much speed improvemt appending with a numpy array then a normal python array

# What color do you want to mask for
color="blue"
# Name of file to save rec to
file_name="sakkijarven_polkka"

fil

if color=="green":
    mask_min=(62,51,120)
    mask_max=(83,115,241)
elif color=="blue":
    mask_min=(72,94,97)
    mask_max=(173,249,248)

# to track how long a 'frame' is get start time and the subract end time dived by len to get ms per frame
# on my computer I get about 40-37 ms per frame or ~25 fps

recording=[]
pag.press("space") # start the piano 
time_start=time.time()

x_ratio,y_ratio=pag.size()[0]/2560, pag.size()[1] / 1600

x1=80 * x_ratio
y1=1319 * y_ratio
x2=1730 * x_ratio
y2=1320 * y_ratio


while True:
    image = grab_screen((ceil(x1),floor(y1),floor(x2),ceil(y2)))
    hsv=cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    masked=cv2.inRange(hsv,mask_min,mask_max) # maskes for the chosen color
    recording.append(masked[0]) # adds to list
    cv2.imshow('window',masked) # make sure all is good
    if cv2.waitKey(25) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        t_total=time.time()-time_start
        fram_ms=1000*t_total/len(recording)
        break


#print(file_name,",",fram_ms)
f=open(file_name,"w")
np.savetxt(f,np.array(recording))
f.close()

data=read_prec(file_name,fram_ms)
print(len(data))
for i in data:
    print(i)


