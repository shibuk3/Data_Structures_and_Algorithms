When a computer system is turned on it requires a series of initialization and
test before the user can work on it. This process is called booting.

The BIOS chip tells it to look in a fixed place, usually on the lowest-numbered 
hard disk (the boot disk) for a special program called a boot loader (under Linux
the boot loader is called Grub or LILO). The boot loader is pulled into memory 
and started. The boot loader’s job is to start the real operating system. 

__Basic Input Output System (BIOS) :__

It provides a set of instructions and is responsible for booting the computer.
The BIOS performs all the test needed at startup time. These tests are collectively
known as Power On Self Test(POST) .The computer contains hardware like keyboard, 
monitor, disk drives, etc. there functioning requires interfacing with the operating 
system. The BIOS provides drivers for basic hardware like keyboard
and monitor, mouse, etc. The operating system provides hardware for 
printer, modem, etc. Drivers for some hardware may not be available
in the operating system hence these have to be explicitly installed by 
the user.

__Power On Self Test (POST) :__

POST consists of a series of diagnostic test that runs automatically 
when a user turns on the computer. The actual test may differ depending 
on the configuration of the BIOS. However, the usual test includes testing 
of the RAM, keyboard and the disk drives. If these tests are successful the
computer boots itself and loads the operating system but if these tests are 
unsuccessful, the computer reports the errors through a series of beeps to
draw the operator’s attention and finally an error message is displayed on
the monitor.

__Master Boot Record__ 

The Master Boot Record (MBR) is a small program that starts when
the computer is booting, in order to find the operating system
(eg. Windows XP). This complicated process (called the Boot Process)
starts with the POST (Power On Self Test) and ends when the Bios 
searches for the MBR on the Hard Drive, which is generally located 
in the first sector, first head, first cylinder (cylinder 0, head 0, sector 1). 
