#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>
//#include <linux/can/netlink.h>
//#include <linux/if_link.h>
//#include <linux/rtnetlink.h>
//#include <linux/netlink.h>
#include "libsocketcan.h"
#include "bbexample.h"

int main(int argc, char **argv)
{
	int s, i; 
	int nbytes;
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame frame;
	char *name  = "can0";
	__u32 bR = 500000;
	
	can_set_bitrate(name, bR);
	LibHelloWorld();

	can_do_start(name);


	printf("CAN Sockets Receive Demo\r\n");

	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}

	strcpy(ifr.ifr_name, "can0" );
	ioctl(s, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;
	

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}

	nbytes = read(s, &frame, sizeof(struct can_frame));
printf("0\r\n");
 	if (nbytes < 0) {
		perror("Read");
		return 1;
	}
printf("1\r\n");
	printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);

	for (i = 0; i < frame.can_dlc; i++)
		printf("%02X ",frame.data[i]);

	printf("\r\n");

	printf("2\r\n");

	if (close(s) < 0) {
		perror("Close");
		return 1;
	}

	return 0;
}

