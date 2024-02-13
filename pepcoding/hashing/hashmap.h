#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node * next;

	Node(string key,T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
};

template<typename T>
class Hashtable{
	Node<T> ** table;
	int cs; 
	int ts;

	int hashFn(string key){
		int p = 1;
		int ans = 0;
		for(auto c : key){
			ans = (ans + c*p)%ts;
			p = (p*29)%ts;
		}
		return ans;
	}

	void rehash(){
		//create a table of 2x size
		// copy the data
		// delete the old table 

		



	}


public:
	Hashtable(int defaultSize=7){
		ts = defaultSize;
		cs = 0;
		table = new Node<T>*[ts];

		//init each bucket with a NULL address (important)
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
	}

	void insert(string key,int value){
		//1. get the index
		int index = hashFn(key);
		//Insert at that index 
		Node<T>* n = new Node<T>(key,value);
		n->next = table[index];
		table[index] = n;
		cs++;
		//load factor ...
		float load_factor = cs/ts;
		if(load_factor>0.75){
			//rehash 
			// write later...
			rehash();
		}

	}

	T* search(string key){
		int index = hashFn(key);

		Node<T> * temp = table[index];
		while(temp!=NULL){
			if(temp->key==key){
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void print(){

		//iterate over buckets
		for(int i=0;i<ts;i++){
			Node<T> * temp = table[i];
			cout<<"Bucket "<<i<<": ";
			while(temp!=NULL){
				cout<<temp->key<<" ,";
				temp = temp->next;
			}
			cout <<endl;
		}

	}

};