
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Sarah Ginck, Megan Baker, Dennis Ephraim - Team 24
//comment explanation for each game

//Word Unscrambler: The user selects a number 1-5, and that number will correspond to a 5-7 letter scrambled word. The user will be given one attempt to unscramble the word, and they will be told if they were correct or not.

/*Tic-Tac-Toe:
 * The tic-tac-toe game is a two player game. The game should allow the
 * user to pick which player they are, X or O, and replace the slot
 * number with their indicated letter.The players can continue to play
 * on the same board for as long as they would like, and can quit at
 * anytime. They are also able to override the other players position
 * for an added challenge.That challenge round is up to the individual
 * players if they want to play that way, as it will make the game take
 * a very long time. When they finish playing a congratuating message
 * will appear, and the code will stop.*/

//4=10:
// You are given 4 different numbers and have to make them equal 10 useing addition, subtraction, multiplication or division.

char checker(int[],double[]);
void sort_x_pos(double[]);
void good_to_go(double[],int[],double[]);
void four_ten_main (void);
void function1(char word1[]);
void function2(char word2[]);
void function3(char word3[]);
void function4(char word4[]);
void function5(char word5[]);
void word_main(void);
void make_board(char board[][3]);
char player_type(char player);
int turn(char decision);
void replaced_board(int spot, char board[][3], char decision);
void tic_tac_main(void);

int main(){
    int game;
    char go;
    // ask user what game they want to play
    do{
    printf("What game do you want to play? 4=10(1), Word Unscrambler(2),Tic Tac Toe(3)?");
    scanf("%d",&game);

    // start correct game
    if(game==1){
        four_ten_main();
    }
    else if(game==2){
        word_main();
    }
    else if (game==3){
		tic_tac_main();
	}
	printf("Do you want to play a different game? y/n");
	scanf(" %c",&go);
    }while(go=='y');

}
///////////////////////// WORD UNSCRAMBLER ////////////////////////////
void word_main(void)
{
	//variables
	int usernum;
	char word1[5]="shark", word2[6]="alpaca", word3[6]="almond", word4[6]="bistro", word5[7]="apricot";
	char again='y';

	//ask user to enter number designated to a word
	printf("\n\nWelcome to Word Unscrambler!");
	do
	{
	printf("\nTo select a word to unscramble, enter a number 1-5.\n1 is the easiest, 5 is the most difficult.\n");
	scanf("%d",&usernum);

	//error check user input
	while (usernum<1 || usernum>5)
	{
		printf("To select a word to unscramble, enter a number 1-5. 1 is the easiest, 5 is the most difficult. \n\n");
		scanf("%d",&usernum);
	}

	//switch case for word options
	switch (usernum)
	{
		case 1:
			function1(word1);
			break;
		case 2:
			function2(word2);
			break;
		case 3:
			function3(word3);
			break;
		case 4:
			function4(word4);
			break;
		case 5:
			function5(word5);
			break;
	}

	//ask user if they want to run again
	printf("\n\nWould you like to unscramble another word? y/n ");
	scanf(" %c",&again);
    while (again != 'n' && again != 'y')
	{
		printf("\n\nWould you like to unscramble another word? y/n ");
		scanf(" %c",&again);
	}
	}while (again=='y');
}

