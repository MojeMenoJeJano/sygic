// Sygic.cpp : Defines the entry point for the application.
//
#pragma once
#include "Sygic.h"

//member function of struct Result // currently not in use
void Result::printResult() {
	if (listOfVertecesInShorestPath != std::nullopt) {
		std::cout << std::endl << "Shortest Path from: " << (*listOfVertecesInShorestPath).front() << " to: " << (*listOfVertecesInShorestPath).back() << " is: ";
		for (auto& vertex : *listOfVertecesInShorestPath) {
			std::cout << vertex << " ";
		}
		std::cout << std::endl << "with the weight of path: " << lenghtOfPath << std::endl;
	}
}

int main()
{
	if (test1() && test2() && test3()) { std::cout << "all tests passed"; }
	else { std::cout << "somthink broke along he way"; };
	return 0;
}
