#pragma once

#include "consts.hpp"

#define CONTROLLER_SIDE RIGHT_HAND

#define JOY_FLIP_X false
#define JOY_FLIP_Y false
#define JOY_DEADZONE 0.2 // 0-1

#define PIN_JOY_X 34
#define PIN_JOY_Y 35
#define PIN_JOY_BTN 32
#define PIN_A_BTN 33
#define PIN_B_BTN 25
#define PIN_MENU_BTN 26

#if CONTROLLER_SIDE == RIGHT_HAND
#define CONTROLLER_NAME CONTROLLER_NAME_RIGHT_HAND
#elif CONTROLLER_SIDE == LEFT_HAND
#define CONTROLLER_NAME CONTROLLER_NAME_LEFT_HAND
#endif