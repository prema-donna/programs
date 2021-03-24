#include<iostream>
#include<cstdlib>

using namespace std;

/**
* Attempts to read up to count number of bytes from the serial
* port into the buffer.
**
Returns the number of bytes actually read.
*/
int read(char *buffer, unsigned int count);

/**
* This function should only be called when a complete message
* has been parsed. The complete message should be at the start
* of the input buffer.
*/
void process_message(char *buffer, unsigned int message_id);

//Ended up not using this function
int get_message_size_from_message_id(int message_id);

int main(){
	
	while(1){
		//these variables will help me parse the desired serial message
		char message[105];
		int n;
		
		//first, let's try and isolate the 5 byte start sequence
		do{
			n = read(message,5);
		}while(0xFF != message[0] && 0xFF != message[1] && 0xFF != message[2] && 0xFF != message[3] && 0xFF != message[4]);
		
		//parse message ID
		n = read(&message[5],1);
		unsigned int messageID = (unsigned int)message[5]; 
		
		//parsing 3 reserved bytes
		n = read(&message[6],3);
		
		//It's clear that the separator bytes should always be 0xFE. We'll continue to parse until a different separator is detected
		char separator = 0xFE
		unsigned int repeated_length = 6;
		unsigned int iter_num = 0;
		
		//parsing first separator
		n = read(&message[9], 1);
		char header[6] = {message[5], message[6], message[7], message[8], message[9], '\0'};
		
		//parsing payload for first time
		n = read(&message[10], 4);
		char payload[6] = {message[10],message[11],message[12], message[13], message[9], '\0'}; 
		unsigned int index = 14;
		
		//add the repeated payload and the 2 separators until a different separator is read
		do{
			n = read(&message[index+iter_num*repeated_length,repeated_length);
			iter_num++;
		}while(separator == message[index+iter_num*repeated_length] && separator == message[index+5+iter_num*repeated_length])
		
		//if a different byte than the separator is found, parse the next 5 bytes into the message array so that we're at the point of a 
		//potential checksum
		index += iter_num*repeated_length;
		n = read(&message[index], 5);
		
		//Let's see if the checksum is valid
		char *xor_hp= {header[0]^payload[0], header[1]^payload[1], header[2]^payload[2], header[3]^payload[3], '\0'}
		index += 5;
		char *checksum= {message[index], message[index+1], message[index+2], message[index+3], '\0'};
		
		//if equal, we have a valid checksum, thus write the checksum and the last separator byte and call process_message()
		if (strcmp(xor_hp,checksum) == 0){
			n = read(&message[index], 5);
			process_message(message, messageID);
			
			//We have a good message now. Let's break out of the infinite loop. 
			//Note: After calling process_message(), we could easily clear the message and allow the infinite loop to keep running 
			break;
		}
		
		//if we have an invalid checksum, discard the entire message, and allow the infinite loop to run again until a valid message is found
		else{
			message = "";
		}
	}
		
	return 0;
}