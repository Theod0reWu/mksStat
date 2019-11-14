#include "stat.h"

int main(int argc, char const *argv[]) {
  struct stat info;
  stat("program", &info);
  int size = info.st_size;
  int mode = info.st_mode;
  char* time_stamp =  ctime(&info.st_atime);
  printf("The executable program file\n");
  printf("size: %i\n", size);
  printf("permissions: %i\n", mode);
  printf("access time: %s \n", time_stamp);

  printf("There are ");
  if (size >= pow(10,9)){
  	printf("%d Gigabytes", (double)size / pow(10,9) );
  }else {
  	printf("%i Bytes", size); //I doubt there could be more than a gigbyte in an .exe file
  } printf(" in the file\n\n");
  
  mode = mode & (int) pow(2,9)-1;
  int smode [3]; int i = 2;
  while (mode > 0){
  	//printf("%i\n", mode % 8);
  	smode[i] = mode % 8;
  	mode = mode / 8;
  	i--;
  }
  printf("-----------------------------------------------\n");
  printf("custom ls -l for the program executable file:\n-----------------------------------------------\n");
  printf("-");
  for (i = 0; i < 3; i++){
  	char s [3];
  	for (int p = 0; p < 3; ++p)
  	{
  		//printf("%i : %i \n", p, smode[i]);
  		if (p == 0 && smode[i] % 2 == 1){s[0] = 'r' ;}
  		else if (p == 1 && smode[i]  % 2 == 1) {s[1]= 'w';}
  		else if (p == 2 && smode[i]  % 2 == 1) {s[p] = 'x';}
  		else {s[p] = '-';}
  		smode[i] = smode[i] / 2;
  	}
  	printf("%s", s);
  }
  printf(" %s", getpwuid(info.st_uid)->pw_name);
  printf(" %i", info.st_uid);
  printf(" %i", size);
  char*t;
  strncpy(t,time_stamp+4, 12);
  printf(" %s", t);
  printf( " program\n");
  return 0;
}