from bfs_c import bfs

graph = {}
graph["A"] = ["B", "C"];
graph["B"] = ["C"];
graph["C"] = ["D"];
graph["D"] = ["E"];
a = {"a":["1"]}
bfs(graph, "A")
