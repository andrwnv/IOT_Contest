#pragma once

#include <unordered_map>
#include <queue>
#include <list>

template <typename T>
class Graph
{
public:
    explicit Graph(std::unordered_map<T, std::list<T>> const&);

    Graph()  = default;
    ~Graph() = default;

    void traversal_in_depth(T const& node);
    void traversal_in_breadth(T const& node);
    void addEdge(T key, std::list<T> const& node);
    void print() const;

private:
    void traversal_in_depth(T const& node, std::unordered_map<T, bool> & visited); // There are alg.

private:
    std::unordered_map<T, std::list<T>> m_data;
};


template<typename T>
Graph<T>::Graph(std::unordered_map<T, std::list<T>> const& data) { m_data = data; }

template<typename T>
void Graph<T>::addEdge(T key, std::list<T> const& node) { m_data.insert(m_data.end(), std::pair<T, std::list<T>>(key, node)); }

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
void Graph<T>::traversal_in_depth(T const& node)
{
    std::unordered_map<T, bool> visited_list;
    traversal_in_depth(node, visited_list);

    std::cout << std::endl;
}

template<typename T>
void Graph<T>::traversal_in_depth(T const& node, std::unordered_map<T, bool> &visited)
{
    visited[node] = true;
    std::cout << node << std::endl;

    for (auto const& item : m_data[node])
    {
        if (visited[item])
            return;

        traversal_in_depth(item, visited);
    }

}

template<typename T>
void Graph<T>::traversal_in_breadth(const T &node)
{
    std::unordered_map<T, bool> visited_list;
    std::queue<T> __queue;

    __queue.push(node);
    visited_list[node] = true;

    for (;!__queue.empty();)
    {
        std::cout << __queue.front() << std::endl;

        auto tmp = __queue.front();
        __queue.pop();

        for (auto const& item : m_data.at(node))
        {
            if (visited_list[item])
                return;

            __queue.push(item);
            visited_list[item] = true;
        }
    }
}

