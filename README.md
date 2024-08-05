# DIY VR Gamepad

Personal project to create VR gamepad (not to be confused with 6DoF controller) that can fit just above the finger with the mainboard being on either backhand or wrist.
Reason for the project is wanting to have reliable and responsive control than using hand gesture while using hand-tracking mode.
Also for immersion, better than grabbing controller and dropping them "safely" just to do specific things, which happens very often.
This project is similar towards [LucidGloves](https://github.com/LucidVR/lucidgloves) minus the tracking part, only the controller.

The project utilise [BLE Gamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad) and [Steam Input](https://partner.steamgames.com/doc/features/steam_controller), compatibility is not known but if the games support Steam Input, it likely can work.

## Known Issue

-  Steam Input only works on active window (known issue with Steam Input in general)

## Planned

As if it will ever happen xdd

* [ ] Better casing
* [ ] Better schematic
* [ ] OpenVR driver
* [ ] Rumble
* [ ] IMU fallback
* [ ] WiFi support
* [ ] Quest support?
