# Ultrasonic Sensor with SAMD51
The code for controling ultrasonic sensor with Metro M4 Express (Adafruit) with ROSserial protocol uploaded in file name **ultrasonic sensor.**
## Circuit diagram for connecting 3 ultrasonic sensors with Metro M4 Express board
Connecting ultrasonic sensor by compounding Metro M4 Express board with I2C Shield. Ultrasonic sensor conected with I2C Shield as shown in figure below. After that linked between the board and laptop by using USB wiring.

<img width="371" alt="image" src="https://user-images.githubusercontent.com/40823576/179183335-e71ef158-c25d-4cd7-b65e-abf522e577d1.png">

## Uploading code in Arduino IDE Program (Ubuntu)
1) In case of the error occured after clicked on upload as shown in the figure below. Fixing by opening Terminal and type command **sudo chmod 777/dev/port name**. Next, uploading the code again.
<img width="709" alt="image" src="https://user-images.githubusercontent.com/40823576/179187310-c13e86a4-b3a3-41a0-9873-a506625a7c62.png">

2) After uploading complete, the text **Done Uploading** will show in box below.
<img width="709" alt="image" src="https://user-images.githubusercontent.com/40823576/179187807-ef048d18-0290-435a-996d-4873b27ce5e0.png">

## Connecting with ROS
1) Open terminal and enter command **roscore** as shown below.
<img width="629" alt="image" src="https://user-images.githubusercontent.com/40823576/179189281-d94679b1-59a4-4a89-960a-3ce63f6f4ca8.png">

2) Open new terminal, enter command **ls/dev/port name** (your port name will show in Arduino IDE program). Enter command **rosrun rosserial_python serial_node.py/dev/port name.** In case of error occured, open new terminal window and enter command **sudo chmod777/dev/port name**
<img width="844" alt="image" src="https://user-images.githubusercontent.com/40823576/179190302-4ff82191-22a9-44e0-a380-27741d34e5b6.png">

3) Open new terminal window, enter command **rostopic list** to show variables that can be called. Command for calling variable is **rostopic echo/variable name** e.g. rostopic echo/ultrasonic2 to display readable distance from sensor2.
<img width="842" alt="image" src="https://user-images.githubusercontent.com/40823576/179192849-ce7bf4a1-8346-4efe-82cd-0896f43bdfd3.png">

4) The screen shows the distance readable from Ultrasonic sensor as shown in below figure.
<img width="482" alt="image" src="https://user-images.githubusercontent.com/40823576/179196751-34a30009-1e61-4366-bd40-78f421bc15cb.png">

# IMU with SAMD51
IMU consists of accelerometer for measuring acceleration and velocity, gyroscope for measuring rotational rate (angle). Some also incude magnetometer. The code for controling IMU with Metro M4 Express uploaded in file name **icm20948_spi** for IMU and **icm20948_spi_mag** for IMU with magnetic.

## Connecting with ROS
After uploading the code, next step to connecting with ROS. This example used PlatformIO instaed of Arduino IDE, but Arduino IDE can also work.
1) Open terminal and enter command **roscore** as shown below
![Screenshot (25)](https://user-images.githubusercontent.com/40823576/182123785-3dfadaad-c9e9-4e96-8e7c-3c9d460e6ed2.png)

2) Enter command **rosrun rosserial_pythonserial_node.py/dev/port name**
![Screenshot (26)](https://user-images.githubusercontent.com/40823576/182124380-1b1baa44-8b2b-42c3-9657-85de629bddf8.png)

3) Open new terminal, enter command **rostopic list** to show variables that can be called. Command for calling variable is **rostopic echo/variable name** e.g. rostopic echo/raw_imu to display readable velocity and acceleration in x, y, z-axis.
![Screenshot (29)](https://user-images.githubusercontent.com/40823576/182125202-27f1ad5d-450d-4142-9990-fe274c304f02.png)

4) The screen shows readable velocity and acceleration in x, y, z-axis as shown in below figure.
![Screenshot (30)](https://user-images.githubusercontent.com/40823576/182125548-b45aef10-46bb-422d-8af4-8b0ae7bab2e0.png)






