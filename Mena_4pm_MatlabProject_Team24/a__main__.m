% Megan Baker, Sarah Ginck, Dennis Ephraim --> Team 24
%What our program does: Our graphing calculator program can generate matrices, 
%intake polynomials and functions, and complete various forms of analysis
%on them. This list includes derivatives, statistical analysis, and plotting.

clc
clear

disp('Welcome to Texas Instruments TI-84');

% displaying image
pic=imread("ti84_load.png"); 
imshow(pic) 
%pause pic 
pause(3)

%ask user which operation they want
what_do=menu('What operation do you want to execute?','Take a derivative','Matrix operations','Graphing');
    switch what_do
        case 1
            %call derivative function
            TakeDerivativeMAIN()
    
        case 2
            %call matrix function
            matrix_ops()
    
        case 3
            %call plotting function
            plotting_and_graphing()
    end

%thank user for using program
disp('Thank you for using our TI-84 Calculator. Run program again to perform another operation.');