    #include <iostream>
    #include <string>
    #include <vector>
    #include <list>
    #include <queue>
    #include <stack>

    using namespace std;



    struct node{
      int data;
      node* left;
      node* right;
    };

    struct Linknode{
      int data;
      Linknode* next;
};

    class btree{
      public:
        btree();
        ~btree();

        void insert(int key);
        node* search(int key);
        void destroy();
        void preorder();
        void postorder();
        void inorder();
        void maxdepth();
        void haspathsum(int sum);
        void allpath(int sum);
        node* findmax();
      //  void deletenode();
        node* LCA(int m, int n);
        void CreatLink();
        void ZigZag();
        void CheckBalance();

      private:
        void insert(int key,node* leaf);
        void destroy(node* leaf);
        node* search(int key,node* leaf);
        void preorder(node* leaf);
        void postorder(node* leaf);
        void inorder(node* leaf);
        int maxdepth(node* leaf);
        bool haspathsum(node* leaf,int sum);
        void allpath(node* root,int path[],int pathlen,int sum);
        void printarray(int path[],int pathlen,int sum);
        node* findmax(node* leaf);
    //    void deletenode(node* leaf);
        node* LCA(node* leaf,int m,int n);
        void CreatLink(node* leaf,int path[],int pathlen);
        void printLink(int path[],int pathlen);
        void ZigZag(node* leaf);
        int CheckBalance(node* leaf);
        node* root;
    };
//Constructor
    btree::btree(){

    root = NULL;
    }
//Destructor
    btree::~btree(){
    destroy();
    }

void btree::destroy(){
destroy(root);
}

  void  btree::destroy(node* leaf){
    if(leaf != NULL){
      destroy(leaf->right);
      destroy(leaf->right);
      delete leaf;
    }
}

// Method to insert data into tree
void btree::insert(int key, node* leaf){

  if(key<leaf->data){
          if(leaf->left != NULL)
            insert(key,leaf->left);
          else{
            leaf->left = new node;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf ->left->right = NULL;
                }
    }
    else if(key>=leaf->data) {
      if(leaf->right !=NULL)
        insert(key,leaf->right);
      else{
        leaf->right = new node;
        leaf->right->data = key;
        leaf->right->left=NULL;
        leaf->right->right=NULL;
        }
      }
}

  void  btree::insert(int key){
        if(root != NULL)
          insert(key,root);
        else{
        root = new node;
        root->data = key;
        root->left = NULL;
        root -> right = NULL;
    }
    }

// method to search for a key
node* btree::search(int key,node* leaf){

    if(leaf != NULL){
      if(key == leaf->data)
          return leaf;
      if(key<leaf->data)
          return search(key,leaf->left);
      if(key >= leaf->data)
          return search(key,leaf->right);
}
else return NULL;
}

node* btree::search(int key){
return search(key,root);
}

// method to print data in preorder
void btree::preorder(){
cout<<"Preorder"<<endl;
 preorder(root);
}

void btree::preorder(node* leaf){
list<node*> mylist;
node* temp = leaf;
cout<<temp->data;
/*while(1){
while(temp != NULL){
  cout<<temp->data<<":";
  mylist.push_front(leaf);
  temp = temp->left;
}
if(mylist.empty())
  break;
temp = mylist.front();
mylist.pop_front();
temp = temp->right;
}*/
}

// method to print data in postorder
void btree::postorder(){
cout<<"Postorder"<<endl;
 postorder(root);
}
void btree::postorder(node* leaf){
if(leaf != NULL){
  postorder(leaf->left);
  postorder(leaf->right);
  cout<<leaf->data<<":";
}
}

// method to print data in inorder
void btree::inorder(){
cout<<"Inorder"<<endl;
inorder(root);
}
void btree::inorder(node* leaf){
if(leaf != NULL){
  inorder(leaf->left);
  cout<<leaf->data<<":";
  inorder(leaf->right);
}
}

//method to find the depth of the tree
void btree::maxdepth(){
cout<<"MaxDepth:"<<endl;
int depth;
depth = maxdepth(root);

cout<<depth<<endl;
}

int btree::maxdepth(node* leaf){

int ldepth = 0;
int rdepth = 0;

if(leaf == NULL)
return(0);
else{
 ldepth = maxdepth(leaf->left);
 rdepth = maxdepth(leaf->right);
}

if(ldepth>rdepth)
return(ldepth+1);
else
return(rdepth+1);

}

// method to return if a tree has a path with given sum
void btree::haspathsum(int sum){
bool T_F;
T_F = haspathsum(root,sum);

cout<<"True/False"<<T_F<<endl;
}

bool btree::haspathsum(node* leaf,int sum){
int subsum = 0;
if(leaf == NULL)

return(sum == 0);
else{
subsum = sum - leaf->data;
if((leaf->left && leaf->right) ||(!leaf->right && !leaf->left))
return(haspathsum(leaf->left,subsum) || haspathsum(leaf->right,subsum));
else if(leaf->left)
  return(haspathsum(leaf->left,subsum));
else return haspathsum(leaf->right,subsum);
}
}

// method to print all paths from root to leaf
void btree::allpath(int sum){

int pathlen = 0;
int path[1000];
allpath(root,path,pathlen,sum);
}

void btree::allpath(node* leaf, int path[],int pathlen,int sum){

if(leaf == NULL)
return ;
path[pathlen] = leaf->data;
pathlen++;

if(leaf->left == NULL && leaf->right == NULL)
printarray(path,pathlen,sum);

else{
allpath(leaf->left,path,pathlen,sum);
allpath(leaf->right,path,pathlen,sum);
}
}

