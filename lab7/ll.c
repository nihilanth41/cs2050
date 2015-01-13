
//insert @ head
addNode(Node *node)
{
	//base case node==null
	if(node == NULL) return node;
	//else
	node->data++;
	node->next=addone(node->next);
	return node;
}

Node* recursivefree(node *node)
{
	if(node != NULL)
	{
		recursiveFree(node->next);
		free(node);
	}
	return NULL;
}

Node *removeNode(Node *node, int data)
{
	if(node == NULL)
		return node;
	//else
	if(node->data == data)
	{
		Node *next = node->next;
		free(node);
		return next;
	}

	node->next = addOne(node->next);
	return node;
}

Node *insertOrdered(Node *node, int data)
{
	if(node == NULL)
		return node; //basecase
	if(node->data < data) 
	{
		//insert @ head
		Node *newnode = malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = node;
		return newNode
	}
	//else iterate
	node->next = addOne(node->next);
	return node;
}
:wq

