import networkx as nx
from networkx.algorithms import shortest_path, all_shortest_paths, has_path
import matplotlib.pyplot as plt
import numpy as np


# 假設所有路徑都沒有負權重，且都為1 
class Graph(nx.Graph):
    """[summary]
    Graph class that is based on networkx graph object
    Args:
        nx ([type]): [description]
    """
    nodesNum = 0
    edgesNum = 0
    def __init__(self,airplanes_list, airplanes_edges):
        super(Graph, self).__init__()
        super(Graph, self).add_nodes_from(airplanes_list)
        super(Graph, self).add_edges_from(airplanes_edges)
        Graph.nodesNum = len( self.nodes)
        Graph.edgesNum = len( self.edges)
        
        
    @staticmethod
    def draw(obj):
        nx.draw(obj, with_labels=True, font_weight='bold')
        plt.show()

    def get_shortest_path(self, start_node_id, end_node_id):
        # 作為熱身，請實現 get_shortest_path(self, start_node_id, end_node_id) 方法，
        # 而不使用您選擇的網絡/圖形包中的任何方法。
        #  該函數應以 start_node_id 和 end_node_id 作為輸入，
        # 並返回表示最短路徑的節點 id 列表（如果有多個，則為最短路徑）
        
        # CDHDR ->BKPF = 2
        # CDHDR ->CDPOS = 1
        # BFS
        # 實現 all_shortest_paths , shortest_path
        # Dijkstra algorithm or bellman-ford"
        return shortest_path(self, source =start_node_id, target=end_node_id)
        # simple test function

        visit = np.zeros((self.nodesNum,), dtype=bool)
        distance = np.ones( (self.nodesNum)) * np.inf;
        adjacency_matrix = np.ones((self.nodesNum, self.nodesNum) ) *np.inf


        # int w[9][9];    // adjacency matrix
        # int d[9];       // 記錄起點到各個點的最短路徑長度
        # int parent[9];  // 記錄各個點在最短路徑樹上的父親是誰
        # bool visit[9];  // 記錄各個點是不是已在最短路徑樹之中

    def get_subtrees(self, selected_node_ids):
        pass
        
        # 實現方法 get_subtrees(self, selected_node_ids)。
        # - 輸入應該是要合併到樹中的節點 ids selected_node_ids 列表。
        # - 此函數的輸出應該是樹列表，其中每棵樹都由邊列表表示（邊是兩個節點 id 的元組）。
        #  是創建樹列表的各種方法。 選擇一種可以將計算成本降至最低的方法。

    def all_path():
        # // 添加節點s 到路徑
        # path.push_back(s);
        
        # int n = graph.size();
        # if(s == n-1){
        #     // 到達終點
        #     ret.push_back(path);
        #     path.pop_back();
        #     return ;
        # }
        # // 遍歷每個相鄰節點
        # for(int v:graph[s]){
        #     traverse(graph, v, path);
        # }
        # // 從路徑移出節點
        # path.pop_back();
