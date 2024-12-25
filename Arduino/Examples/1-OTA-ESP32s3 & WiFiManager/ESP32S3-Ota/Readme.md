# ESP32-S3 OTA Example

This repository demonstrates how to enable Over-The-Air (OTA) updates on the ESP32-S3 R8N16 module. The example provides robust Wi-Fi configuration options and integrates the `ArduinoOTA` library for seamless firmware updates without requiring physical access to the device.

## Features

- **OTA Updates**:
  - Remote firmware updates via Wi-Fi using the `ArduinoOTA` library.
  - Secure updates with a configurable hostname and password.
  - Real-time progress tracking displayed on the serial monitor.
  - Error handling for OTA issues (e.g., authentication failure, file write errors).

- **Wi-Fi Configuration Options**:
  - **Fixed Credentials**: Connects directly to a predefined network.
  - **Access Point Mode**: Enables manual Wi-Fi configuration if no network is set.

- **Customizable Behavior**:
  - Easily toggle between blocking and non-blocking modes for OTA handling.
  - Modular design for adaptability to various IoT projects.

## Code Structure

### OTA Functionality
The OTA system is activated by enabling the `OTA_Enable` definition in the code:
```cpp
#define OTA_Enable enable
```
When enabled:
- Hostname is set to `OTAESP32`.
- Password is set to `pass` (changeable in the code).
- OTA update progress and errors are logged via the serial monitor.

### Wi-Fi Setup
There are two configuration options for Wi-Fi connectivity:
1. **Fixed SSID and Password**:
   Uncomment the following lines in the code and replace with your credentials:
   ```cpp
   #define wifi_pass "your_wifi_password"
   #define wifi_ssid "your_wifi_ssid"
   ```

2. **Access Point Mode**:
   By default, the ESP32 uses `WiFiManager` to start in AP mode if no fixed credentials are provided. Users can manually select a network via the ESP32's access point.

### Error Handling
The following OTA events are handled:
- **Start**: Logs when the update begins.
- **Progress**: Displays update progress as a percentage.
- **End**: Logs when the update finishes.
- **Error**: Logs specific OTA errors.

### Blocking and Non-Blocking Modes
The code supports non-blocking mode for handling OTA updates while maintaining responsiveness in the main loop. Set `wm_nonblocking` to `true` to enable non-blocking mode.

## How to Use

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Ali-khajavi/ESP32S3.git
   ```

2. **Install Required Libraries**:
   - [ArduinoOTA](https://github.com/esp8266/Arduino)
   - [WiFiManager](https://github.com/tzapu/WiFiManager)

3. **Edit Configuration**:
   - Uncomment and modify the Wi-Fi credentials if using the fixed SSID/password option.
   - Update the OTA hostname and password in the code as needed.
   - Upload the code using Arduino IDE

4. **Test OTA Updates**:
   - Use an OTA-compatible tool (e.g., Arduino IDE) to send firmware updates wirelessly.
   - Monitor the serial output for progress and debugging.

## Requirements

### Hardware
- ESP32-S3 R8N16 module or a compatible ESP32-S3 development board.
- Wi-Fi network for connectivity.

### Software
- Arduino IDE.
- Required libraries as mentioned above.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Happy coding and enjoy building your OTA-enabled IoT projects with the ESP32-S3!
