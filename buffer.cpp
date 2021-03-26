#include <iostream>
#include <cstdlib>
#include <mutex>

std::mutex mutex;
int a_index = 0;

void read_func(int* array)
{
	for(int i= 0; i< 7; i++) std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}

void write(int** buffer)
{
	int* array = new int[7];
  mutex.lock();
	for(int i= 0; i< 7; i++)
	{
		array[i] = buffer[a_index][i];
	}
  read_func(array);
  a_index++;
  mutex.unlock();
}

int main()
{
	int buffer[2][7] = {{1,2,3,4,5,6,7},{8,9,10}};
	int** buff = new int*[2];
	for(int i= 0; i< sizeof(buffer)/sizeof(int); i++) buff[i] = new int[7];
	for(int i= 0; i< 2; i++)
	{
		for(int j= 0; j< 7; j++) buff[i][j] = buffer[i][j];
	}
	write(buff);
	write(buff);
	return 0;
}
