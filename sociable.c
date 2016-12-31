#include <stdio.h>
#include <math.h>
#define MAXCYC 28
#define MAXNUM 10000000

/* gia thn metaglwtish xrhsimopoieitai h entolh gcc sociable.c -o sociable -lm */

int main()
{
	int abc,sum, num,k,i,c,d,cycle,cur,mc,pl1,pl2,plall;
	sum=1;
	pl1=0;
	pl2=0;
	plall=0;
	for(num=2;num<=MAXNUM;num++)
	{
		k=0;         
		cur=num;       /* Na diathrei thn arxikh timh tou ari8mou*/
		for(cycle=1;(cycle<=MAXCYC && k==0);cycle++ )
    	{
    		abc=sqrt((double)num);
    		for(i=2;i<=abc;i++)
    	    {
		   		if(num%i==0)            /* Euresh tou athroismatos twn diairetwn*/
			    {
				sum+=i;
			    long d = num/i;
				if(d!=i)
				  sum+=d;
				}
			}
    	   if (sum==cur && k==0)
    	    {
    	      plall+=1;	            /* Plh8os olwn twn kyklwn*/
    	      if (cycle==1)				/*Plh8os twn teleiwn*/
    	         pl1+=1;
    	      if (cycle==2)				/*Plh8os twn filiwn*/
    	         pl2+=1;
			  printf("Cycle of length %d",cycle);
			  printf(": %d ",cur);
		      k=1; 						/* An einai sociable na stamathsei na psaxnei tous allous kuklous */
		      mc=cycle;					/*O teleutaios kuklos pou vre8hke o sociable*/
		      num=cur;					/*Na gurisei h timh poy eixe sthn arxh o numb*/
		      sum=1;
			  for(c=1;c<=mc;c++ )
    		  {
    		  		abc=sqrt((double)num);
    		 		for(i=2;i<=abc;i++)
    	    		{
		   				if(num%i==0)
		   				  {
			    			sum+=i;		/*Efoson vre8hke kapoios sociable na ksanaginei o kuklos gia na emfanistoyn ta sum*/
							long d = num/i;
							if(d!=i)
								sum+=d;
						  }
					}
					printf("%d ",sum);
					num=sum; 
					sum=1;
	    	  } 
	    	  printf("\n");
	    	}
	    	if (cur>sum || sum>MAXNUM)		/*Na mhn emfanistoyn oi kukloi pou eexoume hdh vrei kai autoi pou to a8roisma 3epernaei to maxnum*/
	    	{
	    	    k=1;
	    	}
		    num=sum;           /*Na ektelestei h timh tou sum sth sunarthsh*/
			sum=1;	
				
		}
  			num=cur;		/*Na epistrafei h timh tou current sto num wste na 3anaginei h diadikasia gia ton epomeno ari8mo*/
	}
	printf("Found %d cycles including \n",plall);
	printf("%d cycles with perfect numbers and \n",pl1);
	printf("%d cycles with amicable numbers",pl2);
	return 0;
}



