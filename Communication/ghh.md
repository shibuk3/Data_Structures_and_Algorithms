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
