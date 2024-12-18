#include <stdio.h>
#include <stdbool.h>

// Define a structure to store the status of each light
typedef struct {
    bool red;      // Red light status (ON = 1, OFF = 0)
    bool green;    // Green light status (ON = 1, OFF = 0)
    bool orange;   // Orange light status (ON = 1, OFF = 0)
} TrafficLight;

// Function to display the current status of the traffic light
void displayStatus(TrafficLight light) {
    printf("Traffic Light Status:\n");
    printf("Red Light: %s\n", light.red ? "ON" : "OFF");
    printf("Green Light: %s\n", light.green ? "ON" : "OFF");
    printf("Orange Light: %s\n", light.orange ? "ON" : "OFF");
}

// Function to set the status of the traffic lights
void setStatus(TrafficLight *light, bool red, bool green, bool orange) {
    light->red = red;
    light->green = green;
    light->orange = orange;
}

int main() {
    // Initialize a traffic light with all lights OFF
    TrafficLight light = {false, false, false};

    // Set the initial state of the traffic light (e.g., Red light is ON)
    setStatus(&light, true, false, false);  // Red ON, Green and Orange OFF

    // Display the current status
    displayStatus(light);

    // Change the status of the lights (e.g., Green light ON)
    setStatus(&light, false, true, false);  // Green ON, Red and Orange OFF

    // Display the updated status
    displayStatus(light);

    // Change the status again (e.g., Orange light ON)
    setStatus(&light, false, false, true);  // Orange ON, Red and Green OFF

    // Display the updated status
    displayStatus(light);

    return 0;
}
