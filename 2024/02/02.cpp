#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>	// Required for std::sort
#include <sstream>	// Required for std::istringstream


uint32_t abs_diff( uint32_t a, uint32_t b )
{
	if( a > b ){
		return a - b;
	}else{
		return b - a;
	}
}


bool is_num_near( uint32_t a, uint32_t b ){
	uint32_t diff = abs_diff( a, b );
	if( (0 < diff) && (diff < 4) ){
		return true;
	}else{
		return false;
	}
}


bool is_vector_safe( std::vector<uint32_t>& items ){
	bool result = true;
	bool is_increasing = false;
	if( items[0] < items[1] ){
		is_increasing = true;
	}
	for( uint32_t i = 0; i < items.size() - 1; i++ ){
		if( is_increasing ){
			if( items[i] < items[i+1] ){
				if( is_num_near( items[i], items[i+1] ) ){
					//safe
				}else{
					result = false;
					break;
				}
			}else{
				result = false;
				break;
			}
		}else{
			if( items[i] > items[i+1] ){
				if( is_num_near( items[i], items[i+1] ) ){
					//safe
				}else{
					result = false;
					break;
				}
			}else{
				result = false;
				break;
			}
		}
	}
	return result;
}


int main( int argc, char** argv )
{	
	std::cout << "Hello World!" << std::endl;
	
	// parse the input file
	// get two arrays or vectors
	// sort each vectors
	// get the distances and get the sum
	
	
	if( argc != 2 ){
		std::cout << "Usage: ./02 <input_file>" << std::endl;
		return -1;
	}
	
	std::ifstream file_handler;
	std::string line;
	
	file_handler.open( argv[1], std::ios::out );
	
	uint32_t safe_cnt = 0;
	while( std::getline( file_handler, line) )
	{
		//std::cout << line << std::endl;
		
		std::vector<uint32_t> numbers; // To store the extracted numbers
		uint32_t num;

		// Create an istringstream from the input string
		std::istringstream iss( line );

		// Read numbers from the stringstream until no more integers can be extracted
		while( iss >> num ){
			numbers.push_back(num);
		}
		if( is_vector_safe( numbers ) ){
			safe_cnt++;
		}
	}
	file_handler.close();
	
	std::cout << "Part 1 Safe Count: " << safe_cnt << std::endl;
	
	// Part 2
	file_handler.open( argv[1], std::ios::out );
	
	uint32_t safe_cnt2 = 0;
	while( std::getline( file_handler, line) )
	{
		//std::cout << line << std::endl;
		
		std::vector<uint32_t> numbers; // To store the extracted numbers
		uint32_t num;

		// Create an istringstream from the input string
		std::istringstream iss( line );

		// Read numbers from the stringstream until no more integers can be extracted
		while( iss >> num ){
			numbers.push_back(num);
		}
		
		//bool is_safe = true;
		if( is_vector_safe( numbers ) ){
			safe_cnt2++;
		}else{
			for( uint32_t i = 0; i < numbers.size(); i++ ){
				// remove one member until safe
				std::vector<uint32_t> copy_vec = numbers;
				copy_vec.erase( copy_vec.begin() + i );
				
				if( is_vector_safe( copy_vec ) ){
					safe_cnt2++;
					break;
				}
			}
		}
	}
	file_handler.close();
	
	std::cout << "Part 2 Safe Count: " << safe_cnt2 << std::endl;
	
	
	return 0;
}