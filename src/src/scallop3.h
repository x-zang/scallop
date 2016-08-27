#ifndef __SCALLOP3_H__
#define __SCALLOP3_H__

#include "splice_graph.h"
#include "hyper_set.h"
#include "equation.h"
#include "router.h"
#include "path.h"

typedef map< edge_descriptor, vector<int> > MEV;
typedef pair< edge_descriptor, vector<int> > PEV;
typedef pair< vector<int>, vector<int> > PVV;
typedef pair<PEE, int> PPEEI;
typedef map<PEE, int> MPEEI;
typedef pair<int, int> PI;
typedef map<int, int> MI;

// for noisy splice graph
class scallop3
{
public:
	scallop3();
	scallop3(const string &name, const splice_graph &gr, const hyper_set &hs);
	virtual ~scallop3();

public:
	int assemble();

public:
	string name;						// name for this gene
	splice_graph gr;					// splice graph
	MEI e2i;							// edge map, from edge to index
	VE i2e;								// edge map, from index to edge
	MEV mev;							// super edges
	vector<int> v2v;					// vertex map
	hyper_set hs;						// hyper edges
	int round;							// round in iteration
	vector<path> paths;					// predicted transcripts
	vector<router> routers;

private:
	// trivial, or hard
	int classify();

	// iterate
	int iterate();
	bool decompose_tree();
	bool split_vertex(bool hyper);
	bool remove_edge();
	bool decompose_trivial_vertex();

	// graph modify routines
	bool decompose_trivial_vertex(int v);
	bool decompose_trivial_vertex(int v, vector<PI> &ve0, vector<int> &ve1);
	int split_vertex(int x, const vector<int> &xe, const vector<int> &ye);
	int split_edge(int exi, double w);
	int merge_adjacent_edges(int x, int y);
	int merge_adjacent_equal_edges(int x, int y);
	int remove_edge(int e);
	int balance_vertex(int v);

	// init
	int init_vertex_map();
	int init_super_edges();

	// topology
	int greedy_decompose(int num);
	int split_merge_path(const VE &p, double w, vector<int> &v);
	int split_merge_path(const vector<int> &p, double w, vector<int> &v);
	int collect_path(int e);
	int collect_existing_st_paths();
	vector<int> topological_sort();

	// print and draw
	int print();
	int stats();
	int draw_splice_graph(const string &file);
};

#endif
