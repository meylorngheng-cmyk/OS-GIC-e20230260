# Class Activity 2 — Processes & Inter-Process Communication

- **Student Name:** Meylorng Heng
- **Student ID:** e20230260
- **Date:** October 23, 2026

---

## Task 1: Process Creation on Linux (fork + exec)

### Compilation & Execution
![Task 1 - Compile & Run](screenshots/task1_compile_run.png)

### Process Tree
![Task 1 - Process Tree](screenshots/task1_process_tree.png)

### Output
### Questions
1. **What does `fork()` return to the parent? What does it return to the child?**
   > `fork()` returns the child process's PID to the parent process, and returns `0` to the child process.

2. **What happens if you remove the `waitpid()` call? Why might the output look different?**
   > Without `waitpid()`, the parent might exit before the child finishes, creating an orphan process and causing interleaved terminal output.

3. **What does `execlp()` do? Why don't we see "execlp failed" when it succeeds?**
   > `execlp()` replaces the current process image with a new program. When successful, it does not return because the memory space is entirely overwritten.

4. **Draw the process tree for your program (parent → child). Include PIDs from your output.**
   > `./forkchild (PID: 856317) ──> ./forkchild (PID: 856319)`

5. **Which command did you use to view the process tree (`ps --forest`, `pstree`, or `htop`)? What information does each column show?**
   > We used `ps -ef --forest`. Columns show UID, PID, PPID, CPU usage, start time, terminal, and command.

---

## Task 2: Process Creation on Windows

### Compilation & Execution
![Task 2 - Compile & Run](screenshots/task2_compile_run.png)

### Task Manager Screenshots
![Task 2 - Task Manager Tree](screenshots/task2_taskmanager_tree.png)
![Task 2 - Task Manager Details](screenshots/task2_taskmanager_details.png)

### Questions
1. **What is the key difference between how Linux creates a process (`fork` + `exec`) and how Windows does it (`CreateProcess`)?**
   > Linux uses two steps (`fork` duplicates, `exec` replaces), whereas Windows creates and loads a process in a single call (`CreateProcess`).

2. **What does `WaitForSingleObject()` do? What is its Linux equivalent?**
   > It blocks until the specified kernel object is signaled. Its Linux equivalent is `waitpid()`.

3. **Why do we need to call `CloseHandle()` at the end? What happens if we don't?**
   > To release kernel object handles and prevent resource/handle leaks.

4. **In Task Manager, what was the PID of your parent program and the PID of mspaint? Do they match your program's output?**
   > Yes, the PIDs match the console application output.

5. **Compare the Processes tab (tree view) and the Details tab (PID/PPID columns). Which view makes it easier to understand the parent-child relationship? Why?**
   > The Processes tab tree view is easier because it visually nests child processes under their parents.

---

## Task 3: Shared Memory IPC

### Compilation & Execution
![Task 3 - Compile & Run](screenshots/task3_compile_run.png)

### Output
### Questions
1. **What does `shm_open()` do? How is it different from `open()`?**
   > Creates or opens a POSIX shared memory object in RAM, unlike `open()` which deals with persistent disk files.

2. **What does `mmap()` do? Why is shared memory faster than other IPC methods?**
   > Maps shared memory into virtual address space, avoiding data copying between kernel and user space.

3. **Why must the shared memory name match between producer and consumer?**
   > The name acts as a global kernel identifier so both processes map to the same physical memory.

4. **What does `shm_unlink()` do? What would happen if the consumer didn't call it?**
   > Removes the shared memory object name; without it, the memory remains allocated until reboot.

5. **If the consumer runs before the producer, what happens? Try it and describe the error.**
   > `shm_open()` fails with `ENOENT` because the shared memory object does not exist yet.

---

## Task 4: Message Queue IPC

### Compilation & Execution
![Task 4 - Compile & Run](screenshots/task4_compile_run.png)

### Output
### Questions
1. **How is a message queue different from shared memory? When would you use one over the other?**
   > Message queues pass discrete messages with kernel synchronization; shared memory provides raw RAM access for high-throughput data.

2. **Why does the queue name in `common.h` need to start with `/`?**
   > POSIX standards require all message queue names to begin with a forward slash.

3. **What does `mq_unlink()` do? What happens if neither the sender nor receiver calls it?**
   > Destroys the message queue name; if uncalled, it persists in kernel memory until reboot.

4. **What happens if you run the receiver before the sender?**
   > The receiver fails because the queue has not been created yet.

5. **Can multiple senders send to the same queue? Can multiple receivers read from the same queue?**
   > Yes, POSIX message queues support multiple concurrent senders and receivers.
