#include<iostream>
#include<cstdlib>


int my_func(int inc){
 	static int x = 0;
	x += inc;
	return x;
}

int main()
{  
  int sum = 0;
  for(int i= 1; i <= 4; i++)
  {
    sum += my_func(i);
    std::cout<<"sum = "<<sum<<std::endl;
  }
  return 0;
}
