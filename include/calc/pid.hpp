#pragma once

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

#include "api.h"

/*
* A class implementing PID
*/
class PID{ 
    public:

    /*
    * Variables
    */
    double output = 0.0; // PID Output
    double error = 0.0; // Error, Or rather PROPORTIONAL :3
    double prev_error = 0.0; // Previous Error
    double target = 0.0; // Target point (?) Not sure if will use.
    double integral = 0.0; // Integral term
    double derivative = 0.0; // Derivative Term

    /*
    * Constants to be set!!! 1 is a placeholder
    */
    double kP = 1;
    double kI = 1;
    double kD = 1;
    double helpful_range = 1000;

    

    void reset_PID(){
        
        // Reset PID values
        error = 0.0;
        integral = 0.0; 
        derivative = 0.0;

        // Reset prev_error
        prev_error = 0.0; 
    }

    double get_PID_output(double setpoint, double sensor_value){
        // Calculate error. 
        // error = setpoint - current sensor value
        // aka PROPORTIONAL.
        error = sensor_value - setpoint;
        // times by proportional gain constant
        error = error*kP;

        // Calculate integral 
        integral += error * kI;
        // if error > helpful range,  I = 0
        // if error = 0, I = 0
        if (error > helpful_range){
            integral = 0;
        } else if (error = 0){
            integral = 0;
        }

        // Calculate derivative 
        derivative = error - prev_error; // Delta error
        
        // Update prev_error and prev_time
        prev_error = error;

        // outut = P + I + D;
        output = error + integral + derivative;

        // Return (plug output value into arcade drive function to get it to move)
        return output;
        
        //Wait
        pros::delay(10);
    }

};

