import draw_graph
import os

def main():
  # only draw a graph when not testing or submitting
  if os.environ["ACTION"] != "run":
    return
  
  nodes = []
  coords = {}
  edges = []
  with open("out_nodes.txt","r") as f:
    lines = f.readlines()
    for line in lines:
      entries = line.split(",");
      num = int(entries[0])
      x = float(entries[1])
      y = float(entries[2])
      nodes.append(num)
      coords[num] = (x,y)
      #print(num,x,y)
  with open("out_edges.txt","r") as f:
    lines = f.readlines()
    for line in lines:
      entries = line.split(",");
      n1 = int(entries[0])
      n2 = int(entries[1])
      dist = float(entries[2])
      edges.append((n1,n2))

  draw_graph.maybe_draw_tour(nodes,coords,edges)

if __name__ == '__main__':
  main()