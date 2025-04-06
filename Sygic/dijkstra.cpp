#include "dijkstra.h"

void Result::printResult() {
	if (listOfVertecesInShorestPath != std::nullopt) {
		std::cout << std::endl << "Shortest Path from: " << (*listOfVertecesInShorestPath).front() << " to: " << (*listOfVertecesInShorestPath).back() << " is: ";
		for (auto& vertex : *listOfVertecesInShorestPath) {
			std::cout << vertex << " ";
		}
		std::cout << std::endl << "with the weight of path: " << lenghtOfPath << std::endl;
	}
}

std::vector<int> calculatePath(const std::vector<int>& predecessors, const int start, const int finish) {
	std::vector<int> resultingPath;
	for (int vertex = finish; vertex != start; vertex = predecessors[vertex]) {
		resultingPath.push_back(vertex);
	}
	resultingPath.push_back(start);

	std::reverse(resultingPath.begin(), resultingPath.end());
	return (std::move(resultingPath));
};
Result dijkstra(const std::vector<int>& vertece, const std::vector<Edge>& edgesList, const int start, const int finish) {

	const int numberOfVertexes = vertece.size(); //size_t to int

	if (start == finish) { return Result(std::move(std::vector<int>{start}), 0); }

	//predecessors is for path reconstruction
	std::vector<int> predecessors(numberOfVertexes);
	std::fill(predecessors.begin(), predecessors.end(), MAX);
	predecessors[start] = start;

	std::vector<bool> vertexesAddedToShortestPath(numberOfVertexes);
	std::fill(vertexesAddedToShortestPath.begin(), vertexesAddedToShortestPath.end(), false);
	vertexesAddedToShortestPath[start] = true;

	std::vector<int> distancesFromStart(numberOfVertexes);
	std::fill(distancesFromStart.begin(), distancesFromStart.end(), MAX);
	distancesFromStart[start] = 0;

	for (int i = 1; i < numberOfVertexes; i++) {

		//recalcualte distances
		for (auto& edge : edgesList) {
			if (vertexesAddedToShortestPath[edge.vertexFrom]) {
				if (distancesFromStart[edge.vertexFrom] != MAX &&
					((distancesFromStart[edge.vertexFrom] + edge.weightOfEdge) < distancesFromStart[edge.vertexTo])) {
					distancesFromStart[edge.vertexTo] = (distancesFromStart[edge.vertexFrom] + edge.weightOfEdge);
					predecessors[edge.vertexTo] = edge.vertexFrom;
				}
			}
		}

		//adding next vertex with shortest distance not alredy in
		//could be more eficient using priority queue
		int positionOfVertexWithMinDistanceNotYetInPath = 0;
		int minDistanceNotYetInPath = MAX;
		for (int i = 0; i < numberOfVertexes; i++) {
			if (!(vertexesAddedToShortestPath[i])) {
				if (distancesFromStart[i] < minDistanceNotYetInPath) {
					minDistanceNotYetInPath = distancesFromStart[i];
					positionOfVertexWithMinDistanceNotYetInPath = i;
				}
			}
		}
		vertexesAddedToShortestPath[positionOfVertexWithMinDistanceNotYetInPath] = true;

	}
	//recreate shortest path from finish to start
	if (distancesFromStart[finish] == MAX) { return (Result(std::nullopt, MAX)); }/* or throw and error: throw std::runtime_error("No path exists between the source and destination."*/
	std::vector<int> resultingPath = calculatePath(predecessors, start, finish);

	return (Result(std::move(resultingPath), distancesFromStart[finish]));
}
