/*
 * Start gas motor
 *
 * author: Ryan Skeele
 *
 */
//#include <nuttx/config.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <poll,h>
//#include <uORB/uORB.h>
//#include <uORB/topics/sensor_combined.h>
//
//__EXPORT int autoboat_main(int argc, char *argv[]);
// 
//int autoboat_main(int argc, char *argv[])
//{
//	printf("Hello Sky!\n");
//	return 0;
//}

/*
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
#include <poll.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <nuttx/wqueue.h>
#include <nuttx/clock.h>
#include <systemlib/systemlib.h>
#include <systemlib/err.h>
#include <uORB/uORB.h>
#include <uORB/topics/vehicle_status.h>
#include <poll.h>
#include <drivers/drv_gpio.h>
#include <modules/px4iofirmware/protocol.h>

//__EXPORT void autoboat_main(int argc, char *argv[]);

//Add comment of what fd is
int fd = open(PX4IO_DEVICE_PATH, 0);
int vehicle_status_sub;
struct vehicle_status_s status;
//memset(status,0,sizeof(status));


void autoboat_main(int argc, char *argv){
	vehicle_status_sub = orb_subscribe(ORB_ID(vehicle_status));
	bool updated;
	orb_check(vehicle_status_sub, &updated);
	if(updated){
		orb_copy(ORB_ID(vehicle_status), vehicle_status_sub, &status);
	}
	if(status.arming_state == ARMING_STATE_ARMED){
//		ioctrl(fd, GPIO_SET_OUTPUT, a1);
//		ioctrl(fd, GPIO_SET_CLEAR, a1);
	}
}
