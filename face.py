import numpy as np
import serial
import time
import sys
import cv2

arduino = serial.Serial('COM7', 9600)
time.sleep(2)
print("Connection to arduino...")


face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)

while (True):
    ret, img = cap.read()
    cv2.resizeWindow('img', 500, 500)
    #cv2.line(img, (500, 250), (0, 250), (0, 255, 0), 1)
    #cv2.line(img, (250, 0), (250, 500), (0, 255, 0), 1)
    #cv2.circle(img, (250, 250), 5, (255, 0, 255), -1)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray,1.4,6)

    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 5)
        roi_gray = gray[y:y + h, x:x + w]
        roi_color = img[y:y + h, x:x + w]

        arr = {y: y + h, x: x + w}
        print('arr=')
        print(arr)

        print('X :' + str(x))
        print('Y :' + str(y))
        print('x+w :' + str(x + w))
        print('y+h :' + str(y + h))

        xx = int(x + (x + h)) / 2
        yy = int(y + (y + w)) / 2

        print('xx=')
        print(xx)
        print('yy=')
        print(yy)

        center = (xx, yy)

        print("Center of Rectangle is :", center)
        data1 = "X{0:f}Y{1:f}Z".format(xx,yy)
        #data2= "Y{0:f}Z".format(yy)
        print("output = '" + data1 + "'")
        #print("output = '" + data2 + "'")
        arduino.write(data1.encode())
        #arduino.write(data2.encode())



    cv2.imshow('img', img)

    if cv2.waitKey(20) & 0xFF==ord('q'):
        break


