

#include <iostream>
#include "binarysearchtree.cpp"

using namespace std;

void checkEmpty(bool b) {
    if (b)
        cout << "Tree is Empty" << endl;
    else
        cout << "Tree is not Empty" << endl;
}

void itemFound(TreeType<int> &tree, int item) {
    bool found;
    tree.RetrieveItem(item, found);
    if (found)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;
}

void insertRecursively(TreeType<int> &newTree, int array[], int start, int end) {
    int mid = (start + end) / 2;
    newTree.InsertItem(array[mid]);

    if (start == end)
        return;

    if (start < mid)
        insertRecursively(newTree, array, start, mid - 1);

    insertRecursively(newTree, array, mid + 1, end);
}

int main() {

    // First Task
    TreeType<int> tree;                          // Create a tree object

    checkEmpty(tree.IsEmpty());                  // Print if the tree is empty or not

    tree.InsertItem(4);                          // Insert ten items
    tree.InsertItem(9);
    tree.InsertItem(2);
    tree.InsertItem(7);
    tree.InsertItem(3);
    tree.InsertItem(11);
    tree.InsertItem(17);
    tree.InsertItem(0);
    tree.InsertItem(5);
    tree.InsertItem(1);

    checkEmpty(tree.IsEmpty());          

    cout << tree.LengthIs() << endl;           

    itemFound(tree, 9);                         
    itemFound(tree, 13);                       

    // Print the elements in the tree (inorder)
    tree.ResetTree(IN_ORDER);
    bool finish = false;
    while (!finish) {
        int value;
        tree.GetNextItem(value, IN_ORDER, finish);
        cout << value << " ";
    }
    cout << endl;

    // Print the elements in the tree (preorder)
    tree.ResetTree(PRE_ORDER);
    finish = false;
    while (!finish) {
        int value;
        tree.GetNextItem(value, PRE_ORDER, finish);
        cout << value << " ";
    }
    cout << endl;

    // Print the elements in the tree (postorder)
    tree.ResetTree(POST_ORDER);
    finish = false;
    while (!finish) {
        int value;
        tree.GetNextItem(value, POST_ORDER, finish);
        cout << value << " ";
    }
    cout << endl;

    tree.MakeEmpty();                          


    // Second Task
    TreeType<int> sequenceTree;                 
    int num = 10;
    int sequence[] = {11, 9, 4, 2, 7, 3, 17, 0, 5, 1};

    for (int i = 0; i < num; i++) {
        sequenceTree.InsertItem(sequence[i]);
    }

    int n, arr[num + 10], index = 0;

    sequenceTree.ResetTree(IN_ORDER);
    finish = false;
    while (!finish) {
        sequenceTree.GetNextItem(n, IN_ORDER, finish);
        arr[index++] = n;
    }

    TreeType<int> newTree;

    insertRecursively(newTree, arr, 0, index - 1);

    newTree.ResetTree(PRE_ORDER);
    finish = false;
    while (!finish) {
        newTree.GetNextItem(n, PRE_ORDER, finish);
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
