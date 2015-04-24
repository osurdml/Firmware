/*
 * Start gas motor
 *
 * author: Ryan Skeele
 *
 */
#include <stdio.h>
#include <sys/ioctl.h>
#include <systemlib/systemlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <nuttx/fs/ioctl.h>
#include <uORB/uORB.h>
#include <uORB/topics/vehicle_status.h>
#include <drivers/drv_gpio.h>
#include <modules/px4iofirmware/protocol.h>

//Add comment of what fd is
int fd = open(PX4IO_DEVICE_PATH, 0);
int vehicle_status_sub;
struct vehicle_status_s status;
//memset(status,0,sizeof(status));
vehicle_status_sub = orb_subscribe(ORB_ID(vehicle_status));


int gas_motor_main(int argc, char *argv[]){
	bool updated;
	orb_check(vehicle_status_sub, &updated);
	if(updated){
		orb_copy(ORB_ID(vehicle_status), vehicle_status_sub, status);
	}
	if(status.arming_state == ARMING_STATE_ARMED){
		printf("STARTING GAS MOTOR\n");
		ioctrl(fd, GPIO_SET_OUTPUT, a1);
		usleep(1000);
		ioctrl(fd, GPIO_SET_CLEAR, a1);
	}
	return 0;
}