/////////////////////////////////////////////
void function1(char word1[])
{
	//variables
	int i,temp1,temp2;
	char guess1[5];

	//scramble word + display it
	printf("\nYou will be unscrambling a 5 letter word.\n");
	for (i=0;i<3;i=i+2)
	{
		temp1=word1[i];
		temp2=word1[i+2];
		word1[i]=temp2;
		word1[i+2]=temp1;
	}
	printf("\nYour word is: %s\n\n",word1);

	//ask user for guess
	printf("Your guess for the unscrambled word: ");
	scanf("%s",guess1);

	//display if they won or lost
	if(guess1[0] == 's' || guess1[0] == 'S')
	{
		if(guess1[1] == 'h')
		{
			if(guess1[2] == 'a')
			{
				if(guess1[3] == 'r')
				{
					if(guess1[4] == 'k')
					{
						printf("\nHooray! You won!");
					}
				}
			}
		}
	}
	if(guess1[0] == 's' || guess1[0] == 'S')
	{
		if(guess1[1] != 'h' || guess1[2] != 'a' || guess1[3] != 'r' || guess1[4] != 'k')
		{
			printf("\nGood try! The correct word was shark.");
		}
	}

	else
	{
		printf("\nGood try! The correct word was shark.");
	}
}
/////////////////////////////////////////////
void function2(char word2[])
{
	//variables
	int i,temp1,temp2;
	char guess2[6];

	printf("\nYou will be unscrambling a 6 letter word.\n");

	//scramble word  + display it
	for (i=0;i<4;i=i+2)
	{
		temp1=word2[i+1];
		temp2=word2[i+2];
		word2[i+1]=temp2;
		word2[i+2]=temp1;
	}
	printf("\nYour word is: %c%c%c%c%c%c\n",word2[0],word2[1],word2[2],word2[3],word2[4],word2[5]);

	//ask user for guess
	printf("\nYour guess for the unscrambled word: ");
	scanf("%s",guess2);

	//display if they won or lost
	if(guess2[0] == 'a' || guess2[0] == 'A')
	{
		if(guess2[1] == 'l')
		{
			if(guess2[2] == 'p')
			{
				if(guess2[3] == 'a')
				{
					if(guess2[4] == 'c')
					{
						if(guess2[5] == 'a')
						{
							printf("\nHooray! You won!");
						}
					}
				}
			}
		}
	}
	if(guess2[0] == 'a' || guess2[0] == 'A')
	{
		if(guess2[1] != 'l' || guess2[2] != 'p' || guess2[3] != 'a' || guess2[4] != 'c' || guess2[5] != 'a')
		{
			printf("\nGood try! The correct word was alpaca.");
		}
	}

	else
	{
		printf("\nGood try! The correct word was alpaca.");
	}
}

/////////////////////////////////////////////
void function3(char word3[])
{
	//variables
	int i,temp5,temp6,temp7,temp8;
	char guess3[6];

	printf("\nYou will be unscrambling a 6 letter word.\n");

	//scramble word  + display it
	for (i=0;i<4;i=i+2)
	{
		temp5=word3[i];
		temp6=word3[i+1];
		word3[i]=temp6;
		word3[i+1]=temp5;
		temp7=word3[i+2];
		temp8=word3[i+3];
		word3[i+2]=temp8;
		word3[i+3]=temp7;
	}

	printf("\nYour word is: %c%c%c%c%c%c\n",word3[0],word3[1],word3[2],word3[3],word3[4],word3[5]);

	//ask user for guess
	printf("\nYour guess for the unscrambled word: ");
	scanf("%s",guess3);

	//display if they won or lost
	if(guess3[0] == 'a' || guess3[0] == 'A')
	{
		if(guess3[1] == 'l')
		{
			if(guess3[2] == 'm')
			{
				if(guess3[3] == 'o')
				{
					if(guess3[4] == 'n')
					{
						if(guess3[5] == 'd')
						{
							printf("\nHooray! You won!");
						}
					}
				}
			}
		}
	}
	if(guess3[0] == 'a' || guess3[0] == 'A')
	{
		if(guess3[1] != 'l' || guess3[2] != 'm' || guess3[3] != 'o' || guess3[4] != 'n' || guess3[5] != 'd')
		{
			printf("\nGood try! The correct word was almond.");
		}
	}

	else
	{
		printf("\nGood try! The correct word was almond.");
	}
}
/////////////////////////////////////////////
void function4(char word4[])
{
	//variables
	int i,temp1,temp2,temp3,temp4;
	char guess4[6];

	printf("\nYou will be unscrambling a 6 letter word.\n");

	//scramble word + display it
	for (i=0;i<2;i=i+2)
	{
		temp1=word4[i];
		temp2=word4[i+2];
		word4[i]=temp2;
		word4[i+2]=temp1;
	}
	temp3=word4[4];
	temp4=word4[5];
	word4[4]=temp4;
	word4[5]=temp3;

	printf("\nYour word is: %c%c%c%c%c%c\n",word4[0],word4[1],word4[2],word4[3],word4[4],word4[5]);

	//ask user for guess
	printf("\nYour guess for the unscrambled word: ");
	scanf("%s",guess4);

	//display if they won or lost
	if(guess4[0] == 'b' || guess4[0] == 'B')
	{
		if(guess4[1] == 'i')
		{
			if(guess4[2] == 's')
			{
				if(guess4[3] == 't')
				{
					if(guess4[4] == 'r')
					{
						if(guess4[5] == 'o')
						{
							printf("\nHooray! You won!");
						}
					}
				}
			}
		}
	}
	if(guess4[0] == 'b' || guess4[0] == 'B')
	{
		if(guess4[1] != 'i' || guess4[2] != 's' || guess4[3] != 't' || guess4[4] != 'r' || guess4[5] != 'o')
		{
			printf("\nGood try! The correct word was bistro.");
		}
	}

	else
	{
		printf("\nGood try! The correct word was bistro.");
	}
}
/////////////////////////////////////////////
void function5(char word5[])
{
	//variables
	int temp1,temp2,temp3,temp4;
	char guess5[7];

	printf("\nYou will be unscrambling a 7 letter word.\n");

	//scramble word + display it
	temp1=word5[0];
	temp2=word5[2];
	word5[2]=temp1;
	word5[0]=temp2;
	temp3=word5[4];
	temp4=word5[6];
	word5[6]=temp3;
	word5[4]=temp4;

	printf("\nYour word is: %c%c%c%c%c%c%c\n",word5[0],word5[1],word5[2],word5[3],word5[4],word5[5],word5[6]);

	//ask user for guess
	printf("\nYour guess for the unscrambled word: ");
	scanf("%s",guess5);

	//display if they won or lost
	if(guess5[0] == 'a' || guess5[0] == 'A')
	{
		if(guess5[1] == 'p')
		{
			if(guess5[2] == 'r')
			{
				if(guess5[3] == 'i')
				{
					if(guess5[4] == 'c')
					{
						if(guess5[5] == 'o')
						{
							if(guess5[6] == 't')
							{
								printf("\nHooray! You won!");
							}
						}
					}
				}
			}
		}
	}
	if(guess5[0] == 'a' || guess5[0] == 'A')
	{
		if(guess5[1] != 'p' || guess5[2] != 'r' || guess5[3] != 'i' || guess5[4] != 'c' || guess5[5] != 'o' || guess5[6] != 't')
		{
			printf("\nGood try! The correct word was apricot.");
		}
	}

	else
	{
		printf("\nGood try! The correct word was apricot.");
	}
}

