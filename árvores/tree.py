# Estrutura de Dados I
# Matheus Marinho
# Árvores

from bigtree import Node

# Elements
root = Node('a')
b = Node('b', parent=root)
c = Node('c', parent=root)
d = Node('d', parent=b)
e = Node('e', parent=b)

# Showing
root.show()

# Childrens
root.children
