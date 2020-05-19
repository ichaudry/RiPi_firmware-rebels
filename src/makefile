all: pull compile_driver

pull:
	@git pull

compile_driver:
	@gcc driver.c motors.c lineSensors.c echoSensor.c sideSensors.c lineFollow.c obstacleAvoid.c hardwareCheck.c -o driver -lwiringPi -pthread


