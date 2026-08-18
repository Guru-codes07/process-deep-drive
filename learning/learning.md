# Learning

The "learning/" directory contains small C programs, exercises, and mini-projects designed to build the systems programming skills needed for the final Process Monitor.

The focus is on learning by writing code, experimenting with Linux system interfaces, and understanding how things work under the hood.

---

# 📂 Directory Structure

Each learning project follows a simple structure:

```
learning/
├── project-name/
│   ├── *.c
│   ├── README.md
│   ├── notes.md
│   └── Makefile
│
└── another-project/
    ├── *.c
    ├── README.md
    ├── notes.md
    └── Makefile
```

# Files
...
File| Purpose
"*.c"| Source code and exercises
"README.md"| Project overview and learning objectives
"notes.md"| Concepts, system calls, observations, and important details
"Makefile"| Build instructions
...
---

# 🚀 Quick Start

Clone the repository and enter the learning directory:

git clone https://github.com/Guru-codes07/process-deep-dive.git
cd process-deep-dive/learning

Choose a project:

cd project-name

Build it using the provided Makefile:

make

Run the program:

./program-name

To clean the generated files:

make clean

«The exact executable name depends on the individual project's Makefile.»

---

# 🧠 How to Use the Learning Materials

For each project, a good approach is:

1. Read the project's "README.md".
2. Go through "notes.md".
3. Read the source code.
4. Build and run the program.
5. Modify the code and experiment.
6. Try implementing the concept yourself without looking at the solution.

Don't be afraid to break the programs. Experimenting with the code is an important part of learning systems programming.

---

# 🔬 What You'll Practice

The projects in this directory will cover concepts useful for the final Process Monitor, including:

- C programming
- Linux processes
- System calls
- File I/O
- File descriptors
- Memory management
- "/proc" filesystem
- Process information
- CPU and memory statistics
- Error handling
- Linux/POSIX APIs

---

# 📌 Learning Principle

«Read → Understand → Run → Modify → Experiment»

The goal isn't just to make the programs work. It's to understand why they work and how the underlying Linux system behaves.

---

# 📄 License

This project is licensed under the MIT License.

See the main repository's ""LICENSE"" (../LICENSE) file for the complete license.

---

# ⭐ Keep Experimenting

Every exercise here is a building block for the final Process Monitor.

Take your time, experiment with the code, read the Linux documentation, and don't hesitate to modify the examples to see what happens.