////////////////////// FOUR = TEN ////////////////////////////

void four_ten_main(void){
    //declare need vars
    FILE *path;
    path=fopen("4_eq_10_pos.txt","r");
    int check,h=0,x[3];
    double sum, pos_ar[100][4],ar_pass[4],use[4];
    char user_ans[100],cont='y',all_good='n',win_yon;

    //read in data from file using EOF
    for(int i=0;i<100;i++){
        check=fscanf(path,"%lf %lf %lf %lf",&pos_ar[i][0],&pos_ar[i][1],&pos_ar[i][2],&pos_ar[i][3]);
        if (check==EOF){
            break;
        }
    }
    //Welcome to game
    printf("Welcome to 4=10! You have to take the four numbers you are given and make them equal ten using +,-,*,/ \n");

    // create an array of one dim to compare to the user nums entered
    double pos_dim1[4]={pos_ar[h][0],pos_ar[h][1],pos_ar[h][2],pos_ar[h][3]};

    //loop to run game multiple times
    do{
        // display the numbers to be used in this run
        printf("Your numbers are\n%.0lf %.0lf %.0lf %.0lf\n",pos_ar[h][0],pos_ar[h][1],pos_ar[h][2],pos_ar[h][3]);
        // pass arrays to checker to make user that the user did not enter any different numbers then the ones provided
        good_to_go(pos_dim1,x,use);// I did this in a function because for some reason when I put a while loop before the checker function it did not compile
        //after the correct numbers have been passed pass them to the checker function to see if they equal 10 after the opprations
        win_yon=checker(x,use);
        // if it does equal ten ask if they want to run again or exit
        if (win_yon=='y'){
            printf("Your answer was correct! Do you want to try another? y/n :");
            scanf(" %c", &cont);
            h++;
        }
        else{
            printf("That was not it, try again\n");// if they get it wrong loop to let them try again
        }

    }while(cont=='y');
}

