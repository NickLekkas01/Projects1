#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***create(void)
{
    int i,j;
    char ***A;
    A=malloc(8*sizeof(char**));
    for(i=0 ; i<8 ; i++)
    {
        A[i]=malloc(8*sizeof(char*));
        for(j=0; j<8 ; j++)
            A[i][j]=malloc(50*sizeof(char));
    }
    strcpy(A[0][0],"T1");
    strcpy(A[0][1],"H1");
    strcpy(A[0][2],"I1");
    strcpy(A[0][3],"K");
    strcpy(A[0][4],"P");
    strcpy(A[0][5],"I2");
    strcpy(A[0][6],"H2");
    strcpy(A[0][7],"T2");
    strcpy(A[1][0],"S1");
    strcpy(A[1][1],"S2");
    strcpy(A[1][2],"S3");
    strcpy(A[1][3],"S4");
    strcpy(A[1][4],"S5");
    strcpy(A[1][5],"S6");
    strcpy(A[1][6],"S7");
    strcpy(A[1][7],"S8");
    strcpy(A[6][0],"s1");
    strcpy(A[6][1],"s2");
    strcpy(A[6][2],"s3");
    strcpy(A[6][3],"s4");
    strcpy(A[6][4],"s5");
    strcpy(A[6][5],"s6");
    strcpy(A[6][6],"s7");
    strcpy(A[6][7],"s8");
    for(i=2 ; i<6 ; i++)
        for(j=0 ; j<8 ; j++)
            strcpy(A[i][j],".");
    strcpy(A[7][0],"t1");
    strcpy(A[7][1],"h1");
    strcpy(A[7][2],"i1");
    strcpy(A[7][3],"p");
    strcpy(A[7][4],"k");
    strcpy(A[7][5],"i2");
    strcpy(A[7][6],"h2");
    strcpy(A[7][7],"t2");
    
    return A;
}

