% Train a decision tree classifier for
% the mini-projcet

% Load the spreadsheet
allData = readmatrix("MiniProjectData.xlsx");
% Extract the features (training data)
train = allData(:, 2:4);
% Create answers for supervised learning
results = strings(15,1);
results(1:5) = "wooden desk";
results(6:10) = "blank paper";
results(11:15) = "red plastic";

% Create and view th decision tree model
model = fitctree(train, results);
view(model, "mode", "graph");