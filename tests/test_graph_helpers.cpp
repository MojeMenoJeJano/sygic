#pragma once
#include <gtest/gtest.h>
#include "../Sygic/dijkstra.h"
#include "../Sygic/graph_helpers.h"
#include <optional>

// Test cases
TEST(test, createVertexListFromEdges) {

	std::vector<Edge> edgeList = { {2, 0, 1}, { 1,3,10 }, { 2,3,15 }, { 0,3,2 }, { 3,4,3 } };
	std::vector<int> vertexesExpected = {0, 1, 2, 3, 4};
	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgeList);
	EXPECT_EQ(areVectorsEqual(vertexesExpected, vertexes), true);

	vertexesExpected = { 0, 1, 2, 4 };
	vertexes.clear();
	createVertexListFromEdges(vertexes, edgeList);
	EXPECT_EQ(areVectorsEqual(vertexesExpected, vertexes), false);

	edgeList.clear();
	vertexesExpected.clear();
	vertexes.clear();
	createVertexListFromEdges(vertexes, edgeList);
	EXPECT_EQ(areVectorsEqual(vertexesExpected, vertexes), true);
}

TEST(test, checkWeightsOfEdgesArePositive) {
	std::vector<Edge> edgeList = { {2, 0, 1}, { 1,3,10 }, { 2,3,15 }, { 0,3,2 }, { 3,4,3 } };
    EXPECT_EQ(checkWeightsOfEdgesArePositive(edgeList), true);
	edgeList[0] = Edge{ 0,1,-1 };
	EXPECT_EQ(checkWeightsOfEdgesArePositive(edgeList), false);
	edgeList.clear();
	EXPECT_EQ(checkWeightsOfEdgesArePositive(edgeList), true);
	edgeList = { {0, 1, 1}, {1, 2, 10} };
	EXPECT_EQ(checkWeightsOfEdgesArePositive(edgeList), true);
}


TEST(test, checkOptionalAndCompareVectors) {
	Result result{std::nullopt, MAX};
	std::vector<int> expectetVertexList{};
	int expectetResult = MAX;

	EXPECT_EQ(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResult), false);

	result.listOfVertecesInShorestPath = std::vector<int>{ 1,2,3,4,5 };
	result.lenghtOfPath = 4;
	expectetVertexList = std::vector<int>{ 1,2,3,4,5 };
	expectetResult = 4;
	EXPECT_EQ(checkOptionalAndCompareVectors(result, expectetVertexList, expectetResult), true);

	result.listOfVertecesInShorestPath = std::vector<int>{ 1, 2, 3, 4 };
	expectetVertexList = std::vector<int>{ 1, 2, 3, 5 };
	EXPECT_EQ(checkOptionalAndCompareVectors(result, expectetVertexList, 4), false);

}