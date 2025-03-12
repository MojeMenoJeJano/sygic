#include "test.h"

void createVertexListFromEdges(std::vector<int>& vertexes, const std::vector<Edge>& edgesList) {
	std::set<int> helperSet;

	for (auto& edge : edgesList) {

		if (!(helperSet.contains(edge.vertexFrom))) {
			helperSet.insert(edge.vertexFrom);
			vertexes.push_back(edge.vertexFrom);
		};
		if (!(helperSet.contains(edge.vertexTo))) {
			helperSet.insert(edge.vertexTo);
			vertexes.push_back(edge.vertexTo);
		};
	}
	std::sort(vertexes.begin(), vertexes.end());
}
bool areTheWeightsOfEdgesPositive(const std::vector<Edge>& edgesList) {
	for (auto& edge : edgesList) {
		if (edge.weightOfEdge <= 0) { return false; }
	}
	return true;
}
bool checkOptionalAndComapreVectors(const Result& result, const std::vector<int>& expectetVertexList, const int expectetResutl) {
	if (result.listOfVertecesInShorestPath.has_value()) {

		std::vector<int> res = result.listOfVertecesInShorestPath.value();
		if ((result.lenghtOfPath == expectetResutl) && (areVectorsEqual(res, expectetVertexList)))
		{
			return true;
		}
		else { return false; }
	}
	else { return false; }
}
//should be change for google test in future
bool test1() {
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

	if (!(areTheWeightsOfEdgesPositive(edgesList))) {
		std::cout << "You made edge with negative weight." << std::endl;
		return false;
	}
	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	start = 2;
	finish = 4;
	expectetResutl = 6;
	expectetVertexList = std::vector<int>{ 2,0,3,4 };
	result = dijkstra(vertexes, edgesList, start, finish);
	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	start = 1;
	finish = 4;
	expectetResutl = 13;
	expectetVertexList = std::vector<int>{ 1,3,4 };
	result = dijkstra(vertexes, edgesList, start, finish);
	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	return true;
}
bool test2() {
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
	if (!(areTheWeightsOfEdgesPositive(edgesList))) {
		std::cout << "You made edge with negative weight." << std::endl;
		return false;
	}
	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	start = 0;
	finish = 1;
	expectetResutl = 20;
	expectetVertexList = std::vector<int>{ 0,2,1 };
	result = dijkstra(vertexes, edgesList, start, finish);
	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	start = 0;
	finish = 3;
	expectetResutl = 2;
	expectetVertexList = std::vector<int>{ 0,3 };
	result = dijkstra(vertexes, edgesList, start, finish);
	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	return true;

}
bool test3() {
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
	if (!(areTheWeightsOfEdgesPositive(edgesList))) {
		std::cout << "You made edge with negative weight." << std::endl;
		return false;
	}
	std::vector<int> vertexes{};
	createVertexListFromEdges(vertexes, edgesList);

	Result result = dijkstra(vertexes, edgesList, start, finish);

	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	start = 2;
	finish = 9;
	expectetResutl = 3;
	expectetVertexList = std::vector<int>{ 2,5,9 };
	result = dijkstra(vertexes, edgesList, start, finish);
	if (!(checkOptionalAndComapreVectors(result, expectetVertexList, expectetResutl))) { return false; };

	return true;

}
