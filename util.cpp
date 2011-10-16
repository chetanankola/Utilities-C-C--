#include "util.h"



void displaySpace(int num) {
	for(int i =0;i<num;i++) {
		fprintf(stdout," ");
	}
}

char* mydtoa(double number, int width, int precision)
{
	static char buffer[10][32];
	static int current = 0;
	char temp[32];
	char *ptr;

	if (width > 0) {
		if (precision > 0)
		{
			sprintf(temp, "%%%d.%df", width, precision);
		}
		else {
			sprintf(temp, "%%%df", width);

		}
	} else {
		if (precision > 0)
		{
			sprintf(temp, "%%.%df", precision);
		}
		else {
			sprintf(temp, "%%f");
		}
	}
	ptr = buffer[current];
	sprintf(ptr, temp, number);
	current++;
	current %= 10;
	return ptr;
}




/**
param1: 123 
return “123”
*/
char* myItoa(int num) {
	
	char *str = new char [32];
	int isnegative = 0;
	if(num == 0 ) {
		strcpy(str,"0");
		return str;
	}
	if(num<0) {
		num = num*(-1);
		isnegative = 1;
	}

	
	while(num!=0) {
		int rdigit = num%10;		///< rdigit holds 3 of 123
		num = num / 10;			///< update number 123 becomes 12
		str = prepend(str,rdigit);	
	}
	
	if(isnegative) {
		char* minstr = new char[32]; 
		strcpy(minstr,"-");
		strcat(minstr,str);
		delete str;
		return minstr;
	} 
	return str;
}
// prepend(“abc”,4 ) returns “4abc”
char* prepend(char *str, int num) {
	
	char *temp = new char[32];
	char a[2];
	char allnum[] = "0123456789";
	a[1] = '\0';
	a[0] = allnum[num];
	strcpy(temp,a);
	//fprintf(stdout,"-%s --%s  %d",str,temp,num);
	strcat(temp,str);
	delete str;
	return temp;
}


/* myatoi_failsonfirstnondigit: */
int myatoi(char *s)
{
    int i=0, n=0;
    while(s[i]==' ' || s[i]=='\t' || s[i]=='\n')
    {
   	 ++i;
    }

    for (; s[i] >= '0' && s[i] <= '9'; ++i)
   	 n = 10 * n + (s[i] - '0');
    return n;
}












