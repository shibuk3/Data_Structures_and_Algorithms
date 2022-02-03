### __SPI__
```md
What is SPI?

The Serial Peripheral Interface (SPI) protocol is another popular synchronous
serial communication protocol in embedded designs. SPI communication involves one
or more master devices and one or more slave devices using a shared bus. Full duplex 
or 4-wire SPI uses two data lines, a shared clock line, and a slave select line. Half
duplex or 3-wire SPI uses a shared data line.
```

__Pin Descriptions__

- MISO: Master In, Slave Out - Data is shifted out from the slave and into the master on this line.
- MOSI: Master Out, Slave In - Data is shifted out from the master and into the slave on this line.
- SCLK: Clock - The clock is always driven by the master. The clock starts as soon as data is loaded 
into the master’s transmitter and stops when the last bit is shifted out.

- SS: Slave Select - A dedicated slave select (or chip select) line is used to address different
slave devices. A slave will only receive data if its SS pin is asserted (active low).

__Pros:__

- Low overhead - SPI protocol uses dedicated slave select lines for each slave device. 
This eliminates the need for sending addresses over the data lines and decreases overhead.

- Reliable - The dedicated clock line eliminates baud mismatches that are common in asynchronous protocols (like UART).

- Fast - Dual data lines increase the overall throughput and the low overhead increases overall bps.

- Shared bus - The dedicated slave select lines allow multiple devices to share the same data/clock 
lines. If the device’s SS line is not enabled, the device will simply ignore data.

__Cons:__

- High pin count - Compared to other common serial communication protocols, SPI uses quite a few pins.
An extra pin (SS) is required for every slave device and master device for multi-master setups.

- Error checking - No default CRC checking or bus contention indication

- Transmission Initiation - The master must initiate all transmissions. If a slave has data
to send to the master, it must wait for the master to start transmission, or use
external signals to interrupt the master.
