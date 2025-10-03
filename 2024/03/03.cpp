#include <iostream>
#include <fstream>
#include <vector>
#include <regex>


int main( int argc, char** argv )
{	
	std::cout << "Hello World!" << std::endl;
	
	if( argc != 2 ){
		std::cout << "Usage: ./03 <input_file>" << std::endl;
		return -1;
	}
	
	std::ifstream file_handler;
	std::string line;
	
	file_handler.open( argv[1], std::ios::out );
	
	uint32_t total1 = 0;
	while( std::getline( file_handler, line) )
	{
		//std::cout << line << std::endl;
		std::regex rgx( "mul\\(\\d{1,3},\\d{1,3}\\)" );
		std::regex rgx2( "\\d{1,3}" );
		
		uint32_t data1, data2;
		
		std::regex_token_iterator<std::string::iterator> c{ line.begin(), line.end(), rgx };
		std::regex_token_iterator<std::string::iterator> rend;
		
		while( c != rend ) {
			std::string str = *c++;
			//std::cout << str << std::endl;
			
			std::regex_token_iterator<std::string::iterator> c2{ str.begin(), str.end(), rgx2 };
			std::regex_token_iterator<std::string::iterator> rend2;
			std::vector<int> numbers;
			int number;
			
			while( c2 != rend2 ){
				number = std::stoi(*c2);
				numbers.push_back(number);
				c2++;
			}
			total1 += numbers[0]*numbers[1];
		}
	}
	file_handler.close();
	
	std::cout << "Part 1 Total: " << total1 << std::endl;
	
	// Part 2
	file_handler.open( argv[1], std::ios::out );
	
	uint32_t total2 = 0;
	bool is_mul = true;
	while( std::getline( file_handler, line) )
	{
		//std::cout << line << std::endl;
		std::regex rgx( "mul\\(\\d{1,3},\\d{1,3}\\)|do\\(\\)|don't\\(\\)" );
		std::regex rgx2( "\\d{1,3}" );
		
		uint32_t data1, data2;
		
		std::regex_token_iterator<std::string::iterator> c{ line.begin(), line.end(), rgx };
		std::regex_token_iterator<std::string::iterator> rend;
		
		while( c != rend ) {
			std::string str = *c++;
			//std::cout << str << std::endl;
			
			if( str == "do()" ){
				is_mul = true;
				continue;
			}else if( str == "don't()" ){
				is_mul = false;
				continue;
			}
			
			if( is_mul ){
				std::regex_token_iterator<std::string::iterator> c2{ str.begin(), str.end(), rgx2 };
				std::regex_token_iterator<std::string::iterator> rend2;
				std::vector<int> numbers;
				int number;
				
				while( c2 != rend2 ){
					number = std::stoi(*c2);
					numbers.push_back(number);
					c2++;
				}
				total2 += numbers[0]*numbers[1];
			}
		}
	}
	file_handler.close();
	
	std::cout << "Part 2 Total: " << total2 << std::endl;
	
	
	return 0;
}