#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 100
typedef struct Node {
int vertex;
struct Node* next;
} Node;
typedef struct Graph {
Node* adjList[MAX_VERTICES];
Node* revAdjList[MAX_VERTICES];
int numVertices;
} Graph;
Graph* createGraph(int numVertices) {
if (numVertices &lt;= 0 || numVertices &gt; MAX_VERTICES) {
printf(&quot;Invalid number of vertices. Exiting...\n&quot;);
exit(EXIT_FAILURE);
}
Graph* graph = (Graph*)malloc(sizeof(Graph));
graph-&gt;numVertices = numVertices;
for (int i = 0; i &lt; numVertices; ++i) {
graph-&gt;adjList[i] = NULL;
graph-&gt;revAdjList[i] = NULL;
}
return graph;
}
void addEdge(Graph* graph, int src, int dest) {
if (src &lt; 0 || src &gt;= graph-&gt;numVertices || dest &lt; 0 || dest &gt;= graph-&gt;numVertices) {
printf(&quot;Invalid source or destination vertex. Ignoring edge...\n&quot;);
return;
}
Node* newNode = (Node*)malloc(sizeof(Node));
newNode-&gt;vertex = dest;
newNode-&gt;next = graph-&gt;adjList[src];
graph-&gt;adjList[src] = newNode;
// Reverse graph for Kosaraju&#39;s algorithm
newNode = (Node*)malloc(sizeof(Node));
newNode-&gt;vertex = src;
newNode-&gt;next = graph-&gt;revAdjList[dest];
graph-&gt;revAdjList[dest] = newNode;
}
void DFSUtil(Graph* graph, int vertex, bool visited[]) {
visited[vertex] = true;
printf(&quot;%d &quot;, vertex);
Node* adjNode = graph-&gt;adjList[vertex];
while (adjNode != NULL) {
int adjVertex = adjNode-&gt;vertex;
if (!visited[adjVertex])
DFSUtil(graph, adjVertex, visited);
adjNode = adjNode-&gt;next;
}
}
void fillOrder(Graph* graph, int vertex, bool visited[], int stack[], int* stackIndex) {
visited[vertex] = true;
Node* adjNode = graph-&gt;revAdjList[vertex];
while (adjNode != NULL) {
int adjVertex = adjNode-&gt;vertex;
if (!visited[adjVertex])
fillOrder(graph, adjVertex, visited, stack, stackIndex);
adjNode = adjNode-&gt;next;
}
stack[++(*stackIndex)] = vertex;
}
Graph* getTranspose(Graph* graph) {
Graph* transposedGraph = createGraph(graph-&gt;numVertices);
for (int i = 0; i &lt; graph-&gt;numVertices; ++i) {
Node* current = graph-&gt;adjList[i];
while (current != NULL) {
addEdge(transposedGraph, current-&gt;vertex, i);
current = current-&gt;next;
}
}
return transposedGraph;
}
void printSCCs(Graph* graph) {
int stack[MAX_VERTICES];
int stackIndex = -1;
bool visited[MAX_VERTICES] = { false };
for (int i = 0; i &lt; graph-&gt;numVertices; ++i) {
if (!visited[i])
fillOrder(graph, i, visited, stack, &amp;stackIndex);
}
Graph* transposedGraph = getTranspose(graph);
for (int i = 0; i &lt; graph-&gt;numVertices; ++i)
visited[i] = false;
while (stackIndex &gt;= 0) {
int vertex = stack[stackIndex--];
if (!visited[vertex]) {
DFSUtil(transposedGraph, vertex, visited);
printf(&quot;\n&quot;);
}
}
free(transposedGraph);
}
int main() {
Graph* graph = createGraph(8);
// Define edges for demonstration
addEdge(graph, 0, 1);
addEdge(graph, 1, 2);
addEdge(graph, 2, 0);
addEdge(graph, 2, 3);
addEdge(graph, 3, 4);
addEdge(graph, 4, 5);
addEdge(graph, 5, 3);
addEdge(graph, 6, 5);
addEdge(graph, 6, 7);
addEdge(graph, 7, 6);
printf(&quot;Strongly Connected Components:\n&quot;);
printSCCs(graph);
return 0;
}
