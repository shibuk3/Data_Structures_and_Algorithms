### __Process__

- [Process states in os](https://www.gatevidyalay.com/process-states-in-operating-system/)
- [Prcoess control block](https://www.gatevidyalay.com/process-control-block-process-attributes/)
- [Virtual memory or Demand paging](https://www.geeksforgeeks.org/virtual-memory-in-operating-system/)


### __threads__

```md

Thread is a single sequence stream within a process. Threads have same properties
as of the process so they are called as light weight processes. Threads are
executed one after another but gives the illusion as if they are executing
in parallel. Each thread has different states. Each thread has  

Thread is the segment of a process means a process can have multiple
threads and these multiple threads are contained within a process.
A thread has three states: Running, Ready, and Blocked.
```
- Thread ID
- A program counter 
- A register set 
- A stack space 


```html
Comparison Basis	Process	Thread
Definition	A process is a program under execution i.e an active program.	A thread is a lightweight process that can be managed independently by a scheduler.
Context switching time	Processes require more time for context switching as they are more heavy.	Threads require less time for context switching as they are lighter than processes.
Memory Sharing	Processes are totally independent and don’t share memory.	A thread may share some memory with its peer threads.
Communication	Communication between processes requires more time than between threads.	Communication between threads requires less time than between processes .
Blocked	If a process gets blocked, remaining processes can continue execution.	If a user level thread gets blocked, all of its peer threads also get blocked.
Resource Consumption	Processes require more resources than threads.	Threads generally need less resources than processes.
Dependency	Individual processes are independent of each other.	Threads are parts of a process and so are dependent.
Data and Code sharing	Processes have independent data and code segments.	A thread shares the data segment, code segment, files etc. with its peer threads.
Treatment by OS	All the different processes are treated separately by the operating system.	All user level peer threads are treated as a single task by the operating system.
Time for creation	Processes require more time for creation.	Threads require less time for creation.
Time for termination	Processes require more time for termination.	Threads require less time for termination.

```




