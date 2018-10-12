#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int result;
	opterr = 0;
	while((result = getopt(argc, argv, "sj:x::"))!=-1){	/*one colon for NECESSARY parameter 
							  	two colon for OPTIONAL parameter*/
		switch(result){
			case 's':
			printf("option=s, optopt=%c, optarg=%s", optopt,optarg);
			break;
			case 'j':
			printf("option=j, optopt=%c, optarg=%s", optopt,optarg);
			break;
			case 'x':
			printf("option=x, optopt=%c, optarg=%s", optopt,optarg);
			break;
			case '?':
			printf("result=?, optopt=%c, optarg=%s", optopt,optarg);
			break;
			default:
			printf("default, result=%c\n",result);
		}
		printf("argv[%d]=%s\n", optind, argv[optind]);
	}
	printf("result=-1,optind=%d\n", optind);
	for(result=optind;result<argc;result++)
		printf("-----argv[%d]=%s\n",result,argv[result]);
    for(result=1;result<argc;result++)
		printf("at the end-----argv[%d]=%s\n",result,argv[result]);
    return 0;
}
