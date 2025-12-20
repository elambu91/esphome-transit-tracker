# ESPHome Transit Tracker Component

This is an ESPHome custom component for the [Transit Tracker](https://transit-tracker.eastsideurbanism.org/) project with Hebrew language and Right-to-Left (RTL) text display support.

## About This Component

This ESPHome component adds:
- **RTL (Right-to-Left) text rendering** - Proper text direction for Hebrew and other RTL languages
- **Hebrew status messages** - All system messages translated to Hebrew
- **Enhanced text handling** - Improved string processing for Hebrew characters

This component is automatically used by the firmware - **you don't need to use this repository directly**. It's referenced in the firmware configuration and downloaded during the build process.

## Related Projects

### Transit Tracker Firmware
**Repository:** [elambu91/transit-tracker](https://github.com/elambu91/transit-tracker)

Start here to build your Transit Tracker! This repository contains the firmware configuration and build system for flashing your ESP32 device with Hebrew support.

### Israeli Bus API Server
**Repository:** [elambu91/israeli-bus](https://github.com/elambu91/israeli-bus)

Backend server that provides real-time Israeli bus schedule data. Required if you want to display Israeli bus arrivals.

## Building Your Own Transit Tracker

Visit the [Transit Tracker build guide](https://transit-tracker.eastsideurbanism.org/) for the complete parts list. You'll need:
- ESP32-S3 development board
- HUB75 LED matrix panels (64x32 or 64x64)
- Power supply (5V, 4A minimum)
- Enclosure (optional, 3D printable files available)

Then head to the [Transit Tracker Firmware repository](https://github.com/elambu91/transit-tracker) to flash your device.

## Credits

- **Original Transit Tracker:** [Eastside Urbanism](https://transit-tracker.eastsideurbanism.org/)
- **Hebrew/RTL Support:** This component
