//File: graph_helper.h
//contains helper functions fot testing implementation of dijkstra
#pragma once
#include "dijkstra.h"
#include <vector>
#include <algorithm>

void createVertexListFromEdges(std::vector<int>& vertexes, const std::vector<Edge>& edgesList); //in header for google test only
bool checkWeightsOfEdgesArePositive(const std::vector<Edge>& edgesList);
bool checkOptionalAndCompareVectors(const Result& result, const std::vector<int>& expectetVertexList, const int expectetResutl); //in header for google test only
template <typename T>
bool areVectorsEqual(const std::vector<T>& first, const std::vector<T>& second) {
	if (first.size() != second.size()) {
		return false;
	}
	for (int i = 0; i < first.size(); i++) {
		if (first[i] != second[i]) { return false; }
	}
	return true;
}