void good_to_go(double pos_vals[], int x[], double use[]){
    // declare local vars
    char all_good='n',user_ans[100];


    while(all_good=='n'){
        // get user input in string
        printf("Enter your solution, and make sure to use the right numbers\n");
        scanf("%s", user_ans);

	    int a=1;// iter by 2 to get operand given and iter by 1 to assign them to the correct x array pos
	    for(int b=0;b<3;b++){
	        if (user_ans[a]=='+'){
	            x[b]=1;}
	        else if(user_ans[a]=='-'){
	            x[b]=2;}
	        else if(user_ans[a]=='*'){
	            x[b]=3;}
	        else if(user_ans[a]=='/'){
	            x[b]=4;}
	        a=a+2;}

        // There is a way to not need to convert data types by asking for each index individually but it makes more sense and is cleaner to do it this way
	    int t=0;// iter by 2 to get values and iter by 1 to assign them to the correct use array pos
	    for(int q=0;q<4;q++){
	        double double_temp;// double and char vars need to convert the char data type to a double data type
	        char char_temp[1];
	        char_temp[0]=user_ans[t];
	        sscanf(char_temp, "%lf", &double_temp);// function that converts chars to doubles
	        use[q]=double_temp;
	        t=t+2;

	    }

	    if (use[0]>=10){
	        use[0]=use[0]/10;// for some reason unknown to me some times the first number read in gets multiplied by ten so this fixes that
	    }
	    // We do not want to edit the use array since it has the values in the correct order so create an identical array to sort so a comparison can be made
	    double use_hold[4]={use[0],use[1],use[2],use[3]};
	    //sort the user array and given array to make sure they are the same
	    sort_x_pos(pos_vals);
	    sort_x_pos(use_hold);
	    // compares each value
	    for(int m=0;m<4;m++){
            if(use_hold[m]==pos_vals[m]){
                all_good='y';}
            else{
                // if one is not equal break and set while loop condtion to True to run again
                all_good='n';
                break;
            }

	    }
    }
}


