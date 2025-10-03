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
	
	// Part 1
	std::sort( data_vector1.begin(), data_vector1.end() );
	std::sort( data_vector2.begin(), data_vector2.end() );
	
	uint32_t total1 = 0;
	for( uint32_t i = 0; i < data_vector1.size(); i++ ){
		total1 += abs_diff( data_vector1[i], data_vector2[i] );
	}
	
	std::cout << "Part 1 Total: " << total1 << std::endl;
	
	// Part 2
	// we can reuse the sorted vectors...
	//std::cout << std::count( data_vector2.begin(), data_vector2.end(), data_vector1[0] ) << std::endl;
	uint32_t total2 = 0;
	for( const uint32_t& data : data_vector1 ){
		total2 += data * std::count( data_vector2.begin(), data_vector2.end(), data );
	}
	std::cout << "Part 2 Total: " << total2 << std::endl;
	
	return 0;
}