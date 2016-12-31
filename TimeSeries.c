#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double dtwrec(int,int,double*,double*,double);
double dtwdp(int,double*,double*,double);

int main (int argc, char *argv[])
{
	int n,m,trainc,testc,i,l1,l2,*K1,*K2,minplace;
	double **A,**B,c,dist,min,end_time,start_time,elapsed_time,counter=0.0;
	start_time = clock();
	if (argc==1)
		c=INFINITY;
	else
		c=atoi(argv[1]);
	/*printf("Give the number of training set's "); */
    	scanf("%d",&trainc);
	/*printf("Give the lines of each timeline: ");*/
	scanf("%d",&l1);
	A=malloc(trainc*sizeof(double*));
	K1=malloc(trainc*sizeof(int));
	if (A==NULL || K1==NULL)
	{
		printf("Sorry, cannot allocate memory\n");
		return -1;
	}
	for (i=0 ; i<trainc ; i++)
	{
		A[i]=malloc(l1*sizeof(double));
		if (A[i]==NULL)
		{
			printf("Sorry, cannot allocate memory\n");
			return -1;
		}
	}
	/*printf("Read the numbers for A\n");*/
	for (i=0 ; i<trainc ; i++)
	{	
		scanf("%d",&K1[i]);
		for(n=0 ; n < l1 ; n++)
		{
			scanf("%lf",&A[i][n]);
		}
	}
	/*printf("Give the number of test set's "); */
    scanf("%d",&testc);
	/*printf("Give the lines of each timeline: ");*/
	scanf("%d",&l2);
	if (l1!=l2)  
		return -1;
	B=malloc(testc*sizeof(double*));
	K2=malloc(testc*sizeof(int));
	if (B==NULL || K2==NULL)
	{
		printf("Sorry, cannot allocate memory\n");
		return -1;
	}
	for (i=0 ; i<testc ; i++)
	{
		B[i]=malloc(l1*sizeof(double));
		if (B[i]==NULL)
		{
			printf("Sorry, cannot allocate memory\n");
			return -1;
		}
	}
	/*printf("Read the numbers for B\n");*/
	for (i=0 ; i<testc ; i++)
	{	
		scanf("%d",&K2[i]);
		for(n=0 ; n < l1 ; n++)
		{
			scanf("%lf",&B[i][n]);
		}
	}
	for (i=0; i<testc ; i++)
	{
		min=INFINITY;
		for (n=0; n<trainc ; n++)
		{
			#ifdef REC
				dist=dtwrec(l1,l1,A[n],B[i],c);
			#else
	        		dist=dtwdp(l1,A[n],B[i],c);
			#endif
		   	if (dist<min)
		   	{
		   		min=dist;
				minplace=n;
		   	}
		}
		printf("Series %d (class %d) is nearest ",(i+1),K2[i]); 
		printf("(distance %lf) to series %d (class %d) \n",min,(minplace+1),K1[minplace]);
		if (K2[i]!=K1[minplace])
			counter++;
	}
	for (i=0 ; i<trainc ; i++)
		free(A[i]);
	for (i=0 ; i<testc ; i++)
		free(B[i]);
	free(A);
	free(B);
	printf("Error rate: %lf \n",counter/testc);
	end_time = clock();
	elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
	printf("CPU time:%lf \n",elapsed_time);
	return 0;
}

double dtwrec(int l1,int l2,double *A,double *B,double c)
{
	double min,k,d;
	int big,small;
	d=(A[l1]-B[l2])*(A[l1]-B[l2]);
	
	if (l1==1 && l2==1 )
	{
		if (abs(l1-l2)<=c)
			return d;
		else
			return INFINITY;
	}
	else if (l1>1 && l2==1)
	{
		if (abs(l1-l2)<=c)
			return d+dtwrec(l1-1,l2,A,B,c);
		else
			return INFINITY+dtwrec(l1-1,l2,A,B,c);
	}
	else if (l1==1 && l2>1)
	{
		if (abs(l1-l2)<=c)
			return d+dtwrec(l1,l2-1,A,B,c);
		else
			return INFINITY+dtwrec(l1,l2-1,A,B,c);
	}
	else
	{
		min=dtwrec(l1,l2-1,A,B,c);
		k=dtwrec(l1-1,l2,A,B,c);
		if(k<min)
			min=k;
		k=dtwrec(l1-1,l2-1,A,B,c);
		if(k<min)
			min=k;
		if (abs(l1-l2)<=c)
			return d+min;
		else
			return INFINITY+min;
	}
}

double dtwdp(int l1,double *A,double *B,double c)
{
	int n,m,big,small,line=1,i,j,st,end;
	double **P,min,k,value;
	P=malloc(2*sizeof(double*));
	if (P==NULL)
	{
	        printf("Sorry, cannot allocate memory\n");
            	return -1;
    	}
	for (n=0 ; n<2 ; n++)
	{
		P[n]=malloc((l1)*sizeof(double));
		if (P[n]==NULL)
		{
                	printf("Sorry, cannot allocate memory\n");
                	return -1;
        	}
	}
	
	for(n=0 ; n<l1 ; n++)
	{
		if (line==0)
			line=1;
		else 
			line=0;	
		if (n-c<0)
			st=0;
		else
			st=n-c;
		if (n+c>l1)
			end=l1;
		else 
			end=n+c;
		{
		for(m=st ; m<=end ; m++)
			if (n==0 && m==0)
				P[line][m]=(A[n]-B[m])*(A[n]-B[m]);
			else if (n>0 && m==0 && abs(n-m)<=c){
				if (line==0)
                			P[line][m]=((A[n]-B[m])*(A[n]-B[m]))+P[line+1][m];
				else if (line==1)
					P[line][m]=((A[n]-B[m])*(A[n]-B[m]))+P[line-1][m];
			}
	        	else if (n==0 && m>0 && abs(n-m)<=c)
					P[line][m]=((A[n]-B[m])*(A[n]-B[m]))+P[line][m-1];
			else if(n>0 && m>0 && abs(n-m)<=c)
        		{
					min=INFINITY;
					k=P[line][m-1];
					if(k<min && n-(m-1)<=c)
                        			min=k;
					if (line==0)
					{
                				k=P[line+1][m];
                				if(k<min && m-(n-1)<=c)
                        				min=k;
                				k=P[line+1][m-1];
                				if(k<min)
                        				min=k;
					}
					else if (line==1)
					{
						k=P[line-1][m];
                				if(k<min && m-(n-1)<=c)
                        				min=k;
                				k=P[line-1][m-1];
                				if(k<min)
                        				min=k;
					}
                			P[line][m]=(A[n]-B[m])*(A[n]-B[m])+min;	
			}
		}
	}
	value=P[line][l1-1];
	for (n=0 ; n<2 ; n++)
		free(P[n]);
	free(P);
	return value;
}