char checker(int x[], double use[]){

    // return var and var to that holds the value after math ops
    double sumation;
    char ans;
    /*
    If you could turn a string in to a executable line of code you could just have a str="s=use[0]_use[1]_use[2]_use[3]"
    and then if stamets that uppdated the value of one opp
    j=8
    x=[1,1,1]
    use=[1,2,3,4]
    with open('run.py', 'w') as file:
        file.write(f'use=[{use[0]},{use[1]},{use[2]},{use[3]}]\n')
    str1="s=use[0]_use[1]_use[2]_use[3]"
    #print(str1)
    for i in range(3):
        if x[i]==1:
            str1=str1.replace("_","+",1)
        elif x[i]==2:
            str1=str1.replace("_","-",1)
        elif x[i]==3:
            str1=str1.replace("_","*",1)
        elif x[i]==4:
            str1=str1.replace("_","/",1)
        j=j+7
    with open('run.py', 'a') as file:
        file.write(str1)


    import run
    #print(run.s)
    if run.s==10:
        ans='y'
    else:
        ans='n'

    The only way I could think of doing that is by printing to a file and then saving it as a exutable and the running it and returning a value back to the main program
    That I did not know how to do that in c++ but the above code is code that should work in python, it is not in cython syntax but could easily be edited

    */
    // run through ever possible answer in a very brute force way
    if (x[0]==1){
        if (x[1]==1){
            if (x[2]==1){
                sumation=use[0]+use[1]+use[2]+use[3];
                ////ans=f'{use[0]}+{use[1]}+{use[2]}+{use[3]}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]+use[1]+use[2]-use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]+use[1]+use[2]*use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
        }
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]+use[1]+use[2]/use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
        else if (x[1]==2){
            if (x[2]==1){
                sumation=use[0]+use[1]-use[2]+use[3];
                //ans=f'{use[0]}+{use[1]}-{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]+use[1]-use[2]-use[3];
                //ans=f'{use[0]}+{use[1]}-{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]+use[1]-use[2]*use[3];
                //ans=f'{use[0]}+{use[1]}-{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]+use[1]-use[2]/use[3];
                //ans=f'{use[0]}+{use[1]}-{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==3){
            if (x[2]==1){
                sumation=use[0]+use[1]+use[2]+use[3];
                //ans=f'{use[0]}+{use[1]}*{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]+use[1]*use[2]-use[3];
                //ans=f'{use[0]}+{use[1]}*{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]+use[1]*use[2]*use[3];
                //ans=f'{use[0]}+{use[1]}*{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]+use[1]*use[2]/use[3];
                //ans=f'{use[0]}+{use[1]}*{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
        }
        else if (x[1]==4){
            if (x[2]==1 && use[2]!=0){
                sumation=use[0]+use[1]/use[2]+use[3];
                //ans=f'{use[0]}+{use[1]}÷{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2 && use[2]!=0){
                sumation=use[0]+use[1]/use[2]-use[3];
                //ans=f'{use[0]}+{use[1]}÷{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3 && use[2]!=0){
                sumation=use[0]+use[1]/use[2]*use[3];
                //ans=f'{use[0]}+{use[1]}÷{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0 && use[2]!=0){
                sumation=use[0]+use[1]/use[2]/use[3];
                //ans=f'{use[0]}+{use[1]}÷{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}}
    else if (x[0]==2){
        if (x[1]==1){
            if (x[2]==1){
                sumation=use[0]-use[1]+use[2]+use[3];
                //ans=f'{use[0]}-{use[1]}+{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]-use[1]+use[2]-use[3];
                //ans=f'{use[0]}-{use[1]}+{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]-use[1]+use[2]*use[3];
                //ans=f'{use[0]}-{use[1]}+{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]-use[1]+use[2]/use[3];
                //ans=f'{use[0]}-{use[1]}+{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}

        else if (x[1]==2){
            if (x[2]==1){
                sumation=use[0]-use[1]-use[2]+use[3];
                //ans=f'{use[0]}-{use[1]}-{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]-use[1]-use[2]-use[3];
                //ans=f'{use[0]}-{use[1]}-{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]-use[1]-use[2]*use[3];
                //ans=f'{use[0]}-{use[1]}-{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]-use[1]-use[2]/use[3];
                //ans=f'{use[0]}-{use[1]}-{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==3){
            if (x[2]==1){
                sumation=use[0]-use[1]*use[2]+use[3];
                //ans=f'{use[0]}-{use[1]}*{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]-use[1]*use[2]-use[3];
                //ans=f'{use[0]}-{use[1]}*{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]-use[1]*use[2]*use[3];
                //ans=f'{use[0]}-{use[1]}*{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]-use[1]*use[2]/use[3];
                //ans=f'{use[0]}-{use[1]}*{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==4){
            if (x[2]==1){
                sumation=use[0]-use[1]/use[2]+use[3];
                //ans=f'{use[0]}-{use[1]}÷{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]-use[1]/use[2]-use[3];
                //ans=f'{use[0]}-{use[1]}÷{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]-use[1]/use[2]*use[3];
                //ans=f'{use[0]}-{use[1]}÷{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]-use[1]/use[2]/use[3];
                //ans=f'{use[0]}-{use[1]}÷{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}}
    else if (x[0]==3){
        if (x[1]==1){
            if (x[2]==1){
                sumation=use[0]*use[1]+use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]*use[1]+use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]*use[1]+use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]*use[1]+use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==2){
            if (x[2]==1){
                sumation=use[0]*use[1]-use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]*use[1]-use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]*use[1]-use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]*use[1]-use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==3){
            if (x[2]==1){
                sumation=use[0]*use[1]+use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]*use[1]*use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]*use[1]*use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]*use[1]*use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==4){
            if (x[2]==1){
                sumation=use[0]*use[1]/use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]*use[1]/use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]*use[1]/use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]*use[1]/use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        if (x[1]==1){
            if (x[2]==1){
                sumation=use[0]+use[1]+use[2]+use[3];
                ////ans=f'{use[0]}+{use[1]}+{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]+use[1]+use[2]-use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]+use[1]+use[2]*use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]+use[1]+use[2]/use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
    }
    else if (x[0]==4){
        if (x[1]==1){
            if (x[2]==1){
                sumation=use[0]/use[1]+use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]/use[1]+use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]/use[1]+use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]/use[1]+use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}+{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==2){
            if (x[2]==1){
                sumation=use[0]/use[1]-use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]/use[1]-use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]/use[1]-use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]/use[1]-use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}-{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==3){
            if (x[2]==1){
                sumation=use[0]/use[1]+use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]/use[1]*use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]/use[1]*use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]/use[1]*use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}*{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        else if (x[1]==4){
            if (x[2]==1){
                sumation=use[0]/use[1]/use[2]+use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]/use[1]/use[2]-use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]/use[1]/use[2]*use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]/use[1]/use[2]/use[3];
                //ans=f'{use[0]}*{use[1]}÷{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
        if (x[1]==1){
            if (x[2]==1){
                sumation=use[0]+use[1]+use[2]+use[3];
                ////ans=f'{use[0]}+{use[1]}+{use[2]}+{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==2){
                sumation=use[0]+use[1]+use[2]-use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}-{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==3){
                sumation=use[0]+use[1]+use[2]*use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}*{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}
            else if (x[2]==4 && use[3]!=0){
                sumation=use[0]+use[1]+use[2]/use[3];
                //ans=f'{use[0]}+{use[1]}+{use[2]}÷{use[3];}'
                if (sumation==10){
                    ans='y';
                    return ans;}}}
    }
}


void sort_x_pos(double sort_ar[]){

    double temp1, temp2;// create temp vars
    int i,j;//iter vars
    for(j=0;j<4;j++){
        for(i=0;i<3;i++){
            if(sort_ar[i]>sort_ar[i+1]){
                //if bigger swap
                temp1=sort_ar[i+1];
                temp2=sort_ar[i];
                sort_ar[i]=temp1;
                sort_ar[i+1]=temp2;

            }
        }
    }
}

void tic_tac_main(void)
{
	//create var for running code again
	char again;

	//print instructions
	printf("Welcome to Tic-Tac-Toe! \nThis is a two player game. \nTo play the game, first identify which player you are. Then you will be asked which location you would like to go. \nAt the end of each turn, indicate if you would like to continue by typing y or n. \nHAVE FUN! GOOD LUCK! \n\n\n");

	//call make_board fxn
	char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	make_board(board);

	do
	{
		//call ask which player fxn
		char player, decision;
		decision = player_type(player);

		//call turn fxn
		int spot;
		spot = turn(decision);

		//call replaced board fxn
		replaced_board(spot, board, decision);

		//ask the user if they want to continue the game.
		printf("Do you want to continue the game? (y or n): ");
		scanf(" %c", &again);

	}while (again == 'y');

	printf("Thanks for playing! Great job winner!");
}

////////////////////////////////////////////////////////////////////////
void make_board(char board[][3])
{
	//create board setup

	//print board to screen
	int i=0, j=0;

	printf("---------------\n");
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			printf("| %c |", board[i][j]);
		}
		printf("\n");
		printf("---------------\n");

	}


}

