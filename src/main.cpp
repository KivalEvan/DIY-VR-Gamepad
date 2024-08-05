#include <Arduino.h>
#include <BleGamepad.h>

#include "defines.hpp"

#define BTN_COUNT 4

uint8_t pinButtons[BTN_COUNT] = {PIN_A_BTN, PIN_B_BTN, PIN_MENU_BTN, PIN_JOY_BTN};
#if CONTROLLER_SIDE == RIGHT_HAND
// A, B, PS, Right Joystick
uint16_t gamepadButtons[BTN_COUNT] = {BUTTON_1, BUTTON_2, BUTTON_9, BUTTON_11};
#elif CONTROLLER_SIDE == LEFT_HAND
// X, Y, Start, Left Joystick
uint16_t gamepadButtons[BTN_COUNT] = {BUTTON_3, BUTTON_4, BUTTON_8, BUTTON_10};
#endif

#define DEADZONE_VALUE (int16_t)(2048.0 * JOY_DEADZONE)
#define DEADZONE_VALUE_MIN_N 2048 - DEADZONE_VALUE
#define DEADZONE_VALUE_MIN_P 2048 + DEADZONE_VALUE

uint16_t vrxJoystickLecture = 0;
uint16_t vryJoystickLecture = 0;

uint16_t vrxJoystickValue = 0;
uint16_t vryJoystickValue = 0;

BleGamepad bleGamepad(CONTROLLER_NAME, CONTROLLER_MANUFACTURER);
BleGamepadConfiguration bleGamepadConfig;

void setup() {
   Serial.begin(SERIAL_BAUD_RATE);

   for (uint8_t i = 0; i < BTN_COUNT; i++) {
      pinMode(pinButtons[i], INPUT_PULLUP);
   }

   bleGamepadConfig.setHatSwitchCount(0);
   bleGamepad.begin(&bleGamepadConfig);
}

void loop() {
   if (bleGamepad.isConnected()) {
      vrxJoystickLecture = analogRead(PIN_JOY_X);
      vryJoystickLecture = analogRead(PIN_JOY_Y);
      if (DEADZONE_VALUE_MIN_N < vrxJoystickLecture && vrxJoystickLecture < DEADZONE_VALUE_MIN_P) {
         vrxJoystickLecture = 2048; 
      }
      if (DEADZONE_VALUE_MIN_N < vryJoystickLecture && vryJoystickLecture < DEADZONE_VALUE_MIN_P) {
         vryJoystickLecture = 2048;
      }

      vrxJoystickValue = map(vrxJoystickLecture, 4095, 0, 0, 32737);
      vryJoystickValue = map(vryJoystickLecture, 0, 4095, 0, 32737);

      for (uint8_t i = 0; i < BTN_COUNT; i++) {
         if (!digitalRead(pinButtons[i])) {
            bleGamepad.press(gamepadButtons[i]);
         } else {
            bleGamepad.release(gamepadButtons[i]);
         }
      }
      
#if CONTROLLER_SIDE == RIGHT_HAND
         bleGamepad.setZ(vrxJoystickValue);
         bleGamepad.setRX(vryJoystickValue);
#elif CONTROLLER_SIDE == LEFT_HAND
         bleGamepad.setX(vrxJoystickValue);
         bleGamepad.setY(vryJoystickValue);
#endif
   }
}
