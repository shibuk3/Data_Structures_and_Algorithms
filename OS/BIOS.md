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

__Location Of BIOS :__

BIOS is typically placed in a chip known as Read Only Memory(ROM) 
that comes with the computer. This ensures that the BIOS will
always be available even if the hard disk is formatted or 
replaced. However, in many cases the content of the ROM is
transferred to the RAM when the system is started. This is
because the RAM allows quicker access as compared to the
ROM. Copying of the content of the ROM to the RAM is known
as shadowing.

__Complementary Metal Oxide Semiconductor RAM :___

As the BIOS will interface the hardware with the operating system, it will
require configurations of the hardware components like hard disk, monitor
, etc. This information is permanently saved in an area known as Complementary
Metal Oxide Semiconductor Random Access Memory (CMOS RAM). Power is 
supplied to the CMOS from a small battery so its contents will not be 
lost after the PC is turned off. Therefore, there is a battery and a
small RAM memory on the board which stores information in a permanent
manner. The CMOS needs very little power so there is not much of strain
on the computer’s battery. Even then the battery is rechargeable is
recharged every time the computer is turned on.
