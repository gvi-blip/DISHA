Considering the fact that so many accidents are reported wherein the blind and visually impaired are involved, obviously, there is a lot of scope for improvement through innovation. The high cost of existing products is also an issue for the majority of users as a lot of them have limited employment and resources. Technology is meant for those who need it not those who can afford it. All the aforementioned facts motivated us to design a product that is cheap, pragmatic and can help prevent such accidents and save the lives of our users and other people involved in an accident.

Disha is a headwear device that warns the user if they are dangerously close to an object or a collision. It detects if the user has fallen and after confirming that they have, “Disha” notifies the emergency contacts the user has specified. It can also detect objects through their light emission enabling it to protect the user in darker environments. Since our product is meant to be worn whenever the user is outdoor (though the user can wear it in their house as well), the project had to be made comfortable for everyday use. Further in this chapter, what design initially had to be implemented and what the final product was including all the approaches that were thought of is discussed. The project has been named “Disha” as it means Direction in Hindi. The aspiration is to help as many blind people as possible through this project.

Assembly of Hardware and Components:

Initially, the attempt was to interface all modules with a single Arduino UNO board.

Ultrasonic, LDR, MPU 6050 modules and the Buzzer worked fine on a single Arduino UNO board. 

GPS & GSM modules worked fine when tested individually with Arduino UNO using Software Serial Libraries for both.
Using GPS & GSM together posed a problem. GPS coordinates were not being encoded correctly from NMEA sentences.

https://forum.arduino.cc/t/multiple-softwareserial-communication-issue/483766

The problem is discussed on this public forum. Using the Software Serial port for GPS and Serial Port for GSM worked fine.
After testing all the modules and interfacing them with the Arduino UNO, the GPS problem came up again. The coordinates were not being encoded correctly from NMEA sentences.

https://forum.arduino.cc/t/issues-with-softserial-altsoftserial-i2c-interrupts-anyone-know-anything-ab/324576/6

The problem is discussed on this public forum. The MPU 6050 uses I2C communication on pins 4&5 on Arduino UNO which causes problems while working with SoftwareSerial Library. After debugging, the solution was to use a second UNO board for GPS & GSM, using SoftwareSerial Library and Serial Port, respectively.

The next step was to determine the best way to make the two boards communicate. It was already established that:

•	I2C pins on the first board are being used by MPU 6050 so master-slave configuration between the two boards cannot be implemented.

•	I2C and Software Serial Library don’t work well together.

•	GSM occupies the serial port on the second board so serial communication cannot be used between the boards.

Considering these constraints, the simplest option was to use unused digital I/O pins on the boards in the form of interrupts. Digital I/O pins 11 on both boards are connected together. Pin 9 on one board is connected to Pin 13 on the board with GSM and GPS to send a fall alert.
 To reduce the size of components, Arduino UNO boards were replaced by Arduino NANO boards.
