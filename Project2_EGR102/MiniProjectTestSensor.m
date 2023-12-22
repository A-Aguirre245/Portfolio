% This code was written so that you can test individual pieces of your MiniProject Sensor (material classifier) Fall 2021.
% code written by Julie Whitney 11/15/2021

% Note this code is meant to be copied and pasted to the command line to check out any particular
% part of the sensor you want to test.

% Start by connecting to the arduino
clear all

a = arduino() %only needed if arduino not connected

% TEST THE LEDs and the PHOTORESISTOR

%  ********************************************************************
    %COPY AND PASTE this section of the code to the command line to test
    %RED
        writeDigitalPin(a,'D5',1);
        pause(2);
         REDread = readVoltage(a,'A0');
       % pause (2); %Makes sure the LED is on 
       writeDigitalPin(a,'D5',0);
       fprintf('The RED LED measured %.2f. \n', REDread);
       
 
       % **************************************************************
       % COPY AND PASTE this to the command line to test the GREEN
       
        writeDigitalPin(a,'D6',1);
        pause(2);
        GREENread = readVoltage(a,'A0'); %read from arduino
        %pause (2); %slows down read speed
        writeDigitalPin(a,'D6',0);
        fprintf('The GREEN LED measured %.2f. \n', GREENread);
        
     % ******************************************************************   
        %COPY AND PASTE this to the command line to test the BLUE
        writeDigitalPin(a,'D7',1);
        pause(2);
        BLUEread = readVoltage(a,'A0'); %read from arduino
        %pause (1); %slows down read speed
        writeDigitalPin(a,'D7',0);
        fprintf('The BLUE LED measured %.2f. \n', BLUEread);
        
        
