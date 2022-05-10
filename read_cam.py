import cv2
import numpy as np

# read camera with OpenCV
cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    if not ret:
        break
    cv2.imshow('frame', frame)
    if cv2.waitKey(1) == 27:
        break
cap.release()