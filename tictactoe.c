#include<stdio.h>

char matrix[3][3], player1[50], player2[50];


void getDetails();
char check();
void initMatrix();
void displayMatrix();
void getPlayer1Move();
void getPlayer2Move();
void geo();

int main(){
    geo();
    return 0;
}

/* geo definition */
void geo(void){
    printf(" ~~~~  Tic Tac Toe Game  ~~~\n");
    getDetails();
    char done = ' ';
    initMatrix();
    do{
        displayMatrix();
        getPlayer1Move();
        check();
        done = check();
        if(done != ' ') break;
        displayMatrix();
        getPlayer2Move();
        done = check();
        if(done != ' ') break;
    }while(done==' ');
    if(done == 'X'){
        displayMatrix();
        printf("\n %s won!\n",player1);
    }else{
        displayMatrix();
        printf("\n %s won!\n", player2);
    }
    

}


/* Get Details of Players */
void getDetails(void){
    printf("\n Enter Player1 Details: ");
    scanf("%s",player1);
    printf("\n Enter Player2 Details:");
    scanf("%s",player2);
}



/*Initialize matrix*/
void initMatrix(void){
    int i;
    for(i = 0; i < 3; i++){
        matrix[0][i] = ' ';
        matrix[1][i] = ' ';
        matrix[2][i] = ' ';
    }
}


/* Get player1 move */
void getPlayer1Move(void){
    int x, y;
    printf("\n %s Enter ( X,Y ) Co-Ordinates of your move: ", player1);
    scanf("%d %d", &x, &y);
    x--, y--;
    if(matrix[x][y] != ' '){
        printf("Invalid Move!");
        getPlayer1Move();
    }else
    {
        matrix[x][y] = 'X';
    }
}



/* Get player2 move */
void getPlayer2Move(void){
    int x, y;
    printf("\n %s Enter X,Y Co-Ordinates of your move: ", player2);
    scanf("%d %d", &x, &y);
    x--, y--;
    if(matrix[x][y] != ' '){
        printf("Invalid Move!");
        getPlayer1Move();
    }else
    {
        matrix[x][y] = '0';
    }
}

/* Check who won */
char check(void){
    int i;
    // Check Diagonally
    if(matrix[0][0] == matrix[1][1] && matrix[1][1]  == matrix[2][2]) 
        return matrix[0][0];
    else if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[3][0])
        return matrix[0][2];
    //check columns
    for(i = 0; i < 2; i++){
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            return matrix[0][i];
    }
    //check rows
    for(i = 0; i < 2; i++){    
    if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            return matrix[i][0];
    }
    return ' ';
}

/* Display matrix */
void displayMatrix(){
    int i;
    for( i = 0; i < 3; i++){
        printf("%c | %c | %c\n", matrix[i][0], matrix[i][1], matrix[i][2]);
        if(i!=2) printf("--| --|--\n");
    }
}
