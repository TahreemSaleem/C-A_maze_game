#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void front();
void gotoxy(int x , int y );
struct hscore {
    char name[20];
    int score;
};

int main()
{//system("COLOR red");
system("COLOR DF"); 
    struct hscore total;
    struct hscore temp;
    temp.score=0;
    int pts=0;
    FILE *fptr;
    int x=0;
    int y=0;
    int ch1, ch2;
    int a=0;
    int b=0;int i;
    int ast=0;
    int line=0;
    int spc=0;
    int move=0;
    int wall[79][24]={0};
    int wallx=0;
    int wally=0;
    unsigned int time=1000;

    front();
    gotoxy(28,16);
    printf("Player name: ");
    scanf("%s",&total.name);
    gotoxy(28,18);
    printf ("Press any key to begin game\n");
    getch();
    system ("cls");
    gotoxy(0,0);

    system("COLOR BC");
    //maze
    for(line=0;line<=4;line++){
        for(ast=0;ast<=78;ast++){
            printf("*");
        }
        printf("\n");
    }
    for(line=0;line<=4;line++){
        for(ast=0;ast<4;ast++)
            printf("*");
        printf("\n");}
    for(line=0;line<=14;line++){
        for(ast=0;ast<4;ast++)
            printf("*");
        for(spc=0;spc<11;spc++)
            printf(" ");
        for (ast=0;ast<64;ast++)
            printf("*");
        printf("\n");
    }

    //wall
    for (wally=0;wally<=24;wally++){
        wallx=3;
        wall[wallx][wally]=1;
    }
    for (wally=10;wally<=24;wally++){
        wallx=15;
        wall[wallx][wally]=1;
    }
    for (wallx=4;wallx<=75;wallx++){
        wally=4;
        wall[wallx][wally]=1;
    }
    for (wallx=15;wallx<=75;wallx++){
        wally=10;
        wall[wallx][wally]=1;
    }

    //end point
    for(wally=5;wally<=9;wally++){
        wallx=78;
        wall[wallx][wally]=2;
    }
    //print start end
    gotoxy(7,25);
    printf("Start");
    gotoxy(78,6);
    printf("E");
    gotoxy(78,7);
    printf("n");
    gotoxy(78,8);
    printf("d");
    //cursor
    x=9;
    y=24;
    gotoxy(9,24);
    ch1 = getch(); 
    ch2 = 0;

    if (ch1 == 0xE0) { 
        ch2=getch();
        while(wall[x][y]!=1 && wall[x][y]!=2){
            switch(ch2) {
            case 75:
                while(1){
                    x--;
                    printf("O");gotoxy(x,y);
                    Sleep(120);
                    pts++;
                    if (kbhit()){ 
                        ch1 = getch(); 
                        ch2 = 0;
                        if (ch1 == 0xE0) 
                        { 
                            ch2=getch();}
                        break;}
                    if (wall[x][y]!=0)
                        break;} 

                break;
            case 77:
                while(1){
                    x++;
                    printf("O");gotoxy(x,y);
                    Sleep(120);pts++;
                    if (kbhit()){ 
                        ch1 = getch(); 
                        ch2 = 0;
                        if (ch1 == 0xE0) 
                        { 
                            ch2=getch();}
                        break;}
                    if (wall[x][y]!=0)
                        break;} 

                break; 
            case 72:
                while(1){
                    y--;
                    printf("O");gotoxy(x,y);
                    Sleep(120);pts++;
                    if (kbhit()){ 
                        ch1 = getch(); 
                        ch2 = 0;
                        if (ch1 == 0xE0) 
                        { 
                            ch2=getch();}
                        break;}

                    if (wall[x][y]!=0)
                        break; }

                break;

            case 80:
                while (1){
                    y++;
                    printf("O");gotoxy(x,y);
                    Sleep(120);pts++;
                    if (kbhit()){ 
                        ch1 = getch(); 
                        ch2 = 0;
                        if (ch1 == 0xE0) 
                        { 
                            ch2=getch();}
                        break;}

                    if (wall[x][y]!=0)
                        break;} 

                break;

            default:
                printf("O");
                if (wall[x][y]!=0)
                    break;
                break;}
        }}
    if (wall[x][y]==1){
        gotoxy(40,8);
        printf("Game Over\n");
        getch(); 

        system ("cls");
        total.score=pts;
        if ((fptr = fopen ("highscore.dat","ab+"))==NULL){
            printf("File cannot be opened\n");
        }
        else{
            fread (&temp, sizeof(struct hscore),1,fptr);
            //new highscore
            if (total.score>temp.score){
                fclose(fptr);
                fopen("highscore.dat","wb");
                fwrite(&total,sizeof (struct hscore),1,fptr);
                fclose(fptr);
                gotoxy(35,8);
                printf(" Name:%s\n \tCongratulations you made new highscore = %d\n",total.name,total.score);
            }
            else {
                gotoxy(35,8);
                printf ("Name:%s\n \tYour Score:%d\n \tCurrent highscore: %s  %d\n",total.name,total.score,temp.name, temp.score);
                fclose(fptr);
            }
        }
        return 0;
    }
    if (wall[x][y]==2){
        system("cls");
        gotoxy(35,8);
        printf("Level 1 Complete\n\n\tPress any key to continue to next level");
        pts+=500;

    }


    //level:2

    system("COLOR AE");
    system("cls");

    gotoxy(0,0);
    int x1=0;
    int y1=0;
    int ch3, ch4;
    int g=0;
    int h=0;
    int wall1[100][100]={0};
    int wallx1=0;
    int wally1=0;
    int ytemp;


    //layout
    for(h=0;h<=3;h++){ //first bar

        for(g=0;g<=70;g++)

            printf("*");

        printf("\n");
    }
    ytemp=6;
    for(h=0;h<=3;h++){ //second bar
        gotoxy(8, ytemp);
        for(g=0; g<=70;g++){
            printf("*");
        }
        ytemp++;
    }
    printf("\n\n\n");
    for(h=0;h<=3;h++){
        for(g=0;g<=70;g++){
            printf("*");}
        printf("\n");

    }

    printf("\n\n\n");
    ytemp=20;
    for(h=0;h<=3;h++){
        gotoxy(8, ytemp++);
        for(g=0; g<=70;g++)
            printf("*");
    }
    //print start end
    gotoxy(3,24);
    printf("Start");
    gotoxy(74,0);
    printf("END");
    
    //wall
    for (wallx1=0;wallx1<70;wallx1++){ //first bar horizontal
        wally1=3;
        wall1[wallx1][wally1]=1;
    }
    for (wally1=0;wally1<4;wally1++){ //first bar vertical
        wallx1=70;
        wall1[wallx1][wally1]=1;
    }
    for (wallx1=8;wallx1<78;wallx1++){ //second bar horizontal1
        wally1=6;
        wall1[wallx1][wally1]=1;
    }
    for (wallx1=8;wallx1<78;wallx1++){ //second bar horzontal2
        wally1=9;
        wall1[wallx1][wally1]=1;
    }
    for (wally1=6;wally1<=9;wally1++){ //second bar vertical
        wallx1=8;
        wall1[wallx1][wally1]=1;
    }
    for (wally1=12;wally1<=15;wally1++){ //third bar vertical
        wallx1=70;
        wall1[wallx1][wally1]=1;
    }
    for (wallx1=0;wallx1<70;wallx1++){
        wally1=12;
        wall1[wallx1][wally1]=1; //third bar horizontal 1
    }
    for (wallx1=0;wallx1<70;wallx1++){
        wally1=15;
        wall1[wallx1][wally1]=1; //third bar horizontal 2
    }
    for (wallx1=8;wallx1<78;wallx1++){ //fourth bar horizontal 1
        wally1=20;
        wall1[wallx1][wally1]=1;
    }
    for (wallx1=8;wallx1<78;wallx1++){ //fourth bar horizontal 2
        wally1=20;
        wall1[wallx1][wally1]=1;
    }
    for (wally1=20;wally1<=24;wally1++){ // fourth bar vertical
        wallx1=8;
        wall1[wallx1][wally1]=1;

    }
    //end point
    for (wallx1=71;wallx1<78;wallx1++){
        wally1=1;
        wall1[wallx1][wally1]=2;
    }

    //cursor movement

    x1=4;
    y1=23;
    gotoxy(4,23);
    ch3 = getch(); 
    ch4 = 0;
    if (ch3 == 0xE0) { 
        ch4=getch();
        while(wall1[x1][y1]!=1 && wall1[x1][y1]!=2){


            switch(ch4) {
            case 75:
                while(1){
                    x1--;
                    printf("O");gotoxy(x1,y1);
                    Sleep(120);pts+=2;
                    if (kbhit()){ 
                        ch3 = getch(); 
                        ch4 = 0;
                        if (ch3 == 0xE0) 
                        {
                            ch4=getch();}
                        break;}
                    if (wall1[x1][y1]!=0)
                        break;} 

                break;
            case 77:
                while(1){
                    x1++;
                    printf("O");gotoxy(x1,y1);
                    Sleep(120);pts+=2;
                    if (kbhit()){ 
                        ch3 = getch(); 
                        ch4 = 0;
                        if (ch3 == 0xE0) 
                        { 
                            ch4=getch();}
                        break;}
                    if (wall1[x1][y1]!=0)
                        break;} 

                break; 
            case 72:
                while(1){
                    y1--;
                    printf("O");gotoxy(x1,y1);
                    Sleep(120);pts+=2;
                    if (kbhit()){ 
                        ch3 = getch(); 
                        ch4 = 0;
                        if (ch3 == 0xE0) 
                        { 
                            ch4=getch();}
                        break;}

                    if (wall1[x1][y1]!=0)
                        break; }

                break;

            case 80:
                while (1){
                    y1++;
                    printf("O");gotoxy(x1,y1);
                    Sleep(150);pts+=2;
                    if (kbhit()){ 
                        ch3 = getch(); 
                        ch4 = 0;
                        if (ch3 == 0xE0) 
                        { 
                            ch4=getch();}
                        break;}

                    if (wall1[x1][y1]!=0)
                        break;} 

                break;

            default:
                printf("O");
                if (wall1[x1][y1]!=0)
                    break;
                break;}
        }}
    if (wall1[x1][y1]==1){
        gotoxy(40,5);
        printf("Game Over\n");
        getch(); system ("cls");
        total.score=pts;
        if ((fptr = fopen ("highscore.dat","ab+"))==NULL){
            printf("File cannot be opened\n");
        }
        else{
            fread (&temp, sizeof(struct hscore),1,fptr);
            //new highscore
            if (total.score>temp.score){
                fclose(fptr);
                fopen("highscore.dat","wb");
                fwrite(&total,sizeof (struct hscore),1,fptr);
                fclose(fptr);
                gotoxy(35,8);
                printf(" Name:%s\n\n\t Congratulations you made new highscore = %d\n",total.name,total.score);
            }
            else {
                gotoxy(35,8);
                printf ("Name:%s\n\n \tYour Score:%d\n\t Current highscore: %s  %d\n",total.name,total.score,temp.name, temp.score);
                fclose(fptr);
            }
        }
        return 0;
    }
    if (wall1[x1][y1]==2){
        system("cls");
        gotoxy(35,8);
        printf("Level 2 Complete\n\n\tPress any key to continue to next level");
    pts+=800;
    }

    //level:3
    system("COLOR 9A");

    system("cls");
    gotoxy(0,0);
    int j;
    int wall2[78][24]={0};
    int wallx2=0;
    int wally2=0;
    int ch6,ch7;
    unsigned int time1=1000;
    int x2=0;
    int y2=0;

    //layout

    printf("\n");
    for (j=0;j<2;j++) //1st
    {  printf("********   ");

    for (i=0;i<66;i++)
        printf("*");
    printf("\n");}

    for (j=0;j<3;j++)                                  //2
    { printf("********   *********");
    for(i=0;i<49;i++)
        printf(" ");
    printf("********");
    printf("\n");}
    for (j=0;j<2;j++)                                 //3
    { for (i=0;i<8;i++)
    printf("*");
    printf("   ");

    for (i=0;i<9;i++)
        printf("*");
    printf("   ");
    for (i=0;i<43;i++)
        printf("*");
    printf("   ");
    for (i=0;i<8;i++)
        printf("*");
    printf("\n");}
    for (j=0;j<3;j++)                                    //4
    {
        printf("********   *********");
        for (i=0;i<27;i++)
            printf(" ");
        printf("********              ********");
        printf("\n");}
    for (j=0;j<2;j++)                                   //5
    {   printf("********   ");
    for (i=0;i<33;i++)
        printf("*");
    printf("   ********   ");
    for (i=0;i<19;i++)
        printf("*");
    printf("\n");}
    for (j=0;j<3;j++)                      //6
    {
        printf("********   *********");
        for (i=0;i<15;i++)
            printf(" ");
        printf("*********   ********   ");
        for (i=0;i<19;i++)
            printf("*");
        printf("\n");}
    for (j=0;j<3;j++)                 //7
    {
        for (i=0;i<8;i++)
            printf("*");
        printf("   ");
        for (i=0;i<9;i++)
            printf("*");
        printf("   ");
        for (i=0;i<9;i++)
            printf("*");
        for (i=0;i<15;i++)
            printf(" ");
        printf("********   ");
        for (i=0;i<19;i++)
            printf("*");
        printf("\n");}
    for (j=0;j<3;j++)                 //8
    {
        for (i=0;i<8;i++)
            printf("*");
        for (i=0;i<15;i++)
            printf(" ");
        for (i=0;i<32;i++)
            printf("*");
        for (i=0;i<22;i++)
            printf(" ");
        printf("\n");}
    for (j=0;j<2;j++)                   //9
    {       for (i=0;i<77;i++)
    printf("*");
    printf("\n");}



    //detecting walls


    for (wally2=0;wally2<=24;wally2++){  //vertical:1
        wallx2=7; 
        wall2[wallx2][wally2]=1;
    }
    for (wally2=0;wally2<=18;wally2++){ //vertical:2
        wallx2=11;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=2;wally2<=10;wally2++){//vertical:3a
        wallx2=19;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=12;wally2<=18;wally2++){//vertical:3b
        wallx2=19;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=6;wally2<=7;wally2++){//vertical:4a
        wallx2=23;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=16;wally2<=21;wally2++){//vertical:4b
        wallx2=23;
        wall2[wallx2][wally2]=1;
    }

    for (wally2=16;wally2<=18;wally2++){//vertical:5
        wallx2=31;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=12;wally2<=15;wally2++){//vertical:6
        wallx2=35;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=11;wally2<=15;wally2++){  //vertical:7
        wallx2=43;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=7;wally2<=18;wally2++){ //vertical:8
        wallx2=47;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=7;wally2<=21;wally2++){//vertical:9
        wallx2=54;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=11;wally2<=18;wally2++){//vertical:10
        wallx2=58;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=6;wally2<=7;wally2++){//vertical:11
        wallx2=65;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=2;wally2<=10;wally2++){//vertical:12
        wallx2=69;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=11;wallx2<=19;wallx2++){ //horizontal:7a
        wally2=18;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=7;wallx2<=22;wallx2++){ //horizontal:8a
        wally2=22;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=19;wallx2<=68;wallx2++){//horizontal:1
        wally2=2;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=23;wallx2<=65;wallx2++){//horizontal:2
        wally2=6;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=23;wallx2<=46;wallx2++){//horizontal:3a
        wally2=7;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=54;wallx2<=65;wallx2++){//horizontal:3b
        wally2=7;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=19;wallx2<=43;wallx2++){//horizontal:4a
        wally2=11;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=19;wallx2<=34;wallx2++){//horizontal:5
        wally2=12;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=23;wallx2<=31;wallx2++){//horizontal:6a
        wally2=17;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=35;wallx2<=43;wallx2++){//horizontal:6b
        wally2=15;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=31;wallx2<=46;wallx2++){//horizontal:7b
        wally2=19;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=58;wallx2<=76;wallx2++){//horizontal:7c
        wally2=18;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=58;wallx2<=68;wallx2++){//horizontal:4b
        wally2=11;
        wall2[wallx2][wally2]=1;
    }
    for (wallx2=54;wallx2<=76;wallx2++){ //horizontal:8b
        wally2=22;
        wall2[wallx2][wally2]=1;
    }
    for (wally2=19;wally2<=22;wally2++){//finish line
        wallx2=77;
        wall2[wallx2][wally2]=2;
    }

    //print start end
    gotoxy(7,0);
    printf("Start");
    gotoxy(78,19);
    printf("E");
    gotoxy(78,20);
    printf("N");
    gotoxy(78,21);
    printf("D");


    //cursr movement
    x2=9;
    y2=1;
    gotoxy(9,1);
    ch6 = getch(); 
    ch7 = 0;

    if (ch6 == 0xE0) { 
        ch7=getch();
        while(wall2[x2][y2]!=1 && wall2[x2][y2]!=2){


            switch(ch7) {
            case 75:
                while(1){
                    x2--;
                    printf("0");gotoxy(x2,y2);
                    Sleep(100);pts+=3;
                    if (kbhit()){ 
                        ch6 = getch(); 
                        ch7 = 0;
                        if (ch6 == 0xE0) 
                        { 
                            ch7=getch();}
                        break;}
                    if (wall2[x2][y2]!=0)
                        break;} 

                break;
            case 77:
                while(1){
                    x2++;
                    printf("0");gotoxy(x2,y2);
                    Sleep(100);
                    pts+=3;
                    if (kbhit()){ 
                        ch6 = getch(); 
                        ch7 = 0;
                        if (ch6 == 0xE0) 
                        { 
                            ch7=getch();}
                        break;}
                    if (wall2[x2][y2]!=0)
                        break;} 

                break; 
            case 72:
                while(1){
                    y2--;
                    printf("0");gotoxy(x2,y2);
                    Sleep(100);
                    pts+=3;
                    if (kbhit()){ 
                        ch6 = getch(); 
                        ch7 = 0;
                        if (ch6 == 0xE0) 
                        { 
                            ch7=getch();}
                        break;}

                    if (wall2[x2][y2]!=0)
                        break; }

                break;

            case 80:
                while (1){
                    y2++;
                    printf("0");gotoxy(x2,y2);
                    Sleep(100);pts+=3;
                    if (kbhit()){ 
                        ch6 = getch(); 
                        ch7 = 0;
                        if (ch6 == 0xE0) 
                        { 
                            ch7=getch();}
                        break;}

                    if (wall2[x2][y2]!=0)
                        break;} 

                break;

            default:
                printf("O");
                if (wall2[x2][y2]!=0)
                    break;
                break;}

        }}
    //display2ing
    if (wall2[x2][y2]==1){
        gotoxy(28,4);
        printf("Game Over\n");
        getch(); system("cls");
        total.score=pts;
        if ((fptr = fopen ("highscore.dat","ab+"))==NULL){
            printf("File cannot be opened\n");
        }
        else{
            fread (&temp, sizeof(struct hscore),1,fptr);
            //new highscore
            if (total.score>temp.score){
                fclose(fptr);
                fopen("highscore.dat","wb");
                fwrite(&total,sizeof (struct hscore),1,fptr);
                fclose(fptr);
                gotoxy(35,8);
                printf(" Name:%s\n\n\t Congratulations you made new highscore = %d\n",total.name,total.score);
            }
            else {
                gotoxy(35,8);
                printf ("Name:%s\n\n \tYour Score:%d\n\t Current highscore: %s  %d\n",total.name,total.score,temp.name, temp.score);
                fclose(fptr);
            }
        }
        
        
        return 0;
    }
    if (wall2[x2][y2]==2){
        gotoxy(28,4);
        printf("Level 3 Complete\n\t\tPress any key to END the game");
    pts+=1000;
    getch(); system("cls");
        total.score=pts;
        if ((fptr = fopen ("highscore.dat","ab+"))==NULL){
            printf("File cannot be opened\n");
        }
        else{
            fread (&temp, sizeof(struct hscore),1,fptr);
            //new highscore
            if (total.score>temp.score){
                fclose(fptr);
                fopen("highscore.dat","wb");
                fwrite(&total,sizeof (struct hscore),1,fptr);
                fclose(fptr);
                gotoxy(35,8);
                printf(" Name:%s\n\\tn Congratulations you made new highscore = %d\n",total.name,total.score);
            }
            else {
                gotoxy(35,8);
                printf ("Name:%s\n\n\t Your Score:%d\n \tCurrent highscore: %s  %d\n",total.name,total.score,temp.name, temp.score);
                fclose(fptr);
            }
        }
    
    
    }
    


    getch();
    
    return 0;

}

void gotoxy(int x, int y){

    HANDLE stdOutput;

    COORD pos;

    stdOutput = GetStdHandle(
        STD_OUTPUT_HANDLE);

    pos.X =x;

    pos.Y =y;

    SetConsoleCursorPosition(stdOutput, pos);}

void front()
{
    printf("        *              *          *        *       ************  ************\n"); 
    printf("       ***             **        **       ***      ************  ************\n");
    printf("       ***             ***      ***       ***      ************  ************\n");
    printf("      *****            ****    ****      *****              ***  ****        \n");
    printf("     **   **           *****  *****     **   **            ***   ****        \n");
    printf("    ***   ***          ************    ***   ***          ***    ************\n");
    printf("   ***     ***         *** **** ***   ***     ***        ***     ************\n");
    printf("   ***********         ***  **  ***   ***********       ***      ****        \n");
    printf("   ***********         ***   *  ***   ***********      ***       ****        \n");
    printf("   ***     ***  *****  ***      ***   ***     ***    **********  ************\n");
    printf("   ***     ***  *****  ***      ***   ***     ***   ***********  ************\n");
    printf("   ***     ***  *****  ***      ***   ***     ***  ************  ************\n");
}
