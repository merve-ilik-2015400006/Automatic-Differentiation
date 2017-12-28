
#include "variable.h"
using namespace std;

Variable::Variable(){
    value=0;
    derivative=0;
    from=nullptr;
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
    this->indegree++;
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
vector<Node *> Variable::getIncomings() {
    vector <Node*> result;
    if(from != nullptr)
        result.push_back((Node*)(from));
    return result;
}

/*Variable::~Variable(){

}*/



