#ifndef ERROR_HPP
#define ERROR_HPP

#include<string>
#include<iostream>

class Error{
public:
	static void showError(std::string errorMessage){
		std::cout<<errorMessage<<std::endl;
	}
};

#endif
