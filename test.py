import spam

graph = {}
graph["A"] = ["B", "C"];
graph["B"] = ["C"];
graph["C"] = ["D"];
graph["D"] = ["E"];
a = {"a":["1"]}
spam.system(graph)
