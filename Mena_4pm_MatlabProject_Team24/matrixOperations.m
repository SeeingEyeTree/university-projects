% Megan Baker, Sarah Ginck, Dennis Ephraim --> Team 24
%matrix operations function 

%comment for main: Our graphing calculator program can generate matrices, 
%intaking polynomials and functions, and completing various forms of analysis
%on them. These tasks include plotting, derivatives, and statistical analysis.  

function matrixOperations(x,y,e,f,matrix1,matrix2) 
    
%enable to run again
    another_time=1; 
    while another_time==1
        pickOperation=menu('Select an operation to perform:', 'multiplication','division','addition','subtraction'); 
        switch pickOperation 
            case 1 
                if y==e %dimensions are compatible
                    result1=matrix1*matrix2;
                    disp(result1);
                else 
                    disp('Error! Calculation cannot be computed. Matrices are not compatible dimensions.') 
                end
            case 2 
                if x==e && y==f %both dimensions are compatible
                    result2=matrix1./matrix2;
                    disp(result2);
                else 
                    disp('Error! Calculation cannot be computed. Matrices are not compatible dimensions.') 
                end 
            case 3 
                if x==e && y==f %both dimensions are compatible
                    result3=matrix1+matrix2;
                    disp(result3);
                else 
                    disp('Error! Calculation cannot be computed. Matrices are not compatible dimensions.') 
                end 
            case 4 
                if x==e && y==f %both dimensions are compatible
                    result4=matrix1-matrix2;
                    disp(result4);
                else 
                    disp('Error! Calculation cannot be computed. Matrices are not compatible dimensions.') 
                end 
        end 
    %ask user if they want to go again
    another_time=input('Complete another operation? 1 for yes, 2 for no '); 
    end 
end 