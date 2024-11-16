// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
struct Node
{
    int coeff;
    int powX;
    int powY;
    int powZ;
    Node *next;
};
Node *createNode(int coeff, int powX, int powY, int powZ, Node *head)
{
    Node *newNode = new Node;
    newNode->coeff = coeff;
    newNode->powX = powX;
    newNode->powY = powY;
    newNode->powZ = powZ;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node *addOrUpdateNode(Node *head, int coeff, int powX, int powY, int powZ)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->powX == powX && temp->powY == powY && temp->powZ == powZ)
        {
            temp->coeff += coeff;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    Node *newNode = new Node;
    newNode->coeff = coeff;
    newNode->powX = powX;
    newNode->powY = powY;
    newNode->powZ = powZ;
    newNode->next = nullptr;
    if (prev == nullptr)
    {
        return newNode;
    }
    else
    {
        prev->next = newNode;
    }
    return head;
}
void displayPoly(Node *head)
{
    Node *temp = head;
    bool first = true;
    while (temp != nullptr)
    {
        if (temp->coeff != 0)
        {
            if (!first && temp->coeff > 0)
            {
                cout << " + ";
            }
            cout << temp->coeff << "x^" << temp->powX << "y^" << temp->powY << "z^" << temp->powZ;
            first = false;
        }
        temp = temp->next;
    }
    cout << endl;
}
Node *multiplyPolynomials(Node *poly1, Node *poly2)
{
    Node *result = nullptr;
    for (Node *temp1 = poly1; temp1 != nullptr; temp1 = temp1->next)
    {
        for (Node *temp2 = poly2; temp2 != nullptr; temp2 = temp2->next)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int powX = temp1->powX + temp2->powX;
            int powY = temp1->powY + temp2->powY;
            int powZ = temp1->powZ + temp2->powZ;
            result = addOrUpdateNode(result, coeff, powX, powY, powZ);
        }
    }
    return result;
}
int main()
{
    Node *poly1 = nullptr;
    poly1 = createNode(3, 2, 1, 0, poly1);
    poly1 = createNode(2, 1, 1, 1, poly1);
    poly1 = createNode(5, 0, 0, 0, poly1);
    Node *poly2 = nullptr;
    poly2 = createNode(1, 2, 2, 0, poly2);
    poly2 = createNode(1, 1, 1, 1, poly2);
    poly2 = createNode(1, 0, 0, 0, poly2);

    cout << "First Polynomial: ";
    displayPoly(poly1);
    cout << "Second Polynomial: ";
    displayPoly(poly2);

    Node *result = multiplyPolynomials(poly1, poly2);
    cout << "Result of Multiplication: ";
    displayPoly(result);

    return 0;
}
