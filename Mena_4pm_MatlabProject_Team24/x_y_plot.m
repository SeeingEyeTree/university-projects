% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24
% plotting x and y function
function [] = x_y_plot(x, y)

%ask user for labels
x_axis = input('X axis title?', 's');
y_axis = input('Y axis title?', 's');
color = menu('What color?', 'green', 'black', 'yellow', 'blue');
style = menu('What style line?', 'x', 'o', '-', '+');

%selecting color and style for plot
switch color
    case 1
        switch style
            case 1
                plot (x, y, 'gx')
                xlabel(x_axis)
                ylabel(y_axis)
            case 2
                plot(x, y, 'go')
                xlabel(x_axis)
                ylabel(y_axis)
            case 3
                plot(x, y, 'g-')
                xlabel(x_axis)
                ylabel(y_axis)
            case 4
                plot(x, y, 'g+')
                xlabel(x_axis)
                ylabel(y_axis)
        end
    case 2
        switch style
            case 1
                plot (x, y, 'kx')
                xlabel(x_axis)
                ylabel(y_axis)
            case 2
                plot(x, y, 'ko')
                xlabel(x_axis)
                ylabel(y_axis)
            case 3
                plot(x, y, 'k-')
                xlabel(x_axis)
                ylabel(y_axis)
            case 4
                plot(x, y, 'k+')
                xlabel(x_axis)
                ylabel(y_axis)
        end
    case 3
        switch style
            case 1
                plot (x, y, 'yx')
                xlabel(x_axis)
                ylabel(y_axis)
            case 2
                plot(x, y, 'yo')
                xlabel(x_axis)
                ylabel(y_axis)
            case 3
                plot(x, y, 'y-')
                xlabel(x_axis)
                ylabel(y_axis)
            case 4
                plot(x, y, 'y+')
                xlabel(x_axis)
                ylabel(y_axis)
        end
    case 4
        switch style
            case 1
                plot (x, y, 'bx')
                xlabel(x_axis)
                ylabel(y_axis)
            case 2
                plot(x, y, 'bo')
                xlabel(x_axis)
                ylabel(y_axis)
            case 3
                plot(x, y, 'b-')
                xlabel(x_axis)
                ylabel(y_axis)
            case 4
                plot(x, y, 'b+')
                xlabel(x_axis)
                ylabel(y_axis)
        end
end
end