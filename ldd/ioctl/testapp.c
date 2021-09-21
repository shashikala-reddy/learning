#include <stdio.h>		//standard input output- printf, scanf
#include <unistd.h>		//standard symbolic constants and types- getpid(), close(fd)
#include <fcntl.h>		//file control operations- open and close system calls, O_RDWR flag
#include <stdlib.h>		//exit function- exit(0)
#include<sys/ioctl.h>	//ioctl system call
#include<errno.h>		//error type and number
#include <sys/types.h>
#include<string.h>

#define MY_MAGIC 'a'	//unique
#define WR_VALUE _IOW(MY_MAGIC,'a',int32_t*)	//ioctl with write parameters(copy_from_user)
#define RD_VALUE _IOR(MY_MAGIC,'b',int32_t*)	//ioctl with read parameters(copy_to_user)
#define MY_IOCTL_MAX_CMD 2

int main()
{
	int fd;
    int32_t value, number;	
	
	printf("[%d] - Opening device my_cdrv\n", getpid() );
	
	fd = open( "/dev/my_Ioctl_driver", O_RDWR );
	if( fd < 0 ) {
		printf("\n\nDevice could not be opened\n\n");
		printf("%d %s\n", errno, strerror(errno));
		return errno;
	}
	printf("Device opened with ID [%d]\n", fd);
	
	   
	printf("Enter the Value to send\n");
	scanf("%d",&number);
	printf("Writing Value to Driver\n");
	 

	/*return 0 or non-negative value on success 
	returns -1 for error and errno will set appropriately*/
	if((ioctl(fd, WR_VALUE, (int32_t*) &number) < 0))
	{
		printf("%d %s", errno, strerror(errno));
		return errno;
	}

	printf("Reading Value from Driver\n");
	if((ioctl(fd, RD_VALUE, (int32_t*) &value)<0))
	{
		printf("%d %s", errno, strerror(errno));
		return errno;	
	}
	printf("Value is %d\n", value);

	printf("Closing Driver\n");
	if((close(fd)<0))
	{
		printf("%d %s", errno, strerror(errno));
		return errno;
	}
	
	
	
	exit(0);
}

