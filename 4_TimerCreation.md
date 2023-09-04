# Timer Implementation in Operating Systems 🕒

## Introduction 📚
- The Operating System implements the concept of timers in the context of a separate code flow, which could be either a separate thread or a separate process.
  
## How Timers Work 👩‍🔬
- **Application Scenario**: You have an application (`Application B`) with a function (`fule`) that performs some work.
  
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

---

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
