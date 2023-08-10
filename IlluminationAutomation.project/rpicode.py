import RPi.GPIO as GPIO
from gpiozero import MotionSensor
import time, sys

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

pinNum = 18
GPIO.setup(pinNum, GPIO.OUT)

pir = MotionSensor(21)

last_motion_time = 0.0

try:
    while True:
        if pir.motion_detected:
            time.sleep(0.5)
            if pir.motion_detected:
                print("Motion Detected")
                print(last_motion_time)
                GPIO.output(pinNum, 0)
                last_motion_time = time.time()
        elif time.time() - last_motion_time >0.1:
            GPIO.output(pinNum, 1)
            print("Motion stopped ")
        time.sleep(0.1)
                            
except KeyboardInterrupt:
    GPIO.cleanup()
