% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function re=PowerRule(non_dc_func)

    cof_spot='null';
    exp_spot='null';
    for i=1:length(non_dc_func)
        %finds what index is the mult
        if non_dc_func(i)=='*'
            cof_spot=i;
            %disp(i)
        elseif non_dc_func(i)=='^'
            exp_spot=i;
            %disp(i)
        end
    
    end
    % starts at the beginning to get the coefficient and goes till the * to
    % get the value of the first term
    coefficient=str2num(non_dc_func(1:(cof_spot-1)));
    
    % goes from ^ to end to find the value of the exponent
    exponet=str2num(non_dc_func((cof_spot+3):length(non_dc_func)));
    power=exponet-1;
    co_new=exponet*coefficient;
    if power >1 || power<0
        re=[num2str(co_new),'x^',num2str(power)];
    elseif power==1
        re=[num2str(co_new),'x'];
    elseif power==0
        re=[num2str(co_new)];
    end
    %disp(coefficient)
    if co_new==0
        re='0';
    end

end