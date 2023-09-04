# Types of Timers: Detailed Notes for Interview Preparation 📝

## Introduction 🌟

- The focus of this section is to discuss the various **types of timers**.
- Specifically, we will cover **One-shot timers, Periodic timers, and Exponential Backoff timers**.

---

## Types of Timers 🕰️

### 1. One-shot Timers ⏲️

- Triggered only **once**.
- Examples:
  - Deleting a data structure after 10 seconds.
  - Sending a terminate request after a specified time.
- Used in scenarios where an event needs to occur **only once in the future**.

### 2. Periodic Timers ⏰

- Triggered at **regular intervals**.
- Example:
  - Sending out "Hello" packets every 5 seconds.
- Suitable for repetitive tasks that happen at fixed intervals.

### 3. Exponential Backoff Timers 📈

- A special case of **Periodic timers**.
- The time intervals are **exponentially spaced**.
- Used in TCP for implementing its backoff algorithm.
- Triggers could occur at 1, 2, 4, 8, 16, 32, 64, ... seconds.

---

## Implementation 🛠️

- Will use Linux and built-in APIs to create these types of timers.
- The goal is to provide a foundational understanding, and then build a **custom timer library** for full control over timers.

---

## Interview Questions & Answers 🤔💡

### Q1: What are the three main types of timers?

**A1**: The three main types of timers are One-shot timers, Periodic timers, and Exponential Backoff timers. One-shot timers trigger once, Periodic timers at regular intervals, and Exponential Backoff timers at exponentially increasing intervals.

### Q2: Can you give an example of a use-case for One-shot timers?

**A2**: One-shot timers could be used for deleting a data structure from an application after 10 seconds have passed, or sending a terminate request after a specific period.

### Q3: What differentiates Periodic timers from Exponential Backoff timers?

**A3**: While both are types of timers that trigger more than once, Periodic timers do so at regular intervals, whereas Exponential Backoff timers do so at exponentially increasing intervals.

### Q4: What is a practical application of Exponential Backoff timers?

**A4**: A practical application is in the TCP protocol, which uses Exponential Backoff timers to implement its backoff algorithm. This helps in avoiding network congestion by varying the intervals between packet retransmissions.
------


Best of luck with your interview preparation! 🍀
