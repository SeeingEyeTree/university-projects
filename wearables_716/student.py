
from time import sleep
from adafruit_ble import BLERadio
# Used to create an advertisement that specifies the services provided by device over Bluetooth Low Energy (BLE)
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
# Used for the UART service that allows device to communicate over BLE using a UART (serial communication) interface
from adafruit_ble.services.nordic import UARTService
# Provides access to the features of the CPB, specifically temperature sensor, onboard buttons/switches, neopixels, and Bluetooth functionality
from adafruit_circuitplayground.bluefruit import (cpb)
# Used to play mp3 files which are saved onto the CPB
from adafruit_circuitplayground import cp
# Used to access pins on board for i/o connection
import board
# Used for Zipper Switch as a Digital Input
import digitalio

import analogio
import touchio
import pwmio

cpb.pixels.brightness = 0.2
# Define color constants for LED colors
RED = (255, 0, 0)
MAGENTA = (255, 0, 20)
ORANGE = (255, 40, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
JADE = (0, 255, 40)
BLUE = (0, 0, 255)
INDIGO = (63, 0, 255)
VIOLET = (127, 0, 255)
PURPLE = (180, 0, 255)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)


## Initialize Bluetooth, UART service, and advertising
ble = BLERadio()
uart_server = UARTService()
uart_advertisement = ProvideServicesAdvertisement(uart_server)
uart_connection = None

readInValue = analogio.AnalogIn(board.A2)

condfab = board.A1
touch = touchio.TouchIn(condfab)

def advertise():
    # Start advertising the UART service
    ble.start_advertising(uart_advertisement)
    # Set initial pixel positions for neopixel broadcast indication
    pixel_pos = 0
    pixel_pos2 = 9
    # Set starter color to PURPLE for boradcasting neopixel animation
    color = PURPLE
    while True:
        if ble.connected:
            if touch.value:
                STR = (readInValue.value * 3.3) / 65536
                print(f"Writing {STR}")
                uart_server.write(f"{STR}\n")
            else:
                uart_server.write("a") # send null value
            sleep(0.05)
            break
        # Play neopixel broadcast animation to wait for connection to be established
        else:
            cpb.pixels[pixel_pos] = color
            cpb.pixels[pixel_pos2] = color
            pixel_pos = (pixel_pos + 1)
            pixel_pos2 = (pixel_pos2 - 1)
            sleep(0.1)
            if pixel_pos == 5 and pixel_pos2 == 4:
                # Color constant set to BLACK for neopixels to turn OFF
                color = BLACK
            # Once ring is fully turned OFF (AKA BLACK), need to refill by coloring PURPLE
            if pixel_pos == 10 and pixel_pos2 == -1:
                # Color constant set to BLACK for neopixels to turn OFF
                color = PURPLE
                # Resetting pixel positions to restart animation
                pixel_pos = 0
                pixel_pos2 = 9
    # Turn neopixels OFF
    cpb.pixels.fill(BLACK)
    # Stop advertising the UART service
    ble.stop_advertising()

while True:
    advertise()

