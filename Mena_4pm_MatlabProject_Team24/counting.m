% Megan Baker, Sarah Ginck, Dennis Ephraim --> Team 24
%finding if a number is in the matrix function 

function [count1,count2]=counting(matrix1,matrix2) 
    %ask user to pick matrix
    select_matrix=input('Select a matrix: 1 or 2 '); 

    %for first matrix
    if select_matrix==1 
        %ask user to enter number
        user_number1=input('Enter a number to see how often it appears in the matrix: '); 
        count1=0; 
        %size matrix
        [rows1,cols1]=size(matrix1); 
        %counting loop
        for i=1:rows1 
            for j=1:cols1 
                if matrix1(i,j)==user_number1 
                    count1=count1+1; 
                end 
            end 
        end 
        disp(['The number you entered appears ', num2str(count1), ' times in the matrix.']); 
    end 

    %for second matrix
    if select_matrix==2 
        %ask user to enter number
        user_number2=input('Enter a number to see how often it appears in the matrix: '); 
        count2=0; 
        %size matrix
        [rows2,cols2]=size(matrix2);
        %counting loop
        for i=1:rows2 
            for j=1:cols2 
                if matrix2(i,j)==user_number2 
                    count2=count2+1; 
                end 
            end 
        end 
        disp(['The number you entered appears ', num2str(count2), ' times in the matrix.']); 
    end 
end 