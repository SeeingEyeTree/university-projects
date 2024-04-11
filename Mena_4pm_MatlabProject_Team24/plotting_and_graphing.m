% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24
function []= plotting_and_graphing()

    % input own data or from a file
    data_type = menu('Would you like to input your own 2x4 matrix or a data file?', 'my own 2x4 matrix', 'data file **data must have either 2 rows or 2 columns**');
    switch data_type
        case 1 % inputting own data
            % get data FUNCTION
            [x, y] = get_data_matrix ();
    
            % plotting line of best fit with original points
            best_fit(x, y)
        case 2 % load data file
            % getting data file and loading FUNCTION
            [x, y] = input_load_data ();
    
            % plotting x and y FUNCTION
            x_y_plot(x, y);
    end
end