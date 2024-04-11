% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function [words,mult]=Trig(trig_func)
    %trig_func=menu('What is your trig function?','sin(x)','cos(x)','tan(x)','csc(x)','sec(x)','cot(x)');
    
    % tells the program what the function is in words it will understand
    

    % takes the derivative of the function
    if trig_func(1:3)=='sin'
        words='cos(';
        mult=1;
    elseif trig_func(1:3)=='cos'
        words='sin(';
        mult=-1;
    elseif trig_func(1:3)=='tan'
        words='sec^2(';
        mult=1;
    elseif trig_func(1:3)=='sec'
        words='csc( cot(';
        mult=-1;
    elseif trig_func(1:3)=='csc'
        words='tan( sec(';
        mult=1;
    elseif trig_func(1:3)=='cot'
        words='csc^2(';
        mult=-1;
    end

end