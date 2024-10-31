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
    long ts = 0; // Unit of time
    long prev_time = 0; // Previous time
    double output = 0.0; // PID Output
    double error = 0.0; // Error, Or rather PROPORTIONAL :3
    double prev_error = 0.0; // Previous Error
    double target = 0.0; // Target point (?) Not sure if will use.
    double integral = 0.0; // Integral term
    double derivative = 0.0; // Derivative Term

    /*
    * Constants to be set!!!
    */
    double kP;
    double kI;
    double kD;
    double helpful_range = 1000;

    

    void reset_PID(){
        
        // Reset PID values
        error = 0.0;
        integral = 0.0; 
        derivative = 0.0;

        // Reset prev_time and prev_error
        prev_time = 0;
        prev_error = 0; 
    }

    double get_PID_output(double setpoint, double sensor_value){

        double delta_time;
        double delta_error;

        // Calculate error. 
        // error = setpoint - current sensor value
        // aka PROPORTIONAL.
        error = setpoint - sensor_value;
        // times by proportional gain constant
        error = error*kP;

        // Get the current time
        // Change in time
        delta_time = ts - prev_time;
        //Change in error
        delta_error = error - prev_error;

        // Calculate integral 
        integral += error * delta_time * kI;
        // if error > helpful range,  I = 0
        // if error = 0, I = 0
        if(error > helpful_range){
            integral = 0;
        } else if (error = 0){
            integral = 0;
        }

        // Calculate derivative 
        if(delta_time>0){ // To ensure that no undefined value comes from delta_error being divided by 0
            derivative = delta_error / delta_time;
        }
        
        // Update prev_error and prev_time
        prev_error = error;
        prev_time = ts;

        // outut = P + I + D;
        output = error + integral + derivative;

        // Return (plug output value into arcade drive function to get it to move)
        return output;
        
        //Wait
        pros::delay(10);
    }

};

