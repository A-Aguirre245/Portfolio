%{
Mini Project - Uses various ideas learned in EGR 102 to create one 
final project
Author: Andres Aguirre
Assignment: EGR 102-012 Week 15 Mini Project
Changed:    1 December 2022
History:    16 November 2022 - Initial version
            1 December 2022 - Final edits
Purpose: This code uses many of the skills learned in EGR 102 to create a
final code that brings together the content learned in the class. By using
a photoresistor and a LED circuit, the code measures the reflected light of
a certain material, which well then be ran through a series of if
statements. Finally, the code will then move the position of a  servo motor 
to demonstrate what material it is sensing. 
%}

clear;
a = arduino();

% Connect to servo
s1 = servo(a, 'D9', 'MinPulseDuration', 700*10^-6, 'MaxPulseDuration', 2300*10^-6)
writePosition(s1, 1);
count = 1;

% Create a while loop and prompt user to insert material
while(count > 0)
    disp("Enter the material under the sensor");
    count = input("Type 1 when ready: ");
    pause(1);

    % Measure under red light
    writeDigitalPin(a, 'D5', 1); % on
    pause(0.1);
    red = readVoltage(a, 'A0');
    pause(0.1);
    writeDigitalPin(a, 'D5', 0); % off
    pause(0.1);

    % Measure under green light
    writeDigitalPin(a, 'D6', 1); % on
    pause(0.1);
    green = readVoltage(a, 'A0');
    pause(0.1);
    writeDigitalPin(a, 'D6', 0); % off
    pause(0.1);

    % Measure under blue light
    writeDigitalPin(a, 'D7', 1); % on
    pause(0.1);
    blue = readVoltage(a, 'A0');
    pause(0.1);
    writeDigitalPin(a, 'D7', 0); % off
    pause(0.1);

    if (red < 3.99804)
        disp("wooden desk");
        writePosition(s1, 0);
    elseif (red < 4.2522)
        disp("red plastic");
        writePosition(s1, 0.5);
    else
        disp("blank paper");
        writePosition(s1, 1);
    end

    % Prompt user if they would like to continue or stop
    count = input("Press 1 to continue, or 0 to end the code: ");
end