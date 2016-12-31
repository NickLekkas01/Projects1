#include <stdio.h>

int main(void){
	unsigned int ch,counter,counter1,sum,ab,cd,flag,a,b,c,k,i,n=0; 
	counter=0;   /*Counter of all encoded characters*/
	counter1=1;  /* Counter for the four characters*/
	sum=0;
	k=0;
	flag=0;
	ch = getchar();
	while(ch==' ' || ch=='\t' || ch=='\n' || ch==13) ch=getchar();
	if(ch!='<') flag=1;
	ch = getchar();
	while(ch==' ' || ch=='\t' || ch=='\n' || ch==13) ch=getchar();
	if(ch!='~') flag=1;
	if (flag==1) fprintf(stderr,"Bad start\n");
	ch = getchar(); /* Read character */
	while(ch==' ' || ch=='\t' || ch=='\n' || ch==13) ch=getchar();
	if ((ch<'!' || ch>'u') && ch!=EOF && ch!='~' && ch!='>' && ch!='z')
	 {
		   flag=1;
		   fprintf(stderr,"Bad input character\n");
	}
	a=ch;
	b=ch;
	c=ch;
	while (ch !=EOF && flag==0  ) { /* Go on if we didn't reach end of file */
 	     if(ch=='z' && counter1==1)
  		for(i=0;i<4;i++)
   		    putchar(0);
		else{
		ch=ch-33;
		if (counter1==1 && k==0) sum=sum+(85*85*85*85*ch);
		if (counter1==2 && k==0 && n==0) sum=sum+(85*85*85*ch);
		if (counter1==3 && k==0 && n==0) sum=sum+(85*85*ch);
		if (counter1==4 && k==0 && n==0) sum=sum+(85*ch);
		if (counter1==5 && k==0 && n==0) sum=sum+ch;
		if (counter1==5 && k==0 && n==0) {
			ab=sum/(256*256*256);    
			cd=sum%(256*256*256);
			putchar(ab);
			counter++;
			ab=cd/(256*256);
			cd=cd%(256*256);
			putchar(ab);
			counter++;
			ab=cd/(256);
			cd=cd%(256);
			putchar(ab);
			counter++;  
			if( c!='~')
			  {  
			   putchar(cd);
		        counter++;
			  }
			counter1=0;	
			sum=0;
		  }
 		  if(n==0)  /*If ch!='~' */
		     counter1++; 
	      }
		ch = getchar(); /* Read next character */
		while(ch==' ' || ch=='\t' || ch=='\n' || ch==13 ) ch=getchar();
		if (ch=='~') n=1;
		if (((ch=='z' && counter1!=1) || (ch<'!' || ch>'u' )&& ch!='z' ) && ch!=EOF && ch!='~' && ch!='>' ) {
		   flag=1;
		   fprintf(stderr,"Bad input character\n");
		}
		a=b;   /*a= 2 characterters before the last*/
		b=c;   /*b= 1 characterter before the last*/
		c=ch;  /*c= last char*/
		if (a=='~' && b=='>') k=1;
		if (ch==EOF){ /* If we run out of character*/
		    	counter1--;
		    if (k==0) flag=1;
		    if (flag==1) fprintf(stderr,"Bad end\n");
			if (b!='>' && k==1 ) fprintf(stderr,"Unnecessary Input\n");
			if (4-(counter1)==0){
				sum=sum+(84);
				ab=sum/(256*256*256);
				cd=sum%(256*256*256);
				putchar(ab);
				ab=cd/(256*256);   /*if the given char are 4, then print 3 decoded*/
				cd=cd%(256*256);
				putchar(ab);
				ab=cd/(256);
				cd=cd%(256);
				putchar(ab);
				}
			else if(4-(counter1)==1){
				sum=sum+((84*85)+84);
			    ab=sum/(256*256*256);
				cd=sum%(256*256*256);	/*if the given char are 3, then print 2 decoded*/
				putchar(ab);
				ab=cd/(256*256);
				cd=cd%(256*256);
				putchar(ab);
				}
			else if(4-(counter1)==2){
				sum=sum+((84*85*85)+(84*85)+84);	/*if the given char are 2, then print 1 decoded*/
				ab=sum/(256*256*256);
				cd=sum%(256*256*256);
				putchar(ab);
				}
		}
	}
}
