#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include "Mesh.hpp"

typedef std::tuple<uint64_t, uint64_t> vertex;
typedef std::tuple<vertex, vertex> edge;
typedef std::tuple<vertex, vertex> face;

class Analysis {
    private:

        static void enumerateElem1(Mesh *mesh, Element *elem,
                    std::map<uint64_t, std::map<vertex, uint64_t>> &levelVertices,
                    std::map<uint64_t, std::map<edge, uint64_t>> &levelEdges, uint64_t &n);
        static void enumerateElem(Mesh *mesh, Element *elem,
                    std::map<uint64_t, std::map<vertex, uint64_t>> &levelVertices,
                    std::map<uint64_t, std::map<edge, uint64_t>> &levelEdges, uint64_t &n, uint64_t level);
        // returns modified edge if taken from parent or returns
        // original edge with the information which coordinate has been modified
        static std::tuple<edge, uint64_t> parentEdge(edge e,
                    std::map<uint64_t, std::map<vertex, uint64_t>> &levelVertices,
                    std::map<uint64_t, std::map<edge, uint64_t>> &levelEdges, uint64_t level);
        static void mergeAnaliser(Node *node);
        
        static void findLeftRotationChild(Node ** _parent, Node ** _root, bool child1, bool child2, Node ** _child, Node ** _otherChild, Mesh * mesh);
        static void findRightRotationChild(Node ** _parent, Node ** _root, bool child1, bool child2, Node ** _child, Node ** _otherChild, Mesh * mesh);
        static Node * leftRotation(Node ** _parent, Node ** _root, bool child1, bool child2, Node ** _child, Node ** _otherChild, bool * b);
        static Node * rightRotation(Node ** _parent, Node ** _root, bool child1, bool child2, Node ** _child, Node ** _otherChild, bool * b);
        
    public:
        static void enumerateDOF(Mesh *mesh);
        static void doAnalise(Mesh *mesh);
        static void nodeAnaliser(Node *n, std::set<uint64_t> *parent);
	static int rotate(Node * root, Node * parent, Mesh * mesh, bool * b);

        // for debug use
        static void debugNode(Node *n);
        static void printTree(Node *n);
        static void printElement(Element *e);

};

#endif // ANALYSIS_HPP
