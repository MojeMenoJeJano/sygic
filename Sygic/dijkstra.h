//File: dijkstra.h
#pragma once
#include <vector>
#include <set>
#include <optional>
#include <iostream>

constexpr int MAX = std::numeric_limits<int>::max();

struct Result {
	std::optional<std::vector<int>> listOfVertecesInShorestPath;
	int lenghtOfPath;
	void printResult();
};

struct Edge {
	int vertexFrom;
	int vertexTo;
	int weightOfEdge;
};
std::vector<int> calculatePath(const std::vector<int>& predecessors, const int start, const int finish);
Result dijkstra(const std::vector<int>& vertece, const std::vector<Edge>& edgesList, const int start, const int finish);