#ifndef __TREE_HPP
#define __TREE_HPP

#include <iostream>
using namespace std;

class tree {
	public:
		data info;
		tree* LChild;
		tree* RChild;
			
	void add (tree** t,data d){			
		if (*t == NULL){			
			*t = (tree*) malloc (sizeof(tree));	
			(*t)->LChild = NULL;
			(*t)->RChild = NULL;
			(*t)->info = d;
		}
		else if (convert(d.word) > convert((*t)->info.word)){			
			add(&((*t)->RChild),d);
		}
		else if (convert(d.word) < convert((*t)->info.word)){
			add(&(*t)->LChild,d);
		}
	}
	
	void print(string method,tree* root){
		if (root != NULL){
			if (method == "pre-order"){
				cout<<"["<<root->info.word<<"] ";
				print ("pre-order",root->LChild);
				print ("pre-order",root->RChild);
			}
			else if (method == "in-order"){
				print ("in-order",root->LChild);
				cout<<"["<<root->info.word<<"] ";
				print ("in-order",root->RChild);
			}
			else if (method == "pos-order"){
				print ("pos-order",root->LChild);
				print ("pos-order",root->RChild);
				cout<<"["<<root->info.word<<"] ";				
			}
			else{
				cout<<"[ERROR] Print method does not exist.";
			}
		}
	}
	
	tree* search (data d,tree* root,int cont,int* NOp, bool path){		
		if  ((root == NULL) or (convert(d.word) == convert(root->info.word))){
			*NOp = cont;
			return root;
		}
		else if (convert(d.word) < convert(root->info.word)){
			cont++;		
			if (path){
				cout<<"0";
			}
			search (d,root->LChild,cont,NOp,path);		
		}
		else if (convert(d.word) > convert(root->info.word)){
			cont++;	
			if (path){
				cout<<"1";		
			}
			search (d,root->RChild,cont,NOp,path);
		}		
	}
};

void turnToArray(tree* t,data array[],int cont){
	if (t != NULL){
		for (int i=0;i<100;i++){
			array[cont].word[i] = t->info.word[i];
		}
		cont++;
		turnToArray(t->LChild,array,cont);
		turnToArray(t->RChild,array,cont);
	}
}

#endif
