
#include "../inc/function.h"

   void output()
	 {
	   printf("\n\n Customer no    :%d\n",customer.number);
	   printf(" Name 	   :%s\n",customer.name);
	   printf(" Mobile no      :%.f\n",customer.mobile_no);
	   printf(" Account number :%d\n",customer.acct_no);
	   printf(" Street         :%s\n",customer.street);
	   printf(" City           :%s\n",customer.city);
	   printf(" Old balance    :%.2f\n",customer.oldbalance);
	   printf(" Current payment:%.2f\n",customer.payment);
	   printf(" New balance    :%.2f\n",customer.newbalance);
	   printf(" Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf(" Account status :");
	   switch(customer.acct_type)
	      {
	      case 'C':
		  printf("CURRENT\n\n");
		 break;
	      case 'O':
		  printf("OVERDUE\n\n");
		 break;
	      case 'D':
		  printf("DELINQUENT\n\n");
		 break;
	      default:
		  printf("ERROR\\n\n");
	      }

	      return;
	}