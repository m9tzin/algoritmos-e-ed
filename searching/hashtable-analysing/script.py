# Hash Analysing w/ matplot
# Estrutura de Dados II
# Matheus Marinho

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carrega os dados
data = pd.read_csv('hash_results.csv')

# Renomeia as colunas para corresponder ao CSV gerado pelo código C
if 'NumInputs' in data.columns:
    data = data.rename(columns={'NumInputs': 'inputs'})
if 'Collisions' in data.columns:
    data = data.rename(columns={'Collisions': 'colisoes'})

# Configura o estilo dos gráficos
plt.style.use('ggplot')
plt.figure(figsize=(15, 12))

# Define cores para melhor visualização
colors = ['#1f77b4', '#ff7f0e', '#2ca02c']

# Gráfico de Número de Colisões
plt.subplot(2, 1, 1)
for i, table_size in enumerate(data['TableSize'].unique()):
    subset = data[data['TableSize'] == table_size]
    plt.plot(subset['inputs'], subset['colisoes'], 'o-', 
             linewidth=2, markersize=8, color=colors[i],
             label=f'M={table_size}')

plt.title('Número de Colisões vs. Número de Entradas', fontsize=16, fontweight='bold')
plt.xlabel('Número de Entradas', fontsize=14)
plt.ylabel('Número de Colisões', fontsize=14)
plt.legend(fontsize=12)
plt.grid(True)
plt.xscale('log')
plt.xticks(data['inputs'].unique(), data['inputs'].unique())

# Gráfico de Tempos de Execução
plt.subplot(2, 1, 2)
markers = ['o', 's', '^']
linestyles = ['-', '--']

for i, table_size in enumerate(data['TableSize'].unique()):
    subset = data[data['TableSize'] == table_size]
    plt.plot(subset['inputs'], subset['InsertionTime'], markers[i]+linestyles[0], 
             linewidth=2, markersize=8, color=colors[i],
             label=f'Inserção M={table_size}')
    plt.plot(subset['inputs'], subset['SearchTime'], markers[i]+linestyles[1], 
             linewidth=2, markersize=8, color=colors[i], alpha=0.6,
             label=f'Busca M={table_size}')

plt.title('Tempo de Execução vs. Número de Entradas', fontsize=16, fontweight='bold')
plt.xlabel('Número de Entradas', fontsize=14)
plt.ylabel('Tempo (segundos)', fontsize=14)
plt.legend(fontsize=12)
plt.grid(True)
plt.xscale('log')
plt.xticks(data['inputs'].unique(), data['inputs'].unique())

# Taxa de colisão (gráfico adicional)
plt.figure(figsize=(15, 6))
for i, table_size in enumerate(data['TableSize'].unique()):
    subset = data[data['TableSize'] == table_size]
    # Calcula a taxa de colisão: colisões / número de entradas
    collision_rate = subset['colisoes'] / subset['inputs']
    plt.plot(subset['inputs'], collision_rate, 'o-', 
             linewidth=2, markersize=8, color=colors[i],
             label=f'M={table_size}')

plt.title('Taxa de Colisão vs. Número de Entradas', fontsize=16, fontweight='bold')
plt.xlabel('Número de Entradas', fontsize=14)
plt.ylabel('Taxa de Colisão (colisões/entradas)', fontsize=14)
plt.legend(fontsize=12)
plt.grid(True)
plt.xscale('log')
plt.xticks(data['inputs'].unique(), data['inputs'].unique())

# Salva todos os gráficos
plt.figure(1)
plt.tight_layout()
plt.savefig('hash_performance.png', dpi=300)

plt.figure(2)
plt.tight_layout()
plt.savefig('hash_collision_rate.png', dpi=300)

print("Gráficos gerados com sucesso:")
print("1. hash_performance.png - Colisões e Tempos de Execução")
print("2. hash_collision_rate.png - Taxa de Colisão")

plt.show()