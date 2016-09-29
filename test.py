from bfs_c import bfs

from collections import  deque
import networkx as nx
import time


def BFS1(G):
     q = deque()
     q.appendleft(G.keys()[0])
     visited = set([G.keys()[0]])
    #  print visited
     while(len(q) > 0 ):
         n = q.pop()
        #  print n
         for node in G[n]:
    	     if  len(visited.intersection([node])) == 0 :
                     q.appendleft(node)
                     visited.add(node)

def BFS2(G):
     q = deque()
     q.appendleft(G.keys()[0])
     visited = list([G.keys()[0]])
    #  print visited
     while(len(q) > 0 ):
         n = q.pop()
        #  print n
         for node in G[n]:
    	    #  if  len(visited.intersection([node])) == 0 :
            # print visited
            if node not in visited:
                     q.appendleft(node)
                    #  visited =  visited.union(node)
                     visited.append(node)


if __name__ == "__main__":
   import matplotlib.pyplot as plt
   times= list()
   ax = list()
   for index in xrange(1, 1000,10):
       G = nx.complete_graph(index)
       G = nx.to_dict_of_lists(G)
       G = {str(k):[str(i) for i in v] for k,v in G.items()}
       print index
       t1=time.time()
       BFS1(G)
       t12 = time.time()- t1
       t2 = time.time()
       t22 = bfs(G, G.keys()[0])
       # print t22
       # t22 = time.time() - t2
       ax.append(index)
       times.append((t12, t22))
   plt.plot(ax, [x for x,y in times], '-or', label="Python")
   plt.plot(ax, [y for x,y in times], '-ob', label="C++")
   plt.ylabel("seconds")
   plt.xlabel("number of nodes \n on complete graph")
   plt.legend()
   plt.show()