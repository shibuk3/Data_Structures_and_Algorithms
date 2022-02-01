What is overlays in operating system ? How does it help in solving problem of external fragmentation ?

Overlaying means "the process of transferring a block of program code or other data into internal memory,
replacing what is already stored". Overlaying is a technique that allows programs to be larger than the
computer's main memory. An embedded would normally use overlays because of the limitation of physical
memory which is  internal memory for a system-on-chip and the lack of virtual memory facilities.

Overlaying requires the programmers to split their object code to into multiple completely-independent
sections, and the overlay manager that linked to the code will load the required overlay dynamically & 
will swap them when necessary.


This technique requires the programmers to specify which overlay to load at different circumstances.
