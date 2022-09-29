class Node{
	int data;
	Node leftNode;
	Node rightNode;

	Node(int value){
		this.data = value;
		this.leftNode = null;
		this.rightNode = null;
	}
}

public class binaryTree{
	static Node root;

	public static void main(String [] args){
		insert(root, 2);
		insert(root, 4);
		insert(root, 1);
		System.out.println(root.leftNode.data);
	}

	public static void insert(Node current , int data){
		if(current == null){
			current = new Node(data);
			return;
		}
		if (data > current.data) {
			insert(current.rightNode, data);	
		} else {
			insert(current.leftNode, data);	
		}
	}
}

