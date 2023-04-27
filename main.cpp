#include "mbed.h"

// Define InterruptIn pins for Joystick
InterruptIn up(p15);
InterruptIn down(p12);
InterruptIn left(p13);
InterruptIn right(p16);
InterruptIn center(p14);

// Define callback functions for each direction
void up_pushed() {
    wait_ms(50); // Debounce delay
    if (up.read() == 1) {
        printf("Joystick pushed up\n");
    }
}

void down_pushed() {
    wait_ms(50); // Debounce delay
    if (down.read() == 1) {
        printf("Joystick pushed down\n");
    }
}

void left_pushed() {
    wait_ms(50); // Debounce delay
    if (left.read() == 1) {
        printf("Joystick pushed left\n");
    }
}

void right_pushed() {
    wait_ms(50); // Debounce delay
    if (right.read() == 1) {
        printf("Joystick pushed right\n");
    }
}

void center_pushed() {
    wait_ms(50); // Debounce delay
    if (center.read() == 1) {
        printf("Joystick pushed center\n");
    }
}

int main() {
    // Attach interrupt handlers to each direction
    up.rise(&up_pushed);
    down.rise(&down_pushed);
    left.rise(&left_pushed);
    right.rise(&right_pushed);
    center.rise(&center_pushed);

}