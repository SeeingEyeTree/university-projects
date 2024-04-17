% made in 50 minutes
board = [[' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' '],
                [' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ']];

disp(board)
pipe=1:1:10;
hole = randi(8);
hole2 = randi(7);
pipe(hole)=9;
pipe(hole+1)=10;
clc
col_num=10;

bird=2;
x=3;
while true
    move = input('Up Down None? u/d,n',"s");
    clc

    
    board(bird,x) = 0;
    if move == 'u'
        bird = bird-1;
    elseif move == 'd'
        bird = bird+2;
  
    else
        bird = bird+1;
    end
    board(bird,x)='B';
    for i= pipe
        board(i,col_num)=' ';
        board(i,col_num-1)='|';
    end
    if board(bird,x) == '|'
        clc
        disp('Hit pipe')
        break
    end


    disp(board)
    

    if bird >= 10
        clc
        disp('Hit the gound too hard')
        break
    end

    if col_num == 2
        col_num = 10;
        pipe = 1:1:10;
        hole = randi(8);
        pipe(hole)=1;
        pipe(hole+1)=2;

    else col_num ~= 1;
        col_num = col_num-1;

    end


end

disp(board)
disp('game_over')
