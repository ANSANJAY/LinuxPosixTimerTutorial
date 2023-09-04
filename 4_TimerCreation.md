# Timer Implementation in Operating Systems 🕒

## Introduction 📚
- The Operating System implements the concept of timers in the context of a separate code flow, which could be either a separate thread or a separate process.
  
## How Timers Work 👩‍🔬
- **Application Scenario**: You have an application (`Application B`) with a function (`foo`) that performs some work.
  
- **Creating a Timer**: At some point, the application starts a timer using a hypothetical API (`new_time_launch`).
  
  - **Function Pointer**: A mandatory argument for the timer is a function pointer pointing to the function (`foo`) that will execute when the timer expires.
  
  - **Function Argument**: The function (`foo`) also takes an argument, which needs to be provided when the timer is created.
  
- **Thread Creation**: After invoking the API, the OS forks a new thread (`T1`).

  - **Thread State**: Initially, this new thread (`T1`) will be blocked.
  
  - **Expiration Time**: If the timer is set to expire in 5 seconds, the thread stays blocked until then.
  
  - **Thread Execution**: After 5 seconds, the function `foo` is invoked with the provided argument.
  
- **Thread Termination**: Once the function (`foo`) completes its execution, the thread (`T1`) is terminated by the OS.

- **Resource Management**: The application should free all resources occupied by the timer at the end of the function `foo`.

## Types of Timers ⏲️
- **One-shot Timers**: Executes once and then the thread is killed.
  
- **Periodic Timers**: Repeats the function call at fixed intervals.
  
- **Exponential Backoff Timers**: The timer interval doubles after each execution.
  
## Timer Creation API 👨‍💻
- **API Function**: `timer_create()`
  
  - **Arguments**: 
    1. Type of timer
    2. Controlling parameters
    3. Pointer to the timer
  
  - **Return Value**: Returns 0 on success, -1 on error.
  
- **Controlling Parameters**:
  - Struct `evp` with three members: 
    1. `Sigev_notify_function`: The function to be executed when timer expires.
    2. `Sigev_value.sival_ptr`: The argument for the function.
    3. `SIGEV_THREAD`: To specify that a thread is used for callback.
  
- **Expiration Time**: Controlled by `itimerspec` data structure.
  
- **Starting the Timer**: Use `timer_set_time()` API.
- 
# `timer_create` Function in Linux

## Function Prototype

```c
int timer_create(clockid_t clockid, struct sigevent *evp, timer_t *timerid);
```

## Description

Creates a timer.

### Parameters

- **`clockid`**: Specifies the clock used for measuring time. A typical value is `CLOCK_REALTIME`, which uses wall clock time.
- **`timerid`**: Returns a unique timer ID as an integer.
- **`evp`**: Specifies how the process should be notified when the timer expires.

## `struct sigevent`

The `sigevent` structure has an abridged definition as follows:

```c
struct sigevent {
    int sigev_notify;  // Notification method
    int sigev_signo;   // Timer expiration signal
    union sigval sigev_value;  // Value passed to signal handler or thread function
    void (*sigev_notify_function) (union sigval);  // Thread notification function
    ...
};
```

### Notification Methods

Various notification methods are possible:

- **`SIGEV_SIGNAL`**: Send a signal
- **`SIGEV_THREAD`**: Call a function in a new thread

### `sigev_value`

Specifies the data to be sent to the signal handler or passed to the thread function. The value can be an integer or a pointer.

```c
union sigval {
    int sival_int;  // Integer value for accompanying data
    void *sival_ptr;  // Pointer value for accompanying data
};
```

## Example Usage

```c
clockid_t clockid = CLOCK_REALTIME;
timer_t timerid;
struct sigevent evp;

evp.sigev_notify = SIGEV_THREAD;
evp.sigev_notify_function = &timer_callback;
// Additional configurations...

int ret = timer_create(clockid, &evp, &timerid);
```

By defining the `sigevent` structure and using `timer_create`, you can create a timer that will notify you through various methods when it expires.



---

# `struct itimerspec` in Linux

## Name

`timespec` - Interval for a timer with nanosecond precision

## Library

Standard C Library (libc)

## Synopsis

```c
#include <time.h>

struct itimerspec {
    struct timespec it_interval;  /* Interval for periodic timer */
    struct timespec it_value;     /* Initial expiration */
};
```

## Description

The `itimerspec` structure describes the initial expiration and the interval of a timer in seconds and nanoseconds.

### Members

- **`it_interval`**: Specifies the interval for the periodic timer.
- **`it_value`**: Specifies the time for the initial expiration of the timer.

## Standards

Linux.

## Notes

This type is also provided by the `<sys/timerfd.h>` header.

## Example Usage

```c
#include <time.h>

struct itimerspec timerSpec;

timerSpec.it_interval.tv_sec = 1;  // 1 second
timerSpec.it_interval.tv_nsec = 0; // 0 nanoseconds

timerSpec.it_value.tv_sec = 2;     // Initial expiration after 2 seconds
timerSpec.it_value.tv_nsec = 0;    // 0 nanoseconds
```

By defining the `itimerspec` structure, you can control both the interval and initial expiration time of a timer with nanosecond-level precision.

## Interview Questions 🤔

### Q1: Can you explain how the concept of timers is implemented in operating systems?

👉 **Answer**: Timers in operating systems are implemented in the context of a separate code flow, usually a thread or a process. When a timer is set to expire after a certain time, a new thread is spawned and kept in a blocked state. Once the timer expires, the function specified during timer creation is invoked.

### Q2: What is a timer callback function?

👉 **Answer**: A timer callback function is a function that gets executed when a timer expires. This function is specified when the timer is created, along with any arguments it may need.

### Q3: How do you set the expiration time for a timer?

👉 **Answer**: The expiration time is set using the `itimerspec` data structure, which contains two members for specifying time in seconds and nanoseconds.

### Q4: Explain the difference between one-shot, periodic, and exponential backoff timers.

👉 **Answer**: 
- One-shot timers execute the function once and then the thread is terminated.
- Periodic timers execute the function at regular intervals.
- Exponential backoff timers double the interval after each execution.

### Q5: What are the primary components for controlling timer behavior during its creation?

👉 **Answer**: During timer creation, you usually specify three main things: 
1. The type of timer you want to create.
2. Controlling parameters, often bundled in a struct.
3. A pointer that will hold the created timer's details.

---

Feel free to add more questions and answers as you dive deeper into this topic. 📘✨
