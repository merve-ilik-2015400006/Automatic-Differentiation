
#include "graph.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}


int main(int argc, char * argv[]){

    Graph g;

    ifstream infile(argv[2]);
    ofstream output1(argv[3]);
    ofstream output2(argv[4]);
    string line;
    getline(infile,line);

    g.readGraph(argv[1]);
    if(g.isCyclic()){
        output1<<"ERROR: COMPUTATION GRAPH HAS CYCLE!"<<endl;
        output2<<"ERROR: COMPUTATION GRAPH HAS CYCLE!"<<endl;
        return 0;
    }


    while(getline(infile,line)){

        vector<double> nums;
        split1(line,nums);
        vector<double> x;
        for(int i=0;i<g.inputNodes.size();i++){
           x.push_back(nums[i]);
        }

           output1<< g.forwardPass(x);

        vector<double> derivatives=g.backwardPass();
        for(int i=0;i<g.inputNodes.size();i++){
            output2<< derivatives[i];
        }
        output1<<endl;
        output2<<endl;
    }









}