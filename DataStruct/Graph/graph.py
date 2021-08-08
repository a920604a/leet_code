import copy
import sys
from abc import ABCMeta, abstractmethod
from collections import defaultdict

# 假設所有路徑都沒有負權重，且都為1


# interface according probelm
class GraphFactory(metaclass=ABCMeta):
    @abstractmethod
    def get_shortest_path(self, src: str, des: str):
        pass

    @abstractmethod
    def get_subtrees(self, selected_node_ids: list):
        pass


class Graph(GraphFactory):
    def __init__(self, vertices: list, edges: list):
        self.vertices = vertices
        self.edges = edges
        self.V = len(vertices)
        self.E = len(edges)
        # char -> int
        self.encode = Graph.encode(self.vertices)
        # Int -> char
        self.decode = {y: x for x, y in self.encode.items()}

        self.graph_init()
        # initialize graph adjacency matrix for get shortest path method
        self.adjacency_matrix = self.construct_adjacency_matrix(self.edges)
        # initialize graph adjacency list for get_subtrees method
        self.adjacency_list = Graph.construct_adjacency_list(self.edges)

    @staticmethod
    def encode(vertices: list):
        mapping = dict()
        i = 0
        for v in vertices:
            mapping[v] = i
            i += 1
        return mapping

    @staticmethod
    def construct_adjacency_list(edges: list):

        adjacency_list = defaultdict(list)
        for (u, v) in edges:
            adjacency_list[u].append(v)
        return adjacency_list

    def graph_init(self):
        self.graph = [[0 for column in range(self.V)] for row in range(self.V)]
        for i in range(self.V):
            self.graph[i][i] = 1

    def construct_adjacency_matrix(self, edges: list):
        graph = copy.deepcopy(self.graph)
        for edge in edges:
            s, e = self.encode[edge[0]], self.encode[edge[1]]

            graph[s][e] = 1
            graph[e][s] = 1
        for i in range(self.V):
            graph[i][i] = 0

        return graph

    def printSolution(self, src, dist):
        for node in range(self.V):
            print(
                "The distance from ",
                self.decode[src],
                "to\t",
                self.decode[node],
                "is \t",
                dist[node],
            )

    def findClosestPt(self, dist: list, visited: set) -> int:
        # pick the closest node from not visited set

        min = sys.maxsize
        for v in range(self.V):
            if dist[v] < min and v not in visited:
                min = dist[v]
                min_index = v

        return min_index

    def get_shortest_path(self, src: str, des: str):
        """[dijkstra algo]
        asume edges are positive


        Args:
            src (str): [source node]
            des (str): [destination node]

        Returns:
            [int]: [The shortest distance from source node to destination node]
        """

        des = self.encode[des]
        src = self.encode[src]

        # initalize
        # dist : maintain a list to recorder src to each dist shortest distance.
        # visited : represented the point whether already visited
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        visited = set()

        for cout in range(self.V):
            # find a point u which is the closest from dist list
            u = self.findClosestPt(dist, visited)

            # because of positive edges
            visited.add(u)

            # update closer path
            # self.adjacency_matrix[u][v] 有路可以直接到
            # visited[v]  還沒拜訪過
            # dist[u] + self.adjacency_matrix[u][v] < dist[v] 距離較短，可以更新
            for v in range(self.V):
                if (
                    self.adjacency_matrix[u][v] > 0
                    and v not in visited
                    and dist[u] + self.adjacency_matrix[u][v] < dist[v]
                ):
                    dist[v] = dist[u] + self.adjacency_matrix[u][v]

        # debug
        # self.printSolution(src, dist)
        # print(
        #     "The distance from ",
        #     self.decode[src],
        #     "to\t",
        #     self.decode[des],
        #     "is \t",
        #     dist[des],
        # )
        return dist[des]
        #        dist = 0  inf inf   inf inf inf
        # u=A           0    1   1   inf inf inf , visited = {A}
        # u=B           0    1   1   2   inf inf , visited = {A, B}
        # u=C           0    1   1   2   2   inf , visited = {A, B, C}
        # u=D           0    1   1   2   2   3   , visited = {A, B, C, D}
        # u=E           0    1   1   2   2   3   , visited = {A, B, C, D, E}
        # u=F           0    1   1   2   2   3   , visited = {A, B, C, D, E, F}

    def get_subtrees(self, selected_node_ids: list, method="bfs"):
        ret = []
        Search = None
        if method == "bfs":
            Search = self.bfs
        else:
            Search = self.dfs

        for selected_node in selected_node_ids:
            path = Search(selected_node)
            ret.append(path)
            # debug
            # print(f"node:\t{selected_node},\npath:\n{path}\n")
        return ret

    def dfsUtil(self, v, visited, ret):

        visited.add(v)
        # traverse node v's neighbours
        for neighbour in self.adjacency_list[v]:

            # check the point whether visited already
            if neighbour not in visited:
                ret.append((v, neighbour))
                self.dfsUtil(neighbour, visited, ret)

    def dfs(self, v):

        visited = set()
        ret = []
        self.dfsUtil(v, visited, ret)

        return ret

    def bfs(self, selected_node: str):

        queue = []
        visited = set()
        ret = []

        queue.append(selected_node)
        visited.add(selected_node)
        while queue:
            selected_node = queue.pop(0)
            # traverse selected_node neighbours
            for i in self.adjacency_list[selected_node]:
                # check the point whether visited already
                if i not in visited:
                    queue.append(i)
                    visited.add(i)
                    ret.append((selected_node, i))
        return ret


