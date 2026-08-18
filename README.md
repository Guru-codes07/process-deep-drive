# process-deep-dive

«A hands-on journey into Linux process management and systems programming in C.»

process-deep-dive is a learning-focused project dedicated to understanding how processes work inside Linux by building a process monitoring tool from scratch in C.

The goal isn't just to create another system-monitoring utility. The goal is to understand what happens under the hood — how Linux represents processes, how process information can be accessed, how CPU and memory usage are calculated, and how system-level information can be turned into a useful application.

---

🧠 About the Project

Processes are one of the fundamental concepts of an operating system.

Every time you open a terminal, launch a browser, run a program, or start a background service, you're interacting with processes.

Tools like:

- "ps"
- "top"
- "htop"
- System Monitor
- Process managers

provide information about these processes.

But instead of simply using these tools, process-deep-dive takes a different approach:

«Build one yourself and learn how it works.»

The project explores Linux process management step by step using C, Linux system calls, the "/proc" filesystem, file I/O, memory management, and other systems-programming concepts.

---

🎯 Project Goal

The final goal of this project is to build a lightweight Process Monitor capable of inspecting and displaying information about running processes.

The monitor is intended to provide information such as:

- Process ID (PID)
- Process state
- CPU usage
- Memory usage
- Command name
- Command line
- Other useful process statistics

It should also support real-time monitoring, allowing process information to update continuously as the system changes.

---

🔍 What Makes This Project Different?

This isn't a project where the final code is written first and the concepts are explained afterward.

The project follows a learning-by-building approach.

Instead of asking:

«"How do I make a process monitor?"»

the project asks:

«"What do I need to understand about Linux processes to build one myself?"»

That naturally leads into topics such as:

C Programming
      ↓
Linux Processes
      ↓
Process IDs
      ↓
System Calls
      ↓
/proc Filesystem
      ↓
Process Statistics
      ↓
CPU Usage
      ↓
Memory Usage
      ↓
Real-Time Monitoring
      ↓
Process Monitor

Each concept contributes to understanding the final application.

---

🐧 Linux Processes

A major focus of this project is understanding how Linux manages processes.

You'll explore concepts such as:

- What exactly is a process?
- How are processes identified?
- What is a PID?
- What is a parent process?
- How are processes created?
- How do processes terminate?
- What are process states?
- How does Linux track process information?

You'll also learn how programs can interact with this information from C.

---

📂 Exploring "/proc"

One of the most important parts of the project is the Linux "/proc" filesystem.

Linux exposes a huge amount of runtime information through "/proc".

For example:

/proc/1/
/proc/1000/
/proc/2500/

Numeric directories correspond to process IDs.

Inside them, Linux exposes information about individual processes.

For example:

/proc/<pid>/status
/proc/<pid>/stat
/proc/<pid>/cmdline

The process monitor will use this information to discover and inspect running processes.

This provides practical experience working with a pseudo-filesystem exposed by the Linux kernel.

---

⚙️ Systems Programming

While developing the project, you'll work with low-level Linux concepts rather than relying entirely on high-level libraries.

You'll encounter APIs and concepts such as:

open()
read()
close()
fork()
exec()
wait()
getpid()

along with:

- File descriptors
- System calls
- Process creation
- Process termination
- File I/O
- Memory allocation
- Error handling

The goal is to understand what these mechanisms actually do and how applications interact with the operating system.

---

📊 CPU Monitoring

Monitoring CPU usage introduces another interesting problem.

A process doesn't simply have a fixed "CPU percentage."

CPU usage needs to be calculated by observing how much CPU time a process consumes over a period of time.

This project explores concepts including:

- CPU time
- Process CPU time
- Sampling intervals
- System CPU statistics
- Usage calculations
- Periodic updates

This makes the project a practical exercise in working with time-based system statistics.

---

💾 Memory Monitoring

The process monitor will also inspect process memory usage.

You'll explore concepts such as:

- Virtual memory
- Resident memory
- Memory pages
- RSS
- Process address space

and learn how Linux exposes memory information that can be interpreted by user-space programs.

---

🖥️ Process States

Processes can exist in different states during their lifetime.

The monitor will display process states such as:

R  Running
S  Sleeping
D  Uninterruptible Sleep
T  Stopped
Z  Zombie

Understanding these states provides a better picture of what processes are actually doing inside the operating system.

---

🔄 Real-Time Monitoring

A major feature of the final tool is the ability to monitor processes continuously.

Instead of displaying information once:

Read → Display → Exit

the monitor can repeatedly collect and update information:

Read
 ↓
Calculate
 ↓
Display
 ↓
Wait
 ↓
Read again
 ↓
Calculate again
 ↓
Update display
 ↓
...

This turns the project from a simple "/proc" parser into an actual monitoring application.

---

🛠️ Technologies

The project primarily focuses on:

Technology| Purpose
C| Core programming language
Linux| Target operating system
GCC| Compilation
Linux "/proc"| Process information
POSIX/Linux APIs| System interaction
Make| Build automation
Git| Version control

---

📚 What You'll Learn

By working through this project, you'll gain practical experience with:

C Programming

- Pointers
- Structures
- Strings
- Dynamic memory
- File handling
- Error handling
- Modular programming

Linux

- Processes
- PIDs
- Process states
- "/proc"
- File descriptors
- System calls
- CPU statistics
- Memory statistics

Systems Programming

- Kernel/user-space interaction
- Reading system information
- Parsing system data
- Resource monitoring
- Real-time data collection

Software Development

- Project organization
- Debugging
- Testing
- Makefiles
- Git
- Documentation

---

🎓 Why This Project Matters

Understanding processes is an important foundation for anyone interested in:

- Operating Systems
- Systems Programming
- Cybersecurity
- Linux Administration
- Networking
- Backend Infrastructure
- Embedded Systems
- Performance Engineering
- DevOps
- Low-Level Programming

A process monitor may look like a relatively small project, but building one from scratch forces you to understand several fundamental operating-system concepts.

---

🚀 The Philosophy

The philosophy behind process-deep-dive is:

«Don't just use system tools. Understand how they work.»

Instead of treating Linux as a black box, this project encourages you to look inside it.

Read the data.

Understand the structures.

Experiment with system calls.

Observe processes.

Break things.

Fix them.

And eventually build something useful from what you've learned.

---

🏁 Final Goal

The end result will be a functional process monitoring tool written in C that can inspect running processes and present useful resource information.

But the actual outcome goes beyond the final program.

The real goal is to develop the ability to look at a system-level problem and think:

What information does the operating system provide?
                ↓
Where can I access it?
                ↓
How is that information represented?
                ↓
How can I read it from C?
                ↓
How can I process it?
                ↓
How can I turn it into a useful tool?

That's the essence of process-deep-dive.

---

⭐ Learn. Explore. Build.

process-deep-dive is more than a process monitor project.

It's a practical exploration of Linux processes, C programming, and systems programming, with a real application as the final destination.

«Understand the process. Build the monitor. Dive deeper into Linux.»
