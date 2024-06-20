/*

rivate:
void pushBttom(stack<int> &St, int top){
if(St.empty()){
St.push(top);
return;
}

int top1 = St.top();
St.pop();
pushBttom(St, top);
St.push(top1);
}
public:
void Reverse(stack<int> &St){
if(St.empty()){
return;
}
int top = St.top();
St.pop();
Reverse(St);
pushBttom(St, top);
}

*/