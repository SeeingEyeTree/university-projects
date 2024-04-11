% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function f_list=decompose(non_dc_func)
    break_spots=[0];
    f_list={};
    start=1;
    %skips the first character if it is a minus sign so that it does not
    %create a cell for nothing
    if non_dc_func(1)=='-'
        start=2;
    end
    
    for i=start:length(non_dc_func)
        if non_dc_func(i)=='+' || non_dc_func(i)=='-'
            break_spots=[break_spots,(i)];
            %disp(i)
        end

    end
    %catches all of the characters between the + or - symbol
    for i=2:length(break_spots)
        f_list{end+1}={non_dc_func((break_spots(i-1)+1):(break_spots(i)-1))};
    end
    % adds the last one since the for loop index would go over
    f_list{end+1}={non_dc_func((break_spots(length(break_spots))+1:length(non_dc_func)))};


end