#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class input{
    public:
        int val(string s){
            return s=="T";
        }
};


class Gate {
public:
    int evaluate(int input1, int input2);
};

class ANDGate : public Gate {
public:
    int evaluate(int input1, int input2){
        return input1 && input2;
    }
};

class ORGate : public Gate {
public:
    int evaluate(int input1, int input2) {
        return input1 || input2;
    }
};

class XORGate : public Gate {
public:
    int evaluate(int input1, int input2) {
        return input1 ^ input2;
    }
};

class XNORGate : public Gate {
public:
    int evaluate(int input1, int input2){
        return !(input1 ^ input2);
    }
};

class NORGate : public Gate {
public:
    int evaluate(int input1, int input2){
        return !(input1 || input2);
    }
};

class NANDGate : public Gate {
public:
    int evaluate(int input1, int input2){
        return !(input1 && input2);
    }
};


class NOTGate : public Gate {
public:
    int evaluate(int input1){
        if(input1==1) return 0;
        return 1;
    }
};

//these two are for the setters in circuit clas
bool isValidgate(vector<std::string>& g) {
    for (auto gate:g) {
        if (gate != "AND" && gate != "XOR" && gate != "XNOR" && gate != "OR" && gate != "NOR" && gate != "NOT" && gate!="NAND") {
            return false; 
        }
    }
    return true; 
}
bool isValidinput(vector<string>& i) {
    for (auto input:i) {
        if (input != "T" && input != "F") {
            return false; 
        }
    }
    return true; 
}
int NOTGateCount(vector<string> &g){
    int count=0;
    for (auto gate:g) {
        if (gate == "NOT") {
            count+=1;
        }
    }
    return count;
}

class Circuit{
private:
    vector<string> gates;
    vector<string> inputs;
public:
    int setGates(vector<string>g){
        if(isValidgate(g)){
            gates=g;
            return 1;
        }
        else{
            cout<<"Invalid Gates! ";
            return 0;
        }
    }
    void setInputs(vector<string>i){
        if(isValidinput(i) && (i.size()-1+NOTGateCount(gates) == gates.size())){
            inputs = i;
        }
        else{
            cout<<"Invalid Inputs! ";
        }
    }
    Circuit(vector<string>g, vector<string>i){
        if(setGates(g)){
            setInputs(i);
        }
        
    };
    void evaluate(){
        input I;
        int result =I.val(inputs[0]);
        int ctrl=0;
        for(int i=0;i<gates.size();i++){
            if(gates[i]=="AND"){
                ANDGate a;
                result = a.evaluate(result,I.val(inputs[ctrl+1]));
            }
            else if(gates[i]=="OR"){
                ORGate o;
                result = o.evaluate(result,I.val(inputs[ctrl+1]));
            }
            else if(gates[i]=="XOR"){
                XORGate x;
                result = x.evaluate(result,I.val(inputs[ctrl+1]));
            }
            else if(gates[i]=="NXOR"){
                XNORGate xn;
                result = xn.evaluate(result,I.val(inputs[ctrl+1]));
            }
            else if(gates[i]=="NOR"){
                NORGate n;
                result = n.evaluate(result,I.val(inputs[ctrl+1]));
            }
            else if(gates[i]=="NAND"){
                NANDGate nd;
                result = nd.evaluate(result,I.val(inputs[ctrl+1]));
            }
            else if(gates[i]=="NOT"){
                NOTGate nt;
                result = nt.evaluate(result);
                ctrl--;
            }
            ctrl++;

            

        }
        cout<<"Final Result is "<<result<<endl;
    }
    






};

int main() {
    vector<string> g1={"NOT","OR","AND"};
    vector<string> i1={"T","T","T"};
    Circuit c1(g1,i1);

    vector<string> g2={"NOT"};
    vector<string> i2={"T"};
    Circuit c2(g2,i2);

    vector<string> g3={"NOT","AND"};
    vector<string> i3={"T","T"};
    Circuit c3(g3,i3);

    vector<string> g4={"XOR","OR","NAND"};
    vector<string> i4={"T","T","F","F"};
    Circuit c4(g4,i4);






    c1.evaluate();
    c2.evaluate();
    c3.evaluate();
    c4.evaluate();


    
    return 0;
}
