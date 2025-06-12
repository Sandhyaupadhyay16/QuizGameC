#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
enum b
{
    false,
    true
};
void main(void)
{
    int ch;
    char l, answer;
    clrscr();
    printf("\n\n\n\n\n\n\n");
    printf("-------------------------------Welcome To The Quiz------------------------------\n");
    printf("	      +-------+                          _______       _______ \n ");
    printf(" 	      |       |      |         |            |                / \n ");
    printf("             |       |      |         |            |               /  \n ");
    printf("  	      |       |      |         |            |              /   \n ");
    printf("             |    // |      |         |            |             /    \n ");
    printf("  	      |   //  |      |         |            |            /     \n ");
    printf("  	      +--//---+      |_________|         ___|___        /______\n ");
    printf("\n");
    printf("-------------------------------Welcome To The Quiz------------------------------\n");
    getch();
    clrscr();
    printf("\n----------------------------------RULES OF THE GAME----------------------------");
    printf("\n\n\n                      ->THERE ARE TOTAL 10 QUESTIONS");
    printf("\n                      ->10 MARKS WILL BE AWARDED FOR CORRECT ANSWER");
    printf("\n                      ->NO MARKS WILL BE AWARDED FOR INCORRECT");
    printf("\n                      ->TOTAL SCORE WILL BE SHOWN AT END\n");
    printf("\n--------------------------------------------------------------------------------");
    printf("\n                      Press 1 to open General Knowledge Quiz ");
    printf("\n                      Press 2 to open Computer Programming Quiz ");
    printf("\n                      Press 3 to open Social Science Quiz ");
    printf("\n                      Press 4 to open Science Quiz ");
    printf("\n                      Press 5 to open English Grammer Quiz ");
    printf("\n                      Press 6 to open Quit the game");
    printf("\n\n\n                            Enter Your Choice =  ");
    scanf("%d", &ch);
    clrscr();
    FILE *p;
    switch (ch)
    {
    case 1:
        p = fopen("GK.txt", "r");
        break;
    case 2:
        p = fopen("CO.txt", "r");
        break;
    case 3:
        p = fopen("social.txt", "r");
        break;
    case 4:
        p = fopen("science.txt", "r");
        break;
    case 5:
        p = fopen("grammer.txt", "r");
        break;
    case 6:
        exit(1);
        break;
    default:
        printf("\n\n\n\n\n\n\n\n\n");
        printf("----------------------------------Invalid Choice--------------------------------");
        printf("\n\n                            !!PRESS ANY KEY TO EXIT!!  \n");
        getch();
        exit(1);
    }
    int score, g;
    char buffer[900];
    srand(time(0));
    int data[10], count = 0, in = 0;
    for (int c = 0; c < 10; c++)
    {
        b found = false;
        while (!found)
        {
            data[c] = rand() % 50 + 1;
            found = true;
            for (int r = 0; r < c; r++)
            {
                if (data[c] == data[r])
                {
                    found = false;
                }
            }
        }
    }
    for (c = 0; c < 10; c++)
    {
        g = data[c];
        for (int f = 0; f < (g - 1) * 6; f++)
        {
            fgets(buffer, 900, p);
        }
        printf("\n\n\n\n\n");
        printf("Ques%d-> ", c + 1);
        for (int z = 0; z < 5; z++)
        {
            printf("%s ", fgets(buffer, 900, p));
        }
        printf("\nEnter Your Answer =  ");
        scanf(" %c", &answer);
        fflush(stdin);
        answer = tolower(answer);
        l = *fgets(buffer, 900, p);
        printf("\n--------------------------------------------------------------------------------");
        if (answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd')
        {
            in++;
            printf("\n                               INVALID CHOICE\n                             Correct Option is %c\n", l);
        }
        else if (answer == l)
        {
            count++;
            printf("\n                               Correct Answer\n");
        }
        else
        {
            in++;
            printf("\n                              Incorrect Answer\n                          The Correct option is %c \n", l);
        }
        printf("\n--------------------------------------------------------------------------------");
        rewind(p);
        getchar();
        clrscr();
    }
    printf("\n\n\n\n\n\n\n\n");
    printf("                              !!CONGRATULATIONS!!\n\n--------------------------------------------------------------------------------\n");
    printf("                           Total Correct Answers = %d \n", count);
    printf("                           Total Incorrect Answers =%d \n", in);
    printf("                           Total Score = %d out of %d \n", count * 10, (10 * (in + count)));
    printf("\n--------------------------------------------------------------------------------\n");
    fclose(p);
    getch();
}
