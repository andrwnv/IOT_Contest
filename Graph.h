#pragma once

#include <unordered_map>
#include <list>


template <typename T>
class Graph
{
public:
    explicit Graph(std::unordered_map<T, std::list<T>> const&);

    Graph()  = default;
    ~Graph() = default;

    void traversal_inDepth(T node);
    bool addEdge(T key, std::list<T> const& node);
    void print() const;

private:
    void traversal_inDepth(T node, std::unordered_map<T, bool> & visited); // There are alg.

private:
    std::unordered_map<T, std::list<T>> m_data;
};


template<typename T>
Graph<T>::Graph(std::unordered_map<T, std::list<T>> const& data) { m_data = data; }

template<typename T>
bool Graph<T>::addEdge(T key, std::list<T> const& node)
{
    try {
        m_data[key].push_back(node);
    } catch (std::exception const& ) { return false; }

    return true;
}

template<typename T>
void Graph<T>::print() const
{
    std::cout << "Your Graph: " << std::endl;

    for(auto const & map_item : m_data)
    {
        std::cout << map_item.first << "->";

        for(auto const & list_item : map_item.second)
            std::cout << list_item << ", ";

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

template<typename T>
void Graph<T>::traversal_inDepth(T node)
{
    std::unordered_map<T, bool> visited_list;
    traversal_inDepth(node, visited_list);

    std::cout << std::endl;
}

template<typename T>
void Graph<T>::traversal_inDepth(T node, std::unordered_map<T, bool> &visited)
{
    visited[node] = true;
    std::cout << node << std::endl;

    for (auto const& item : m_data[node])
    {
        if (visited[item])
            return;

        traversal_inDepth(item, visited);
    }

}

