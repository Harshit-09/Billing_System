#include "../inc/function.h"
int tl,sl,ts;
void search()
   {
	 char ch;
	 char nam[100];
	 int n,i,m=1;
	 FILE *fp;
	 fp=fopen("billing.dat","rb");
	 do{
		printf("\nenter your choice:");
		ch=getchar();
	 }while(ch!='1' && ch!='2');
	 switch(ch){
	      case '1':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    do{
			printf("\nchoose customer number:");
			scanf("%d",&n);
			if(n<=0 || n>ts)
			printf("\nenter correct\n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&customer,sl,1,fp);
			    output();
			}
			printf("\n\nagain?(y/n)");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
		    break;
	      case '2':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    fseek(fp,(ts-1)*sl,SEEK_SET);
		    fread(&customer,sizeof(customer),1,fp);
		    n=customer.number;

		    do{
			printf("\nenter the name:");
			scanf("%s",nam);
			fseek(fp,0,SEEK_SET);
			for(i=1;i<=n;i++)
			{
			     fread(&customer,sizeof(customer),1,fp);
			     if(strcmp(customer.name,nam)==0)
			     {
				output();
				m=0;
				break;
			     }
			}
			if(m!=0)
			printf("\n\nDoesn't exist\n");
			printf("\nAnother / Want to Try Again?(y/n)");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
	      }
	      return;
	 }