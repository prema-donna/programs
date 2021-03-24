#include<stdio.h>
#include<stdlib.h>

//The main assumption that I'm making is that compressing = removing duplicate bytes, and decompressing = restoring all original values 

//Steps for the compression algorithm implementation (int byte_compress function)
//1) Create compressed_array, duplicate_array, and element_no array, and allocate memory with malloc(). We need the duplicate_array and the element_no array in order to
//	 ensure that this is also decompressible, as those two arrays are used to store duplicated values and their respective indices.
//2) Use two indexes, 1 for compressed_array array and 1 for duplicate array, updating the former if the number is unique and the latter if number is a repeat
//3) Loop through the data_ptr array. If there's a repeat, add byte to duplicate_array and update the number of duplicates.  Then, record the index where the repeat
//   occurred, and replace the repeated value with 0x80 (decimal value of 128, which is outside the 0 to 127 range)
//4) Given that repeats have been replaced with 0x80, can simply add all bytes that are not 0x80 to the compressed_array. 
//5) Call the print() function to print out the compressed array.
//6) Free the memory for all three arrays.

//Optional decompression algorithm implementation (void byte_decompress() function)
//7) If you want to restore the array to its original data values, uncomment the byte_decompress() function call in compressed_array. 
//8) Create a new decompressed_array and allocate memory using malloc().
//9) Loop through the data_ptr array. If data_ptr value = 0x80, place a value from the duplicate array into the decompressed_array. Else, copy from data_ptr buffer. 
//10) Overwrite the data_ptr buffer with the decompressed_array.
//10) Finally, print out the data_ptr buffer using the print() function, and free the memory allocated for the decompressed_array.     

//standard print function
void print(unsigned int* array, int data_size){
	for (int i= 0; i< data_size-1; i++){
		printf("%u,",array[i]);
	}
	printf("%u}\n",array[data_size-1]);	
}

//function that proves that my design allows for decompression/restoring the original data to be done pretty easily
void byte_decompress(unsigned int* data_ptr, unsigned int* duplicate_array, int* element_no, int data_size){
	unsigned int* decompress_array = malloc(sizeof(int)*data_size);
	int dup_index = 0;
	
	//the original buffer has "0x80" wherever a duplicate was found. We need to replace those with the duplicated values. Else, just copy data_ptr to decompress_array
	for(int i= 0; i< data_size; i++){
		if (data_ptr[i] == 0x80){
			//using element_no array to ensure the correct duplicate value will be placed in the correct index of the decompressed_array.
			decompress_array[element_no[dup_index]] = duplicate_array[dup_index];
			dup_index++;
		}
		else{
			decompress_array[i] = data_ptr[i];
		}
	}
	//this line restores the original buffer. Can easily just print out decompress_array, but the assignment asked for the original buffer to be restored
	data_ptr = decompress_array;
	
	//print out original buffer after decompression 
	printf("Decompressed array: {");
	print(data_ptr, data_size);
	free(decompress_array);
}

//byte compression function that stores duplicates in an array, removes them from the data input array, and outputs the new size of the compressed array 
int byte_compress(unsigned int* data_ptr, int data_size){
	//three arrays are used for 1)creating the compressed_array, 2)tracking duplicates for decompression, and 3)tracking indices where a replacement occurred
	unsigned int* compress_array = malloc(sizeof(int)*data_size);
	int ca_index = 0;
	unsigned int* duplicate_array = malloc(sizeof(int)*data_size);
	int* element_no = malloc(sizeof(int)*data_size);
	int dup_index = 0;
	
	//loops through array, checks for duplicates and stores the value and index in duplicate_array and element_no array, and replaces duplicates with 0x80. 
	for(int i= 0; i< data_size; i++){
		unsigned int byte = data_ptr[i];
		for(int j= i+1; j< data_size; j++){
			if(byte == data_ptr[j] && byte != 0x80){ 
				duplicate_array[dup_index] = byte;
				data_ptr[j] = 0x80;
				element_no[dup_index] = j;
				dup_index++;
			}
		}
		//stores unique value into compress_array. If there's a repeat, only the first instance of the value will be used.
		if (byte != 0x80){
			compress_array[ca_index] = byte;
			ca_index++;
		}			
	}
	
	//reallocating memory for all three arrays, then free the memory after print() function is called and the byte_decompress line is called
	int compressed_size = data_size - dup_index;
	printf("Compressed array: {");
	print(compress_array, compressed_size);
	
	//Uncomment this function call to see proof that the data_ptr[] array can be restored to its original state   
	byte_decompress(data_ptr, duplicate_array, element_no, data_size);
	
	free(compress_array);
	free(element_no);
	free(duplicate_array);
	
	return compressed_size; 
}

//expected output, if byte_decompress() function call is uncommented: 
//Compressed array: {3,116,4,53,100,0,86,69,9}
//Decompressed array: {3,116,4,4,4,53,53,100,100,100,100,0,0,0,0,0,86,69,86,86,86,9,9,9}
//New size of array after compression: 9
int main(){
	unsigned int data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
								0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
								0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };
	int data_size = 24;
	int new_size = byte_compress(data_ptr,data_size);
	
	printf("New size of array after compression: %d\n", new_size);

	return 0;
}