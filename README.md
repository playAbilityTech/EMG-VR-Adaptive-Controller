
# Electromyographic Quest VR Adaptive Controller 🦾🔌🎮👓🌟

This project allows you to connect a MyoWare sensor to a standard electronic board (such as Arduino, ESP, etc.) to trigger small 9gr model motors directly attached to an Oculus Quest controller, simply fixed with hot glue.

![Nicolas Huchet and Valentin Squirelo tinkering adaptive controllers with Oculus Quest 2](https://i.imgur.com/3QhD80Ul.jpg)


## Required Materials
- [MyoWare Sensor](https://www.sparkfun.com/products/13723)
- Standard electronic board (Arduino, ESP, etc.)
- 9gr servo motor
- Oculus Quest controller
- Hot glue

In this project, a potentiometer is used to adjust the trigger threshold value in real-time. By connecting the potentiometer to the threshold pin, you can increase or decrease the threshold value by turning the potentiometer, effectively controlling the sensitivity of the MyoWare sensor to muscle contractions. This makes it easy to fine-tune the system according to the user's needs without reprogramming the electronic board.

## Installation
1. Clone this repository on your computer.
2. Open the .ino file in the Arduino IDE or another IDE compatible with your electronic board.
3. Connect your electronic board to your computer via USB.
4. Download and install the necessary libraries if they are not already present (Servo.h in this case).
5. Compile and upload the code to your electronic board.

## Connecting Components
- Connect the MyoWare sensor output to the pin defined in myowareInPin (pin 12 by default).
- Connect the threshold potentiometer to the pin defined in thresholdInPin (pin 15 by default).
- Connect the 9gr servo motor to the pin defined in servoPin (pin 27 by default).


## Code Functionality
The code reads the analog values from the MyoWare sensor and the trigger threshold. If the value read by the MyoWare sensor exceeds the threshold, the 9gr model motor is activated, simulating a press on the Oculus Quest controller.

The code is divided into several parts:
- Including the Servo library to control the motor.
- Defining the input pins for the MyoWare sensor and the trigger threshold.
- Declaring and initializing variables for the values of the MyoWare sensor, trigger threshold, and motor.
- Configuring pins and initializing serial communication in the setup() function.
- Reading the analog values from the MyoWare sensor and trigger threshold, and activating the motor if necessary, in the loop() function.

## Customization
You can adjust the threshold values and motor angles by modifying the threshold variable and the arguments of the myservo.write() function, respectively.

To change the initial threshold value, modify the following line in the code:

```cpp
int threshold = 2000;
```
To adjust the motor angles, modify the arguments of the myservo.write() function:

```cpp
myservo.write(80); // Move the servo motor to the 80-degree position
myservo.write(130); // Move the servo motor to the 130-degree position
```

## Updating Pins
To update the connection pins, modify the following lines in the code:

```cpp
#define thresholdInPin 15
#define myowareInPin 12
static const int servoPin = 27;
```
Replace the pin numbers with the pins you want to use on your electronic board. For example, if you want to use pins 3, 5, and 6, the modified code would be:

```cpp
#define thresholdInPin 3
#define myowareInPin 5
static const int servoPin = 6;
```
Make sure to connect the components to the corresponding pins on your electronic board after modifying these lines.

## MyoWare Sensor Documentation and Links
The MyoWare Sensor is a muscle activity measurement sensor (electromyography or EMG) developed by Advancer Technologies. It is designed to be used with microcontrollers such as Arduino and allows detecting muscle contractions.

### Documentation
- [MyoWare Muscle Sensor Guide](https://cdn.sparkfun.com/assets/learn_tutorials/5/8/3/MyoWare_Muscle_Sensor_v3_-_Product_Brief.pdf) (MyoWare sensor datasheet)
- [MyoWare Sensor User Guide](https://learn.sparkfun.com/tutorials/myoware-muscle-sensor-kit) (SparkFun)


## License
This project is available under the MIT License. See the LICENSE file for more information.
