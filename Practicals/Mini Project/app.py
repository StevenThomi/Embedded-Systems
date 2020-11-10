# import threading library
import threading
# import os for screen clearing
import os
# import RPi.GPIO for cleanup and event detection
import RPi.GPIO as GPIO
# import time for runtime calculation
from time import time
# import datetime for time format output
from datetime import datetime
# import sleep for buzzer beep period
from time import sleep

# import defined classes
from ES2EEPROMUtils import ES2EEPROM
from Sensor import Sensor
from Setup import Setup

class App:
    def __init__(self, c = 0, l = 0):
        # default values c (for interval controller) and l (for logger)
        self.__c = c
        self.__l = l

    def set_c(self, c):
        # set the interval controller
        self.__c = c

    def set_l(self, l):
        # set the logger
        self.__l = l

    def get_c(self):
        # get the interval controller
        return self.__c

    def get_l(self):
        # get the logger
        return self.__l

# If the file is executed directly, run the sensor thread
if __name__ == '__main__':
    # Create EEPROM object
    eeprom = ES2EEPROM()

    # Create Setup object
    bus = Setup()

    # Create Sensor object
    sense = Sensor()

    # Create App object
    app = App()

    # Setup the SPI bus and GPIO pins
    bus.boardSetup()

    # advance the interval controller variable
    # whenever a rising edge is detected
    def my_callback_c(channel):
        app.set_c(1 + app.get_c())

    # advance the logger variable
    # whenever a rising edge is detected
    def my_callback_l(channel):
        app.set_l(1 + app.get_l())

    # define the threading target function
    def fetch_sensors():
        # set default interval to 5s
        interval = 5
        # run = -1 in order for input from 0s to be printed
        run = -1
        # set current time to now
        now = time()

        # Set up PWM Buzzer:
        # pin: 13
        # frequency: 50 Hz
        pwm = GPIO.PWM(13, 50)

        # print output header
        print("Time      \t| Sys Timer \t|\t Temperature  \t\t|\t Luminosity\t|\t Buzzer")
        print("_______________________________________________________________________________________________________________")

        while True:
            # Retrieve the SPI bus
            channel_1, channel_2 = bus.getBus()

            # Setup the sensors
            sense.setTemperature(channel_1)
            sense.setLuminosity(channel_2)

            # Fetch temperature in degrees C
            temperature = sense.getTemperature()

            # Fetch luminosity as a percentage
            luminosity = sense.getLuminosity()

            # Retrieve interval and logger controllers
            c = app.get_c()
            l = app.get_l()

            # Retrieve interval state
            if c == 0:
                interval = 5
            elif c == 1:
                interval = 2
            elif c == 2:
                interval = 1
            else:
                app.set_c(0)
                interval = 5

            # Retrieve logging state
            if l == 0:
                logging = False
            elif l == 1:
                logging = True
            else:
                app.set_l(0)
                logging = False
                
                # clear screen
                os.system('clear')
                # inform of logging stopage
                print("Logging has stopped.")

            # calculate runtime, as a real number
            runtime = round(time() - now)

            # obtain and format time output
            current_time = datetime.now()
            current_time = current_time.strftime("%H:%M:%S")

            # if there is no remainder between the runtime and the selected interval &
            # the value has not already been printed run != runtime
            if ((runtime % interval) == 0) and (run != runtime):
                run = runtime

                # signal the buzzer if the light intensity is greater than 70 %
                if luminosity >= 70:
                    # Start PWM Buzzer:
                    # Duty Cycle: 50 % ON
                    # Duration: 0.5 s
                    pwm.start(50)
                    sleep(0.5)
                    pwm.stop()

                    buzzer = "*"
                else:
                    buzzer = " "

                # print record fields
                print("{} \t|\t {:d} \t|\t {:4.2f} C \t\t|\t{:4.2f} % \t|\t{} ".format(current_time, runtime, temperature, luminosity, buzzer))
                print("_______________________________________________________________________________________________________________")

                # if the logging value (set by logger) is True, write the record fields to EEPROM
                if logging:
                    # Convert temperature and luminosity variables to integers
                    # write_byte() only writes integers, not float data types
                    temp = int(temperature)
                    lum = int(luminosity)

                    eeprom.insert_scores([0, interval, lum, temp])

########################################################################################

    try:
        # Add GPIO 16 and GPIO 26 events:
        # Condition: Event on rising edge
        # Bounce Tiem: 200 ms
        GPIO.add_event_detect(16, GPIO.RISING, callback=my_callback_l, bouncetime=200)
        GPIO.add_event_detect(26, GPIO.RISING, callback=my_callback_c, bouncetime=200)
        # Create the threading object; target fetch_sensors() method
        x = threading.Thread(target=fetch_sensors)
        # Start the thread
        x.start()

    finally:
        # Terminate the thread; join to the main program
        x.join()
        # Clean up after yourself
        GPIO.cleanup()

########################################################################################
