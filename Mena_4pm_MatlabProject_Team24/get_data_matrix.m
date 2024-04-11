% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24
% inputting your own 2x4 matrix data
function [x, y] = get_data_matrix ()

%have user assign values for variables
    a = input('row 1 col 1: ');
    b = input('row 1, col 2: ');
    c = input('row 1, col 3: ');
    d = input('row 1, col 4: ');
    e = input('row 2, col 1: ');
    f = input('row 2, col 2: ');
    g = input('row 2, col 3: ');
    h = input('row 2, col 4: ');

    %compact variables into matrix
    data = [a, b, c, d; e, f, g, h];
    
    %assigning x and y
    x = data(1,:);
    y = data(2, :);
end