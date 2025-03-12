#pragma once
#include <vector>
#include <vector>
#include <set>
#include <optional>

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
Result dijkstra(const std::vector<int>& vertece, const std::vector<Edge>& edgesList, const int start, const int finish);