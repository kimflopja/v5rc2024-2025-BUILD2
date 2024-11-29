#pragma once

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

#include "api.h"

# if 0

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
    double integral = 0.0; // Integral term
    double derivative = 0.0; // Derivative Term

    // Turn
    double turnOutput = 0.0;
    double turnDifference = 0.0;
    double turnError = 0.0; // Error, Or rather PROPORTIONAL :3
    double turnPrev_error = 0.0; // Previous Error
    double turnIntegral = 0.0; // Integral term
    double turnDerivative = 0.0; // Derivative Term

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
        // Turn values
        turnError = 0.0;
        turnIntegral = 0.0; 
        turnDerivative = 0.0;

        // Reset prev_error
        prev_error = 0.0; 
        turnPrev_error = 0.0;
    }

    double get_PID_output(double setpoint, double sensor_value){
        // Calculate error. 
        // aka PROPORTIONAL.
        error = setpoint - sensor_value;
        // times by proportional gain constant

        // Calculate integral 
        integral += error;
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
        output = error*kP + integral*kI + derivative*kD;

        // Return 
        return output;

        //Wait
        pros::delay(10);
    }

    double get_turn_output(double turnSetpoint, double leftPosition, double rightPosition){
        // Calculate error. 
        // aka PROPORTIONAL.
        turnError = leftPosition - rightPosition;
        // times by proportional gain constant

        // Calculate integral 
        turnIntegral += turnError;
        // if error > helpful range,  I = 0
        // if error = 0, I = 0
        if (turnError > helpful_range){
            turnIntegral = 0;
        } else if (turnError = 0){
            turnIntegral = 0;
        }

        // Calculate derivative 
        turnDerivative = turnError - turnPrev_error; // Delta error
        
        // Update prev_error and prev_time
        turnPrev_error = turnError;

        // outut = P + I + D;
        turnOutput = turnError + turnIntegral + turnDerivative;

        // Return the PID output
        return turnOutput;

        //Wait
        pros::delay(10);
    }

};


#endif