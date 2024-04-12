
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
import pwmio


cpb.pixels.brightness = 0.2
# Define color constants for LED colors
RED = (255, 0, 0)
MAGENTA = (255, 0, 20)
ORANGE = (255, 40, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
JADE = (0, 255, 40)
BLUE = (0, 0, 127)
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
pwm_output = pwmio.PWMOut(board.A3)


last_sent=0


def scan():
    for advertisement in ble.start_scan(ProvideServicesAdvertisement, timeout=0.1):
        cpb.pixels.fill(BLUE)
        if UARTService in advertisement.services:
            print("Located distress signal")
            ble.stop_scan()
            if True: # condtion to conect
                # Connect to the discovered device
                uart_connection = ble.connect(advertisement)
                sleep(0.5)
                print(f"Connected: {uart_connection.connected}")
                if uart_connection.connected:
                    # Set neopixel color to MAGENTA to indicate connection made
                    cpb.pixels.fill(MAGENTA)
                    # Create a UARTService object for communication
                    uart_service = uart_connection[UARTService]
                    # Start advertising a BlueTooth connection
                    ble.start_advertising(uart_advertisement)
                    print("Advertising Started")
                    sleep(1)
                    # Once a connection is made, temperature is extracted, converted to a float, then compared to the threshold temperature
                    while uart_connection.connected:
                        try:
                            STR = (
                                uart_service.readline()
                                .decode("utf-8")
                                .strip()
                                .split(":")
                            )
                            print(f"Received value: {STR}")

                            if ble.connected:
                                uart_server.write(f"{STR}\n")
                                if STR[0] != '':
                                    motor_strength = float(STR[0])
                                    cpb.pixels.fill(JADE)
                                else:
                                    pass
                                    cpb.pixels.fill(MAGENTA)
    
                            potvalue = (motor_strength/3.3) * 65535
                            print(int(potvalue))
                            pwm_output.duty_cycle = int(potvalue)

                            
                            
                        except Exception as e:
                            print(f"Error: {e}")
                            break
                    # Turn neopixels OFF
                    cpb.pixels.fill(BLACK)
                    ble.stop_advertising()
                    uart_connection.disconnect()
            break


while True:
    scan()



















