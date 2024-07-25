# Arduino Mega & NEO-6M GPS module

- Serial monitor used for troubleshooting purpose.
- Serial port 3 is used to communicate with GPS module.

- Arduino Mega will check for the GPS output every 2 seconds. If the data output failed, it will continously checking the Serial port 3.

The output message includes:
- Latitude
- Longitude
- Altitude
- Speed
- Number of connected satellites
