# Estrutura de Dados I
# Matheus Marinho
# Árvores
from bigtree import list_to_tree

path_list = ['a/b/d', 'a/b/e', 'a/c'] 
# a -> b -> d
# a -> b -> e
# a -> c 
root = list_to_tree(path_list)

root.hshow()