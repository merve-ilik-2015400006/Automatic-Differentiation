
#include "graph.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;


int main(int argc, char*argv[]){

    Graph g;

    ifstream infile(argv[2]);
    ofstream output1;
    output1.open(argv[3]);
    ofstream output2;
    output2.open(argv[4]);
    string line;
    getline(infile,line);

    g.readGraph(argv[1]);
    if(g.isCyclic()){
        output1<<"ERROR: COMPUTATION GRAPH HAS CYCLE!"<<endl;
        output2<<"ERROR: COMPUTATION GRAPH HAS CYCLE!"<<endl;
        return 0;
    }
    output1<<g.vars[g.outputNode]->name<<endl;
    for(int i=0; i<g.inputNodes.size(); i++){
        output2 << "d" << g.name[g.outputNode] << "_d" << g.name[g.inputNodes[i]] << " ";
    }
    output2 << endl;
    while(getline(infile,line)){

        istringstream buf(line);
        std::istream_iterator<string> beg(buf), end;
        vector<string> nums(beg,end);

        vector<double> x;
        for(int i=0;i<nums.size();i++){
            x.push_back(stod(nums[i]));
        }

        output1<< setprecision(16) << g.forwardPass(x);

        vector<double> derivatives=g.backwardPass();
        for(int i=0;i<g.inputNodes.size();i++){
            output2<< setprecision(16)<<derivatives[i] << " ";
        }
        output1<<endl;
        output2<<endl;
    }






return 0;


}
