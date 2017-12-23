
#include "variable.h"
using namespace std;
#include <vector>
#include "Node"
Variable::Variable(){
    value=0;
    derivative=0;
    from=nullptr;
    to= nullptr;
    this->id=0;
    this->name="";

}

Variable::Variable(int _id, string _name, double _value) {
    this->id=_id;
    this->name=_name;
    this->value=_value;
}

void Variable::setFrom(Function *_from) {
    this->from=_from;
}

void Variable::addTo(Function *_to) {
    this->to.push_back(_to);
}

vector<Node *> Variable::getOutgoings() {

    vector<Node *> result;
    for(int i=0;i<this->to.size();i++){
        result.push_back((Node*)(to[i]));
    }
    return result;
}
vector<Node *> Variable::Incomings() {
    vector <Node*> result;
    result.push_back((Node*)(to));
}

Variable::~Variable() {
    delete this->from;
    delete this->to;
}


