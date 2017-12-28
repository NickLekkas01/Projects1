#include <stdio.h>
#include <stdlib.h>

unsigned char buffer = 0x00;
int count = 0;


char FindComm(char i)                       /* Find Comments and Ignore them */
{
	
	while (i == '#')                     /* "#" determines the existence of a comment */
    {
		while (i!= '\n')
		{
			i= getchar();
		}
		i= getchar(); 
	}
	return i;
}


void printBin(unsigned char c,int x,int width)                        /* 8 bits stored in one byte */
{
	buffer= buffer << 1;                    
    count ++;
    if(c=='1')							
        buffer |= 0x01;			
    else
        buffer |=0x00;    
    if(x==width-1 && width%8!=0)
    {
        while(count<8)
        {
            buffer=buffer<<1;
            buffer |= 0x01;
            count++;
        }
    }
    if(count==8)
    {
        putchar(buffer);
        count=0;
        buffer=0x00;
    }					
}




int main(int argc,char*argv[])
{   
	unsigned char c,d,pix;
	int comment;
	int option=atoi(argv[1]);          /* Option=0 for Binary->Binary and Ascii->Ascii, Option=1 for Binary->Ascii and Ascii->Binary */
	c=getchar();	/* Magic number (P) */
	d=getchar();	/* Magic number (6,5,3,2) */
	
	
	if(c!='P')
	{ 
		printf("Error \n");    /* First character must be P */
		return -1;
	}
	
	if(d!='6' && d!='5' && d!='3' && d!='2')
	{	
		printf("Error \n");    /* Second character must be 6 or 5 or 3 or 2 */
		return -1;
    }
    
    
    if (option==0)
    {
   		printf("%c%c \n",c,d-1);        /* P6->P5  , P5->P4  ,  P3->P2  ,  P2->P1 */
   	}
   	if (option==1)
	{
		if (d=='3' || d=='2')
		{
			printf("%c%c \n",c,(d+2));     /* P3->P5   ,    P2->P4 */
		}
		if(d=='5' || d=='6')
		{
			printf("%c%c \n",c,(d-4));    /* P6->P2   ,    P5->P1 */
		}
	}    
    
	
	   
    do
	{
    	pix= getchar();		/*Ignore white spaces*/
	}while ( pix==' ' || pix=='\n' || pix=='\t');
	
	
	pix=FindComm (pix);
	
		
	int width,height, maxnum, num, a=10;      
	
	
    scanf("%d",&num);       /* Read width without the lost number from do{}while */
    
    
    while ((num/a)!=0)   			/* to find the multiple of the number we lost */
		a=a*10;
	
	width= num + ((pix - '0') * a); 	/* (pix - '0') to convert char "pix" to integer */          
										 /* ((pix - '0') * a) is that one number we lost because of our last do{}while */
	
	printf("%d ",width);
    
    do
	{
    	pix= getchar();				 /*Ignore white spaces*/
	}while ( pix==' ' || pix=='\n' || pix=='\t');
    	
    	
    scanf("%d",&num);     	/* Read height without the lost number from do{}while*/
    
    a=10;
    while ((num/a)!=0)         /* to find the multiple of the number we lost */
		a=a*10;
	
	height= num + ((pix - '0') * a); 	/* (pix - '0') to convert char "pix" to integer */        
										   /* ((pix - '0') * a) is that one number we lost because of our last do{}while */
    printf("%d \n",height); 
   
    do
    {
    	pix= getchar();		/*Ignore white spaces*/
	}while ( pix==' ' || pix=='\n' || pix=='\t');
	
	
	scanf("%d", &num);    /* Read possible max number without the number we lost */
	
	a=10;
    while ((num/a)!=0)         /* to find the multiple of the number we lost */
		a=a*10;
	
	maxnum= num + ((pix - '0') * a);  	 /* (pix - '0') to convert char "pix" to integer */      
											/* ((pix - '0') * a) is that one number we lost because of our last do{}while */
											
    if (d=='6' || d=='3') 
    {
    	printf("%d \n",maxnum);        /* From P5 to P4 and P2 to P1 we don't need the max number */
	}
	
	
	getchar();   			/* ignore a single one white space */
	
    int x , y;
    
    if(d=='2' || d=='3')  /* Ascii encoding */
    {
    	if(d=='2')       /* Case P2 */
    	{
    		
			for(y = 0; y< height; y++)
			{
				for(x = 0; x<width; x++)
				{
					int num;
					scanf("%d", &num);	
					if ((unsigned int) num > (unsigned int)((maxnum+1)/2) )   /* If  "number of gray pixel"is bigger than half, print white else black */
					{
						if (option==0)
						{
							printf("0");
						}
						
						if (option==1)
						{
							printBin('0',x,width);      /* to binary */
					    } 
					}
					else
					{
						if (option==0)
						{
							printf("1");
						}
						
						if (option==1)
						{
							printBin('1',x,width);   /* to binary */
						}
					}
			    }
		    }
		}
		else						/*  Case P3 */
		{
			for(y = 0; y< height; y++)
			{
				for(x = 0; x<width; x++)
				{
					int R, G, B;
					scanf("%d", &R);
					scanf("%d", &G);
					scanf("%d", &B);
					
					if (option==0)
					{
						double pixel= (0.299 * R) + (0.587 * G) + (0.114 * B);		/* Ascii -> Ascii */	
						printf(" %d ", (int)pixel);
					}
					
					if (option==1)
					{
						putchar((R*0.299)+(G*0.587)+B*(0.114));             /* Ascii -> Binary */
					}
					
					
				}
			}
		}            	
	}
	else             	/* Binary Encoding */
	{
		if(d=='5')      /* Case P5: Grayscale to BlackAndWhite (Binary-> ?) */
		{
		
			int counter=0, counter2=0 ;
			
			for(y = 0; y< height; y++)
			{
				for(x = 0; x<width; x++)
				{
					/* Cast getchar() to unsigned in order to prevent overflows.
					 * For example : 10010010 as a char would be treated as -110 and not as 146 
					 * the desired behaviour. 
					 */
					// (char) 10010010 -> 146 wrong -18
					unsigned char pix2 ;
					pix2= getchar();
					if (pix2 > (int)((maxnum+1)/2) )   /* If  "number of gray pixel"is bigger than half, print white else black */ 
					{ 								/* White */
							if (option==0)
							{
								printBin('0',x,width);  
							}
                            
							if (option==1)
							{
								putchar('0');         /* Binary -> Ascii */
							}
					} else	
					{								/* Black */
                            if (option==0)
							{
								printBin('1',x,width);
							}
							
                            if (option==1)
							{
								putchar('1');        /* Binary -> Ascii */
					        }
					}
                    
				}
			}
			
			
			 
	
		}
		else            /* Case P6 */
		{
			for(y = 0; y< height; y++)
			{
				for(x = 0; x<width; x++)
				{
					unsigned char R, G, B;                              /* Red, Green, Blue */
					R=getchar();
					G=getchar();
					B=getchar();
					
					if (option==0)
					{
						putchar((R*0.299)+(G*0.587)+B*(0.114));             /* Binary-> Binary */
					}
					
					if (option==1)
					{
						double pixel= (0.299 * R) + (0.587 * G) + (0.114 * B);  	/* Binary -> Ascii */		                                                        
						printf(" %d ", (int)pixel);		
					}
			    }
		    }
		}
	}    
    
    
    
    
	
	return 0;
}
