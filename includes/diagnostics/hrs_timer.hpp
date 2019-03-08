#ifndef HRSTimer_HPP_
#define HRSTimer_HPP_

/*
    C Includes.
*/


/*
    C++ Includes.
*/
#include <iostream>
#include <chrono>

/*
    Project Includes.
*/

/*
    Diagnostics tool for timing source code execution time, using the 
    high resolution clock.
*/
class HRSTimer {

private:

    // CONSTANTS


    // DATAFIELDS
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point finish;

    double d_avg;
    int i_avg;   
    int counter; 

    // OVERRIDE-ABLE METHODS


	// METHODS


    // GETTERS


    // SETTERS


public:

    // CONSTRUCTORS
    HRSTimer();
    HRSTimer(int max_ct);

    // DESTRUCTORS
    ~HRSTimer();

   	// OVERRIDE-ABLE METHODS


	// METHODS
    void init();
    void end();
    void print_nano();
    void print_nano(std::string prefix_msg);
    void print_micro();
    void print_micro(std::string prefix_msg);
    void print_milli();
    void print_milli(std::string prefix_msg);
    void print_secs();
    void print_secs(std::string prefix_msg);

    // GETTERS


    // SETTERS

};

#endif