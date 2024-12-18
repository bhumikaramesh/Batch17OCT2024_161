#include <stdio.h>

typedef struct {
    unsigned int red:1;
    unsigned int green:1;
    unsigned int orange:1;   
} TrafficLight;


void printTrafficLightStatus(TrafficLight tl) {
    printf("Traffic Light Status:\n");
    printf("Red: %s\n", tl.red ? "On" : "Off");
    printf("Green: %s\n", tl.green ? "On" : "Off");
    printf("Orange: %s\n", tl.orange ? "On" : "Off");
}

int main() {
    TrafficLight tl = {1, 0, 1};  

    printTrafficLightStatus(tl);

    tl.green = 1;  
    tl.red = 0;    

    printf("\nUpdated Traffic Light Status:\n");
    printTrafficLightStatus(tl);

    return 0;
}

