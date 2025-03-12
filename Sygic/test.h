#pragma once
#include "dijkstra.h"
#include "Sygic.h"

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
bool test1();
bool test2();
bool test3();