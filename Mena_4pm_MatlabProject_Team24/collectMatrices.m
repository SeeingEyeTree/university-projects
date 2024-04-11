% Megan Baker, Sarah Ginck, Dennis Ephraim --> Team 24
%getting matrices function 
function [matrix1,matrix2,x,y,e,f]=collectMatrices 
    %data=input('Would you like to generate a matrix of values? 1 for yes, 2 for no '); 
    data=1;
    data2=1;
    %generating matrix 1
    if data==1 
        w=input('Enter the highest value within your first matrix? '); 
        x=input('Enter the number of rows: '); 
        y=input('Enter the number of columns: '); 
        matrix1=randi([0,w],x,y); 
        disp(matrix1); 
        %{
        while data==1 
            data2=input('Would you like to generate another matrix? 1 for yes, 2 for no ');
            data=0;
        end
        %}
    end
    %generating matrix 2
    if data2==1 
        d=input('Enter the highest value within your second matrix? '); 
        e=input('Enter the number of rows: '); 
        f=input('Enter the number of columns: '); 
        matrix2=randi([0,d],e,f); 
        disp(matrix2); 
    else 
    end 
end 