void print(char ***A)
{
    int i,j;
    printf("   ");
    for(j=0; j<8 ; j++)
        printf(" %-2d   ",j);
    printf("\n \n");
    for(i=0 ; i<8 ; i++)
    {
        printf("%d  ",i);
        for(j=0 ; j<8 ; j++)
        {
            printf(" %-2s   ",A[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int i;
    int TOWER_1[2];
    int HORSE_1[2];
    int IDIOT_1[2];
    int KING[2];
    int PRINCESS[2];
    int IDIOT_2[2];
    int HORSE_2[2];
    int TOWER_2[2];
    int SOLDIER[8][2];
    TOWER_1[0]=0; TOWER_1[1]=0;
    HORSE_1[0]=0; HORSE_1[1]=1;
    IDIOT_1[0]=0; IDIOT_1[1]=2;
    KING[0]=0; KING[1]=3;
    PRINCESS[0]=0; PRINCESS[1]=4;
    IDIOT_2[0]=0; IDIOT_2[1]=5;
    HORSE_2[0]=0; HORSE_2[1]=6;
    TOWER_2[0]=0; TOWER_2[1]=7;
    int soldier[8][2];

    for(i=0 ; i<8 ; i++)
    {
        SOLDIER[i][0]=1;
        SOLDIER[i][1]=i;
        soldier[i][0]=6;
        soldier[i][1]=i;
    }
    int tower_1[2];
    int horse_1[2];
    int idiot_1[2];
    int king[2];
    int princess[2];
    int idiot_2[2];
    int horse_2[2];
    int tower_2[2];
    
    tower_1[0]=7; tower_1[1]=0;
    horse_1[0]=7; horse_1[1]=1;
    idiot_1[0]=7; idiot_1[1]=2;
    princess[0]=7; princess[1]=3;
    king[0]=7; king[1]=4;
    idiot_2[0]=7; idiot_2[1]=5;
    horse_2[0]=7; horse_2[1]=6;
    tower_2[0]=7; tower_2[1]=7;

    char ***B;
    B=create();
    print(B);
    int a,b,c,d;
    int terminate=0;
    int j;
    int flag=0;
  while(terminate==0)
  {
    for( ; ; )
    {
        printf("Player 1:Pick a move \n"); 
        printf(".. .. to .. .. \n");
        scanf("%d %d",&a,&b);
        printf("to \n");
        scanf("%d %d",&c,&d);
        if(a<0 || b<0 || c<0 || d<0 || a>7 || b>7 || c>7 || d>7)
        {
            printf("Out of Bounds, try again\n");
            continue;
        }
        if(a==c && b==d)
        {
            printf("You must move the object in a different position,try again \n");
            continue;
        }
        if((strcmp(B[a][b],"T1")==0 || strcmp(B[a][b],"T2")==0) && c!=a && d!=b)
        {
            printf("Not proper move for the tower, try again \n");
            continue;
        }
        if(strcmp(B[a][b],"T1")==0 || strcmp(B[a][b],"T2")==0)
        {
        if(a!=c)
        {
            if(a<c)
            {
                for(i=a ; i<c ; i++)
                {
                    if(strcmp(B[i][d],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
            }
            else
            {
                for(i=a ; i>c ; i--)
                {
                    if(strcmp(B[i][d],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }    
                }
                if(flag==1)
                    continue;
                flag=0;
            }
        }
        else if(b!=d)
        {
            if(b<d)
            {
                for(i=b ; i<d ; i++)
                {
                    if(strcmp(B[c][i],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
            }
            else
            {   
                for(i=b ; i>d ; i--)
                {
                    if(strcmp(B[c][i],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }    
                }
                if(flag==1)
                    continue;
                flag=0;
            }
        }
        }
        if(strcmp(B[a][b],"H1")==0 || strcmp(B[a][b],"H2")==0)
        { 
            if(((c==a+2 && d==b+1) || (c==a+2 && d==b-1) || (c==a-2 && d==b+1) || (c==a-2 && d==b-1)))
            {}
            else
            {
                printf("Not proper move for the horse,try again \n");
                continue;
            }
        }
        if((strcmp(B[a][b],"I1")==0 || strcmp(B[a][b],"I2")==0) && (c==a || d==b))
        {
            printf("Not proper move for the Idiot, try again \n");
            continue;
        }
        if(strcmp(B[a][b],"I1")==0 || strcmp(B[a][b],"I2")==0)
        {
        if(a<c && b<d) 
        {
                for(i=a, j=b ; (i<c && j<d)  ; i++,  j++)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        else if(a<c && b>d)
        {
                for(i=a, j=b ; (i<c && j>d)  ; i++,  j--)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        else if(a>c && b<d)
        {
                for(i=a, j=b ; (i>c && j<d)  ; i--,  j++)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        else
        {
                for(i=a, j=b ; (i>c && j>d)  ; i--,  j--)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        }
        if(strcmp(B[a][b],"K")==0 && (c>a+1 || d>b+1 || c<a-1 || d<b-1))
        {
            printf("Not proper move for the King");
            continue;
        }
        if(strcmp(B[a][b],"P")==0)
        {
            if(a==c)
            {
                if(b<d)
                {
                    for(i=b ; i<d ; i++)
                    {
                        if(strcmp(B[c][i],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        }    
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
                else
                {
                    for(i=b ; i>d ; i--)
                    {
                        if(strcmp(B[c][i],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        }    
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
            }
            else if(b==d)
            {
                if (a<c)
                {
                    for(i=a ; i<c ; i++)
                    {
                       if(strcmp(B[i][d],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        } 
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
                else
                {
                    for(i=a ; i>c ; i--)
                    {
                       if(strcmp(B[i][d],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        } 
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
            }
        }
        if(strcmp(B[a][b],"S1")>=0 && strcmp(B[a][b],"S8")<=0)
        {
            if(a==1)
            {
                if((c>a+2 && b==d) || (c==a && d==b-1) || (c==a && d==b+1) || c==a-1 || (c==a+1 && d==b-1 && strcmp(B[c][d],".")==0) || (c==a+1 && d==b+1 && strcmp(B[c][d],".")==0))
                {
                        printf("Not proper move for the Soldier, try again \n");
                        continue;
                }
            }
            else
            {
                if((c>a+1 && b==d) || (c==a && d==b-1) || (c==a && d==b+1) || c==a-1 || (c==a+1 && d==b-1 && strcmp(B[c][d],".")==0) || (c==a+1 && d==b+1 && strcmp(B[c][d],".")==0))
                {
                        printf("Not proper move for the Soldier, try again \n");
                        continue;
                }
            }   
        }
        else if((strcmp(B[a][b],"S1")>=0 && strcmp(B[a][b],"S8")<=0) && (c>a+2 || d>b+2 ) && c==1)
        {
            printf("Not proper move for the Soldier, try again \n");
            continue;
        }
        if(strcmp(B[c][d],"A")>=0 && strcmp(B[c][d],"Z")<=0)
        {
            printf("You can't place it over your object,try again \n");
            continue;
        }
        else 
        {
            if(strcmp(B[c][d],"a")>=0 && strcmp(B[c][d],"z")<=0)
            {
                printf("CONGRATULATIONS you destroyed Player's 2 %s ! \n",B[c][d]);
                if(strcmp(B[c][d],"k")==0)
                    terminate=1;
            }
            if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=c; TOWER_1[1]=d; }
            if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=c; TOWER_2[1]=d; }
            if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=c; HORSE_1[1]=d; }
            if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=c; HORSE_2[1]=d; }
            if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=c; IDIOT_1[1]=d; }
            if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=c; IDIOT_2[1]=d; }
            if(strcmp(B[a][b],"K")==0)   { KING[0]=c; KING[1]=d; }
            if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=c; PRINCESS[1]=d; }
            if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=c; SOLDIER[0][1]=d; }
            if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=c; SOLDIER[1][1]=d; }
            if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=c; SOLDIER[2][1]=d; }
            if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=c; SOLDIER[3][1]=d; }
            if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=c; SOLDIER[4][1]=d; }
            if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=c; SOLDIER[5][1]=d; }
            if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=c; SOLDIER[6][1]=d; }
            if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=c; SOLDIER[7][1]=d; }

            for(i=0; i<8; i++) 
            {  
                if(soldier[i][0]==KING[0]+1  && (soldier[i][1]+1==KING[1] || soldier[i][1]-1==KING[1]))
                {
                    printf("Your King is in danger with this movement by the soldier %d \n",i);
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                    break;
                }
                if(flag==1)
                    continue;
                flag=0;
            }
            if(tower_1[0]==KING[0])
            {
                flag=1;
                if(tower_1[1]<KING[1])
                {
                    for(i=tower_1[1] ; i<KING[1]; i++)
                        if(strcmp(B[tower_1[0]][i],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                }
                else
                {
                    for(i=tower_1[1] ; i>KING[1]; i--)
                        if(strcmp(B[tower_1[0]][i],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                }
            }
            if(tower_1[1]==KING[1])
            {
                flag=1;
                if(tower_1[0]<KING[0])
                {
                    for(i=tower_1[0] ; i<KING[0]; i++)
                        if(strcmp(B[i][tower_1[1]],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                }
                else
                {
                    for(i=tower_1[0] ; i>KING[0]; i--)
                        if(strcmp(B[i][tower_1[1]],".")!=0)
                        {
                            flag=0;       
                            break;
                        }
                }
            }

            if(flag==1)
            {
                    printf("Your King is in danger with this movement by the tower_1 \n");
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;

            if(tower_2[0]==KING[0])
            {
                flag=1;
                if(tower_2[1]<KING[1])
                {
                    for(i=tower_2[1] ; i<KING[1]; i++)
                        if(strcmp(B[tower_2[0]][i],".")!=0)
                            flag=0;       
                }
                else
                {
                    for(i=tower_2[1] ; i>KING[1]; i--)
                        if(strcmp(B[tower_2[0]][i],".")!=0)
                            flag=0;      
                }
            }
            if(tower_2[1]==KING[1])
            {
                flag=1;
                if(tower_2[0]<KING[0])
                {
                    for(i=tower_2[0] ; i<KING[0]; i++)
                        if(strcmp(B[i][tower_2[1]],".")!=0)
                            flag=0;       
                }
                else
                {
                    for(i=tower_2[0] ; i>KING[0]; i--)
                        if(strcmp(B[i][tower_2[1]],".")!=0)
                            flag=0;      
                }
            }
            if(flag==1)
            {
                    printf("Your King is in danger with this movement by the tower_2 \n");
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;

            if(horse_1[0]+2==KING[0])
            {
                if(horse_1[1]+1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }
                else if(horse_1[1]-1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }
            }
            else if(horse_1[0]-2==KING[0])
            {
                if(horse_1[1]+1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }
                else if(horse_1[1]-1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }    
            }
            if(flag==1)
            {
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;
            
            if(horse_2[0]+2==KING[0])
            {
                if(horse_2[1]+1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }
                else if(horse_2[1]-1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }
            }
            else if(horse_2[0]-2==KING[0])
            {
                if(horse_2[1]+1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }
                else if(horse_2[1]-1==KING[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }    
            }
            if(flag==1)
            {
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=1;
            
            if(idiot_1[0]<KING[0])
            {
                if(idiot_1[1]<KING[1])
                {
                    for(i=idiot_1[0], j=idiot_1[1] ; (i<KING[0] && j<KING[1])  ; i++,  j++)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                        }
                    } 
                }
                else
                {
                    for(i=idiot_1[0], j=idiot_1[1] ; (i<KING[0] && j>KING[1])  ; i++,  j--)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                        }
                    } 
                }    
            }
            else
            {
                if(idiot_1[1]<KING[1])
                {
                    for(i=idiot_1[0], j=idiot_1[1] ; (i>KING[0] && j<KING[1])  ; i--,  j++)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                        }
                    }     
                }
                else
                {
                    for(i=idiot_1[0], j=idiot_1[1] ; (i>KING[0] && j>KING[1])  ; i--,  j--)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                        }
                    } 
                }    
            }

            if(flag==1)
            {
                    printf("Your King is in danger with this movement by the idiot_1 \n");
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=1;

                if(idiot_2[0]<KING[0])
                {
                    if(idiot_2[1]<KING[1])
                    {
                        for(i=idiot_2[0], j=idiot_2[1] ; (i<KING[0] && j<KING[1])  ; i++,  j++)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                            }
                        }    
                    }
                    else
                    {
                        for(i=idiot_2[0], j=idiot_2[1] ; (i<KING[0] && j>KING[1])  ; i++,  j--)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                            }
                        } 
                    }    
                }
                else
                {
                    if(idiot_2[1]<KING[1])
                    {
                        for(i=idiot_2[0], j=idiot_2[1] ; (i>KING[0] && j<KING[1])  ; i--,  j++)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                            }
                        }     
                    }
                    else
                    {
                        for(i=idiot_2[0], j=idiot_2[1] ; (i>KING[0] && j>KING[1])  ; i--,  j--)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                            }
                        } 
                    }    
                }

                if(flag==1)
                {
                    printf("Your King is in danger with this movement by the idiot_2 \n");
                    flag=1;
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;

                if(king[0]+1==KING[0])
                {
                    if(king[1]+1==KING[1])
                        flag=1;
                    else if(king[1]-1==KING[1])
                        flag=1;
                }
                else if(king[0]-1==KING[0])
                {
                    if(king[1]+1==KING[1])
                        flag=1;
                    else if(king[1]-1==KING[1])
                        flag=1;
                }

                if(flag==1)
                {
                    flag=1;
                    printf("Your King is in danger with this movement by the other king \n");
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=1;
                
                if(princess[0]==KING[0])
                {
                    if(princess[1]<KING[1])
                    {
                        for(i=princess[1] ; i<KING[1] ; i++)
                        {
                            if(strcmp(B[princess[0]][i],".")!=0)
                                flag=0;
                        }
                    }
                    else
                        for(i=princess[1] ; i>KING[1] ; i--)
                        {
                            if(strcmp(B[princess[0]][i],".")!=0)
                                flag=0;
                        }
                }
                else if(princess[1]==KING[1])
                {
                    if(princess[0]<KING[0])
                    {
                        for(i=princess[0] ; i<KING[0] ; i++)
                        {
                            if(strcmp(B[i][princess[1]],".")!=0)
                                flag=0;
                        }
                    }
                    else
                    {
                        for(i=princess[0] ; i>KING[0] ; i--)
                        {
                            if(strcmp(B[i][princess[1]],".")!=0)
                                flag=0;
                        }    
                    }
                }
                else
                {
                    if(princess[0]<KING[0])
                    {
                        if(princess[1]<KING[1])
                        {
                            for(i=princess[0], j=princess[1] ; (i<KING[0] && j<KING[1])  ; i++,  j++)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                }
                            }    
                        }
                        else
                        {
                            for(i=princess[0], j=princess[1] ; (i<KING[0] && j>KING[1])  ; i++,  j--)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                }
                            }    
                        }    
                    }
                    else
                    {
                        if(princess[1]<KING[1])
                        {
                            for(i=princess[0], j=princess[1] ; (i>KING[0] && j<KING[1])  ; i--,  j++)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                }
                            }     
                        }
                        else
                        {
                            for(i=princess[0], j=princess[1] ; (i>KING[0] && j>KING[1])  ; i--,  j--)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                }    
                            }
                        }
                    }
                }
                
                if(flag==1)
                {
                    flag=1;
                    printf("Your King is in danger with this movement by the princess \n");
                    if(strcmp(B[a][b],"T1")==0)  { TOWER_1[0]=a; TOWER_1[1]=b; }
                    if(strcmp(B[a][b],"T2")==0)  { TOWER_2[0]=a; TOWER_2[1]=b; }
                    if(strcmp(B[a][b],"H1")==0)  { HORSE_1[0]=a; HORSE_1[1]=b; }
                    if(strcmp(B[a][b],"H2")==0)  { HORSE_2[0]=a; HORSE_2[1]=b; }
                    if(strcmp(B[a][b],"I1")==0)  { IDIOT_1[0]=a; IDIOT_1[1]=b; }
                    if(strcmp(B[a][b],"I2")==0)  { IDIOT_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"K")==0)   { KING[0]=a; KING[1]=b; }
                    if(strcmp(B[a][b],"P")==0)   { PRINCESS[0]=a; PRINCESS[1]=b; }
                    if(strcmp(B[a][b],"S1")==0)  { SOLDIER[0][0]=a; SOLDIER[0][1]=b; }
                    if(strcmp(B[a][b],"S2")==0)  { SOLDIER[1][0]=a; SOLDIER[1][1]=b; }
                    if(strcmp(B[a][b],"S3")==0)  { SOLDIER[2][0]=a; SOLDIER[2][1]=b; }
                    if(strcmp(B[a][b],"S4")==0)  { SOLDIER[3][0]=a; SOLDIER[3][1]=b; }
                    if(strcmp(B[a][b],"S5")==0)  { SOLDIER[4][0]=a; SOLDIER[4][1]=b; }
                    if(strcmp(B[a][b],"S6")==0)  { SOLDIER[5][0]=a; SOLDIER[5][1]=b; }
                    if(strcmp(B[a][b],"S7")==0)  { SOLDIER[6][0]=a; SOLDIER[6][1]=b; }
                    if(strcmp(B[a][b],"S8")==0)  { SOLDIER[7][0]=a; SOLDIER[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;

            strcpy(B[c][d],B[a][b]);
            strcpy(B[a][b],".");
            break;
        }
        if(strcmp(B[a][b],"S")==0 && c==7)
        {
            char *answer;
            do
            {
                printf("What do you want to make your soldier? \n");
                scanf("%s",&answer);
               if(strcmp(answer,"P")==0)
                    strcpy(B[7][d],"P");
                else if(strcmp(answer,"I1")==0)
                    strcpy(B[7][d],"I1");
                else if(strcmp(answer,"I2")==0)
                    strcpy(B[7][d],"I2");    
                else if(strcmp(answer,"H1")==0)
                    strcpy(B[7][d],"H1");
                else if(strcmp(answer,"H2")==0)
                    strcpy(B[7][d],"H2");
                else if(strcmp(answer,"T1")==0)
                    strcpy(B[7][d],"T1");
                else if(strcmp(answer,"T2")==0)
                    strcpy(B[7][d],"T2");    
                else if(strcmp(answer,"K")==0)
                    printf("You can't make another King \n");

            }while(strcmp(answer,"P")!=0 || strcmp(answer,"I1")!=0 || strcmp(answer,"I2")!=0 || strcmp(answer,"H1")!=0 || strcmp(answer,"H2")!=0 || strcmp(answer,"T1")!=0 || strcmp(answer,"T2")!=0);
        }
    }
    print(B);
    for( ; ; )
    {
        printf("Player 2:Pick a move \n"); 
        printf(".. .. to .. .. \n");
        scanf("%d %d",&a,&b);
        printf("to \n");
        scanf("%d %d",&c,&d);
        if(a<0 || b<0 || c<0 || d<0 || a>7 || b>7 || c>7 || d>7)
        {
            printf("Out of Bounds, try again\n");
            continue;
        }
        if(a==c && b==d)
        {
            printf("You must move the object in a different position,try again \n");
            continue;
        }
        if((strcmp(B[a][b],"t1")==0 || strcmp(B[a][b],"t2")==0) && c!=a && d!=b)
        {
            printf("Not proper move for the tower, try again \n");
            continue;
        }
        if(strcmp(B[a][b],"t1")==0 || strcmp(B[a][b],"t2")==0)
        {
        if(a!=c)
        {
            if(a<c)
            {
                for(i=a ; i<c ; i++)
                {
                    if(strcmp(B[i][d],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
            }
            else
            {
                for(i=a ; i>c ; i--)
                {
                    if(strcmp(B[i][d],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }    
                }
                if(flag==1)
                    continue;
                flag=0;
            }
        }
        else if(b!=d)
        {
            if(b<d)
            {
                for(i=b ; i<d ; i++)
                {
                    if(strcmp(B[c][i],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
            }
            else
            {   
                for(i=b ; i>d ; i--)
                {
                    if(strcmp(B[c][i],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }    
                }
                if(flag==1)
                    continue;
                flag=0;
            }
        }
        }
        if(strcmp(B[a][b],"h1")==0 || strcmp(B[a][b],"h2")==0)
        { 
            if(((c==a+2 && d==b+1) || (c==a+2 && d==b-1) || (c==a-2 && d==b+1) || (c==a-2 && d==b-1)))
            {}
            else
            {
                printf("Not proper move for the horse,try again \n");
                continue;
            }
        }
        if((strcmp(B[a][b],"i1")==0 || strcmp(B[a][b],"i2")==0) && (c==a || d==b))
        {
            printf("Not proper move for the Idiot, try again \n");
            continue;
        }
        if(strcmp(B[a][b],"i1")==0 || strcmp(B[a][b],"i2")==0)
        {
        if(a<c && b<d) 
        {
                for(i=a, j=c ; (i<c && j<d)  ; i++,  j++)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        else if(a<c && b>d)
        {
                for(i=a, j=c ; (i<c && j>d)  ; i++,  j--)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        else if(a>c && b<d)
        {
                for(i=a, j=c ; (i>c && j<d)  ; i--,  j++)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        else
        {
                for(i=a, j=c ; (i>c && j>d)  ; i--,  j--)
                {
                    if(strcmp(B[i][j],".")!=0)
                    {
                        printf("There is another object in the middle, you can't move along,try again \n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    continue;
                flag=0;
        }
        }
        if(strcmp(B[a][b],"k")==0 && (c>a+1 || d>b+1 || c<a-1 || d<b-1))
        { 
            printf("Not proper move for the King");
            continue;
        }
        if(strcmp(B[a][b],"p")==0)
        {
            if(a==c)
            {
                if(b<d)
                {
                    for(i=b ; i<d ; i++)
                    {
                        if(strcmp(B[c][i],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        }    
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
                else
                {
                    for(i=b ; i>d ; i--)
                    {
                        if(strcmp(B[c][i],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        }    
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
            }
            else if(b==d)
            {
                if (a<c)
                {
                    for(i=a ; i<c ; i++)
                    {
                       if(strcmp(B[i][d],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=1;
                            break;
                        } 
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
                else
                {
                    for(i=a ; i>c ; i--)
                    {
                       if(strcmp(B[i][d],".")!=0)
                        {
                            printf("There is another object in the middle, you can't move along,try again \n");
                            flag=0;
                            break;
                        } 
                    }
                    if(flag==1)
                        continue;
                    flag=0;
                }
            }
        }
        if(strcmp(B[a][b],"s1")>=0 && strcmp(B[a][b],"s8")<=0)
        {
            if(a==6)
            {
                if((c<a-2 && b==d) || (c==a && d==b-1) || (c==a && d==b+1) || c==a+1 || (c==a-1 && d==b-1 && strcmp(B[c][d],".")==0) || (c==a-1 && d==b+1 && strcmp(B[c][d],".")==0))
                {
                        printf("Not proper move for the Soldier, try again \n");
                        continue;
                }
            }
            else
            {
                if((c<a-1 && b==d) || (c==a && d==b-1) || (c==a && d==b+1) || c==a+1 || (c==a-1 && d==b-1 && strcmp(B[c][d],".")==0) || (c==a-1 && d==b+1 && strcmp(B[c][d],".")==0))
                {
                        printf("Not proper move for the Soldier, try again \n");
                        continue;
                }
            }   
        }
        else if((strcmp(B[a][b],"S1")>=0 && strcmp(B[a][b],"S8")<=0) && (c>a+2 || d>b+2 ) && c==1)
        {
            printf("Not proper move for the Soldier, try again \n");
            continue;
        }
        if(strcmp(B[c][d],"a")>=0 && strcmp(B[c][d],"z")<=0)
        {
            printf("You can't place it over your object,try again \n");
            continue;
        }
        else 
        {
            if(strcmp(B[c][d],"A")>=0 && strcmp(B[c][d],"Z")<=0)
            {
                printf("CONGRATULATIONS you destroyed Player's 1 %s ! \n",B[c][d]);
                if(strcmp(B[c][d],"K")==0)
                    terminate=1;
            }
            if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=c; tower_1[1]=d; }
            if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=c; tower_2[1]=d; }
            if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=c; horse_1[1]=d; }
            if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=c; horse_2[1]=d; }
            if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=c; idiot_1[1]=d; }
            if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=c; idiot_2[1]=d; }
            if(strcmp(B[a][b],"k")==0)   { king[0]=c; king[1]=d; }
            if(strcmp(B[a][b],"p")==0)   { princess[0]=c; princess[1]=d; }
            if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=c; soldier[0][1]=d; }
            if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=c; soldier[1][1]=d; }
            if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=c; soldier[2][1]=d; }
            if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=c; soldier[3][1]=d; }
            if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=c; soldier[4][1]=d; }
            if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=c; soldier[5][1]=d; }
            if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=c; soldier[6][1]=d; }
            if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=c; soldier[7][1]=d; }

            for(i=0; i<8; i++) 
            {  
                if(SOLDIER[i][0]==king[0]-1  && (SOLDIER[i][1]+1==king[1] || SOLDIER[i][1]-1==king[1]))
                {
                    printf("Your King is in danger with this movement by the soldier %d \n",i);
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
                    break;
                }
                if(flag==1)
                    continue;
                flag=0;
            }
            if(TOWER_1[0]==king[0])
            {
                flag=1;
                if(TOWER_1[1]<king[1])
                {
                    for(i=TOWER_1[1] ; i<king[1]; i++)
                        if(strcmp(B[TOWER_1[0]][i],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                }
                else
                {
                    for(i=TOWER_1[1] ; i>king[1]; i--)
                        if(strcmp(B[TOWER_1[0]][i],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                }
            }
            if(TOWER_1[1]==king[1])
            {
                flag=1;
                if(TOWER_1[0]<king[0])
                {
                    for(i=TOWER_1[0] ; i<king[0]; i++)
                        if(strcmp(B[i][TOWER_1[1]],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                }
                else
                {
                    for(i=TOWER_1[0] ; i>king[0]; i--)
                        if(strcmp(B[i][TOWER_1[1]],".")!=0)
                        {
                            flag=0;
                            break;
                        }       
                }
            }

            if(flag==1)
            {
                    printf("Your King is in danger with this movement by the tower_1 \n");
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;

            if(TOWER_2[0]==king[0])
            {
                flag=1;
                if(TOWER_2[1]<king[1])
                {
                    for(i=TOWER_2[1] ; i<king[1]; i++)
                        if(strcmp(B[TOWER_2[0]][i],".")!=0)
                        {
                            flag=0;
                            break;
                        }       
                }
                else
                {
                    for(i=TOWER_2[1] ; i>king[1]; i--)
                        if(strcmp(B[TOWER_2[0]][i],".")!=0)
                        {
                            flag=0;
                            break;
                        }     
                }
            }
            if(TOWER_2[1]==king[1])
            {
                flag=1;
                if(TOWER_2[0]<king[0])
                {
                    for(i=TOWER_2[0] ; i<king[0]; i++)
                        if(strcmp(B[i][TOWER_2[1]],".")!=0)
                        {
                            flag=0;
                            break;
                        }       
                }
                else
                {
                    for(i=TOWER_2[0] ; i>king[0]; i--)
                        if(strcmp(B[i][TOWER_2[1]],".")!=0)
                        {
                            flag=0;
                            break;
                        }      
                }
            }
            if(flag==1)
            {
                    printf("Your King is in danger with this movement by the tower_2 \n");
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;

            if(HORSE_1[0]+2==king[0])
            {
                if(HORSE_1[1]+1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }
                else if(HORSE_1[1]-1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }
            }
            else if(HORSE_1[0]-2==king[0])
            {
                if(HORSE_1[1]+1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }
                else if(HORSE_1[1]-1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_1 \n");
                    flag=1;
                }    
            }
            if(flag==1)
            {
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
            }
                if(flag==1)
                    continue;
                flag=0;
            
            if(HORSE_2[0]+2==king[0])
            {
                if(HORSE_2[1]+1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }
                else if(HORSE_2[1]-1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }
            }
            else if(HORSE_2[0]-2==king[0])
            {
                if(HORSE_2[1]+1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }
                else if(HORSE_2[1]-1==king[1])
                {
                    printf("Your King is in danger with this movement by the horse_2 \n");
                    flag=1;
                }    
            }
            if(flag==1)
            {
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
            }
                if(flag==1)
                    continue;
                flag=1;
            
            if(IDIOT_1[0]<king[0])
            {
                if(IDIOT_1[1]<king[1])
                {
                    for(i=IDIOT_1[0], j=IDIOT_1[1] ; (i<king[0] && j<king[1])  ; i++,  j++)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                    } 
                }
                else
                {
                    for(i=IDIOT_1[0], j=IDIOT_1[1] ; (i<king[0] && j>king[1])  ; i++,  j--)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                    } 
                }    
            }
            else
            {
                if(IDIOT_1[1]<king[1])
                {
                    for(i=IDIOT_1[0], j=IDIOT_1[1] ; (i>king[0] && j<king[1])  ; i--,  j++)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                    }     
                }
                else
                {
                    for(i=IDIOT_1[0], j=IDIOT_1[1] ; (i>king[0] && j>king[1])  ; i--,  j--)
                    {
                        if(strcmp(B[i][j],".")!=0)
                        {
                            flag=0;
                            break;
                        }
                    } 
                }    
            }

            if(flag==1)
            {
                    printf("Your King is in danger with this movement by the idiot_1 \n");
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { IDIOT_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
            }
                if(flag==1)
                    continue;
                flag=1;

                if(IDIOT_2[0]<king[0])
                {
                    if(IDIOT_2[1]<king[1])
                    {
                        for(i=IDIOT_2[0], j=IDIOT_2[1] ; (i<king[0] && j<king[1])  ; i++,  j++)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        }    
                    }
                    else
                    {
                        for(i=IDIOT_2[0], j=IDIOT_2[1] ; (i<king[0] && j>king[1])  ; i++,  j--)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        } 
                    }    
                }
                else
                {
                    if(IDIOT_2[1]<king[1])
                    {
                        for(i=IDIOT_2[0], j=IDIOT_2[1] ; (i>king[0] && j<king[1])  ; i--,  j++)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        }     
                    }
                    else
                    {
                        for(i=IDIOT_2[0], j=IDIOT_2[1] ; (i>king[0] && j>king[1])  ; i--,  j--)
                        {
                            if(strcmp(B[i][j],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        } 
                    }    
                }

                if(flag==1)
                {
                    printf("Your King is in danger with this movement by the idiot_2 \n");
                    flag=1;
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
            }
                if(flag==1)
                    continue;
                flag=0;

                if(KING[0]+1==king[0])
                {
                    if(KING[1]+1==king[1])
                        flag=1;
                    else if(KING[1]-1==king[1])
                        flag=1;
                }
                else if(KING[0]-1==king[0])
                {
                    if(KING[1]+1==king[1])
                        flag=1;
                    else if(KING[1]-1==king[1])
                        flag=1;
                }

                if(flag==1)
                {
                    flag=1;
                    printf("Your King is in danger with this movement by the other king \n");
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; idiot_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=1;
                
                if(PRINCESS[0]==king[0])
                {
                    if(PRINCESS[1]<king[1])
                    {
                        for(i=PRINCESS[1] ; i<king[1] ; i++)
                        {
                            if(strcmp(B[PRINCESS[0]][i],".")!=0)
                            {
                                flag=0;
                                break;
                            }    
                        }
                    }
                    else
                        for(i=PRINCESS[1] ; i>king[1] ; i--)
                        {
                            if(strcmp(B[PRINCESS[0]][i],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        }
                }
                else if(PRINCESS[1]==king[1])
                {
                    if(PRINCESS[0]<king[0])
                    {
                        for(i=PRINCESS[0] ; i<king[0] ; i++)
                        {
                            if(strcmp(B[i][PRINCESS[1]],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(i=PRINCESS[0] ; i>king[0] ; i--)
                        {
                            if(strcmp(B[i][PRINCESS[1]],".")!=0)
                            {
                                flag=0;
                                break;
                            }
                        }    
                    }
                }
                else
                {
                    if(PRINCESS[0]<king[0])
                    {
                        if(PRINCESS[1]<king[1])
                        {
                            for(i=PRINCESS[0], j=PRINCESS[1] ; (i<king[0] && j<king[1])  ; i++,  j++)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                    break;
                                }
                            }    
                        }
                        else
                        {
                            for(i=PRINCESS[0], j=PRINCESS[1] ; (i<king[0] && j>king[1])  ; i++,  j--)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                    break;
                                }
                            }    
                        }    
                    }
                    else
                    {
                        if(PRINCESS[1]<king[1])
                        {
                            for(i=PRINCESS[0], j=PRINCESS[1] ; (i>king[0] && j<king[1])  ; i--,  j++)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                    break;
                                }
                            }     
                        }
                        else
                        {
                            for(i=PRINCESS[0], j=PRINCESS[1] ; (i>king[0] && j>king[1])  ; i--,  j--)
                            {
                                if(strcmp(B[i][j],".")!=0)
                                {
                                    flag=0;
                                    break;
                                }
                            } 
                        }    
                    }
                }
                
                if(flag==1)
                {
                    flag=1;
                    printf("Your King is in danger with this movement by the princess \n");
                    if(strcmp(B[a][b],"t1")==0)  { tower_1[0]=a; tower_1[1]=b; }
                    if(strcmp(B[a][b],"t2")==0)  { tower_2[0]=a; tower_2[1]=b; }
                    if(strcmp(B[a][b],"h1")==0)  { horse_1[0]=a; horse_1[1]=b; }
                    if(strcmp(B[a][b],"h2")==0)  { horse_2[0]=a; horse_2[1]=b; }
                    if(strcmp(B[a][b],"i1")==0)  { idiot_1[0]=a; idiot_1[1]=b; }
                    if(strcmp(B[a][b],"i2")==0)  { idiot_2[0]=a; IDIOT_2[1]=b; }
                    if(strcmp(B[a][b],"k")==0)   { king[0]=a; king[1]=b; }
                    if(strcmp(B[a][b],"p")==0)   { princess[0]=a; princess[1]=b; }
                    if(strcmp(B[a][b],"s1")==0)  { soldier[0][0]=a; soldier[0][1]=b; }
                    if(strcmp(B[a][b],"s2")==0)  { soldier[1][0]=a; soldier[1][1]=b; }
                    if(strcmp(B[a][b],"s3")==0)  { soldier[2][0]=a; soldier[2][1]=b; }
                    if(strcmp(B[a][b],"s4")==0)  { soldier[3][0]=a; soldier[3][1]=b; }
                    if(strcmp(B[a][b],"s5")==0)  { soldier[4][0]=a; soldier[4][1]=b; }
                    if(strcmp(B[a][b],"s6")==0)  { soldier[5][0]=a; soldier[5][1]=b; }
                    if(strcmp(B[a][b],"s7")==0)  { soldier[6][0]=a; soldier[6][1]=b; }
                    if(strcmp(B[a][b],"s8")==0)  { soldier[7][0]=a; soldier[7][1]=b; }    
                }
                if(flag==1)
                    continue;
                flag=0;
                
            strcpy(B[c][d],B[a][b]);
            strcpy(B[a][b],".");
            break;
        }
        if(strcmp(B[a][b],"s")==0 && c==0)
        {
            char *answer2;
            do
            {
                printf("What do you want to make your soldier? \n");
                scanf("%s",&answer2);
               if(strcmp(answer2,"p")==0)
                    strcpy(B[7][d],"p");
                else if(strcmp(answer2,"i1")==0)
                    strcpy(B[7][d],"i1");
                else if(strcmp(answer2,"i2")==0)
                    strcpy(B[7][d],"i2");    
                else if(strcmp(answer2,"h1")==0)
                    strcpy(B[7][d],"h1");
                else if(strcmp(answer2,"h2")==0)
                    strcpy(B[7][d],"h2");
                else if(strcmp(answer2,"t1")==0)
                    strcpy(B[7][d],"t1");
                else if(strcmp(answer2,"t2")==0)
                    strcpy(B[7][d],"t2");    
                else if(strcmp(answer2,"k")==0)
                    printf("You can't make another King \n");

            }while(strcmp(answer2,"p")!=0 || strcmp(answer2,"i1")!=0 || strcmp(answer2,"i2")!=0 || strcmp(answer2,"h1")!=0 || strcmp(answer2,"h2")!=0 || strcmp(answer2,"t1")!=0 || strcmp(answer2,"t2")!=0);
        }
    }
    print(B);
 }     
 return 0;   
}