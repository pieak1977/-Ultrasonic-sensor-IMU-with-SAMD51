//Ultrasonic Sensor
#define USE_USBCON
#include <ros.h>
#include <ros/time.h>
#include "ArduinoHardware.h"
#include <std_msgs/Float32.h>
#include <std_msgs/Int16.h>
#include <sensor_msgs/Range.h>

ros::NodeHandle nh;

#define ul_left_pin 5
#define ul_mid_pin 6
#define ul_right_pin 7

char frameid_l[] = "/ultrasonic_left";
char frameid_m[] = "/ultrasonic_mid";
char frameid_r[] = "/ultrasonic_right";

sensor_msgs::Range range_msg;
sensor_msgs::Range range2_msg;
sensor_msgs::Range range3_msg;
ros::Publisher pub_range( "/ultrasound", &range_msg);
ros::Publisher pub_range2( "/ultrasound2", &range2_msg);
ros::Publisher pub_range3( "/ultrasound3", &range3_msg);

unsigned long timeold = 0;
float getRange_ul(){
   int pin = ul_left_pin;
   pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
    long duration;
    duration = pulseIn(pin, HIGH);
    float range = duration/ 29 / 2;
    return range;
}

float getRange2_ul(){
   int pin = ul_mid_pin;
   pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
    long duration;
    duration = pulseIn(pin, HIGH);
    float range = duration/ 29 / 2;
    return range;
}

float getRange3_ul(){
   int pin = ul_right_pin;
   pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
    long duration;
    duration = pulseIn(pin, HIGH);
    float range = duration/ 29 / 2;
    return range;
}



void setup() {
  // put your setup code here, to run once:
  nh.initNode();

  //nh.advertise(rpm_left_pub);
  //nh.advertise(rpm_right_pub);
  nh.advertise(pub_range);
  nh.advertise(pub_range2);
  nh.advertise(pub_range3);
  delay(20);
}

void loop() {
  // put your main code here, to run repeatedly:
     range_msg.range = getRange_ul();
    range_msg.header.stamp = nh.now();
    range_msg.header.frame_id = frameid_l;
    range2_msg.range = getRange2_ul();
    range2_msg.header.stamp = nh.now();
    range2_msg.header.frame_id = frameid_m;
    range3_msg.range = getRange3_ul();
    range3_msg.header.stamp = nh.now();
    range3_msg.header.frame_id = frameid_r;
    //Publish data
    pub_range.publish(&range_msg);
    pub_range2.publish(&range2_msg);
    pub_range3.publish(&range3_msg);
   
   
    //reset parameter
    timeold = millis();
 
  //nh.loginfo("Log Me");
  nh.spinOnce();

  // wait for a second
  delay(5);
}
