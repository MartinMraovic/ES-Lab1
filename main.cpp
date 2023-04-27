#include "mbed.h"

// Define InterruptIn pins for Joystick
InterruptIn up(p15);
InterruptIn down(p12);
InterruptIn left(p13);
InterruptIn right(p16);
InterruptIn center(p14);

// Define callback functions for each direction
void up_pushed() {
    printf("Joystick pushed up\n");
}

void down_pushed() {
    printf("Joystick pushed down\n");
}

void left_pushed() {
    printf("Joystick pushed left\n");
}

void right_pushed() {
    printf("Joystick pushed right\n");
}

void center_pushed() {
    printf("Joystick pushed center\n");
}

int main() {
    // Attach interrupt handlers to each direction
    up.rise(&up_pushed);
    down.rise(&down_pushed);
    left.rise(&left_pushed);
    right.rise(&right_pushed);
    center.rise(&center_pushed);

     
}
