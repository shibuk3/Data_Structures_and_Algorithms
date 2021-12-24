### Transmission Modes in Computer Networks
![image](https://user-images.githubusercontent.com/51910127/147335915-c7de6e8f-f744-40df-9f32-dc81bf35b347.png)

- Simplex mode

![image](https://user-images.githubusercontent.com/51910127/147336059-187e6069-ded8-49a3-a598-1c131cebd99f.png)

```md
In Simplex mode, the communication is unidirectional, as on a one-way street. Only one of the two
devices on a link can transmit, the other can only receive. The simplex mode can use the entire
capacity of the channel to send data in one direction. 

Example: Keyboard and traditional monitors. The keyboard can only introduce input, the monitor
can only give the output. 
```

- Half Duplex Mode

![image](https://user-images.githubusercontent.com/51910127/147336190-852caaaf-c514-405b-b69c-22290d30b84f.png)

```md

In half-duplex mode, each station can both transmit and receive, but not at the same time.
When one device is sending, the other can only receive, and vice versa. The half-duplex mode 
is used in cases where there is no need for communication in both directions at the same time. 
The entire capacity of the channel can be utilized for each direction. 

Example: Walkie-talkie in which message is sent one at a time and messages are sent in both directions. 

Channel capacity=Bandwidth * Propagation Delay
```

- Full-Duplex Mode

![image](https://user-images.githubusercontent.com/51910127/147336325-ca54a2d9-49aa-4736-8d42-9c6d3dbae470.png)

```md

In full-duplex mode, both stations can transmit and receive simultaneously. In full_duplex mode, 
signals going in one direction share the capacity of the link with signals going in another direction,
this sharing can occur in two ways: 

Either the link must contain two physically separate transmission paths, one for sending and the 
other for receiving.
Or the capacity is divided between signals travelling in both directions. 
 
Full-duplex mode is used when communication in both directions is required all the time.
The capacity of the channel, however, must be divided between the two directions. 

Example: Telephone Network in which there is communication between two persons by a telephone line,
through which both can talk and listen at the same time. 

Channel Capacity=2* Bandwidth*propagation Delay
```
### 
|Synchronous Transmission  |Asynchronous Transmission |
|--------|----------------|
|In Synchronous transmission, Data is sent in form of blocks or frames.      | In asynchronous transmission, Data is sent in form of byte or character.          |
| Synchronous transmission is fast.      | Asynchronous transmission is slow.          |
|Synchronous transmission is costly.     |Asynchronous transmission is economical.         |
|In Synchronous transmission, time interval of transmission is constant.      | In asynchronous transmission, time interval of transmission is not constant, it is random.      |
| In Synchronous transmission, There is no gap present between data.     | In asynchronous transmission, There is present gap between data.          |
|Efficient use of transmission line is done in synchronous transmission.     | While in asynchronous transmission, transmission line remains empty during gap in character transmission.          |
| Synchronous transmission needs precisely synchronized clocks for the information of new bytes.     | Asynchronous transmission have no need of synchronized clocks as parity bit is used in this transmission for information of new bytes.          |

```md
Synchronous Transmission:

In Synchronous Transmission, data is sent in form of blocks or frames. This transmission is
the full duplex type. Between sender and receiver the synchronization is compulsory. In Synchronous
transmission, There is no gap present between data. It is more efficient and more reliable than
asynchronous transmission to transfer the large amount of data.

In Synchronous data transfer, the sending and receiving units are enabled with same clock signal.
It is possible between two units when each of them knows the behavior of the other. The master
performs a sequence of instructions for data transfer in a predefined order. All these actions
are synchronized with the common clock. The master is designed to supply the data at a time when
the slave is definitely ready for it. Usually, the master will introduce sufficient delay to take
into account the slow response of the slave, without any request from the slave. 

The master does not expect any acknowledgment signal from the slave when data is sent by the master
to the slave. Similarly, when data from the slave is read by the master, neither the slave informs 
that the data has been placed on the data bus nor the master acknowledges that the data has been read.
Both the master and slave perform their own task of transferring data at a designed clock period. Since
both devices know the behavior (response time) of each other, no difficulty arises. 
Prior to transferring data, the master must logically select the slave either by sending slave’s address
or sending “device select” signal to the slave. But there is no acknowledgment signal from the slave to
the master if the device is selected. 
```
![image](https://user-images.githubusercontent.com/51910127/147337643-a4c933ba-edba-475f-aebe-aea88f5c16ca.png)

```md
in this timing diagram, the master first places slave’s address in the address bus and read signal in the control
line at the falling edge of the clock. The entire read operation is over in one clock period. 

Advantages –  

The design procedure is easy. The master does not wait for any acknowledges signal from the slave,
though the master waits for a time equal to slave’s response time.
The slave does not generate an acknowledge signal, though it obeys the timing rules as per
the protocol set by the master or system designer. 
 
Disadvantages –  

If a slow speed unit connected to a common bus, it can degrade the overall rate of transfer in the system.
If the slave operates at a slow speed, the master will be idle for some time during data transfer and vice versa. 
```
