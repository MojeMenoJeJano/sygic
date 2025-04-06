#pragma once
#include <gtest/gtest.h>
#include "../Sygic/dijkstra.h"
#include "../Sygic/graph_helpers.h"

TEST(dijkstra, resultPrintResult) {
	Result R(std::nullopt, 1);
	std::ostringstream output;
	std::streambuf* originalCout = std::cout.rdbuf(output.rdbuf()); // Redirect std::cout
	R.printResult();
	std::cout.rdbuf(originalCout); // Restore std::cout
	EXPECT_EQ(output.str(), "");

	R.listOfVertecesInShorestPath = std::vector<int>{ 0,1,2,3 };
	R.lenghtOfPath = 3;
	output.str("");
	output.clear();
	originalCout = std::cout.rdbuf(output.rdbuf()); // Redirect std::cout
	R.printResult();
	std::cout.rdbuf(originalCout); // Restore std::cout
	EXPECT_EQ(output.str(), "\nShortest Path from: 0 to: 3 is: 0 1 2 3 \nwith the weight of path: 3\n");
	
	R.listOfVertecesInShorestPath = std::vector<int>{ 0,1,2,3,5 };
	R.lenghtOfPath = 3;
	output.str("");
	output.clear();
	originalCout = std::cout.rdbuf(output.rdbuf()); // Redirect std::cout
	R.printResult();
	std::cout.rdbuf(originalCout); // Restore std::cout
	EXPECT_NE(output.str(), "\nShortest Path from: 0 to: 3 is: 0 1 2 3 \nwith the weight of path: 3\n");
}

TEST(dijkstra, calculatePath) {
	int start = 0;
	int finish = 0;
	std::vector<int> predecessors{ 0 };
	std::vector<int> resultExpected{ 0 };
	std::vector<int> result = calculatePath(predecessors, start, finish);

	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 0;
	predecessors = { 1,1 };
	resultExpected = { 1,0 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 3;
	predecessors = { 1,1,0,2 };
	resultExpected = { 1,0,2,3 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 4;
	predecessors = { 1,1,0,2,2 };
	resultExpected = { 1,0,2,4 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 5;
	predecessors = { 1,1,0,2,2,2,4 };
	resultExpected = { 1,0,2,5 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 6;
	predecessors = { 1,1,0,2,2,2,4 };
	resultExpected = { 1,0,2,4,6 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 8;
	predecessors = { 1,1,0,2,2,2,4,6,5,6 };
	resultExpected = { 1,0,2,5,8 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));

	start = 1;
	finish = 9;
	predecessors = { 1,1,0,2,2,2,4,6,5,7 };
	resultExpected = { 1,0,2,4,6,7,9 };
	result = calculatePath(predecessors, start, finish);
	EXPECT_TRUE(areVectorsEqual(result, resultExpected));
}

TEST(dijkstra, dijkstra) {
	std::vector<Edge> edgesList = {
	{2,0,1},
	{1,3,10},
	{2,3,15},
	{0,3,2},
	{3,4,3}
	};
	int expectetResutl = 3;
	int start = 2;
	int finish = 3;
	std::vector<int> expectetVertexList{ 2,0,3 };

	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

}
TEST(dijkstra, dijkstra2) {
	std::vector<Edge> edgesList = {
		{2,0,1},
		{1,3,10},
		{2,3,15},
		{0,3,2},
		{3,4,3}
	};
	int expectetResutl = 3;
	int start = 2;
	int finish = 3;
	std::vector<int> expectetVertexList{ 2,0,3 };

	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

	start = 2;
	finish = 4;
	expectetResutl = 6;
	expectetVertexList = std::vector<int>{ 2,0,3,4 };
	result = dijkstra(vertexes, edgesList, start, finish);
	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

	start = 1;
	finish = 4;
	expectetResutl = 13;
	expectetVertexList = std::vector<int>{ 1,3,4 };
	result = dijkstra(vertexes, edgesList, start, finish);
	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

}
TEST(dijkstra, dijkstra3) {
	std::vector<Edge> edgesList = {
			{0,1,21},
			{0,2,12},
			{2,1,8},
			{2,4,50},
			{2,0,1},
			{1,3,10},
			{2,3,15},
			{0,3,2},
			{3,4,3}
	};
	int expectetResutl = 5;
	std::vector<int> expectetVertexList{ 0, 3,4 };
	int start = 0;
	int finish = 4;
	
	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

	start = 0;
	finish = 1;
	expectetResutl = 20;
	expectetVertexList = std::vector<int>{ 0,2,1 };
	result = dijkstra(vertexes, edgesList, start, finish);
	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

	start = 0;
	finish = 3;
	expectetResutl = 2;
	expectetVertexList = std::vector<int>{ 0,3 };
	result = dijkstra(vertexes, edgesList, start, finish);
	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

}
TEST(dijkstra, dijkstra4){
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

	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

	start = 2;
	finish = 9;
	expectetResutl = 3;
	expectetVertexList = std::vector<int>{ 2,5,9 };
	result = dijkstra(vertexes, edgesList, start, finish);
	EXPECT_TRUE(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResutl));

}
