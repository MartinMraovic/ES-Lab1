#include "mbed.h"

// It is possible to see multiple lines printed even when the Joystick is pressed once. This can happen if the Joystick input signal is noisy or if the button bounces when it is pushed, causing multiple interrupts to be triggered. Each interrupt will call its corresponding callback function and print a message to the console, resulting in multiple lines of output.

// One software solution to this problem is to implement a debouncing in the callback functions. Debouncing is the process of removing noise or glitches from a signal by filtering or delaying the signal for a specified time. In the case of a Joystick button, we can add a short delay to the callback function to ensure that the button has settled before processing the input.

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