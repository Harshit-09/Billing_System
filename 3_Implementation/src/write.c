#include "../inc/function.h"
void writefile()
   {
	  FILE *fp;
	  fp=fopen("billing.dat","ab");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }