% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function dif_f=OneLine(re)
    dif_f=[];   
    for i=1:length(re)
        
        x=char(re{i});
        %converts to array of chars to iterate over
    
        %identfies what kind of function provided and takes the
        %derivative of it. It is fine that it might run more than one time
        %since the same value will be passed to the function
        for j=1:length(x)
            %disp(x(j))
            if x(j)=='^'
                type_func='power';
                dif_s=PowerRule(x);
                dif_s=['+',dif_s];


            elseif x(j)=='s' || x(j)=='c' || x(j)=='a'
                type_func='trig';
                [driv,mult]=Trig(x);
                if length(driv)<8
                    if mult==1 % multiplies by negative 1 if negative
                        dif_s=['+',driv,'x)'];
                    else
                        dif_s=['-',driv,'x)'];
                    end
    
                else
                    %styles the function correctly
                    if mult==1
                        dif_s=['+',driv(1:4),'x)',driv(6:9),'x)'];
                    else
                       dif_s=['-',driv(1:4),'x)',driv(6:9),'x)'];
                    end
                end
    %{
            elseif x(j)=='l'
                type_func='ln';
                dif_s=LN(x);
    %}
            end
        % compiles all of the derivatives of one part into one string to display
        
        end
        dif_f=[dif_f,dif_s];
    end
    % removes the first operator so it looks cleaner
    if dif_f(1)=='+'
        dif_f(1)=' ';
    end
end