test_data1 = {
    "nodes": [
        "CDHDR",
        "BKPF",
        "CDPOS",
        "SWWLOGHIST",
        "TVZBT",
        "SWW_WI2OBJ",
        "TMP_AP_BKPF_BSEG_1",
        "T042Z",
        "USR02",
        "T003T",
        "LFB1",
        "TMP_AP_BKPF_BSEG",
        "BSEG",
        "PSIIC_HEAD",
        "_CEL_AP_CASES_VIEW",
        "TBSLT",
        "LFA1",
        "REGUP",
        "BSEC",
        "_CEL_AP_CASES_VIEW_1",
        "T052U",
        "EKPO",
    ],
    "edges": [
        # CDHDR
        ("CDHDR", "CDPOS"),
        ("CDHDR", "USR02"),
        # BKPF
        ("BKPF", "TMP_AP_BKPF_BSEG"),
        ("BKPF", "LFA1"),
        ("BKPF", "_CEL_AP_CASES_VIEW_1"),
        ("BKPF", "BSEG"),
        ("BKPF", "PSIIC_HEAD"),
        ("BKPF", "REGUP"),
        ("BKPF", "LFB1"),
        ("BKPF", "SWW_WI2OBJ"),
        ("BKPF", "_CEL_AP_CASES_VIEW"),
        ("BKPF", "USR02"),
        ("BKPF", "T003T"),
        ("BKPF", "TMP_AP_BKPF_BSEG_1"),
        ("BKPF", "CDPOS"),
        # CDPOS
        ("CDPOS", "CDHDR"),
        ("CDPOS", "BKPF"),
        ("CDPOS", "TMP_AP_BKPF_BSEG"),
        ("CDPOS", "PSIIC_HEAD"),
        ("CDPOS", "_CEL_AP_CASES_VIEW"),
        ("CDPOS", "TMP_AP_BKPF_BSEG_1"),
        # SWWLOGHIST
        ("SWWLOGHIST", "SWW_WI2OBJ"),
        # TMP_AP_BKPF_BSEG_1
        ("TMP_AP_BKPF_BSEG_1", "BKPF"),
        ("TMP_AP_BKPF_BSEG_1", "TVZBT"),
        ("TMP_AP_BKPF_BSEG_1", "SWW_WI2OBJ"),
        ("TMP_AP_BKPF_BSEG_1", "T042Z"),
        ("TMP_AP_BKPF_BSEG_1", "USR02"),
        ("TMP_AP_BKPF_BSEG_1", "TMP_AP_BKPF_BSEG"),
        ("TMP_AP_BKPF_BSEG_1", "BSEG"),
        ("TMP_AP_BKPF_BSEG_1", "LFB1"),
        ("TMP_AP_BKPF_BSEG_1", "LFA1"),
        ("TMP_AP_BKPF_BSEG_1", "TBSLT"),
        ("TMP_AP_BKPF_BSEG_1", "PSIIC_HEAD"),
        ("TMP_AP_BKPF_BSEG_1", "_CEL_AP_CASES_VIEW_1"),
        ("TMP_AP_BKPF_BSEG_1", "REGUP"),
        ("TMP_AP_BKPF_BSEG_1", "T052U"),
        ("TMP_AP_BKPF_BSEG_1", "_CEL_AP_CASES_VIEW"),
        # TVZBT
        ("TVZBT", "LFA1"),
        ("TVZBT", "_CEL_AP_CASES_VIEW_1"),
        ("TVZBT", "BSEG"),
        ("TVZBT", "_CEL_AP_CASES_VIEW"),
        ("TVZBT", "LFB1"),
        ("TVZBT", "TMP_AP_BKPF_BSEG_1"),
        # T042Z
        ("T042Z", "_CEL_AP_CASES_VIEW_1"),
        ("T042Z", "T052U"),
        ("T042Z", "_CEL_AP_CASES_VIEW"),
        ("T042Z", "TMP_AP_BKPF_BSEG_1"),
        # SWW_WI2OBJ
        ("SWW_WI2OBJ", "SWWLOGHIST"),
        ("SWW_WI2OBJ", "BKPF"),
        ("SWW_WI2OBJ", "_CEL_AP_CASES_VIEW"),
        ("SWW_WI2OBJ", "TMP_AP_BKPF_BSEG_1"),
        # USR02
        ("USR02", "CDHDR"),
        ("USR02", "BKPF"),
        ("USR02", "PSIIC_HEAD"),
        ("USR02", "TMP_AP_BKPF_BSEG"),
        ("USR02", "_CEL_AP_CASES_VIEW"),
        # TMP_AP_BKPF_BSEG
        ("TMP_AP_BKPF_BSEG", "LFA1"),
        ("TMP_AP_BKPF_BSEG", "_CEL_AP_CASES_VIEW_1"),
        ("TMP_AP_BKPF_BSEG", "T052U"),
        ("TMP_AP_BKPF_BSEG", "TBSLT"),
        ("TMP_AP_BKPF_BSEG", "REGUP"),
        ("TMP_AP_BKPF_BSEG", "EKPO"),
        ("TMP_AP_BKPF_BSEG", "PSIIC_HEAD"),
        ("TMP_AP_BKPF_BSEG", "_CEL_AP_CASES_VIEW"),
        ("TMP_AP_BKPF_BSEG", "BSEG"),
        ("TMP_AP_BKPF_BSEG", "LFB1"),
        ("TMP_AP_BKPF_BSEG", "TMP_AP_BKPF_BSEG_1"),
        ("TMP_AP_BKPF_BSEG", "USR02"),
        ("TMP_AP_BKPF_BSEG", "SWW_WI2OBJ"),
        ("TMP_AP_BKPF_BSEG", "CDPOS"),
        ("TMP_AP_BKPF_BSEG", "T042Z"),
        ("TMP_AP_BKPF_BSEG", "BKPF"),
        ("TMP_AP_BKPF_BSEG", "TVZBT"),
        # BSEG
        ("BSEG", "BKPF"),
        ("BSEG", "TMP_AP_BKPF_BSEG"),
        ("BSEG", "LFA1"),
        ("BSEG", "BSEC"),
        ("BSEG", "TBSLT"),
        ("BSEG", "_CEL_AP_CASES_VIEW_1"),
        ("BSEG", "_CEL_AP_CASES_VIEW"),
        # LFB1
        ("LFB1", "BKPF"),
        ("LFB1", "TVZBT"),
        ("LFB1", "_CEL_AP_CASES_VIEW_1"),
        ("LFB1", "T052U"),
        ("LFB1", "_CEL_AP_CASES_VIEW"),
        # T003T
        ("T003T", "BKPF"),
        ("T003T", "_CEL_AP_CASES_VIEW"),
        # _CEL_AP_CASES_VIEW
        ("_CEL_AP_CASES_VIEW", "T003T"),
        ("_CEL_AP_CASES_VIEW", "TMP_AP_BKPF_BSEG_1"),
        ("_CEL_AP_CASES_VIEW", "CDPOS"),
        ("_CEL_AP_CASES_VIEW", "USR02"),
        ("_CEL_AP_CASES_VIEW", "BKPF"),
        ("_CEL_AP_CASES_VIEW", "SWW_WI2OBJ"),
        ("_CEL_AP_CASES_VIEW", "LFB1"),
        ("_CEL_AP_CASES_VIEW", "T042Z"),
        ("_CEL_AP_CASES_VIEW", "TVZBT"),
        ("_CEL_AP_CASES_VIEW", "BSEG"),
        ("_CEL_AP_CASES_VIEW", "TMP_AP_BKPF_BSEG"),
        ("_CEL_AP_CASES_VIEW", "PSIIC_HEAD"),
        ("_CEL_AP_CASES_VIEW", "TBSLT"),
        ("_CEL_AP_CASES_VIEW", "LFA1"),
        ("_CEL_AP_CASES_VIEW", "_CEL_AP_CASES_VIEW_1"),
        ("_CEL_AP_CASES_VIEW", "REGUP"),
        ("_CEL_AP_CASES_VIEW", "T052U"),
        ("_CEL_AP_CASES_VIEW", "EKPO"),
        # PSIIC_HEAD
        ("PSIIC_HEAD", "TMP_AP_BKPF_BSEG_1"),
        ("PSIIC_HEAD", "CDPOS"),
        ("PSIIC_HEAD", "BKPF"),
        ("PSIIC_HEAD", "TMP_AP_BKPF_BSEG"),
        ("PSIIC_HEAD", "_CEL_AP_CASES_VIEW_1"),
        ("PSIIC_HEAD", "_CEL_AP_CASES_VIEW"),
        # TBSLT
        ("TBSLT", "TMP_AP_BKPF_BSEG_1"),
        ("TBSLT", "BSEG"),
        ("TBSLT", "TMP_AP_BKPF_BSEG"),
        ("TBSLT", "_CEL_AP_CASES_VIEW_1"),
        ("TBSLT", "_CEL_AP_CASES_VIEW"),
        # LFA1
        ("LFA1", "TMP_AP_BKPF_BSEG"),
        ("LFA1", "BKPF"),
        ("LFA1", "BSEG"),
        ("LFA1", "TMP_AP_BKPF_BSEG_1"),
        ("LFA1", "_CEL_AP_CASES_VIEW"),
        # REGUP
        ("REGUP", "_CEL_AP_CASES_VIEW"),
        ("REGUP", "TMP_AP_BKPF_BSEG"),
        # BSEC
        ("BSEC", "BSEG"),
        ("BSEC", "_CEL_AP_CASES_VIEW_1"),
        # _CEL_AP_CASES_VIEW_1
        ("_CEL_AP_CASES_VIEW_1", "BSEC"),
        ("_CEL_AP_CASES_VIEW_1", "LFA1"),
        ("_CEL_AP_CASES_VIEW_1", "TMP_AP_BKPF_BSEG"),
        ("_CEL_AP_CASES_VIEW_1", "TVZBT"),
        ("_CEL_AP_CASES_VIEW_1", "T042Z"),
        ("_CEL_AP_CASES_VIEW_1", "TBSLT"),
        ("_CEL_AP_CASES_VIEW_1", "BKPF"),
        ("_CEL_AP_CASES_VIEW_1", "BSEG"),
        ("_CEL_AP_CASES_VIEW_1", "LFB1"),
        ("_CEL_AP_CASES_VIEW_1", "PSIIC_HEAD"),
        ("_CEL_AP_CASES_VIEW_1", "TMP_AP_BKPF_BSEG_1"),
        ("_CEL_AP_CASES_VIEW_1", "_CEL_AP_CASES_VIEW"),
        ("_CEL_AP_CASES_VIEW_1", "EKPO"),
        ("_CEL_AP_CASES_VIEW_1", "T052U"),
        # T052U
        ("T052U", "_CEL_AP_CASES_VIEW_1"),
        ("T052U", "TMP_AP_BKPF_BSEG"),
        ("T052U", "BSEG"),
        ("T052U", "LFB1"),
        ("T052U", "TMP_AP_BKPF_BSEG_1"),
        ("T052U", "_CEL_AP_CASES_VIEW"),
        # EKPO
        ("EKPO", "_CEL_AP_CASES_VIEW_1"),
        ("EKPO", "TMP_AP_BKPF_BSEG"),
        ("EKPO", "_CEL_AP_CASES_VIEW"),
    ],
}

test_data2 = {
    "nodes": ["A", "B", "C", "D", "E", "F"],
    "edges": [
        ("A", "B"),
        ("A", "C"),
        ("B", "A"),
        ("B", "C"),
        ("B", "D"),
        ("C", "A"),
        ("C", "B"),
        ("C", "D"),
        ("C", "E"),
        ("D", "B"),
        ("D", "C"),
        ("D", "E"),
        ("D", "F"),
        ("E", "C"),
        ("E", "D"),
        ("F", "D"),
    ],
}
if __name__ == "__main__":
    # client
    g = Graph(test_data1["nodes"], test_data1["edges"])
    print(g.get_shortest_path("CDHDR", "LFB1"))
    print(g.get_subtrees(["BSEC", "T003T"]))
