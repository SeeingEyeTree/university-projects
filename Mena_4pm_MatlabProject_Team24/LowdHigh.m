% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function re=LowdHigh(high,low)
    %decompose the functions
    high_list=decompose(high);
    low_list=decompose(low);
    % takes derivative of top and bottom
    dhigh=OneLine(high_list);
    dlow=OneLine(low_list);
    
    % puts the derivatives in the correct form for the rule
    re=['((',low,')*(',dhigh,')-(',high,')*(',dlow,'))/(',low,')^2'];
end