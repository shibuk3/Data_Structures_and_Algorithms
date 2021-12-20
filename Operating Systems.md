### __Types of Operating System__
- Batch Operating System
- Multiprogramming Operating System
- Multitasking Operating System
- Multiprocessing Operating System
- Real time Operating System

### __Batch Operating system__
- Firstly, user prepares his job using punch cards.
- Then, he submits the job to the computer operator.
- Operator collects the jobs from different users and sort the jobs into batches with similar needs.
- Then, operator submits the batches to the processor
- All the jobs of one batch are executed together.

```md
__Advantages-__
- It saves the time that was being wasted earlier for each individual process in context switching 
from one environment to another environment.
- No manual intervention is needed.

 __Disadvantages-__
1. Priority can not be set for the jobs.
In batch operating system,
- All the jobs of a batch are executed sequentially one after the other.
- The output is obtained only after all the jobs are executed.
- Thus, priority can not be implemented if a certain job has to be executed on an urgent basis.
 
2. Batch operating system may lead to starvation.
In batch operating system,
- The jobs of a particular batch might take long time for their execution.
- This might lead to starvation to other jobs in other batches.
 
3. CPU may remain idle for a long time.
In batch operating system,
- If the jobs of a batch require some I/O operation, then CPU must wait till the I/O operation gets completed.
- Since I/O devices are very slow, CPU remains idle for a long time.
- CPU can not take any other job and execute it.

4. There is a lack of interaction between a user and his job.
- Once a batch is submitted for execution, the user is not able to interact with any of his jobs.
- If a job requires the user to input data during run time, then user must wait till the other
jobs of the batch get executed.
- This also increases the overall execution time.
```
### __Process States in Operating System-__
```md
1. New State-
A process is said to be in new state when a program present in the secondary memory is initiated for execution.
 
2. Ready State- 
- A process moves from new state to ready state after it is loaded into the main memory and is ready for execution.
- In ready state, the process waits for its execution by the processor.
- In multiprogramming environment, many processes may be present in the ready state.
 
3. Run State-
- A process moves from ready state to run state after it is assigned the CPU for execution.
 
4. Terminate State-
- A process moves from run state to terminate state after its execution is completed.
- After entering the terminate state, context (PCB) of the process is deleted by the operating system.
 

5. Block Or Wait State-
- A process moves from run state to block or wait state if it requires an I/O operation or some
 blocked resource during its execution.
- After the I/O operation gets completed or resource becomes available, the process moves to the ready state.
 
6. Suspend Ready State-
- A process moves from ready state to suspend ready state if a process with higher priority has to
 be executed but the main memory is full.
- Moving a process with lower priority from ready state to suspend ready state creates a room
 for higher priority process in the ready state.
- The process remains in the suspend ready state until the main memory becomes available.
- When main memory becomes available, the process is brought back to the ready state.

6. Suspend Wait State-
- A process moves from wait state to suspend wait state if a process with higher priority has to be executed but
 the main memory is full.
- Moving a process with lower priority from wait state to suspend wait state creates a room for higher
 priority process in the ready state.
- After the resource becomes available, the process is moved to the suspend ready state.
- After main memory becomes available, the process is moved to the ready state.
```
```md
A process necessarily goes through minimum 4 states. 
- The minimum number of states through which a process compulsorily goes through is 4.
- These states are new state, ready state, run state and terminate state.
- However, if a process also requires the I/O operation, then minimum number of states is 5.

A single processor can execute only one process at a time.
- A single processor can not more than one processes simultaneously.
- If n processors are present in the system, then only n processes can be executed simultaneously.

Moving a process from wait state to suspend wait state is a better alternative.
- Consider a process with higher priority arrives and the main memory is full.
- Then, there are two ways to make room for it.
 
These two ways are-
- Moving a process with lower priority from ready state to suspend ready state.
- Moving a process with lower priority from wait state to suspend wait state.
  
Out of these-
- Moving a process from wait state to suspend wait state is a better alternative.
- This is because the process is already waiting for some blocked resource.
```
