#ifndef GRAPHALGORITHM_H
#define GRAPHALGORITHM_H

#include <iostream>
#include <type_traits>

/**
 * @class GraphAlgorithm
 * @brief Abstract interface for graph algorithms (True Strategy Pattern).
 *
 * Concrete strategies must implement `run()` to perform the selected algorithm.
 */
template<typename GraphType, typename T>
class GraphAlgorithm {
protected:
    template <typename U = T>
    typename std::enable_if<std::is_pointer<U>::value>::type
    printVertexData(const U& data) {
        std::cout << data->getName() << " ";
    }

    template <typename U = T>
    typename std::enable_if<!std::is_pointer<U>::value>::type
    printVertexData(const U& data) {
        std::cout << data << " ";
    }

public:
    virtual ~GraphAlgorithm() = default;
    virtual int run(GraphType &g, int startId, int endId = -1) = 0;
};

#endif //GRAPHALGORITHM_H