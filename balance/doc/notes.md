# NOTES

Shared Pi IP Address: 10.130.73.179

## 12/7/2018
Best combo with battery at bottom: 60 .5 .5   
Max Speed: 60, Sample Time: 0.01 s  
Higher Kp increased oscillation speed  
Higher Kd increased oscillations more?  
IMU placement and tilt is CRITICAL. Need to secure  
Still trying to figure out what Ki does (seems to reduce oscillations?)  
Battery placement didn't make a huge difference between middle and bottom layer  
https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/16311/www/s18/labs/lab04/previous_versions/handout2016.pdf  

## 12/19/2018
Battery is best placed at the top  
Best combo with battery at top: 60 .5 .5  
Max Speed 70, Sample Time: 0.01 s   
Writing code to get accurate sample time seemed detrimental for some reason  
A "standoff" was used with the IMU to keep in place, didn't seem to do very much. It seems that there will have to be other measures taken to keep the robot from moving off in one direction completely.

## 12/21/2018
Division of responsibility  
Raspberry Pi - imu, roboclaw, lcd  
Arduino - batt, ultrasonic  


## Dean's Suggestions from December 2018
Increase max speed  
Use encoder to account for varying surfaces  
Eventually control motors separately  
