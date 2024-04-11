% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function TakeDerivativeMAIN()
    goagine='y';
    while goagine=='y'
        w_rule=menu('What kind of function to differentiate?',"Product","Quotient","One Line","View Input Syntax");
        
        switch w_rule
            case 3
                
                what_run=input('Enter your function. ','s');
                re=decompose(what_run);
                dif_f=OneLine(re);
                disp(['The derivative of you function is ',dif_f])
        
            case 2
                % gets the functions from the user and passes them to the function
                high_func=input('What is the function on the top? ','s');
                low_func=input('What is the function on the bottom? ','s');
                driv=LowdHigh(high_func,low_func);
                disp(['The derivative of you function is',driv])
            case 1
                one=input('What is your first function? ','s');
                two=input('What is your second function? ','s');
                driv=ProdRule(one,two);
                disp(['The derivative of you function is',driv])
            case 4
                imshow(imread("deriv_documantation.png"))
                %{
            case 4
                in=input('What is the inner? ','s');
                out=input('What is the outer function? ','s');
                driv=ChainRule(in,out);
                disp(['The derivative of you function is',driv])
                %}
        end
        goagine=input('Would you like to take another derivative? y/n ','s');
    end
end
