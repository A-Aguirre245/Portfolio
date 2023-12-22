%{
MiniProjectCollectData - Collect data to train a material sorter

Authors: Neil Moore
Assignment: EGR 102 Mini-Project, Fall 2020
Date: 2020-10-19

Purpose:  This program collects data from illuminating three different
  materials with three different colors of light and measuring the
  reflected light with a photoresistor.  Each set of measurements is taken
  five times, and the resulting data is written to a spreadsheet
  MiniProjectData.xlsx.  See the comment on the "readings" array for the
  structure of the generated spreadsheet.  This spreadsheet will be used
  for training a machine-learning algorithm to produce a decision tree.

Notes:  This code assumes your photoresistor is in a voltage divider
  connected to pin A0 of the Arduino; and that the three LEDs are
  connected to pins D9, D10, and D11.  You should also modify the
  array "materials" to contain the names of the three materials you
  are measuring.  Search this file for the word TODO to find the
  code that needs to be changed.

  This is NOT the final program that will drive your material sorter
  and that will be listed in your report.  Instead, this program is used
  to collect data for training a machine-learning algorithm.

  You might use parts of this code in your final program, but that
  should be in a separate script file.  If you do use any of this code,
  you should credit this file and its author in the "Notes" section of
  your header comment.
%}

clear
a = arduino();

% Turn off all three LEDs.  TODO: change this to match your pins
writeDigitalPin(a, 'D5', 0);
writeDigitalPin(a, 'D6', 0);
writeDigitalPin(a, 'D7', 0);

% TODO: name the three materials you will measure
materials = [ "wooden desk", "blank paper", "red plastic" ];

% Create matrix
% Rows are single tests of a single material:
%    rows 1 through 5:   first material
%    rows 6 through 10:  second material
%    rows 11 through 15: third material
% Columns are measurements:
%    1. material number  2. red reading  3. green reading  4. white reading
readings = zeros(15, 4);

% Perform the experiment five times.
for replicate = 1 : 5
    % Test three different materials per experiment.
    fprintf("Beginning replicate %d\n", replicate);
    
    for material = 1 : 3
        % Row number in the array.  This puts replicate 1 in rows
        % 1, 6, 11; replicate 2 in rows 2, 7, 12; and so on.
        % The first 5 rows will be material 1, the next 5 material 2,
        % and the last 5 material 3.
        row = replicate + (material - 1) * 5;
        
        fprintf("Insert material %s ", materials(material));
        input("and press enter", 's'); % The actual input is ignored
        
        % Put the material number (1, 2, or 3) into column 1
        readings(row, 1) = material;
        
        % Illuminate the material three times and measure the reflected
        % light each time:
        
        % First with the red LED into column 2.  TODO: change for your pin
        writeDigitalPin(a, 'D5', 1); % on
        pause(0.1);
        readings(row, 2) = readVoltage(a, 'A0');
        pause(0.1);
        writeDigitalPin(a, 'D5', 0); % off
        pause(0.1);
        
        % Then with the green LED into column 3.  TODO: change for your pin
        writeDigitalPin(a, 'D6', 1); % on
        pause(0.1);
        readings(row, 3) = readVoltage(a, 'A0');
        pause(0.1);
        writeDigitalPin(a, 'D6', 0); % off
        pause(0.1);
        
        % Then with the white LED into column 4.  TODO: change for your pin
        writeDigitalPin(a, 'D7', 1); % on
        pause(0.1);
        readings(row, 4) = readVoltage(a, 'A0');
        pause(0.1);
        writeDigitalPin(a, 'D7', 0); % off
        pause(0.1);
    end
    fprintf("Completed replicate %d\n\n", replicate);
end

disp("Sensor measurements have been collected in the array 'readings'");

% Write the spreadsheet file
% xlswrite("MiniProjectData.xlsx", readings);
writematrix(readings, "MiniProjectData.xlsx"); % CHANGED
disp("Spreadsheet MiniProjectData.xlsx created");

% TODO: If xlsread doesn't work for you, comment out the above two lines
%   and uncomment the following two lines instead:

% csvwrite("MiniProjectData.csv", readings);
% disp("Spreadsheet MiniProjectData.csv created");