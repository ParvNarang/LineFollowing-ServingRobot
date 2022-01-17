# LineFollowing based Serving Robot
This robot was made to serve people in a restaurant/hospital by delivering food items/medicines to the people.
The robot has a control-room where the robot is parked and sent to various locations on the floor, making use of an IR-sensor array that follows a black line.
It receives the input from the touch sensor in the form of an integer and goes to the location on the floor by checking its status and using those integers as table numbers or bed number. This status is checked with the help of junctions present on the floor. It then reaches the table/bed and waits for the person to take the food and returns to the control-room.
Initially in the code the robot is made to follow a track that serves 4-6 tables/beds in the room and having 2-3 checkpoints.


![IMG_20200619_200943](https://user-images.githubusercontent.com/56078295/104106503-70949300-52dc-11eb-94ed-2e589f56c284.jpg)


# COMPONENTS USED
  - Arduino Mega
  - L298N Motor Driver
  - IR-Sensor Array
  - Touch Sensor Board
  - 12V Lead-Acid Battery
  - 2 x DC Motors
  - 4 x Wheels
