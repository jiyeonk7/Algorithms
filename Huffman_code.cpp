//2016054011 ±èÁö¿¬ 508 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Node {
    char* ch;
    int num;

    Node* left;
    Node* right;
} Node;

Node* CreateNode();
void DeleteNode(Node** node);

Node* InsertTrieBoth(Node* left, Node* right);
int calBit(Node* node, int bit_size);

void MinHeapify(Node** heap, int N, int index);
void BuildHeap(Node** heap, int N);
Node* ExtractHeap(Node** heap, int N);
void InsertHeap(Node** heap, int N, Node* node);

int main() {
    int N;  //  means # of character
    Node** heap;
    int S;  //  means total # of character
    int power = 0;

    Node* trie;

    //FILE* in = fopen("1.in", "r");

    int i;

    scanf("%d", &N);
    //fscanf(in, "%d", &N);
    heap = (Node**)malloc(sizeof(Node*) * (N+1));
    for (i = 1; i <= N; i *= 2)
        power++;

    for (i = 1; i <= N; i++) {
        heap[i] = CreateNode();
        scanf("%s %d", heap[i]->ch, &heap[i]->num);
        //fscanf(in, "%s %d", heap[i]->ch, &heap[i]->num);
    }

    scanf("%d", &S);
    //fscanf(in, "%d", &S);

    BuildHeap(heap, N);

    while(1) {
        trie = InsertTrieBoth(ExtractHeap(heap, N--), ExtractHeap(heap, N--));
        if (N == 0)
            break;
        InsertHeap(heap, N++, trie);
    }

    printf("%d\n", power*S);
    printf("%d\n", calBit(trie, 0));

    //fclose(in);

    return 0;
}

Node* CreateNode() {
    Node* node = (Node*)malloc(sizeof(Node));

    node->ch = (char*)malloc(sizeof(char) * 5);
    
    node->left = NULL;
    node->right = NULL;

    return node;
}

void MinHeapify(Node** heap, int N, int index) {
    Node* key = heap[index];
    int child;

    for (child = index*2; child <= N; child *= 2) {
        if (child < N && (heap[child]->num > heap[child+1]->num))
            child++;

        if (heap[child]->num > key->num)
            break;
        else
            heap[child/2] = heap[child];
    }

    heap[child/2] = key;
}

void BuildHeap(Node** heap, int N) {
    int i;

    for (i = N/2; i > 0; i--)
        MinHeapify(heap, N, i);
}

Node* ExtractHeap(Node** heap, int N) {
    Node* ret = heap[1];
    
    heap[1] = heap[N];
    MinHeapify(heap, N, 1);

    return ret;
}

void InsertHeap(Node** heap, int N, Node* node) {
    int i;

    N++;
    for (i = N; i > 0; i /=2) {
        if (i/2 > 0 && heap[i/2]->num > node->num)
            heap[i] = heap[i/2];
        else
            break;
    }
    heap[i] = node;
}

Node* InsertTrieBoth(Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->left = left;
    node->right = right;

    node->num = left->num + right->num;

    return node;
}

int calBit(Node* node, int bit_size) {
    int ret = 0;

    if (node->left == NULL && node->right == NULL)
        return bit_size * node->num;

    ret += calBit(node->left, bit_size+1);
    ret += calBit(node->right, bit_size+1);

    return ret;
}
