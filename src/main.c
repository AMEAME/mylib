
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "utils.h"
#include "str.h"

int main()
{
	string s1 = "ikeuchi";
	string s2 = "kasmo";
	
	string s3 = concatl(s1, to);
	p(s3);
	
	string s4 = concat(s3, s2);
	p(s4);
	
	return 0;
}
