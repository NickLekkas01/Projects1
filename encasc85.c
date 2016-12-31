#include <stdio.h>

int main(void){
	unsigned int sum,ch,counter,counter1,ab,cd;
	counter=0;   /*Counter of all encoded characters*/
	counter1=1;  /* Counter for the four characters*/
	sum=0;
	printf("<~ \n");
	ch = getchar(); /* Read character */
	while (ch !=EOF ) { /* Go on if we didn't reach end of file */
		if (counter1==1) sum=sum+(256*256*256*ch);
		if (counter1==2) sum=sum+(256*256*ch);
		if (counter1==3) sum=sum+(256*ch);
		if (counter1==4) sum=sum+(ch);
		if (counter1==4) {
			if(sum==0) {
			    printf("z");
			    counter++;
			    if ((counter)%50==0) printf("\n");
			}
			else{
			ab=sum/(85*85*85*85);
			cd=sum%(85*85*85*85);
			putchar(ab+33);
			counter++;
			if ((counter)%50==0) printf("\n");
			ab=cd/(85*85*85);
			cd=cd%(85*85*85);
			putchar(ab+33);
			counter++;
			if ((counter)%50==0) printf("\n");
			ab=cd/(85*85);
			cd=cd%(85*85);
			putchar(ab+33);
			counter++;
			if ((counter)%50==0) printf("\n");
			ab=cd/(85);
			cd=cd%85;
			putchar(ab+33);
			counter++;
			if ((counter)%50==0) printf("\n");
			putchar(cd+33);
			counter++;
			if ((counter)%50==0) printf("\n");
			}
			counter1=0;
			sum=0;
			}
		counter1++;
		ch = getchar(); /* Read next character */
		if (ch==EOF){ /* If we run out of character*/
			if (counter1==4){
				ab=sum/(85*85*85*85);
				cd=sum%(85*85*85*85);
				putchar(ab+33);
				ab=cd/(85*85*85);
				cd=cd%(85*85*85);       /*if the given characters are 3, print 4 encoded char*/
				putchar(ab+33);
				ab=cd/(85*85);
				cd=cd%(85*85);
				putchar(ab+33);
				ab=cd/(85);
				cd=cd%85;
				putchar(ab+33);
				}
			else if(counter1==3){
			    ab=sum/(85*85*85*85);
				cd=sum%(85*85*85*85);
				putchar(ab+33);
				ab=cd/(85*85*85);
				cd=cd%(85*85*85);     /*if the given characters are 2, print 3 encoded char*/
				putchar(ab+33);
				ab=cd/(85*85);
				cd=cd%(85*85);
				putchar(ab+33);
				}
			else if(counter1==2){
				ab=sum/(85*85*85*85);
				cd=sum%(85*85*85*85);   /*if the given characters are 1, print 2 encoded char*/
				putchar(ab+33);
				ab=cd/(85*85*85);
				cd=cd%(85*85*85);
				putchar(ab+33);
				}
			printf("\n");
		}
	}
	printf("~>");
}
