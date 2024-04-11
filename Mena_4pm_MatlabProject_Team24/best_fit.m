% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24
% plotting line of best fit
function [] = best_fit(x, y)

    
    % line of best fit
    order = input('What is the order of your polynomial? ');

    coeffs = polyfit(x, y, order);
    xnew = linspace(min(x), max(x), 200);
    fitpoints = polyval(coeffs, xnew);
    
    % plotting line of best fit and original data
    plot(x, y, 'r*', xnew, fitpoints)
end