#  Timer Implementation Notes 📝

## Overview 🌐
This guide is an elaborate walkthrough of the  on implementing Timer, a Linux timer utility. Timer is created to run as a one-shot timer and can also be configured to run periodically. This guide includes interview questions to help you prepare for discussions about the topic.

## Source Code Location 📍
- The source code is located in the **codebase directory** in this GitHub repo.
- The file to look at is `Timer_example_demo1.c`.

## Required Header Files 📂
- `signal.h`
- `time.h`
- Two mandatory header files when working with Linux timers.
  
## Function to Print Current System Time ⏲️
- Utilizes `time_t` variable and `time()` function to fetch the current system time.
  
```c
time_t t;
time(&t);
printf("Current Time: %s", ctime(&t));
```

## User-Defined Data Structure 🛠️
- A simple pair of integers `a` and `b`.
  
## Timer Callback Function 🔄
- A function that triggers when the timer fires.
- Accepts an argument of type `union sigval`.
- Fetches the user-defined data structure and prints its values.

## Creating Timer ⏱️
### Initialize Timer Variables
1. `sigevent` type of variable to set properties.
2. `timer_t` type of variable for the timer.
  
### Configure `sigevent` Structure
- `sigev_value.sival_ptr`: Points to the user-defined data structure.
- `sigev_notify`: Specifies how to invoke the callback function (in a separate thread in this case).
- `sigev_notify_function`: Points to the timer callback function.

### Create Timer Using API
- Use `timer_create()` to initialize the timer.
  
```c
timer_create(CLOCK_REALTIME, &evp, &timer);
```

### Setting Expiry Time
- `itimerspec` structure has `it_value` for the timer fire time (e.g., 5 seconds and 0 nanoseconds).
  
### Start the Timer
- Use `timer_settime()` to start the timer countdown.
  
## Compilation and Execution 💻
- Compile using `-lrt` flag for linking against the real-time library.

---

# Interview Questions and Answers 🎙️

### Q1: What are the mandatory header files for working with Linux timers?
**A1:** The mandatory header files for working with Linux timers are `signal.h` and `time.h`.

### Q2: How do you fetch and print the current system time in C?
**A2:** You can fetch and print the current system time by using the `time_t` type variable and the `time()` and `ctime()` functions.

### Q3: What is the purpose of the timer callback function?
**A3:** The timer callback function gets invoked when the timer fires. It is responsible for executing whatever action is necessary at that moment, such as fetching and displaying user-defined data.

### Q4: How do you create a one-shot timer in Linux?
**A4:** A one-shot timer can be created by setting the `it_interval` values to zero while using `timer_settime()`.

### Q5: How do you convert a one-shot timer to a periodic timer?
**A5:** A one-shot timer can be converted to a periodic timer by specifying non-zero values in the `it_interval` field in the `itimerspec` structure.

### Q6: What happens when the `timer_create()` function returns a negative value?
**A6:** If `timer_create()` returns a negative value, it means an error has occurred while creating the timer.

### Q7: What does the `-lrt` flag do during the compilation?
**A7:** The `-lrt` flag is used for linking against the real-time library, which is necessary for working with timers in Linux.

