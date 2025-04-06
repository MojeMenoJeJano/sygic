#include "graph_helpers.h"
//vertexes will be filled with unique sorted vertexes
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
// weight of edge must by greater than 0 
bool checkWeightsOfEdgesArePositive(const std::vector<Edge>& edgesList) {
	for (auto& edge : edgesList) {
		if (edge.weightOfEdge <= 0) { return false; }
	}
	return true;
}
bool checkOptionalAndCompareVectors(const Result& result, const std::vector<int>& expectetVertexList, const int expectetResutl) {
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

