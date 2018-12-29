#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
#include "MPU6050.h"

using namespace std;

double RAD_TO_DEG = 180.0/3.14159;
double prevAngle = 0;
double sampleTime = 0.01;


int main()
{
	MPU6050 mpu;
	mpu.initialize();

	while (1) {
		double accX = mpu.getAccelerationX()/16384.0;
		double accY = mpu.getAccelerationY()/16384.0;
		double accZ = mpu.getAccelerationZ()/16384.0;
		double gyroX = mpu.getRotationX()/131.0;
		double gyroY = mpu.getRotationY()/131.0;
		double gyroZ = mpu.getRotationZ()/131.0;

		// calculate angle
		double accAngle = (double) atan(accY/accZ) * RAD_TO_DEG; //degrees
		double gyroRate = gyroX; // degrees/second
		double gyroAngle = gyroRate*sampleTime; // degrees
		double currentAngle = 0.99*(prevAngle + gyroAngle) + 0.01*accAngle; // complementary filter

		printf ("accX=%4.2f accY=%4.2f accZ=%4.2f gyroX=%4.2f gyroY=%4.2f gyroZ=%4.2f currentAngle=%4.2f\n", accX, accY, accZ, gyroX, gyroY, gyroZ, currentAngle); 

		sleep(1);
	}

	return 0;
}