void btree::printarray(int path[],int pathlen,int sum){
int i;
int subsum = 0;
for(i =0;i<pathlen;++i){
subsum += path[i];
cout<<path[i]<<" ";
}
if(sum == subsum)
cout<<"This Path has sum:"<<sum;

cout<<"\n";
}

// method to print the maximun elemnet of a tree
node* btree::findmax(){
return findmax(root);
}

node* btree::findmax(node* leaf){

if(leaf->right == NULL)
return leaf;
else return findmax(leaf->right);

}

// method to return the Least Common Ancestor
node* btree::LCA(int m,int n){
return LCA(root,m,n);
}

node* btree::LCA(node *leaf, int p, int q) {
  if (!leaf || !p || !q) return NULL;
  if (max(p, q) < leaf->data)
    return LCA(leaf->left, p, q);
  else if (min(p, q) > leaf->data)
    return LCA(leaf->right, p, q);
  else
    return leaf;
}

// method to create a linked list od each level of tree
void btree::CreatLink(){
int pathlen = 0;
int path[1000];
CreatLink(root,path,pathlen);
}

void btree::CreatLink(node* leaf,int path[], int pathlen){
int level = 0;

queue<node*> myqueque;
node* temp =NULL;

myqueque.push(root);
myqueque.push(temp);

while(!myqueque.empty()){

node* n = myqueque.front();
myqueque.pop();

if(n != NULL){
path[pathlen] = n->data;
pathlen++;
}

if(n==NULL){
if(!myqueque.empty())  myqueque.push(temp);
printLink(path,pathlen);
pathlen = 0;
level++;
}
else{
if(n->left) myqueque.push(n->left);
if(n->right) myqueque.push(n->right);
}
}
cout<<"Level:"<<level;
}

void btree::printLink(int path[],int pathlen){
int i;

cout<<"List:";

Linknode* tail;
Linknode* n = new Linknode;
n->data = path[0];
Linknode* head = n;
tail = n;

for(i =1;i<pathlen;++i){
n = new Linknode;
n->data = path[i];
tail->next = n;
tail = n;
}
n->next = NULL;

while(head !=NULL){
cout<<head->data<<" ";
head = head->next;
}
cout<<"\n";
}

// method to print data in a ZigZag level traversal
void btree::ZigZag(){
ZigZag(root);
}

void btree::ZigZag(node* leaf){
stack<node*> nextlevel;
stack<node*> currlevel;
node* temp;
int leftright = 1;

currlevel.push(leaf);

while(!currlevel.empty()){
temp = currlevel.top();
currlevel.pop();
if(temp){
  cout<<temp->data<<" ";

  if(leftright){
      if(temp->left) nextlevel.push(temp->left);
      if(temp->right) nextlevel.push(temp->right);
      }
  else{
      if(temp->right) nextlevel.push(temp->right);
      if(temp->left) nextlevel.push(temp->left);
}
    if(currlevel.empty()){
    leftright = 1 - leftright;
    swap(currlevel,nextlevel);
    }
}
}

}

//method to find if a tree id balanced binary tree

void btree::CheckBalance(){
int k;
k = CheckBalance(root);
if(k== -1)
cout<<"False";
else
cout<<"True";
}

int btree::CheckBalance(node* leaf){
if(leaf == NULL) return 0;

int leftht = CheckBalance(leaf->left);
if(leftht == -1) return -1;

int rightht = CheckBalance(leaf->right);
if(rightht == -1) return -1;

int htdiff = abs(leftht - rightht);
if(htdiff > 1) return -1;
else return (max(leftht,rightht)+1);
}

int main(int argc,char** argv){

btree mybtree;

int value,key,choice,sum,m,n;
node *present = new node;
node* maxnode = new node;
node* LCAnode = new node;

while(true){

    cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Quit\n5.Preorder\n6.Inorder\n7.Postorder\n8.Haspathsum\n9.Maxdepth\n10.AllPath\n11.Maxnode\n12.LCA\n13.CreatLink\n14.ZigZag\n15.CheckBalance"<<endl;

    cout<<"\nEnter your choice: ";

    cin>>choice;

    switch(choice){

        case 1:
            cout<<"Enter value"<<endl;
            cin>>value;
            mybtree.insert(value);

            break;

        case 2:
            cout<<"Enter key to search"<<endl;
            cin>>key;
            present = mybtree.search(key);

            cout<<"Key:"<<present->data<<endl;
            break;

        case 3:

            mybtree.destroy();

            break;

        case 4:

            exit(0);

            break;

        case 5:

          mybtree.preorder();

            break;

        case 6:

            mybtree.inorder();

            break;

        case 7:

            mybtree.postorder();

            break;

        case 8:
            cout<<"Enter sum to search"<<endl;
            cin>>sum;
            mybtree.haspathsum(sum);

            break;

        case 9:

            mybtree.maxdepth();

            break;


        case 10:
            cout<<"Enter sum to search"<<endl;
            cin>>sum;
            mybtree.allpath(sum);

            break;

        case 11:
            maxnode = mybtree.findmax();
            cout<<"Max Element:"<<maxnode->data;
            break;

        case 12:
            cout<<"Enter m to search"<<endl;
            cin>>m;
            cout<<"Enter n to search"<<endl;
            cin>>n;
            LCAnode = mybtree.LCA(m,n);
            cout<<"LCA Node:"<<LCAnode->data;
            break;

        case 13:
        mybtree.CreatLink();
        break;

        case 14:
        mybtree.ZigZag();
        break;

        case 15:
        mybtree.CheckBalance();
        break;
          default:

            cout<<"\nInvalid Input. Try again! \n";

            break;

    }

}

return 0;

}
