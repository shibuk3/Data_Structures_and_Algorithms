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

__Advantages-__
- It saves the time that was being wasted earlier for each individual process in context switching from one environment to another environment.
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
- If a job requires the user to input data during run time, then user must wait till the other jobs of the batch get executed.
- This also increases the overall execution time.
