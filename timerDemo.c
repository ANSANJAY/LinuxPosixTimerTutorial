// Include headers for POSIX timers and signals
#include <signal.h>
#include <time.h>

// Include standard header files
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h> // for pause()
#include <stdint.h>
#include <stdbool.h>

// Function to print current system time
static void print_current_system_time(){
	time_t t;
	time(&t); // Get the current system time
	printf("%s ", ctime(&t)); // Print the current time
}

// Example data structure
typedef struct pair_{
	int a;
	int b;
} pair_t;

// Initialize example pair
pair_t pair = { 10, 20 };

// Timer callback function
void timer_callback(union sigval arg){
	print_current_system_time(); // Print current time
	pair_t *pair = (pair_t *) arg.sival_ptr; // Extract user data structure
	printf("pair : [%u %u]\n", pair->a, pair->b); // Print the data
}

// Function to demonstrate timer usage
void timer_demo(){
	int ret;
	struct sigevent evp;
	timer_t timer;
	memset(&timer, 0, sizeof(timer_t)); // Initialize timer to zeros
	memset(&evp, 0, sizeof(struct sigevent)); // Initialize evp to zeros

	evp.sigev_value.sival_ptr = (void *)&pair; // Set user-defined data
	evp.sigev_notify = SIGEV_THREAD; // Set notification type to thread
	evp.sigev_notify_function = timer_callback; // Set callback function

	// Create and initialize the timer
	ret = timer_create(CLOCK_REALTIME, &evp, &timer);
	if ( ret < 0) {
		printf("Timer Creation failed, errno = %d\n", errno);
		exit(0);
	}

	// Set timer intervals
	struct itimerspec ts;
	ts.it_value.tv_sec = 5; // Initial time = 5 seconds
	ts.it_value.tv_nsec = 0; // and 0 nanoseconds
	ts.it_interval.tv_sec = 3; // Subsequent interval = 3 seconds
	ts.it_interval.tv_nsec = 0; // and 0 nanoseconds

	// Start the timer
	ret = timer_settime(timer, 0, &ts, NULL);
	if ( ret < 0) {
		printf("Timer Start failed, errno = %d\n", errno);
		exit(0);
	}
	else {
		print_current_system_time();
		printf("Timer Alarmed Successfully\n");
	}
}

// Main function
int main(int argc, char **argv){
	timer_demo(); // Run the timer demo
	pause(); // Pause execution to keep the program running
	return 0;
}
