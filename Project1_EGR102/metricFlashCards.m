%{
Metric Flash Cards - A way for students to study metric prefixes
Author: Andres Aguirre
Assignment: EGR 102-012 Week 11 Metric Flash Cards
Changed:    1 November 2022
History:    1 November 2022 - Created most of the program
            2 November 2022 - Final edits
Purpose: This code uses a variety of arrays to help draw data from
an excel table that contains information over metric prefixes. Using this
it than creates a review game to help people study their metric prefixes.
The user can input however many prefixes it wants to review and then they
are tested on their knowledge.
%}

% Pull data from the given Excel Sheet into a Table object.
metricTable = readtable("metricPrefixes.xlsx");

% Create two separate string arrays for the names and abbreviations of the
% prefixes, and a numeric array for their exponents.
prefixNames = string(metricTable.prefix);
prefixAbbreviations = string(metricTable.abbreviation);
prefixExponents = double(metricTable.exponent);

% Display the logo.
disp("//----------------------\\");
disp("||  METRIC FLASH CARDS  ||");
disp("\\----------------------//");

% Request the user to input how many prefixes they will review.
reviewNumber = input("How many prefixes would you like to review?: ");
reviewCount = reviewNumber;
i = 1;
rowArray = [];
numCorrectAbbrev = 0;
numCorrectExponent = 0;

% Repeat the following steps for the number of prefixes requested:
while(reviewCount > 0)
    % Using the length of one of the arrays, generate a random integer that
    % will represent the row number of a random prefix from the spreadsheet.
    rowNumber = randi(length(prefixNames));

    % Find the name, abbreviation, and exponent of the prefix and store all
    % three as variables.
    correctAbbreviation = prefixAbbreviations(rowNumber);
    correctExponent = prefixExponents(rowNumber);
    prefixName = prefixNames(rowNumber);

    % Store the row number of the prefix in an array for later use when
    % generating the summary.
    rowArray(i) = rowNumber;
    i = i + 1;

    % Report the prefix’s name to the user.
    fprintf("The metric prefix is: %s \n", prefixName);

    % Prompt the user to input the abbreviation of the prefix.
    abbreviationGuess = input("What is the abbreviation? ", "s");

    % If the input is correct, display a message of congratulations.
    if (abbreviationGuess == correctAbbreviation)
        disp("Abbreviation is correct!");
        numCorrectAbbrev = numCorrectAbbrev + 1;

        % If the input is incorrect, display the correct answer.
    else
        fprintf("The correct abbreviation is: %s \n", correctAbbreviation);
    end

    % Prompt the user to input the exponent of the prefix.
    exponentGuess = input("What is the exponent? ");

    % If the input is correct, display a message of congratulations.
    if (exponentGuess == correctExponent)
        disp("Exponent is correct!");
        fprintf("\n");
        numCorrectExponent = numCorrectExponent + 1;

        % If the input is incorrect, display the correct answer.
    else
        fprintf("The correct exponent is: %.0f \n", correctExponent);
        fprintf("\n");
    end

    % Pause the script for .5 seconds to give the student a short break,
    % then print a blank line.
    pause(0.5);

    reviewCount = reviewCount - 1;
end

% Determine whether or not the user has reviewed any prefixes.
% If not, display a message
if(reviewNumber <= 0)
    disp("No prefixes were reviewed.");

    % Otherwise, display a score report
    % Display the start of the "SESSION REVIEW"
else
    disp("//-------------------------------------------\\");
    disp("|| SESSION REVIEW                            ||");
    disp("||-------------------------------------------||");

    % Display the total number of prefixes reviewed.
    fprintf("|| Number of Prefixes Reviewed:  %2.0f          || \n", reviewNumber);

    % Display the total number and percentage of abbreviations which
    % the student inputted correctly.
    percentAbbreviations = (numCorrectAbbrev / reviewNumber) * 100;
    fprintf("|| Correct Abbreviations:        %2.0f (%5.1f%%) || \n", numCorrectAbbrev, percentAbbreviations);

    % Display the total number and percentage of exponents which the
    % student inputted correctly.
    percentExponents = (numCorrectExponent / reviewNumber) * 100;
    fprintf("|| Correct Exponents:            %2.0f (%5.1f%%) || \n", numCorrectExponent, percentExponents);

    % Uniformly display the name, abbreviation, and exponent of each
    % reviewed prefix.
    disp("||-------------------------------------------||");
    disp("|| REVIEWED PREFIXES                         ||");
    disp("||-------------------------------------------||");

    for(j = 1:length(rowArray))
        fprintf("|| %-5s %-2s  10^%-3.0f                          || \n", prefixNames(rowArray(j)), prefixAbbreviations(rowArray(j)), prefixExponents(rowArray(j)));
    end

    % End the Session Review with a closing line for the block, as
    % displayed in the example.
    disp("\\-------------------------------------------//");
    fprintf("\n");

end

% Display a message of thanks and end the program.
disp("Thank you for using Metric Flash Cards!");
