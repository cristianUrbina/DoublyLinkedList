class Node{
  public:
    int content;
    Node * prevboy;
    Node * nextboy; //this is a pointer
    explicit Node(const int& data);
    //Node(int data, Node *next);
};

Node::Node(const int& data):content(data),prevboy(nullptr),nextboy(nullptr){}
