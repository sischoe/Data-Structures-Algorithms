import networkx as nx
from matplotlib import pyplot as plt

def maybe_draw_tour(nodes, positions, edges):
  """Draw the tour if the code was run manually."""
  
  graph = nx.Graph()
  graph.add_nodes_from(nodes)
  graph.add_edges_from(edges)

  fig = plt.figure(figsize=(12,8))
  axes = fig.add_subplot()
  nx.draw(graph, positions, node_size=1, width=.35, node_color="green", ax=axes)
  fig.savefig("cx_out/tour.png", bbox_inches="tight")