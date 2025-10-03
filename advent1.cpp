#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Required for std::sort


uint32_t abs_diff( uint32_t a, uint32_t b )
{
	if( a > b ){
		return a - b;
	}else{
		return b - a;
	}
}

int main( int argc, char** argv )
{	
	std::cout << "Hello World!" << std::endl;
	
	// parse the input file
	// get two arrays or vectors
	// sort each vectors
	// get the distances and get the sum
	
	
	if( argc != 2 ){
		std::cout << "Usage: ./advent1 <input_file>" << std::endl;
		return -1;
	}
	
	std::ifstream file_handler;
	std::string line;
	uint32_t data1, data2;
	std::string data_str;
	std::vector<uint32_t> data_vector1;
	std::vector<uint32_t> data_vector2;
	
	file_handler.open( argv[1], std::ios::out );
	
	while( std::getline( file_handler, line) )
	{
		//std::cout << line << std::endl;
		data_str = line.substr( 0, 5 );
		data1 = std::stoul( data_str, nullptr, 10);
		
		data_str = line.substr( 8, 5 );
		data2 = std::stoul( data_str, nullptr, 10);
		
		data_vector1.push_back( data1 );
		data_vector2.push_back( data2 );
		
		//std::cout << data1 << " " << data2 << std::endl;
	}
	file_handler.close();
	
	std::sort( data_vector1.begin(), data_vector1.end() );
	std::sort( data_vector2.begin(), data_vector2.end() );
	
	/*for( uint32_t num : data_vector1 ){
		std::cout << num << std::endl;
	}
	std::cout << std::endl;*/
	
	uint32_t total = 0;
	for( uint32_t i = 0; i < data_vector1.size(); i++ ){
		total += abs_diff( data_vector1[i], data_vector2[i] );
	}
	
	std::cout << "Total: " << total << std::endl;
	
	return 0;
}