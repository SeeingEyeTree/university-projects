% Megan Baker, Sarah Ginck, Dennis Ephraim --> Team 24
function [] = matrix_ops()

    %call disclaimer function 
    disclaimer() 
    
    %call collectMatrices function 
    [matrix1,matrix2,x,y,e,f]=collectMatrices; 
    
    %call matrixOperations function 
    matrixOperations(x,y,e,f,matrix1,matrix2) 
    
    %call counting function 
    counting(matrix1,matrix2) 
    
    %call statistical analysis function 
    matrixStatistics(matrix1,matrix2) 
    
end