////////////////////////////////////////////////////////////////////////
char player_type(char player)
{
	//create decision var
	char decision;

	//ask user which player and error check
	do
	{
	printf("\nare you player X or O? \n");
	scanf(" %c", &decision);
	}while (decision != 'X' && decision != 'x' && decision != 'o' && decision !='O');

	return(decision);
}

////////////////////////////////////////////////////////////////////////
int turn(char decision)
{
	//ask user where they want to go, error check
	int spot;

	do
	{
		printf("\nplayer %c, where do you want to go? (enter number to replace): ", decision);
		scanf("%d", &spot);
	}while (spot <= 0 && spot >=10);

	return(spot);
}

////////////////////////////////////////////////////////////////////////
void replaced_board(int spot, char board[][3], char decision)
{
	//switch case to replace number with X or O
	switch(spot)
	{
		case(1):
		{
			board[0][0] = decision;
			make_board(board);
			break;
		}
		case(2):
		{
			board[0][1] = decision;
			make_board(board);
			break;
		}
		case(3):
		{
			board[0][2] = decision;
			make_board(board);
			break;
		}
		case(4):
		{
			board[1][0] = decision;
			make_board(board);
			break;
		}
		case(5):
		{
			board[1][1] = decision;
			make_board(board);
			break;
		}
		case(6):
		{
			board[1][2] = decision;
			make_board(board);
			break;
		}
		case(7):
		{
			board[2][0] = decision;
			make_board(board);
			break;
		}
		case(8):
		{
			board[2][1] = decision;
			make_board(board);
			break;
		}
		case(9):
		{
			board[2][2] = decision;
			make_board(board);
			break;
		}
	}

}




