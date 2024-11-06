#pragma once

#include "drive/drive.hpp"

void resetPIDValues();
void drive_test(int drive, int rotate);
void turn_test();
void drive_and_turn();
void wait_until_change_speed();
void swing_example();
void motion_chaining();
void combining_movements();
void interfered_example();

void closeSide();
void farSide();