#include <iostream>
#include <cstdlib>

using namespace std;

int num_jumps(int X, int Y, int D)
{
	int jumps = 0;
	while(X < Y)
	{
		X += D;
		jumps++;
	}
	return jumps;
}

int main()
{
	int curr_pos, dest_pos, jump_dist;
	cout<<"Enter current position (0 to 1000000000): "<<endl;
	cin>>curr_pos;
	cout<<"Enter destination position (0 to 1000000000): "<<endl;
	cin>>dest_pos;
	cout<<"Enter jump distance (0 to 1000000000): "<<endl;
	cin>>jump_dist;
	
	cout<<"Number of jumps to get to the destination: "<<num_jumps(curr_pos,dest_pos,jump_dist)<<endl;
	
	return 0;
}