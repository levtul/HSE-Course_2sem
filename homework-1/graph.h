
#ifndef HOMEWORK_1_GRAPH_H
#define HOMEWORK_1_GRAPH_H

#include <vector>
#include "src/node.h"

template<typename T>
class IGraph {
public:
    virtual ~IGraph() {}

    IGraph() {};

    IGraph(IGraph *_oth) {};

    virtual void AddEdge(int from, int to, T &&_obj) = 0;

    virtual int VerticesCount() const = 0;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void DeepFirstSearch(int vertex, std::vector<int> &vertices) const = 0;

    virtual void BreadthFirstSearch(int vertex, std::vector<int> &vertices) const = 0;

    virtual void GetEdges(std::vector<std::pair<std::pair<int,int>, T>> &edges) const = 0;
};

template<typename T = void>
class IPtrsGraph {
public:
    virtual ~IPtrsGraph() {}

    IPtrsGraph() {};

    virtual void AddEdge(Node<T> *from, Node<T> *to, T &&_obj) = 0;

    virtual int VerticesCount() const = 0;

    virtual void GetNextVertices(Node<T> *vertex, std::vector<Node<T> *> &vertices) const = 0;

    virtual void GetPrevVertices(Node<T> *vertex, std::vector<Node<T> *> &vertices) const = 0;

    virtual void DeepFirstSearch(Node<T> *vertex, std::vector<Node<T> *> &vertices) const = 0;

    virtual void BreadthFirstSearch(Node<T> *vertex, std::vector<Node<T> *> &vertices) const = 0;
};

template<typename T>
class ObjectCreater {
public:
    static T Create(const T& _obj) {
        return T(_obj);
    }
};

template<typename T>
class ObjectCreater<T*> {
public:
    static T* Create(const T* _obj) {
        return new T(*_obj);
    }
};

template<typename T>
class ObjectDeleter {
public:
    static void Delete(T& _obj) {}
};

template<typename T>
class ObjectDeleter<T*> {
public:
    static void Delete(T* _obj) {
        delete _obj;
        _obj = nullptr;
    }
};

#endif //HOMEWORK_1_GRAPH_H
