# Access Control System with Arduino

This repository contains the source code and documentation for an Access Control System implemented using an Arduino microcontroller board, a fingerprint sensor, an LCD display, a keypad, and an RFID sensor. The system is designed to provide secure access to a physical space by verifying the identity of the user through various authentication methods.

## Components

The following components are used in the access control system:

- Arduino microcontroller board (e.g., Arduino Uno)
- Fingerprint sensor (e.g., Adafruit Fingerprint Sensor)
- LCD display (e.g., 16x2 character LCD)
- Keypad (e.g., 4x4 matrix keypad)
- RFID sensor (e.g., RC522 RFID Reader)

## Functionality

The access control system provides the following functionalities:

1. Fingerprint Authentication: Users can authenticate themselves by placing their fingerprint on the fingerprint sensor. The system compares the captured fingerprint with the pre-registered fingerprints to grant access if a match is found.

2. PIN Authentication: Users can also authenticate themselves by entering a PIN using the keypad. The system verifies the entered PIN against the stored PINs to grant access if a match is found.

3. RFID Authentication: Users can authenticate themselves by scanning an RFID card/tag using the RFID sensor. The system compares the scanned RFID data with the stored RFID data to grant access if a match is found.

4. LCD Display: The LCD display provides visual feedback to the user during the authentication process. It displays relevant messages such as "Place your fingerprint," "Enter your PIN," or "Scan your RFID card."

5. Access Control: Upon successful authentication, the system can control an electronic lock or any other access mechanism to grant or deny access to the user.

## Getting Started

To set up the access control system, follow these steps:

1. Connect the Arduino board to your computer using a USB cable.
2. Connect the fingerprint sensor, LCD display, keypad, and RFID sensor to the appropriate pins on the Arduino board. Refer to the provided datasheets or examples for wiring instructions.
3. Install the Arduino IDE (Integrated Development Environment) if you haven't already.
4. Open the `access_control_system.ino` file in the Arduino IDE.
5. Make sure to install any required libraries for the fingerprint sensor, LCD display, keypad, and RFID sensor. You can find the necessary libraries and installation instructions in their respective documentation.
6. Select the appropriate Arduino board and port in the Arduino IDE.
7. Upload the `access_control_system.ino` sketch to the Arduino board.
8. Monitor the serial output in the Arduino IDE to view the system status and debugging information.

## Usage

Follow these instructions to use the access control system:

1. Power on the Arduino board.
2. The LCD display will show the initial message, prompting the user to choose an authentication method.
3. Select the desired authentication method by following the on-screen instructions.
4. Depending on the chosen method, follow the prompts to place a fingerprint, enter a PIN, or scan an RFID card.
5. The system will verify the provided information and display the result on the LCD display.
6. If the authentication is successful, the access control mechanism (e.g., electronic lock) will be triggered to grant access. Otherwise, access will be denied.

## Contributing

Contributions to this project are welcome. If you find any issues or have any suggestions for improvements, please submit an issue or a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

- This project was inspired by similar projects and tutorials available online.
- Thanks to the developers of the Arduino libraries used in this project for their excellent work.

## Contact

For any inquiries or questions, please contact [ahmedeldesoky284@gmail.com](ahmedeldesoky284@gmail.com). 
