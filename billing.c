#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>



void read_input();
void write_file();
void search();
void output();

struct date{
	   int month;
	   int day;
	   int year;
	   };

  struct account {
	int number;
	char name[100];
	int accnt_no;
	float mobile_no;
	char street[100];
	char city[100];
	char account_type;
	float old_balance;
	float new_balance;
	float payment;
	struct date lastpayment;
  }customer;
  int tl,sl,ts;

int main()
{

    int i;
    int number_of_customer;
	char ch;

    printf("\t !** CUSTOMER BILLING SYSTEM **!\n");
    printf("=================================\n");
    printf("1:- To Add Account On List\n");
    printf("2:- To Search Customer Account\n");
    printf("3:- Exit\n");
    printf("=================================\n");

    do
    {
        printf("Select what you want to do?\n");
        ch=getchar();
    } while(ch<='0' || ch>'3');
    
    
    switch(ch){
		case '1':
    printf("\n How many customer accounts to be add? \n");
    scanf("%d",&number_of_customer);
    for (i = 0; i < number_of_customer; i++)
    {
        read_input();
        if(customer.payment > 0)
        {
            customer.account_type = (customer.payment < 0.1 * customer.old_balance) ? 'O' : 'D';
        }
        else {
            customer.account_type = (customer.old_balance > 0)?'D' : 'C';
            customer.new_balance = customer.old_balance - customer.payment;
            write_file();
        } /*main()*/
    }
        
    case '2':
    printf("\n Search customer & it's details by:\n");
    printf("\n i) Search by Customer Number");
    printf("\n ii) Search by Customer Name");
    search();
    ch=getchar();
    main();
    break;

    case '3':
    /* Code to be written for Exit */
    break;

    default:
    printf("Please choose a Valid Option");
        break;
    }
}

void read_input() {
    FILE *fp = fopen("billing.dat", "rb");
    fseek (fp, 0, SEEK_END);
    tl=ftell(fp);
    sl=sizeof(customer);
    ts = tl/sl;
    fseek(fp,(ts-1)*sl, SEEK_SET);
    fread(&customer, sizeof(customer),1,fp);
    printf("\n Customer Number:%d\n", ++customer.number);
    fclose(fp);

    printf(" Customer Account Number:");
    scanf("%d",&customer.accnt_no);
    
    printf("\n Customer Name:");
    scanf("%s",customer.name);

    printf("\n Customer Mobile no:");
	scanf("%f",&customer.mobile_no);
	
    printf(" Street:");
	scanf("%s",customer.street);

	printf(" City:");
	scanf("%s",customer.city);

	printf(" Previous balance:");
	scanf("%f",&customer.old_balance);

	printf("Current payment:");
	scanf("%f",&customer.payment);
	printf("         Payment date(mm/dd/yyyy):");
	scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	return;
}

void write_file() {
    FILE *fp;
    fp = fopen("billing.dat","ab");
    fwrite(&customer,sizeof(customer),1,fp);
    fclose(fp);
    return;
}

void search() 
{
    char ch;
    char nam[50];
    int i,n,m=1;
    FILE *fp;
    fp = fopen("billing.dat","rb");

    do
    {
        printf("Enter your choice");
        ch=getchar();
    } while (ch!='1' && ch!='2');

    switch(ch){
	      case '1':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    do{
			printf("\n Choose Customer Number:");
			scanf("%d",&n);
			if(n<=0 || n>ts)
			printf("\n Enter Correct Option \n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&customer,sl,1,fp);
			    output();
			}
			printf("\n\n Again? (y/n)");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
		    break;

	      case 2:
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    fseek(fp,(ts-1)*sl,SEEK_SET);
		    fread(&customer,sizeof(customer),1,fp);
		    n=customer.number;

		    do{
			printf("\n Enter the Name:");
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
			printf("\n\n Doesn't Exist\n");
			printf("\n Another? (y/n)");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
	      }
	      return;
    
}

void output()
	 {
	   printf("\n\n    Customer no    :%d\n",customer.number);
	   printf("    Name 	   :%s\n",customer.name);
	   printf("    Mobile no      :%.f\n",customer.mobile_no);
	   printf("    Account number :%d\n",customer.accnt_no);
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%.2f\n",customer.old_balance);
	   printf("    Current payment:%.2f\n",customer.payment);
	   printf("    New balance    :%.2f\n",customer.new_balance);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf("    Account status :");

	   switch(customer.account_type)
	      {
	      case 'C':
		 printf("Current\n\n");
		 break;
	      case 'O':
		 printf("Overdue\n\n");
		 break;
	      case 'D':
		 printf("Delimquent\n\n");
		 break;
	      default:
		 printf("Error!!\\n\n");
	      }
	     
	      return;
	   }