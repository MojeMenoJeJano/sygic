// Sygic.cpp : Defines the entry point for the application.
//
#pragma once
#include "Sygic.h"

//the same test is performed in google test: dijkstra4
bool simpleDijkstraTest() {
	std::vector<Edge> edgesList = {
			{0, 2, 3},
			{1, 3, 5},
			{2, 4, 7},
			{2, 5, 1},
			{3, 5, 4},
			{4, 6, 2},
			{5, 6, 3},
			{6, 7, 8},
			{7, 8, 6},
			{5, 9, 2},
			{9, 10, 4},
			{10, 1, 9},
			{5, 7, 5}
	};
	int expectetResutl = 6;
	std::vector<int> expectetVertexList{ 2,5,7 };
	int start = 2;
	int finish = 7;

	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	if (checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl)){
		std::cout << "We got a Graph and we calculated following: " << std::endl;
		result.printResult();
		return true;
	} else {
		return false;
	}
}
int main()
{
	if (simpleDijkstraTest()) {
		std::cout << std::endl << "The simple test has passed. Hurray !!" << std::endl;
	}
	else {
		std::cout << "Something somwhere might have broke. Have a look where.";
	}
	return 0;
}