if __name__ == "__main__":
    

    airplanes_list = [
                'CDHDR', 
                'BKPF', 'CDPOS', 
                'SWWLOGHIST', 
                'TVZBT', 'SWW_WI2OBJ',  'TMP_AP_BKPF_BSEG_1', 
                'T042Z' , 'USR02',
                'T003T',
                'LFB1',
                'TMP_AP_BKPF_BSEG', 'BSEG' ,
                'PSIIC_HEAD', '_CEL_AP_CASES_VIEW',
                'TBSLT',
                'LFA1',
                'REGUP',
                'BSEC','_CEL_AP_CASES_VIEW_1', 'T052U'  , 'EKPO'      
                ]

    airplanes_edges = [
                # CDHDR
                ('CDHDR','CDPOS'), ('CDHDR', 'USR02'),
                # BKPF
                ('BKPF', 'TMP_AP_BKPF_BSEG'), ('BKPF', 'LFA1'), ('BKPF', '_CEL_AP_CASES_VIEW_1'), ('BKPF', 'BSEG'),
                ('BKPF', 'PSIIC_HEAD'), ('BKPF', 'REGUP'), ('BKPF', 'LFB1'), ('BKPF', 'SWW_WI2OBJ'),
                ('BKPF', '_CEL_AP_CASES_VIEW'),('BKPF', 'USR02'), ('BKPF', 'T003T'), ('BKPF', 'TMP_AP_BKPF_BSEG_1'), ('BKPF', 'CDPOS'),
                # CDPOS
                ('CDPOS','CDHDR'), ('CDPOS','BKPF'), ('CDPOS','TMP_AP_BKPF_BSEG'), ('CDPOS','PSIIC_HEAD'), ('CDPOS','_CEL_AP_CASES_VIEW'), ('CDPOS','TMP_AP_BKPF_BSEG_1'),
                # SWWLOGHIST
                ('SWWLOGHIST','SWW_WI2OBJ' ),
                # TMP_AP_BKPF_BSEG_1
                ('TMP_AP_BKPF_BSEG_1','BKPF' ), ('TMP_AP_BKPF_BSEG_1', 'TVZBT'), ('TMP_AP_BKPF_BSEG_1', 'SWW_WI2OBJ'),
                ('TMP_AP_BKPF_BSEG_1', 'T042Z'), ('TMP_AP_BKPF_BSEG_1', 'USR02'), ('TMP_AP_BKPF_BSEG_1', 'TMP_AP_BKPF_BSEG'),
                ('TMP_AP_BKPF_BSEG_1', 'BSEG'), ('TMP_AP_BKPF_BSEG_1', 'LFB1'), ('TMP_AP_BKPF_BSEG_1', 'LFA1'),
                ('TMP_AP_BKPF_BSEG_1', 'TBSLT'), ('TMP_AP_BKPF_BSEG_1', 'PSIIC_HEAD'), ('TMP_AP_BKPF_BSEG_1', '_CEL_AP_CASES_VIEW_1'),
                ('TMP_AP_BKPF_BSEG_1', 'REGUP'), ('TMP_AP_BKPF_BSEG_1', 'T052U'), ('TMP_AP_BKPF_BSEG_1', '_CEL_AP_CASES_VIEW'),
                # TVZBT
                ('TVZBT', 'LFA1'),('TVZBT', '_CEL_AP_CASES_VIEW_1'),('TVZBT', 'BSEG'),
                ('TVZBT', '_CEL_AP_CASES_VIEW'),('TVZBT', 'LFB1'),('TVZBT', 'TMP_AP_BKPF_BSEG_1'),
                # T042Z
                ('T042Z', '_CEL_AP_CASES_VIEW_1'), ('T042Z', 'T052U'), ('T042Z', '_CEL_AP_CASES_VIEW'), ('T042Z', 'TMP_AP_BKPF_BSEG_1'), 
                # SWW_WI2OBJ
                ('SWW_WI2OBJ', 'SWWLOGHIST'), ('SWW_WI2OBJ', 'BKPF'),('SWW_WI2OBJ', '_CEL_AP_CASES_VIEW'),('SWW_WI2OBJ', 'TMP_AP_BKPF_BSEG_1'),
                # USR02
                ('USR02', 'CDHDR'),('USR02','BKPF' ),('USR02', 'PSIIC_HEAD'),('USR02', 'TMP_AP_BKPF_BSEG'),('USR02', '_CEL_AP_CASES_VIEW'),
                # TMP_AP_BKPF_BSEG
                ('TMP_AP_BKPF_BSEG', 'LFA1'),('TMP_AP_BKPF_BSEG', '_CEL_AP_CASES_VIEW_1'),('TMP_AP_BKPF_BSEG', 'T052U'),
                ('TMP_AP_BKPF_BSEG', 'TBSLT'),('TMP_AP_BKPF_BSEG', 'REGUP'),('TMP_AP_BKPF_BSEG', 'EKPO'),
                ('TMP_AP_BKPF_BSEG', 'PSIIC_HEAD'),('TMP_AP_BKPF_BSEG', '_CEL_AP_CASES_VIEW'),('TMP_AP_BKPF_BSEG', 'BSEG'),
                ('TMP_AP_BKPF_BSEG', 'LFB1'),('TMP_AP_BKPF_BSEG', 'TMP_AP_BKPF_BSEG_1'),('TMP_AP_BKPF_BSEG', 'USR02'),
                ('TMP_AP_BKPF_BSEG', 'SWW_WI2OBJ'),('TMP_AP_BKPF_BSEG', 'CDPOS'),('TMP_AP_BKPF_BSEG', 'T042Z'),
                ('TMP_AP_BKPF_BSEG', 'BKPF'),('TMP_AP_BKPF_BSEG', 'TVZBT'),

                # BSEG
                ('BSEG', 'BKPF'),('BSEG', 'TMP_AP_BKPF_BSEG'),('BSEG', 'LFA1'),('BSEG', 'BSEC'),
                ('BSEG', 'TBSLT'),('BSEG', '_CEL_AP_CASES_VIEW_1'),('BSEG', '_CEL_AP_CASES_VIEW'),
                # LFB1
                ('LFB1', 'BKPF'),('LFB1', 'TVZBT'),('LFB1', '_CEL_AP_CASES_VIEW_1'),
                ('LFB1', 'T052U'),('LFB1', '_CEL_AP_CASES_VIEW'),
                # T003T
                ('T003T', 'BKPF'), ('T003T', '_CEL_AP_CASES_VIEW'),
                # _CEL_AP_CASES_VIEW
                ('_CEL_AP_CASES_VIEW', 'T003T'),('_CEL_AP_CASES_VIEW', 'TMP_AP_BKPF_BSEG_1'),('_CEL_AP_CASES_VIEW', 'CDPOS'),('_CEL_AP_CASES_VIEW', 'USR02'),
                ('_CEL_AP_CASES_VIEW', 'BKPF'),('_CEL_AP_CASES_VIEW', 'SWW_WI2OBJ'),('_CEL_AP_CASES_VIEW', 'LFB1'),('_CEL_AP_CASES_VIEW', 'T042Z'),
                ('_CEL_AP_CASES_VIEW', 'TVZBT'),('_CEL_AP_CASES_VIEW', 'BSEG'),('_CEL_AP_CASES_VIEW', 'TMP_AP_BKPF_BSEG'),('_CEL_AP_CASES_VIEW', 'PSIIC_HEAD'),
                ('_CEL_AP_CASES_VIEW', 'TBSLT'),('_CEL_AP_CASES_VIEW', 'LFA1'),('_CEL_AP_CASES_VIEW', '_CEL_AP_CASES_VIEW_1'),('_CEL_AP_CASES_VIEW', 'REGUP'),
                ('_CEL_AP_CASES_VIEW', 'T052U'),('_CEL_AP_CASES_VIEW', 'EKPO'),
                # PSIIC_HEAD
                ('PSIIC_HEAD','TMP_AP_BKPF_BSEG_1'), ('PSIIC_HEAD', 'CDPOS'), ('PSIIC_HEAD', 'BKPF'), 
                ('PSIIC_HEAD', 'TMP_AP_BKPF_BSEG'),  ('PSIIC_HEAD', '_CEL_AP_CASES_VIEW_1'), ('PSIIC_HEAD', '_CEL_AP_CASES_VIEW'),
                # TBSLT
                ('TBSLT', 'TMP_AP_BKPF_BSEG_1'),('TBSLT', 'BSEG'),('TBSLT', 'TMP_AP_BKPF_BSEG'),
                ('TBSLT', '_CEL_AP_CASES_VIEW_1'),('TBSLT', '_CEL_AP_CASES_VIEW'),
                # LFA1
                ('LFA1', 'TMP_AP_BKPF_BSEG'), ('LFA1', 'BKPF'), ('LFA1', 'BSEG'), 
                ('LFA1', 'TMP_AP_BKPF_BSEG_1'), ('LFA1', '_CEL_AP_CASES_VIEW'),
                # REGUP
                ('REGUP', '_CEL_AP_CASES_VIEW'),('REGUP', 'TMP_AP_BKPF_BSEG'), 
                # BSEC
                (' BSEC', 'BSEG'),(' BSEC', '_CEL_AP_CASES_VIEW_1'),
                # _CEL_AP_CASES_VIEW_1
                ('_CEL_AP_CASES_VIEW_1', 'BSEC'), ('_CEL_AP_CASES_VIEW_1', 'LFA1'), ('_CEL_AP_CASES_VIEW_1', 'TMP_AP_BKPF_BSEG'), 
                ('_CEL_AP_CASES_VIEW_1', 'TVZBT'), ('_CEL_AP_CASES_VIEW_1', 'T042Z'), ('_CEL_AP_CASES_VIEW_1', 'TBSLT'), 
                ('_CEL_AP_CASES_VIEW_1', 'BKPF'), ('_CEL_AP_CASES_VIEW_1', 'BSEG'), ('_CEL_AP_CASES_VIEW_1', 'LFB1'), 
                ('_CEL_AP_CASES_VIEW_1', 'PSIIC_HEAD'), ('_CEL_AP_CASES_VIEW_1', 'TMP_AP_BKPF_BSEG_1'), ('_CEL_AP_CASES_VIEW_1', '_CEL_AP_CASES_VIEW'),
                ('_CEL_AP_CASES_VIEW_1', 'EKPO'),('_CEL_AP_CASES_VIEW_1', 'T052U'),
                # T052U
                ('T052U', '_CEL_AP_CASES_VIEW_1'), ('T052U', 'TMP_AP_BKPF_BSEG'), ('T052U', 'BSEG'), 
                ('T052U', 'LFB1'), ('T052U', 'TMP_AP_BKPF_BSEG_1'), ('T052U', '_CEL_AP_CASES_VIEW'), 
                # EKPO
                ('EKPO', '_CEL_AP_CASES_VIEW_1'),('EKPO', 'TMP_AP_BKPF_BSEG'),('EKPO', '_CEL_AP_CASES_VIEW'),
    
    ]
    G = Graph(airplanes_list,airplanes_edges )  # 建立：空的 無向圖
    
    print(list(G.nodes))
    print(len(list(G.edges)))
    # Graph.draw(G)
    
    print(dir(G))
    # print(list(nx.connected_components(G)))
    print(G.edgesNum)
    print(G.nodesNum)

    