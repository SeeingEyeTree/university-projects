% Megan Baker, Sarah Ginck, Dennis Ephraim --> Team 24
%singular matrix statistical analysis function 
function matrixStatistics(matrix1,matrix2) 
    %ask user to select matrix
    pickMatrix=input('Which matrix would you like to analyze: 1 or 2 '); 
    
    %enable it to run again
    runagain='y'; 
    while runagain=='y'
        if pickMatrix==1 
            whichOperation1=menu('Select operation of analysis to perform: ', 'maximum', 'minimum','sort','standard deviation'); 
            switch whichOperation1 
                case 1 
                    %matrix1=[100,20,30;30,100,200;100,500,200];
                    [rows1,cols1]=size(matrix1); 
                    row_list=[];
                    
                    for i=1:rows1
                        %disp(['matrix1(i)',num2str(matrix1(i,:))])
                        [row_max,colum_num]=max(matrix1(i,:));
                        row_list=[row_list;[row_max,colum_num]];

                    end
                    %disp(row_list)
                    [max1,ind]=max(row_list(:,1));
                    %disp([num2str(value),num2str(ind)])
                    maxLoc1=[ind,row_list(ind,2)];
                    find_location1=input('Would you like to find the location of the maximum?, y/n ','s'); 
                    if find_location1=='y' 
                         
                        disp(['The maximum value is ',num2str(max1), ' which is located at (',num2str(maxLoc1),')']); 
                    elseif find_location1=='n'
                        disp(['The max value is ',num2str(max1)]); 
                    end 
                case 2 
                    
                    [rows1,cols1]=size(matrix1); 
                    
                    row_list=[];
                    
                    for i=1:rows1
                        %disp(['matrix1(i)',num2str(matrix1(i,:))])
                        [row_max,colum_num]=min(matrix1(i,:));
                        row_list=[row_list;[row_max,colum_num]];

                    end
                    %disp(row_list)
                    [max1,ind]=min(row_list(:,1));
                    %disp([num2str(value),num2str(ind)])
                    maxLoc1=[ind,row_list(ind,2)];
                    find_location1=input('Would you like to find the location of the min?, y/n ','s'); 
                    if find_location1=='y' 
                         
                        disp(['The min value is ',num2str(max1), ' which is located at (',num2str(maxLoc1),')']); 
                    elseif find_location1=='n'
                        disp(['The min value is ',num2str(max1)]); 
                    end 
                     
                case 3 
                    sortedMatrix1=sort(matrix1); 
                    disp(sortedMatrix1); 
                case 4 
                    standardDev1=std(matrix1); 
                    disp(standardDev1); 
            end 
        elseif pickMatrix==2 
            whichOperation2=menu('Select operation of analysis to perform: ', 'maximum', 'minimum','sort','standard deviation'); 
            switch whichOperation2 
                case 1 
                    [rows1,cols1]=size(matrix2); 
                    row_list=[];
                    
                    for i=1:rows1
                        %disp(['matrix1(i)',num2str(matrix1(i,:))])
                        [row_max,colum_num]=max(matrix2(i,:));
                        row_list=[row_list;[row_max,colum_num]];

                    end
                    %disp(row_list)
                    [max1,ind]=max(row_list(:,1));
                    %disp([num2str(value),num2str(ind)])
                    maxLoc1=[ind,row_list(ind,2)];
                    find_location1=input('Would you like to find the location of the maximum?, y/n ','s'); 
                    if find_location1=='y' 
                         
                        disp(['The maximum value is ',num2str(max1), ' which is located at (',num2str(maxLoc1),')']); 
                    elseif find_location1=='n'
                        disp(['The max value is ',num2str(max1)]); 
                    end 
                case 2 
                    [rows1,cols1]=size(matrix2); 
                    row_list=[];
                    
                    for i=1:rows1
                        %disp(['matrix1(i)',num2str(matrix1(i,:))])
                        [row_max,colum_num]=min(matrix2(i,:));
                        row_list=[row_list;[row_max,colum_num]];

                    end
                    %disp(row_list)
                    [max1,ind]=min(row_list(:,1));
                    %disp([num2str(value),num2str(ind)])
                    maxLoc1=[ind,row_list(ind,2)];
                    find_location1=input('Would you like to find the location of the min?, y/n ','s'); 
                    if find_location1=='y' 
                         
                        disp(['The min value is ',num2str(max1), ' which is located at (',num2str(maxLoc1),')']); 
                    elseif find_location1=='n'
                        disp(['The min value is ',num2str(max1)]); 
                    end 
                case 3 
                    sortedMatrix2=sort(matrix2); 
                    disp(sortedMatrix2) 
                case 4 
                    standardDev2=std(matrix2); 
                    disp(standardDev2) 
            end 
        end
        runagain=input('Would you like to do another analysis? y/n ','s');
    end 
end 